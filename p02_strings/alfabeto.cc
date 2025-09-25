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
// Contiene la implementación de la clase Alfabeto

#include "alfabeto.h"

Alfabeto::Alfabeto(const std::string& simbolos) {
  for (char c : simbolos) {
    if (c != '&') { 
      simbolos_.insert(c);
    }
  }
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