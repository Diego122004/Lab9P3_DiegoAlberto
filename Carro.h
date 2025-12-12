#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Defecto.h"
using namespace std;
class Carro {

	int id;
	string modelo;
	int año;
	string color;
	string estadoMotor;
	vector<Defecto*> defectos;

public:
	Carro();
	Carro(int id, string modelo, int año, string color, string estadoMotor);
	int getId();
	string getModelo();
	int getAño();
	string getColor();
	string getEstadoMotor();
	vector<Defecto*> getDefectos();
	void setId(int id);
	void setModelo(string modelo);	
	void setAño(int año);
	void setColor(string color);
	void setEstadoMotor(string estadoMotor);
	void agregarDefecto(Defecto* df);
	void eliminarDefecto();
	bool tieneDefectos();
	void mostrarInfo();
	~Carro();

	

	
};