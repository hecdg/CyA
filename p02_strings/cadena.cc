// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Cadenas y lenguajes
// Autor: Héctor Díaz González
// Correo: alu0101734682@ull.edu.es
// Fecha: 20/09/2025
// Archivo: cadena.cc
// Contiene la clase Cadena

#include "cadena.h"
#include <algorithm>

Cadena::Cadena(const std::string& valor, const Alfabeto& alfabeto)
    : valor_(valor), alfabeto_(alfabeto) {}

size_t Cadena::Longitud() const {
  return valor_.size();
}

Cadena Cadena::Inversa() const {
  std::string invertida = valor_;
  std::reverse(invertida.begin(), invertida.end());
  return Cadena(invertida, alfabeto_);
}

std::set<std::string> Cadena::Prefijos() const {
  std::set<std::string> prefijos;
  prefijos.insert("&");
  for (size_t i = 1; i <= valor_.size(); ++i) {
    prefijos.insert(valor_.substr(0, i));
  }
  return prefijos;
}

std::set<std::string> Cadena::Sufijos() const {
  std::set<std::string> sufijos;
  sufijos.insert("&");
  for (size_t i = 0; i < valor_.size(); ++i) {
    sufijos.insert(valor_.substr(i));
  }
  return sufijos;
}

std::ostream& operator<<(std::ostream& os, const Cadena& cadena) {
  os << cadena.valor_;
  return os;
}