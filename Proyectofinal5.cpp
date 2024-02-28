#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

struct Libro {
	string title;
	string author;
	string ISBN;
	int publicationYear;
	string genero;
	string editorial;
	string Idioma;
};

struct Usuario {
	int userID;
	string name;
	string lastname;
	string email;
	string estadodecuenta;
};

struct Bibliotecario {
	int employeeID;
	string name;
	string lastname;
	string email;
	string educacion;
};

void randoms(Libro libros[], Usuario usuarios[], Bibliotecario bibliotecarios[], int size) {
	string listaLibros[] = {"Aprende C", "Aprende PHP", "Aprende Linux", "Harry Potter"};
	string listaNombres[] = {"Juan", "Mara", "Pedro", "Tomas"};
	string listaApellidos[] = {"Gomez", "Lopez", "Martinez", "Semizo"};
	string author[] = {"Marcos Alba", "Jose Fernandez", "Lois Lane", "Bruce Wayne"};
	string listaGenero[] = {"Cuento", "Epopeya", "novela", "Fabulas", "Leyendas", "Romances"};
	string listaEditorial[] = {"Los Huerfanos", "Santillana", "La Hoguera", "Iñarandu"};
	string listaIdioma[] = {"Español", "Ingles", "Aleman", "Ruso"};
	string listaEstado[] = {"Activo", "Desactivo", "Moroso","Activo"};
	string listaEducacion[] = {"Primaria", "Secundaria", "Bachillerato", "Universitario", "Profesional"};
	
	srand(time(nullptr));
	
	random_shuffle(listaLibros, listaLibros + 4);
	random_shuffle(listaNombres, listaNombres + 4);
	random_shuffle(listaApellidos, listaApellidos + 4);
	random_shuffle(author, author + 4);
	random_shuffle(listaGenero, listaGenero + 6);
	random_shuffle(listaEditorial, listaEditorial + 4);
	random_shuffle(listaIdioma, listaIdioma + 4);
	random_shuffle(listaEstado, listaEstado + 3);
	random_shuffle(listaEducacion, listaEducacion + 5);
	
	for (int i = 0; i < size; i++) {
		libros[i].title = listaLibros[i];
		libros[i].author = author[i];
		libros[i].ISBN = "ISBN " + to_string(i + 1);
		libros[i].publicationYear = rand() % 23 + 2000;
		libros[i].genero = listaGenero[i];
		libros[i].editorial = listaEditorial[i];
		libros[i].Idioma = listaIdioma[i];
		
		usuarios[i].userID = i + 1;
		usuarios[i].name = listaNombres[i];
		usuarios[i].lastname = listaApellidos[i];
		usuarios[i].email = usuarios[i].name + usuarios[i].lastname + "@example.com";
		usuarios[i].estadodecuenta = listaEstado[i];
		
		bibliotecarios[i].employeeID = i + 1;
		bibliotecarios[i].name = "Bibliotecari@ " + listaNombres[i];
		bibliotecarios[i].lastname = listaApellidos[i];
		bibliotecarios[i].email = bibliotecarios[i].name + bibliotecarios[i].lastname + "@example.com";
		bibliotecarios[i].educacion = listaEducacion[i];
	}
}

void imprimirDatos(Libro* libros, int size) {
	for (int i = 0; i < size; i++) {
		cout << "Libro " << i + 1 << ": " << libros[i].title << ", Autor: " << libros[i].author << ", Codigo: " << libros[i].ISBN << ", Año: " << libros[i].publicationYear << ", Genero: " << libros[i].genero << ", Editorial: " << libros[i].editorial << ", Idioma: " << libros[i].Idioma << endl;
	}
}

void imprimirDatos(Usuario* usuarios, int size) {
	for (int i = 0; i < size; i++) {
		cout << "Usuario " << i + 1 << ", Id : " << usuarios[i].userID << ", Nombre: " << usuarios[i].name << ", Apellido: " << usuarios[i].lastname << ", Correo:  " << usuarios[i].email << ", Estado: " << usuarios[i].estadodecuenta << endl;
	}
}

