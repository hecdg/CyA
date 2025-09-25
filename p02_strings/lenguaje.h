// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Cadenas y lenguajes
// Autor: Héctor Díaz González
// Correo: alu0101734682@ull.edu.es
// Fecha: 20/09/2025
// Archivo: lenguaje.h
// Contiene la definición de la clase Lenguaje

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