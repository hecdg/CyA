// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Cadenas y lenguajes
// Autor: Héctor Díaz González
// Correo: alu0101734682@ull.edu.es
// Fecha: 20/09/2025
// Archivo: lenguaje.cc
// Contiene la implementación de la clase Lenguaje

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