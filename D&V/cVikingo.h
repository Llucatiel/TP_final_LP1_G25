#pragma once
#include <string>
#include <ctime>
#include <cstdlib>
#include<iostream>
using namespace std;

class cVikingo
{
	static int comida;
	static int cantVikingos;


	string nombre;
	string apellido;
	struct tm fechadeNacimiento = { 0 };
	string altura;
	string peso;
	string trabajo;
	int dragones_terminados;
	

public:
	cVikingo(string nombre, string apellido, int d, int m, int a, string altura, string peso, string trabajo, int dragones_terminados);
	//bool trabajar();
	friend static void atacarDragones(int cantidadeVikingos);
	//bool dragonesMatados();
	string getNombre() { return nombre; }
	string getApellido() { return apellido; }
	int getEdad();

	static int getComida() { return comida; }
	static void cambioComida(int suma);
};