#ifndef LENGUAJE_H
#define LENGUAJE_H

#include <set>
#include <string>
#include <iostream>

class Lenguaje {
 public:
  Lenguaje() = default;
  explicit Lenguaje(const std::set<std::string>& cadenas);

  friend std::ostream& operator<<(std::ostream& os, const Lenguaje& lenguaje);

 private:
  std::set<std::string> cadenas_;
};

#endif  // LENGUAJE_H
