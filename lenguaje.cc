#include "lenguaje.h"

Lenguaje::Lenguaje(const std::set<std::string>& cadenas) : cadenas_(cadenas) {}

std::ostream& operator<<(std::ostream& os, const Lenguaje& lenguaje) {
  os << "{";
  bool first = true;
  for (const auto& cadena : lenguaje.cadenas_) {
    if (!first) os << ", ";
    os << cadena;
    first = false;
  }
  os << "}";
  return os;
}
