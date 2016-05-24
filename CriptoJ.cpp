#include <iostream>
#include <cstring>
#include <stdio.h>
#include <cstdlib>
#include <clocale>
#include "color.hpp"

using namespace std;

string genPassword();
string encriptar(string A, string B);
string desencriptar(string A, string B);
bool esPrimo(int X);
bool esPar(int X);
bool esPermitido(char p[]);
int asciival(char c);

int main() {
	string texto, codificado, descrifrado;
	
	setlocale(LC_CTYPE,"es_ES");
	setlocale(LC_ALL,"es_ES");
	
	std::cout << BOLD(FYEL("\t+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+")) << endl;
	std::cout << BOLD(FYEL("\t| Introduzca El texto a cifrar  |")) << endl;
	std::cout << BOLD(FYEL("\t+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+")) << endl;
	std::getline(std::cin,texto);
	system("reset");
	
	std::cout << BOLD(FYEL("\t+-+-+-+-+-+-+-+-+-+-+-+-+-+-+")) << endl;
	std::cout << BOLD(FYEL("\t|     Mensaje a Encriptar   |")) << endl;
	std::cout << BOLD(FYEL("\t+-+-+-+-+-+-+-+-+-+-+-+-+-+-+")) << endl;
	std::cout << texto << endl << endl;
	
	codificado = encriptar(texto,genPassword());
	std::cout << BOLD(FYEL("\t+-+-+-+-+-+-+-+-+-+-+-+-+-+-+")) << endl;
	std::cout << BOLD(FYEL("\t|     Mensaje Encriptado    |")) << endl;
	std::cout << BOLD(FYEL("\t+-+-+-+-+-+-+-+-+-+-+-+-+-+-+")) << endl;
	std::cout << codificado << endl << endl;
	
	descrifrado = desencriptar(codificado,genPassword());
	std::cout << BOLD(FYEL("\t+-+-+-+-+-+-+-+-+-+-+-+-+-+-+")) << endl;
	std::cout << BOLD(FYEL("\t|     Mensaje Descifrado    |")) << endl;
	std::cout << BOLD(FYEL("\t+-+-+-+-+-+-+-+-+-+-+-+-+-+-+")) << endl;
	std::cout << descrifrado << endl << endl;
	
	return 0;
}

string genPassword() {
	string pass;
	
	pass = "TerjeSorgjerd"; //13
	
	return pass;
}

string encriptar(string A, string B) {
	int lenA = A.length();
	int lenB = B.length();
	int filas = (((int)(lenA / lenB))); if ((lenA%lenB) != 0) filas += 1; 
	int i=0,j=0,k=0,mayor=0,menor=300,vprimo=0,vnoprimo=0;
	int Primos[13], NoPrimos[13];
	string tabla[filas][lenB];
	string enie ("ñ");
	string result;
	string letra;
	bool band = false;
	
	/* Vacia el texto en la matriz por filas */
	while (i < filas && (!band)) {
		while ((j < lenB) && (!band)) {
			
			letra = A[k];
			char *y = new char[letra.length()];
			std::strcpy(y,letra.c_str());
			
			if (esPermitido(y)) tabla[i][j] = A[k];
			else tabla[i][j] = enie;
			
			k++;
			j++;
			delete[] y;
			
			if (k >= lenA)
				band = true;
		}
		
		if (j == lenB && (!band)) {
			i++;
			j=0;
		}
	}
	
	/* Relleno ultima fila */
	if (band) {
		if (j != 0) {
			for (k=j ; k<lenB ; k++)
				tabla[i][k] = " ";
		}
	}
	
	/* Hace poco mas de 30 años me vine de Austria hacia USA con el sueño de, */
	/* Hace mas de 3 decadas me vine a los Estados Unidos trayendo en mi maleta. */	
	
	/* Muestra matriz */
	/*for (i=0 ; i<filas ; i++) {
		for (j=0 ; j<lenB ; j++) {
			letra = tabla[i][j];
			std::cout << letra << " ";
		}
		cout << endl;
	}*/
	
	std::cout << endl << "lenA:: " << lenA << endl;
	std::cout << "clave:: " << B << endl;
	std::cout << "Filas:: " << filas << endl << endl;
	
	/* Construyo los arrays Primo y NoPrimo */
	for (i=0 ; i<lenB ; i++) {
		k = static_cast<int>(B[i]);
		if (esPrimo(k)) {
			Primos[i] = k;
			NoPrimos[i] = -1;
			vprimo += k;
		}else{
			Primos[i] = -1;
			NoPrimos[i] = k;
			vnoprimo += k;
		}
	}
	
	/* [REGLA 1] : Tomare primero las columnas primas, de mayor a menor
	 * luego seleccionare las filas pares, luego las impares (de esa misma 
	 * columna) pero de abajo hacia arriba. */
	while (vprimo > 0) {
		j=0;
		for (i=0 ; i<lenB ; i++) {
			if ((Primos[i] != -1) && (Primos[i] > mayor)) {
				mayor = Primos[i];
				j=i;
			}
		}
		
		/* filas pares de abajo hacia arriba */
		for (i=filas-1 ; i>=0 ; i--) {
			if (esPar(i))
				result += tabla[i][j];
		}
		
		/* filas impares de abajo hacia arriba */
		for (i=filas-1 ; i>=0 ; i--) {
			if (!(esPar(i)))
				result += tabla[i][j];
		}
		
		vprimo -= mayor;
		Primos[j] = -1;
		mayor = 0;
	}
	
	/* [REGLA 2] : Tomare las columnas no primas, de menor a mayor
	 * luego seleccionare las filas impares, luego las pares (de esa 
	 * misma columna) pero de arriba hacia abajo. */
	while (vnoprimo > 0) {
		j=0;
		for (i=0 ; i<lenB ; i++) {
			if ((NoPrimos[i] != -1) && (NoPrimos[i] < menor)) {
				menor = NoPrimos[i];
				j=i;
			}
		}
		
		/* filas impares de arriba hacia abajo */
		for (i=0 ; i<filas ; i++) {
			if (!(esPar(i)))
				result += tabla[i][j];
		}
		
		/* filas pares de arriba hacia abajo */
		for (i=0 ; i<filas ; i++) {
			if (esPar(i))
				result += tabla[i][j];
		}
		
		vnoprimo -= menor;
		NoPrimos[j] = -1;
		menor = 300;
	}
	
	return result;
}

