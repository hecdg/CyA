#ifndef CODE_ANALYZER_H_
#define CODE_ANALYZER_H_

#include <string>
#include "code_structure.h"

class CodeAnalyzer {
  public:
    explicit CodeAnalyzer() = default;

  // Analiza el archivo de entrada (línea a línea) y llena la estructura.
    bool AnalyzeFile(const std::string& input_file);

  // Devuelve la estructura analizada.
    const CodeStructure& estructura() const { return estructura_; }

  private:
    CodeStructure estructura_ = CodeStructure("");
};

#endif  // CODE_ANALYZER_H_
