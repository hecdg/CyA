#ifndef CODE_STRUCTURE_H_
#define CODE_STRUCTURE_H_

#include <string>
#include <vector>

#include "variable.h"
#include "loop.h"
#include "comment.h"

class CodeStructure {
  public:
    explicit CodeStructure(std::string filename);

    void AddVariable(const Variable& var);
    void AddLoop(const Loop& loop);
    void AddComment(const Comment& comment);
    void SetHasMain(bool has_main);

    const std::string& filename() const;
    const std::vector<Variable>& variables() const;
    const std::vector<Loop>& loops() const;
    const std::vector<Comment>& comments() const;
    bool has_main() const;

    bool GenerateReport(const std::string& output_file) const;

 private:
    std::string filename_;
    std::vector<Variable> variables_;
    std::vector<Loop> loops_;
    std::vector<Comment> comments_;
    bool has_main_ = false;
};

#endif  // CODE_STRUCTURE_H_
