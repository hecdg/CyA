#include "code_structure.h"

#include <fstream>
#include <iostream>
#include <sstream>

// Constructor
CodeStructure::CodeStructure(std::string filename)
    : filename_(std::move(filename)) {}

void CodeStructure::AddVariable(const Variable& var) { variables_.push_back(var); }
void CodeStructure::AddLoop(const Loop& loop) { loops_.push_back(loop); }
void CodeStructure::AddComment(const Comment& comment) { comments_.push_back(comment); }
void CodeStructure::SetHasMain(bool has_main) { has_main_ = has_main; }

const std::string& CodeStructure::filename() const { return filename_; }
const std::vector<Variable>& CodeStructure::variables() const { return variables_; }
const std::vector<Loop>& CodeStructure::loops() const { return loops_; }
const std::vector<Comment>& CodeStructure::comments() const { return comments_; }
bool CodeStructure::has_main() const { return has_main_; }

bool CodeStructure::GenerateReport(const std::string& output_file) const {
    std::ofstream ofs(output_file);
    if (!ofs) {
        std::cerr << "Error: no se pudo abrir archivo de salida: " << output_file << "\n";
        return false;
    }

    ofs << "PROGRAM: " << filename_ << "\n";

  // ===== DESCRIPTION =====
    ofs << "DESCRIPTION:\n";
    bool found_description = false;
    for (const auto& c : comments_) {
        if (c.tipo() == "multi" || c.tipo() == "description") {
            ofs << c.contenido() << "\n";
            found_description = true;
            break;  // solo el primero (comentario inicial)
        }
    }
    if (!found_description) {
        ofs << "(none)\n";
    }
    ofs << "\n";

  // ===== VARIABLES =====
    ofs << "VARIABLES:\n";
    if (variables_.empty()) {
        ofs << "(none)\n";
    } else {
        for (const auto& v : variables_) {
        ofs << v.ToString() << "\n";
        }
    }
    ofs << "\n";

  // ===== STATEMENTS (loops) =====
    ofs << "STATEMENTS:\n";
    if (loops_.empty()) {
        ofs << "(none)\n";
    } else {
        for (const auto& l : loops_) {
        ofs << l.ToString() << "\n";
        }
    }
    ofs << "\n";

  // ===== MAIN =====
    ofs << "MAIN:\n";
    ofs << (has_main_ ? "True" : "False") << "\n\n";

  // ===== COMMENTS =====
    ofs << "COMMENTS:\n";
    if (comments_.empty()) {
        ofs << "(none)\n";
    } else {
        for (const auto& c : comments_) {
      // Mostrar formato similar al PDF
        if (c.linea_inicio() == c.linea_fin()) {
            ofs << "[Line " << c.linea_inicio() << "] ";
        } else {
            ofs << "[Line " << c.linea_inicio() << "-" << c.linea_fin() << "] ";
        }

        if (c.tipo() == "multi") {
            ofs << "DESCRIPTION";
        } else {
            ofs << "// " << c.contenido();
        }
        ofs << "\n";
        }
    }

    return true;
}
