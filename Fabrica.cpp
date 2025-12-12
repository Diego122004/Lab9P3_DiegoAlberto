#include "Fabrica.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>

using namespace std;

Fabrica::Fabrica() {};

Fabrica::~Fabrica() {
for(Carro* c : carros)
delete c;
};

void Fabrica::OrdPorModelo(vector<Carro*> cras) {

	int n = cras.size();
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (cras[j]->getModelo() > cras[j + 1]->getModelo()) {
				Carro* temp = cras[j];
				cras[j] = cras[j + 1];
				cras[j + 1] = temp;
			}
		}
	}
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
	vector<Carro*> sinDf;
	for(Carro* c : carros) {
		if (!c->tieneDefectos()) {
			sinDf.push_back(c);
		}
	}
	OrdPorModelo(sinDf);

	for (Carro* c : sinDf) {
		c->mostrarInfo();
	}

};

void Fabrica::listarConDf() {
	vector<Carro*> conDf;
	for(Carro* c : carros) {
		if (c->tieneDefectos()) {
			conDf.push_back(c);
		}
	}
	OrdPorModelo(conDf);
	for (Carro* c : conDf) {
		c->mostrarInfo();
	}
};

void Fabrica::guardarCarros() {
	cout << "CAROS SIN DEFECTOS";
	ofstream out("Carros.txt");
	for (Carro* c : carros) {
		if (!c->tieneDefectos()) {
			out << c->getId() << ","
				<< c->getModelo() << ","
				<< c->getAño() << ","
				<< c->getColor() << ","
				<< c->getEstadoMotor() << "\n";
			}
	}
	cout << "CAROS CON DEFECTOS";
	for (Carro* c : carros) {
		if (c->tieneDefectos()) {
			out << c->getId() << ","
				<< c->getModelo() << ","
				<< c->getAño() << ","
				<< c->getColor() << ","
				<< c->getEstadoMotor() << "\n";

			auto def =
				 c->getDefectos();
			for (int i = 0; i < def.size(); i++) {
				out << def[i]->getDescripcion();
				if(i < def.size()-1){
					out << ";";
				}
				out << "\n";
			};
		}
		out.close();
		cout << "Carros guardados en Carros.txt" << endl;
	}
	
}

void Fabrica::cargarCarros() {
	ifstream in("Carros.txt");
	if (!in.is_open()) {
		cout << "No se pudo abrir el archivo Carros.txt" << endl;
		return;
	}	
	bool leyendoDefectos = false;
	string line;
	while (getline(in, line)){
		if (line == ""|| line == "CAROS SIN DEFECTOS")
			continue;
		if (line == "CAROS CON DEFECTOS") {
			leyendoDefectos = true;
			continue;
		};

		stringstream ss(line);
		string part;
		vector<string> partes;
		Carro* carro = new Carro();

	};
};