

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Fabrica.h"

using namespace std;

void menu();

void menu() {
	Fabrica* f = new Fabrica;
	cout << "Menu de Opciones:" << endl;
	cout << "1. Crear Fabrica" << endl;
	cout << "2. Listar Todos" << endl;
	cout << "3. Listar Sin DF" << endl;
    cout << "4. Listar Con DF" << endl;
    cout << "5. Guardar Archivo" << endl;
	cout << "0. Salir" << endl;
	cout << "Seleccione una opcion: ";
    int opcion;
    cin >> opcion;

    switch (opcion) {
    case 1:
		f->adicionarCarroNuevo();
        break;
    case 2:
		f->listarTodos();
        break;
    case 3:
        f->listarSinDf();
        break;
	case 4:
        f->listarConDf();
		break;
        case 5:
        f->guardarCarros();
		break;
    case 0:
        cout << "Saliendo... Gracias.\n";
        return; // finaliza la recursión
    default:
        cout << "Opcion no valida. Intente de nuevo.\n";
    }



    // Llamada recursiva al menú
    menu();
}

int main() {
	srand(time(0)); // Semilla para numeros aleatorios
	menu();
};
