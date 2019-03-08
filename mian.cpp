#include "Notas.h"
#include <conio.h>
#include <iostream>
using namespace std;
int main()
{
	Notas ejemplo;
	int seleccion = 0;
	do 
	{
		cout << "1. Menu Alumnos \n";
		cout << "2. Menu Materias \n ";
		cout << "3. Menu Notas \n";

		cout << "Seleccione una opcion : ";
		cin >> seleccion;

		switch (seleccion)
		{
		case 1:
			system("cls");

			cout << "1. Insertar Alumnos \n";
			cout << "2. Consultar Alumnos \n";
			cout << "3. Atras \n";

			cin >> seleccion;
			switch (seleccion)
			{
			case 1:
				system("cls");
				ejemplo.insertarAlumnos();
				break;
			case 2:
				system("cls");
				ejemplo.consultarAlumnos();
				break;
			}
			break;
		case 2:
			system("cls");

			cout << "1. Insertar Materia \n";
			cout << "2. Consultar Materias \n";
			cout << "3. Atras \n";

			cin >> seleccion;
			switch (seleccion)
			{
			case 1:
				system("cls");
				ejemplo.insertarMaterias();
				break;
			case 2:
				system("cls");
				ejemplo.consultarMaterias();
				break;
			}
			break;
		case 3:
			system("cls");

			cout << "1. Insertar Notas \n";
			cout << "2. Consultar Notas \n";
			cout << "3. Atras \n";

			cin >> seleccion;
			switch (seleccion)
			{
			case 1:
				system("cls");
				ejemplo.insertarNotas();
				break;
			case 2:
				system("cls");
				ejemplo.consultarNotas();
				break;
			}
			break;
		}
	} while (seleccion != -1);
	_getch();
}
// char * buscarALumno(int);
// char * buscarMateria (int);