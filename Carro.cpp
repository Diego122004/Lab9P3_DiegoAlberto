#include "Carro.h"
#include <iostream>
#include <cstdlib>
using namespace std;

Carro::Carro() {
	id = rand() % 500 + 1; // ID aleatório entre 1 e 500
	string mods[] = { "Corolla","Yaris", "Hilux", "Rav4" , "supra"};
	modelo = mods[rand() % 5];
	año = rand() % 16 + 2010; // Ano aleatório entre 2010 e 2025
	string colors[] = { "Negro", "Azul", "Rojo", "Plata", "Blanco" };
	color = colors[rand() % 5];
	string estados[] = { "Excelente","Bueno", "Regular", "Defectuoso"};
	estadoMotor = estados[rand() % 4];
	int canDefectos = rand() % 5; // Número aleatório de defeitos entre 0 e 4
	string	listDefS[] = { "Rayones", "Abolladuras", "Neumáticos desgastados", "Fallas eléctricas", "Problemas de frenos" };
	for (int i = 0; i < canDefectos; i++) {
		defectos.push_back(new Defecto(listDefS[rand() % 5]));
	};

}
int Carro::getId() {
	return id;
};
string Carro::getModelo() {
	return modelo;
};
int Carro::getAño() {
	return año;
};
string Carro::getColor() {
	return color;
};
string Carro::getEstadoMotor() {
	return estadoMotor;
};
vector<Defecto*> Carro::getDefectos() {
	return defectos;
};
bool Carro::tieneDefectos() {
	return defectos.size() > 0;
};
void Carro::mostrarInfo() {
	cout << id << ", "
		<< modelo << ", "
		<< año << ", "
		<< color << ", "
		<< estadoMotor;

	if (defectos.size() > 0) {
		cout << ", ";
		for (size_t i = 0; i < defectos.size(); i++) {
			cout << defectos[i]->getDescripcion();
			if (i < defectos.size() - 1) {
				cout << "; ";
			}
		};
	};
	cout << endl;
};

void Carro::setId(int newId) {
	this->id = newId;
}
void Carro::setModelo(string newModelo) {
	this->modelo = newModelo;
}
void Carro::setAño(int newAño) {
	this->año = newAño;
}
void Carro::setColor(string newColor) {
	this->color = newColor;
}
void Carro::setEstadoMotor(string newEstadoMotor) {
	this->estadoMotor = newEstadoMotor;
}

void Carro::agregarDefecto(Defecto* defecto) {
	defectos.push_back(defecto);
}

void Carro::eliminarDefecto() {
	for (auto c: defectos) {
		delete c;
		defectos.clear();
	}
}

Carro::~Carro() {
	for (size_t i = 0; i < defectos.size(); i++) {
		delete defectos[i];
	}
}



