#ifndef LOOP_H_
#define LOOP_H_

#include <string>

class Loop {
  public:
    Loop(std::string tipo, int linea);

    const std::string& tipo() const;
    int linea() const;

    std::string ToString() const; 

  private:
    std::string tipo_;
    int linea_;
};

#endif  // LOOP_H_
