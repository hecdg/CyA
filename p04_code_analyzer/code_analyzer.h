#ifndef CODE_ANALYZER_H_
#define CODE_ANALYZER_H_

#include <string>
#include "code_structure.h"

class CodeAnalyzer {
    public:
      explicit CodeAnalyzer() = default;

      bool AnalyzeFile(const std::string& input_file);

      const CodeStructure& estructura() const { return estructura_; }

    private:
      CodeStructure estructura_ = CodeStructure("");
};

#endif  // CODE_ANALYZER_H_
