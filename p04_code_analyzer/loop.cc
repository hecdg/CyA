#include "loop.h"

Loop::Loop(std::string tipo, int linea)
    : tipo_(std::move(tipo)), linea_(linea) {}

const std::string& Loop::tipo() const { return tipo_; }
int Loop::linea() const { return linea_; }

std::string Loop::ToString() const {
    return "[Line " + std::to_string(linea_) + "] LOOP: " + tipo_;
}
