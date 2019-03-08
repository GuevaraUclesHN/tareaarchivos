#include "Notas.h"
#include <fstream>
#include <iostream>
using namespace std;
void Notas::insertarAlumnos()
{
	ofstream fileAlumnos("alumnos.dat", ios::app);

	if (!fileAlumnos)
	{
		cout << "Error de apertura en archivo" << endl;
		return;
	}

	int codigo, edad, cantidad;
	char nombre[30];

	cout << "Indique cantidad de alumnos a ingresar: ";
	cin >> cantidad;

	for (int i = 0; i < cantidad; i++)
	{
		cout << "Ingrese numero de Cuenta: ";
		cin >> codigo;
		cout << "Ingrese nombre de alumno: ";
		cin >> nombre;
		cout << "Ingrese Edad: ";
		cin >> edad;

		fileAlumnos << codigo << " " << nombre << " " << edad << "\n";
			
	}

	fileAlumnos.close();
}

void Notas::consultarAlumnos()
{
	ifstream fileAlumnos("alumnos.dat", ios::in);
	
	if (!fileAlumnos)
	{
		cout << "Error de lectura en archivo!" << endl;
		return;
	}

	int codigo, edad;
	char nombre[30];

	while (fileAlumnos>>codigo>> nombre >>edad)
	{
		cout << "codigo: " << codigo << " nombre: " << nombre << " edad: " << edad << "\n";

	}
	fileAlumnos.close();
}

void Notas::insertarMaterias()
{
	ofstream fileMaterias("materias.dat", ios::app);

	if (!fileMaterias)
	{
		cout << "Error de apertura en archivo" << endl;
		return;
	}

	int codigo, cantidad;
	char nombre[30];

	cout << "Indique cantidad de alumnos a ingresar: ";
	cin >> cantidad;

	for (int i = 0; i < cantidad; i++)
	{
		cout << "Ingrese el codigo de la materia: ";
		cin >> codigo;
		cout << "Ingrese nombre de la materia: ";
		cin >> nombre;
		

		fileMaterias << codigo << " " << nombre << "\n";

	}

	fileMaterias.close();
}

void Notas::consultarMaterias()
{

	ifstream fileMaterias("materias.dat", ios::in);

	if (!fileMaterias)
	{
		cout << "Error de lectura en archivo!" << endl;
		return;
	}

	int codigo;
	char nombre[30];

	while (fileMaterias >> codigo >> nombre)
	{
		cout << "codigo: " << codigo << " nombre: " << nombre << "\n";

	}
	fileMaterias.close();
}

int Notas::buscarAlumno(char * _nombre)
{
	ifstream fileAlumno("alumnos.dat", ios::in);
	if (!fileAlumno)
	{
		cout << "Error de apertura en el archivo";
		return -1;
	}
	int codigoA;
	char nombreA[30];
	int edadA;

	while (fileAlumno >>codigoA>>nombreA>>edadA )
	{
		if (strcmp(nombreA,_nombre)==0)
		{
			fileAlumno.close();
			return codigoA;
		}
	}
	
	fileAlumno.close();
	return -1;
}

int Notas::buscarMateria(char * _materia)
{
	ifstream fileMateria("materias.dat", ios::in);

	if (!fileMateria)
	{
		cout << "Error de apertura en archivo!" << endl;
		return -1;
	}
	int codigoM;
	char  nombreM[30];

	while (fileMateria >> codigoM >> nombreM)
	{
		if (strcmp(nombreM, _materia) == 0)
		{
			fileMateria.close();
			return codigoM;
		}
	}
	fileMateria.close();
	return -1;
}

void Notas::insertarNotas()
{
	ofstream fileNotas("notas.dat", ios::app);
	if (!fileNotas)
	{
		cout << "Error en la apertura !";
		return;
	}
	int cantidad;
	char nombreA[30];
	char nombreM[30];
	float nota;
	cout << "Determine cantidad de notas a ingresar: ";
	cin >> cantidad;

	for (int i = 0; i < cantidad ; i++)
	{
		int codigoA, codigoM;
		do {
			cout << "Ingrese nombre de Alumno: ";
			cin >> nombreA;
			 codigoA = buscarAlumno(nombreA);

		} while (codigoA == -1);
		do 
		{
			cout << "Ingrese nombre de materia";
			cin >> nombreM;
			codigoM = buscarMateria(nombreM);
		} while (codigoM == -1);

		cout << "Ingrese nota: ";
		cin >> nota;

		fileNotas << codigoA << " " << codigoM << " " << nota << "\n";
	}
	fileNotas.close();
}

void Notas::consultarNotas()
{
	ifstream fileMaterias("notas.dat", ios::in);

	if (!fileMaterias)
	{
		cout << "Error de lectura en archivo!" << endl;
		return;
	}

	char nombreA[30];
	char nombreM[30];
	float nota;

	while (fileMaterias >> nombreA >> nombreM>>nota)
	{
		cout << "Nombre del alumno: " << nombreA << " Nombre de la materia: " << nombreM <<" Nota: "<< nota<< "\n";

	}
	fileMaterias.close();
}