string desencriptar(string A, string B) {
	int lenA = A.length();
	int lenB = B.length();
	int filas = (((int)(lenA / lenB)));
	int i,j,k,mayor=0,menor=300,vprimo=0,vnoprimo=0,cont;
	int Primos[13], NoPrimos[13];
	string tabla[filas][lenB];
	string result;
	string letra;
	
	std::cout << endl << "lenA:: " << lenA << endl;
	std::cout << "clave:: " << B << endl;
	std::cout << "Filas:: " << filas << endl << endl;
	
	/* Construyo los arrays Primo y NoPrimo */
	for (i=0 ; i<lenB ; i++) {
		k = static_cast<int>(B[i]);
		if (esPrimo(k)) {
			Primos[i] = k;
			NoPrimos[i] = -1;
			vprimo += k;
		}else{
			Primos[i] = -1;
			NoPrimos[i] = k;
			vnoprimo += k;
		}
	}
	
	/* Proceso inverso para crear la tabla */
	cont=0;
	while (vprimo > 0) {
		j=0;
		for (i=0 ; i<lenB ; i++) {
			if ((Primos[i] != -1) && (Primos[i] > mayor)) {
				mayor = Primos[i];
				j=i;
			}
		}
		
		/* filas pares de abajo hacia arriba */
		for (i=filas-1 ; i>=0 ; i--) {
			if (esPar(i)) {
				tabla[i][j] = A[cont];
				cont += 1;
			}
		}
		
		/* filas impares de abajo hacia arriba */
		for (i=filas-1 ; i>=0 ; i--) {
			if (!(esPar(i))) {
				tabla[i][j] = A[cont];
				cont += 1;
			}
		}
		
		vprimo -= mayor;
		Primos[j] = -1;
		mayor = 0;
	}
	
	while (vnoprimo > 0) {
		j=0;
		for (i=0 ; i<lenB ; i++) {
			if ((NoPrimos[i] != -1) && (NoPrimos[i] < menor)) {
				menor = NoPrimos[i];
				j=i;
			}
		}
		
		/* filas impares de arriba hacia abajo */
		for (i=0 ; i<filas ; i++) {
			if (!(esPar(i))) {
				tabla[i][j] = A[cont];
				cont += 1;
			}
		}
		
		/* filas pares de arriba hacia abajo */
		for (i=0 ; i<filas ; i++) {
			if (esPar(i)) {
				tabla[i][j] = A[cont];
				cont += 1;
			}
		}
		
		vnoprimo -= menor;
		NoPrimos[j] = -1;
		menor = 300;
	}
	
	/* Armar el mensaje desencriptado */
	for (i=0 ; i<filas ; i++) {
		for (j=0 ; j<lenB ; j++) {
			result += tabla[i][j];
		}
	}
	
	return result;
}

bool esPrimo(int X) {
    if (X == 1 || X == 2) return true;
    if (X == 0) return false;
    
    for (int i=2 ; i<X/2 ; i++) {
		if ((X % i) == 0)
			return false;
    }
  
   return true;
}

bool esPar(int X) {
	bool band;
	
	if (X == 0) band = true;
	if ((X % 2) == 0) band = true;
	else if ((X % 2) != 0) band = false;
	
	return band;
}

bool esPermitido(char p[]) {
	int num = static_cast<int>(p[0]);
	bool band = false;
	
	if ((num >= 65) && (num <= 90)) band = true;
	else if ((num >= 97) && (num <= 122)) band = true;
	else if ((num >= 48) && (num <= 57)) band = true;
	else if ((num == 32)) band = true;
	else if ((num == 46)) band = true;
	else if ((num == 44)) band = true;
	
	return band;
}

int asciival(char c) {
	return static_cast<int>(c);
}
