#include "Defecto.h"


Defecto::Defecto() {
	// Constructor por defecto
}
Defecto::Defecto(string decripcion) {
	this->descripcion = decripcion;
}
string Defecto::getDescripcion() {
	return descripcion;
}
Defecto::~Defecto() {
	// Destructor
}	

