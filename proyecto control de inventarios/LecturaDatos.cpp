
#include<iostream>
#include "LecturaDatos.h"

using namespace std;


int leerInt(string mensaje) {
	int entero;
	string mens = mensaje;
	do {
		cout << mens << endl;
		cin >> entero;
		if (entero < 0) {
			cout << "Error... la cantidad debe ser mayor a 0";
		}
	} while (entero < 0);
	return entero;

}

char leerChar(string mensaje) {
	string mens = mensaje;
	string cadena;
	
	do {
		cout << mens << endl;
		cin >> cadena;
		if (cadena == " ") {
			cout << "Error... no se ha ingresado valor";
		}
		if (cadena.length()>1) {
			cout << "Error... debe ingresar sólo un caracter";
		}

	} while (cadena == " " || cadena.length() > 1);
	char c = cadena[0];
	return c;
	
}

string leerString(string mensaje) {
	string cadena;
	do {
		cout << mensaje << endl;
		cin >> cadena;
		if (cadena=="")
		{
			cout << "Error... no se ha ingresado valor";
		}
	} while (cadena == "");
	return cadena;
}



