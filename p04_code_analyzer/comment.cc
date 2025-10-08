#include "comment.h"
#include <sstream>

Comment::Comment(std::string tipo, int linea_inicio, int linea_fin, std::string contenido)
    : tipo_(std::move(tipo)),
      linea_inicio_(linea_inicio),
      linea_fin_(linea_fin),
      contenido_(std::move(contenido)) {}

const std::string& Comment::tipo() const { return tipo_; }
int Comment::linea_inicio() const { return linea_inicio_; }
int Comment::linea_fin() const { return linea_fin_; }
const std::string& Comment::contenido() const { return contenido_; }

std::string Comment::ToString() const {
    std::ostringstream oss;
    oss << "[Line " << linea_inicio_;
    if (linea_fin_ != linea_inicio_) oss << "-" << linea_fin_;
    oss << "] COMMENT (" << tipo_ << "): " << contenido_;
    return oss.str();
}
