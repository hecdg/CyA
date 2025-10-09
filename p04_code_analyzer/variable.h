#ifndef VARIABLE_H_
#define VARIABLE_H_

#include <string>

class Variable {
    public:
        Variable(std::string tipo, std::string nombre, int linea, bool inicializada, std::string valor = "");

        const std::string& tipo() const;
        const std::string& nombre() const;
        int linea() const;
        bool inicializada() const;

        std::string ToString() const; 
    private:
        std::string tipo_;
        std::string nombre_;
        int linea_;
        bool inicializada_;
        std::string valor_;
};

#endif  // VARIABLE_H_
