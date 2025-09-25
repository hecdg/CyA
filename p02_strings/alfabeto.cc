// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Cadenas y lenguajes
// Autor: Héctor Díaz González
// Correo: alu0101734682@ull.edu.es
// Fecha: 20/09/2025
// Archivo: alfabeto.cc
// Contiene la clase Alfabeto

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