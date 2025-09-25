// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 2: Cadenas y lenguajes
// Autor: Héctor Díaz González
// Correo: alu0101734682@ull.edu.es
// Fecha: 20/09/2025
// Archivo: p02_strings.cc
// Contiene el main

#include "cadena.h"
#include "lenguaje.h"
#include <fstream>
#include <iostream>

void MostrarUso() {
  std::cout << "Modo de empleo: ./p02_strings filein.txt fileout.txt opcode\n";
  std::cout << "Opcodes disponibles:\n";
  std::cout << "1: Alfabeto\n";
  std::cout << "2: Longitud\n";
  std::cout << "3: Inversa\n";
  std::cout << "4: Prefijos\n";
  std::cout << "5: Sufijos\n";
}

int main(int argc, char* argv[]) {
  if (argc != 4) {
    MostrarUso();
    return 1;
  }

  std::string input_file = argv[1];
  std::string output_file = argv[2];
  int opcode = std::stoi(argv[3]);

  std::ifstream fin(input_file);
  if (!fin) {
    std::cerr << "Error abriendo fichero de entrada\n";
    return 1;
  }
  std::ofstream fout(output_file);

  std::string valor, simbolos;
  while (fin >> valor >> simbolos) {
    Alfabeto alfabeto(simbolos);
    Cadena cadena(valor, alfabeto);

    switch (opcode) {
      case 1:
        fout << alfabeto << "\n";
        break;
      case 2:
        fout << cadena.Longitud() << "\n";
        break;
      case 3:
        fout << cadena.Inversa() << "\n";
        break;
      case 4:
        fout << Lenguaje(cadena.Prefijos()) << "\n";
        break;
      case 5:
        fout << Lenguaje(cadena.Sufijos()) << "\n";
        break;
      default:
        std::cerr << "Opcode no válido\n";
        return 1;
    }
  }

  return 0;
}
