#include "alfabeto.h"

Alfabeto::Alfabeto(const std::string& simbolos) {
  for (char c : simbolos) {
    if (c != '&') {  // no se permite usar & como símbolo
      simbolos_.insert(c);
    }
  }
}

bool Alfabeto::Pertenece(char simbolo) const {
  return simbolos_.count(simbolo) > 0;
}

const std::set<char>& Alfabeto::Simbolos() const {
  return simbolos_;
}

std::ostream& operator<<(std::ostream& os, const Alfabeto& alfabeto) {
  os << "{";
  bool first = true;
  for (char c : alfabeto.simbolos_) {
    if (!first) os << ", ";
    os << c;
    first = false;
  }
  os << "}";
  return os;
}
