#include "code_analyzer.h"

#include <fstream>
#include <iostream>
#include <regex>
#include <string>

// Analiza un archivo fuente y detecta variables, bucles, comentarios y main
bool CodeAnalyzer::AnalyzeFile(const std::string& input_file) {
    std::ifstream file(input_file);
    if (!file.is_open()) {
        std::cerr << "Error: no se pudo abrir el archivo: " << input_file << "\n";
        return false;
    }

    estructura_ = CodeStructure(input_file);

    std::string line;
    int line_number = 0;

    bool in_multiline_comment = false;
    int multiline_start = 0;
    std::string multiline_content;

    std::regex regex_var(R"(^\s*(int|double)\s+([a-zA-Z_]\w*)(\s*=\s*[^;]+)?;)");
    std::regex regex_for(R"(^\s*for\s*\()");
    std::regex regex_while(R"(^\s*while\s*\()");
    std::regex regex_main(R"(\bint\s+main\s*\()");
    std::regex regex_comment_single(R"(//(.*))");
    std::regex regex_comment_start(R"(/\*)");
    std::regex regex_comment_end(R"(\*/)");

    while (std::getline(file, line)) {
        ++line_number;

    // --- Si estamos dentro de un comentario multilínea ---
    if (in_multiline_comment) {
        multiline_content += "\n" + line;
    if (std::regex_search(line, regex_comment_end)) {
        in_multiline_comment = false;
        estructura_.AddComment(
            Comment("multi", multiline_start, line_number, multiline_content));
        multiline_content.clear();
      }
        continue;
    }

    // --- Detección de inicio de comentario multilínea ---
    if (std::regex_search(line, regex_comment_start)) {
        if (std::regex_search(line, regex_comment_end)) {
            estructura_.AddComment(Comment("multi", line_number, line_number, line));
      } else {
        in_multiline_comment = true;
        multiline_start = line_number;
        multiline_content = line;
      }
        continue;
    }

    // --- Comentario de una línea ---
    std::smatch match;
    if (std::regex_search(line, match, regex_comment_single)) {
        estructura_.AddComment(Comment("single", line_number, line_number, match[1]));
      // seguimos al siguiente para evitar falsos positivos en código comentado
        continue;
    }

    // --- Función main ---
    if (std::regex_search(line, regex_main)) {
        estructura_.SetHasMain(true);
    }

    // --- Bucles ---
    if (std::regex_search(line, regex_for)) {
        estructura_.AddLoop(Loop("for", line_number));
    } else if (std::regex_search(line, regex_while)) {
        estructura_.AddLoop(Loop("while", line_number));
    }

    // --- Variables ---
    if (std::regex_search(line, match, regex_var)) {
        std::string tipo = match[1];
        std::string nombre = match[2];
        bool inicializada = match[3].matched;
        estructura_.AddVariable(Variable(tipo, nombre, line_number, inicializada));
    }
  }

  // --- Si el archivo termina dentro de un comentario multilínea ---
    if (in_multiline_comment) {
        estructura_.AddComment(Comment("multi", multiline_start, line_number, multiline_content + "\n(unterminated)"));
    }

  return true;
}