void imprimirDatos(Bibliotecario* bibliotecarios, int size) {
	for (int i = 0; i < size; i++) {
		cout << "Bibliotecario " << i + 1 << " , EmpleadoId: " << bibliotecarios[i].employeeID << ", " << bibliotecarios[i].name << ", " << bibliotecarios[i].lastname << ", " << bibliotecarios[i].email << ", Educacion : " << bibliotecarios[i].educacion << endl;
	}
}
void listadoLibros(Libro* libros, int size, int index = 0) {
	if (index >= size) {
		return;
	}
	
	cout << "Libro " << index + 1 << ": " << libros[index].title << ", Autor: " << libros[index].author << ", Codigo: " << libros[index].ISBN << ", Año: " << libros[index].publicationYear << ", Genero: " << libros[index].genero << ", Editorial: " << libros[index].editorial << ", Idioma: " << libros[index].Idioma << endl;
	
	listadoLibros(libros, size, index + 1);
}

void listadoUsuarios(Usuario* usuarios, int size, int index = 0) {
	if (index >= size) {
		return;
	}
	
	cout << "Usuario " << index + 1 << ", Id : " << usuarios[index].userID << ", Nombre: " << usuarios[index].name << ", Apellido: " << usuarios[index].lastname << ", Correo:  " << usuarios[index].email << ", Estado: " << usuarios[index].estadodecuenta << endl;
	
	listadoUsuarios(usuarios, size, index + 1);
}

void listadoBibliotecarios(Bibliotecario* bibliotecarios, int size, int index = 0) {
	if (index >= size) {
		return;
	}
	
	cout << "Bibliotecario " << index + 1 << " , EmpleadoId: " << bibliotecarios[index].employeeID << ", " << bibliotecarios[index].name << ", " << bibliotecarios[index].lastname << ", " << bibliotecarios[index].email << ", Educacion : " << bibliotecarios[index].educacion << endl;
	
	listadoBibliotecarios(bibliotecarios, size, index + 1);
}

void buscarLibroPorTitulo(Libro* libros, int size, const string& titulo, int index = 0) {
	if (index >= size) {
		
		return;
	}
	string titulo_lower = titulo;
	transform(titulo_lower.begin(), titulo_lower.end(), titulo_lower.begin(), ::tolower);
	string titulo_libro_lower = libros[index].title;
	transform(titulo_libro_lower.begin(), titulo_libro_lower.end(), titulo_libro_lower.begin(), ::tolower);
	
	if (libros[index].title.rfind(titulo) == 0|| tolower(libros[index].title[0])==tolower(titulo[0])) {
		//cout << "Libros encontrado:" << endl;
		cout << "Titulo: " << libros[index].title << ", Autor: " << libros[index].author << ", Codigo: " << libros[index].ISBN << ", Año: " << libros[index].publicationYear << ", Genero: " << libros[index].genero << ", Editorial: " << libros[index].editorial << ", Idioma: " << libros[index].Idioma << endl;
		
	}
	
	buscarLibroPorTitulo(libros, size, titulo, index + 1);
}

void buscarUsuarioPorNombreApellido(Usuario* usuarios, int size, const string& nombre, const string& apellido,const string& prefijo, int index = 0) {
	if (index >= size) {
		cout << "Usuario con nombre '" << nombre << " " << apellido << "' no encontrado." << endl;
		return;
	}
	string nombreLower = nombre;
	transform(nombreLower.begin(), nombreLower.end(), nombreLower.begin(), ::tolower);
	
	string apellidoLower = apellido;
	transform(apellidoLower.begin(), apellidoLower.end(), apellidoLower.begin(), ::tolower);
	
	// Convertir el nombre y apellido del usuario actual a minúsculas
	string nombreUsuarioLower = usuarios[index].name;
	transform(nombreUsuarioLower.begin(), nombreUsuarioLower.end(), nombreUsuarioLower.begin(), ::tolower);
	
	string apellidoUsuarioLower = usuarios[index].lastname;
	transform(apellidoUsuarioLower.begin(), apellidoUsuarioLower.end(), apellidoUsuarioLower.begin(), ::tolower);
	
	if ((nombreUsuarioLower.find(prefijo) == 0 || apellidoUsuarioLower.find(prefijo) == 0) ||
		(nombreUsuarioLower.find(nombreLower) != string::npos || apellidoUsuarioLower.find(apellidoLower) != string::npos)){
		cout << "Usuario encontrado:" << endl;
		cout << "ID: " << usuarios[index].userID << ", Nombre: " << usuarios[index].name << ", Apellido: " << usuarios[index].lastname << ", Correo: " << usuarios[index].email << ", Estado: " << usuarios[index].estadodecuenta << endl;
	
	}
	
	
	buscarUsuarioPorNombreApellido(usuarios, size, nombre, apellido,prefijo, index + 1);
}

