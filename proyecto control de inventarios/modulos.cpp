#include<iostream>
#include <ctype.h> //<---aqui se encuentran las funciones toupper y tolower
#include"modulos.h"


using namespace std;



int cantPedCajasColIncompleto = 0;
int totalCajasColores = 0, totalCajasColoresVendidas = 0;
int totalCajasColoresFalt = 0, cantPedpapelBondCompleto = 0;
int cantPedPapelBonIncompleto = 0, totalPapelBondMIllar = 0, totalPapeBoVent = 0, totalPapelBonFaltante = 0;
int nuevoIngresoCajaColor, opcion, cantVentCajaColor, nuevoIngresoPapelBondMillar, cantVentPapelbonMillar;
int numVeceActualiCajaCol = 0, numVeceActualiPapelBonMILL = 0;
int cantClientAtenCompl = 0, cantClientAtenParcial = 0;
int valorDecision, nuevaCantidadParcialCajacol, nuevaCantidadParcialPapel, acumuladorPedidoCompletaronParcialCAJA = 0,
acumuladorPedidoCompletaronParcialPapel = 0;
int cantipedidoDEJAatende = 0;


void ModuloProceso() {

	do {

		cantVentCajaColor = leerInt("Ingrese cantidad a vender caja de colores");
		cantVentPapelbonMillar = leerInt("Ingrese cantidad a vender papel bon millar");

		if (cantVentPapelbonMillar <= 0 || cantVentCajaColor <= 0)
			cout << "Cantidad invalida, cantidad debe ser mayor de 0 " << endl;

	} while (cantVentCajaColor <= 0 || cantVentPapelbonMillar <= 0);

	// si hay cantidad sufienciente 
	if (cantVentCajaColor <= totalCajasColores && cantVentPapelbonMillar <= totalPapelBondMIllar)
	{
		if (cantVentCajaColor >= 0 && cantVentPapelbonMillar >= 0) {

			totalCajasColores = totalCajasColores - cantVentCajaColor; // saldo stock 
			cantPedCajasColIncompleto++; // acumulador de cantidad de pedidos completos
			totalCajasColoresVendidas = totalCajasColoresVendidas + cantVentCajaColor; // acumulador total ventas caja color


			totalPapelBondMIllar = totalPapelBondMIllar - cantVentPapelbonMillar;
			cantPedpapelBondCompleto++;
			totalPapeBoVent = totalPapeBoVent + cantVentPapelbonMillar;

			cantClientAtenCompl++;
		}

	}
	// si no hay cantidad suficiente
	if (cantVentCajaColor > totalCajasColores || cantVentPapelbonMillar > totalPapelBondMIllar)
	{
		if (cantVentCajaColor >= 0 && cantVentPapelbonMillar >= 0) {

			valorDecision = leerInt("Cantidad insuficiente, desea pedir menos? V=1 , de lo contrario ingrese 0");
			if (valorDecision == 1) {
				cout << "total caja de colores" << totalCajasColores << endl;
				nuevaCantidadParcialCajacol = leerInt("ingrese la cantidad parcial caja de colores , stock actual: ");
				cout << "total papel bond millar" << totalPapelBondMIllar << endl;
				nuevaCantidadParcialPapel = leerInt("ingrese la cantidad parcial papel bond millar , stock actual: ");

				totalCajasColores = totalCajasColores - nuevaCantidadParcialCajacol; // saldo stock 
				acumuladorPedidoCompletaronParcialCAJA++; // acumulador de cantidad de pedidos completos
				totalCajasColoresVendidas = totalCajasColoresVendidas + nuevaCantidadParcialCajacol; // acumulador total ventas caja color


				totalPapelBondMIllar = totalPapelBondMIllar - nuevaCantidadParcialPapel;
				acumuladorPedidoCompletaronParcialPapel++;
				totalPapeBoVent = totalPapeBoVent + nuevaCantidadParcialPapel;

				cantClientAtenParcial++;
			}
			else {
				if (cantVentCajaColor >= 0 && cantVentPapelbonMillar >= 0) {
					cout << "Cantidad insuficiente" << endl;
					cantPedCajasColIncompleto++;
					totalCajasColoresFalt = cantVentCajaColor - totalCajasColores;


					cantPedPapelBonIncompleto++;
					totalPapelBonFaltante = cantVentPapelbonMillar - totalPapelBondMIllar;
					cantipedidoDEJAatende++;
				}
			}
		}

	}

}

void moduloMostrar() {
	cout << "cantidad de veces que se actualizo CAJA DE COLORES  " << numVeceActualiCajaCol << endl;
	cout << "cantidad de veces que se actualizo PAPEL BOND MILLAR " << numVeceActualiPapelBonMILL << endl;
	cout << "cantidad de clientes atendidos si se completo el pedido " << cantClientAtenCompl << endl;

	cout << "cantidad de pedidos que se atendieron una parte "
		<< cantClientAtenParcial << endl;

	cout << "cantidad de pedidos incompletos ( dejaron de atenderse)  " << cantipedidoDEJAatende << endl;
	cout << "stock de caja de colores   " << totalCajasColores << endl;
	cout << "stock de papel bond " << totalPapelBondMIllar << endl;
	cout << "unidades vendidas de caja de colores   " << totalCajasColoresVendidas << endl;
	cout << "unidades vendidas de papel bond " << totalPapeBoVent << endl;


}

void moduloSalir(){
		cout << "Gracias por su compra" << endl;
	
}

void menu() {
	do {
		do {
			cout << "Menu Principal" << endl;
			cout << "1 Actualizar" << endl;
			cout << "2 Vender" << endl;
			cout << "3 Reportar" << endl;
			cout << "4 Salir" << endl;
			cout << "Ingrese opción" << endl;
			cin >> opcion;
			if (opcion != 1 && opcion != 2 && opcion != 3 && opcion != 4)
				cout << "No valido" << endl;
		} while (opcion != 1 && opcion != 2 && opcion != 3 && opcion != 4);
		switch (opcion)
		{
		case 1: {
			nuevoIngresoCajaColor = leerInt("Nuevo ingreso de productos caja de colores");
			totalCajasColores = totalCajasColores + nuevoIngresoCajaColor;
			numVeceActualiCajaCol++;

			nuevoIngresoPapelBondMillar = leerInt("Nuevo ingreso de productos papel bon millar");
			totalPapelBondMIllar = totalPapelBondMIllar + nuevoIngresoPapelBondMillar;
			numVeceActualiPapelBonMILL++;
			break;
		}
		case 2: {
			
			ModuloProceso();

			break;
		}
		case 3: {
			moduloMostrar();
			

			break;
		}
		case 4: {
		moduloSalir();
			break;
		}
		}
	} while (opcion != 4);

}
