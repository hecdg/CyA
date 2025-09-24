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
  int line_number = 1;
  while (fin >> valor >> simbolos) {
    Alfabeto alfabeto(simbolos);
    Cadena cadena(valor, alfabeto);

    switch (opcode) {
      case 1:
        fout << line_number << " " << alfabeto << "\n";
        break;
      case 2:
        fout << line_number << " " << cadena.Longitud() << "\n";
        break;
      case 3:
        fout << line_number << " " << cadena.Inversa() << "\n";
        break;
      case 4:
        fout << line_number << " " << Lenguaje(cadena.Prefijos()) << "\n";
        break;
      case 5:
        fout << line_number << " " << Lenguaje(cadena.Sufijos()) << "\n";
        break;
      default:
        std::cerr << "Opcode no válido\n";
        return 1;
    }
    ++line_number;
  }

  return 0;
}