void buscarBibliotecarioPorNombreApellido(Bibliotecario* bibliotecarios, int size, const string& nombre, const string& apellido, int index = 0) {
	if (index >= size) {
		cout << "Bibliotecario con nombre '" << nombre << " " << apellido << "' no encontrado." << endl;
		return;
	}
	
	if (bibliotecarios[index].name == nombre || bibliotecarios[index].lastname == apellido) {
		cout << "Bibliotecario encontrado:" << endl;
		cout << "Empleado ID: " << bibliotecarios[index].employeeID << ", Nombre: " << bibliotecarios[index].name << ", Apellido: " << bibliotecarios[index].lastname << ", Correo: " << bibliotecarios[index].email << ", Educación: " << bibliotecarios[index].educacion << endl;
		return;
	}
	
	buscarBibliotecarioPorNombreApellido(bibliotecarios, size, nombre, apellido, index + 1);
}

void menuPrincipal(Libro* libros, Usuario* usuarios, Bibliotecario* bibliotecarios, int size) {
	bool salir = false;
	
	while (!salir) {
		char opcion;
		cout << "Menu" << endl;
		cout << "1) Llenado de datos" << endl;
		cout << "2) Listados" << endl;
		cout << "3) Busqueda" << endl;
		cout << "0) Salir" << endl;
		cout << "Ingrese una opcion: ";
		cin >> opcion;
		
		switch (opcion) {
		case '1':
			randoms(libros, usuarios, bibliotecarios, size);
			cout << "Datos llenados aleatoriamente." << endl;
			break;
		case '2': {
			char subopcion;
			cout << "Submenu - Listados" << endl;
			cout << "A) Listado de libros" << endl;
			cout << "B) Listado de usuarios" << endl;
			cout << "C) Listado de bibliotecarios" << endl;
			cout << "X) Salir" << endl;
			cout << "Ingrese una opcion: ";
			cin >> subopcion;
			
			switch (subopcion) {
			case 'A':
			case 'a':
				listadoLibros(libros, size);
				break;
			case 'B':
			case 'b':
				listadoUsuarios(usuarios, size);
				break;
			case 'C':
			case 'c':
				listadoBibliotecarios(bibliotecarios, size);
				break;
			case 'X':
			case 'x':
				cout << "Saliendo del submenu..." << endl;
				break;
			default:
				cout << "Opcion invalida. Intente de nuevo." << endl;
			}
			break;
		}
		case '3': {
			char subopcion;
			cout << "Submenu - Busqueda" << endl;
			cout << "A) Busqueda de libro (Titulo)" << endl;
			cout << "B) Busqueda de Usuario (Nombre y Apellido)" << endl;
			cout << "C) Busqueda de Bibliotecario (Nombre y Apellido)" << endl;
			cout << "X) Salir" << endl;
			cout << "Ingrese una opcion: ";
			cin >> subopcion;
			
			switch (subopcion) {
			case 'A':
			case 'a': {
				string titulo;
				cout << "Ingrese el titulo del libro a buscar: ";
				cin.ignore();
				getline(cin, titulo);
				buscarLibroPorTitulo(libros, size, titulo);
				break;
			}
			case 'B':
			case 'b': {
				string nombre, apellido,prefijo;
				cout << "Ingrese el nombre del usuario: ";
				cin.ignore();
				getline(cin, nombre);
				buscarUsuarioPorNombreApellido(usuarios, size, nombre,apellido,prefijo);
				break;
			}
			case 'C':
			case 'c': {
				string nombre, apellido;
				cout << "Ingrese el nombre del bibliotecario: ";
				cin.ignore();
				getline(cin, nombre);
				cout << "Ingrese el apellido del bibliotecario: ";
				getline(cin, apellido);
				buscarBibliotecarioPorNombreApellido(bibliotecarios, size, nombre, apellido);
				break;
			}
			case 'X':
			case 'x':
				cout << "Saliendo del submenu..." << endl;
				break;
			default:
				cout << "Opcion invalida. Intente de nuevo." << endl;
			}
			break;
		}
		case '0':
			salir = true;
			break;
		default:
			cout << "Opcion invalida. Intente de nuevo." << endl;
		}
	}
}

int main() {
	const int SIZE = 4;
	Libro libros[SIZE];
	Usuario usuarios[SIZE];
	Bibliotecario bibliotecarios[SIZE];
	
	menuPrincipal(libros, usuarios, bibliotecarios, SIZE);
	
	return 0;
}

