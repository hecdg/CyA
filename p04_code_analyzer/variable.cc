#include "variable.h"
#include <sstream>
#include <cctype>

Variable::Variable(std::string tipo, std::string nombre, int linea, bool inicializada, std::string valor)
    : tipo_(std::move(tipo)), nombre_(std::move(nombre)), linea_(linea), inicializada_(inicializada), valor_(std::move(valor)) {}

const std::string& Variable::tipo() const { return tipo_; }
const std::string& Variable::nombre() const { return nombre_; }
int Variable::linea() const { return linea_; }
bool Variable::inicializada() const { return inicializada_; }

std::string Variable::ToString() const {
    std::ostringstream oss;
    std::string tipo_up = tipo_;

    for (auto& c : tipo_up) c = static_cast<char>(toupper(c));

    oss << "[Line " << linea_ << "] " << tipo_up << ": " << nombre_;
    if (inicializada_) oss << valor_;  
    return oss.str();
}
