#ifndef COMMENT_H_
#define COMMENT_H_

#include <string>

class Comment {
  public:
    Comment(std::string tipo, int linea_inicio, int linea_fin, std::string contenido);

    const std::string& tipo() const;
    int linea_inicio() const;
    int linea_fin() const;
    const std::string& contenido() const;

    std::string ToString() const;

  private:
    std::string tipo_;
    int linea_inicio_;
    int linea_fin_;
    std::string contenido_;
};

#endif  // COMMENT_H_
