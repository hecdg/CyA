// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Cadenas y lenguajes
// Autor: Héctor Díaz González
// Correo: alu0101734682@ull.edu.es
// Fecha: 20/09/2025
// Archivo: alfabeto.h
// Contiene la definición de la clase Alfabeto

#ifndef ALFABETO_H
#define ALFABETO_H

#include <set>
#include <string>
#include <iostream>

class Alfabeto {
 public:
  Alfabeto() = default;
  Alfabeto(const std::string& simbolos);

  friend std::ostream& operator<<(std::ostream& os, const Alfabeto& alfabeto);

 private:
  std::set<char> simbolos_;
};

#endif  // ALFABETO_H