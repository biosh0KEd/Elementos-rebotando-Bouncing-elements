// Efraín Girón Romero 15300102
#include "stdafx.h"
#include <iostream>
#include <Windows.h>

using namespace std;

//Función con la que nos posiciónamos en cualquier parte del programa
//Function to move us somewhere in the console.
void gotoxy(int x, int y)
{
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}

class Elemento
{
public:
	//Enteros x, y conrdenadas que el elemento va a tomar
	//Integers x and y are the coordenates of the element.
	//Enteros numx, numy variables que determinan el movimiento del elemento
	//Integers numx and numy are the variables used to determine the element direction
	int x, y, numx, numy;
	Elemento(int a, int b, int c, int d)
	{
		x = a;
		y = b;
		numx = c;
		numy = d;
	}
	//Funcion para que el elemento rebote por la pantalla
	//Bounce function
	void rebotar()
	{
		//Condicionales que determinan el limite que tiene el elemento
		//Determinig conditions of the element's limit 
		if (x >= 78)
		{
			numx = -1;
		}
		if (x <= 0)
		{
			numx = 1;
		}
		if (y >= 24)
		{
			numy = -1;
		}
		if (y <= 0)
		{
			numy = 1;
		}
		//Operaciones que provocan el movimiento
		//Operations that generate the movement
		x = x + numx;
		y = y + numy;
		gotoxy(x, y);
		cout << ":)";
	}
	//Función para borrar el elemento
	//Function to erase the element
	void borrar() {
		gotoxy(x, y);
		cout << "  ";
	}
};

int main()
{
	Elemento Caracter(40, 20, 1, -1), Caracter2(10, 25, 1, 1), Caracter3(5, 30, -1, 1), Caracter4(50, 10, 1, -1), Caracter5(70, 35, -1, 1);
	bool repetir = true;
	while (repetir == true)
	{
		Caracter.rebotar();
		Caracter2.rebotar();
		Caracter3.rebotar();
		Caracter4.rebotar();
		Caracter5.rebotar();
		Sleep(120);
		Caracter.borrar();
		Caracter2.borrar();
		Caracter3.borrar();
		Caracter4.borrar();
		Caracter5.borrar();
	}
	return 0;
}