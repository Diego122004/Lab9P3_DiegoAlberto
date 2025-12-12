#include "Fabrica.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>

using namespace std;

Fabrica::Fabarica() {};

Fabrica::~Fabarica() {
for(Carro* c : carros)
delete c;
};

void Fabrica::adicionarCarroNuevo() {
	Carro* carro = new Carro();
	carros.push_back(carro);
	cout << "Carro Creado." << endl;
}
void Fabrica::listarTodos() {
	
	for (Carro* c : carros) {
		
		c->mostrarInfo();
	}
}

void Fabrica::listarSinDf() {

};