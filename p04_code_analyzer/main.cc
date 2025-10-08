#include <iostream>
#include <string>
#include "code_analyzer.h"

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Uso: " << argv[0] << " <input_file> <output_report>\\n";
        return 1;
    }

    std::string input = argv[1];
    std::string output = argv[2];

    CodeAnalyzer analyzer;
    if (!analyzer.AnalyzeFile(input)) {
        std::cerr << "Fallo en el análisis del archivo.\\n";
        return 2;
    }

    if (!analyzer.estructura().GenerateReport(output)) {
        std::cerr << "Fallo al generar el reporte.\\n";
        return 3;
    }

    std::cout << "Reporte generado: " << output << "\\n";
    return 0;
}
