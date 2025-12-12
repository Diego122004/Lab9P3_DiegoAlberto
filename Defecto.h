#pragma once
#include <iostream>
#include <string>
using namespace std;

class Defecto {

	string descripcion;
	public:
		Defecto();
		Defecto(string desc);
		~Defecto();
		void setDescripcion(string desc);
		string getDescripcion();
};