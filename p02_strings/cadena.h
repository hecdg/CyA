// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Cadenas y lenguajes
// Autor: Héctor Díaz González
// Correo: alu0101734682@ull.edu.es
// Fecha: 20/09/2025
// Archivo: cadena.h
// Contiene la definición de la clase Cadena

#ifndef CADENA_H
#define CADENA_H

#include "alfabeto.h"
#include <string>
#include <set>

class Cadena {
 public:
  Cadena() = default;
  Cadena(const std::string& valor, const Alfabeto& alfabeto);

  size_t Longitud() const;
  Cadena Inversa() const;
  std::set<std::string> Prefijos() const;
  std::set<std::string> Sufijos() const;

  const std::string& Valor() const { return valor_; }
  const Alfabeto& GetAlfabeto() const { return alfabeto_; }

  friend std::ostream& operator<<(std::ostream& os, const Cadena& cadena);

 private:
  std::string valor_;
  Alfabeto alfabeto_;
};

#endif  // CADENA_H