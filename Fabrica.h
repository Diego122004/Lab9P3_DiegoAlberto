#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Carro.h"
using namespace std;
class Fabrica {
	vector<Carro*> carros;
public:
	Fabrica();
	~Fabrica();
	void adicionarCarroNuevo();
	void listarTodos();
	void listarSinDf();
	void listarConDf();
	void guardarCarros();
	void cargarCarros();
	void OrdPorModelo(vector<Carro*> _carros);


};

