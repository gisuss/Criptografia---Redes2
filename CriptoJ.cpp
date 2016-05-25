#include <iostream>
#include <cstring>
#include <cstdlib>
#include <locale.h>
#include <fstream>
#include "color.hpp"

using namespace std;

string genPassword();
string encriptar(string A, string B);
string desencriptar(string A, string B);
string getText();
bool esPrimo(int X);
bool esPar(int X);
bool esPermitido(char p);
int asciival(char c);

int main() {
	string texto, codificado, descrifrado;
	
	setlocale(LC_CTYPE,"es_ES");
	setlocale(LC_ALL,"es_ES");
	
	texto = getText();
	system("reset");
	
	std::cout << endl << endl;
	std::cout << BOLD(FYEL("\t  \x1B[1m\x1B[37m☾\x1B[0m             \x1B[1m\x1B[37m✫\x1B[0m     \x1B[32m|'.\x1B[0m     ")) << endl;
	std::cout << BOLD(FYEL("\t            \x1B[1m\x1B[37m✫\x1B[0m        \x1B[32m|   |\x1B[0m    ")) << endl;
	std::cout << BOLD(FYEL("\t                \x1B[1m\x1B[37m✫\x1B[0m   \x1B[32m|     |\x1B[0m   ")) << endl;
	std::cout << BOLD(FYEL("\t   \x1B[1m\x1B[37m︸\x1B[0m              \x1B[32m|       |\x1B[0m  ")) << endl;
	std::cout << BOLD(FYEL("\t    \x1B[1m\x1B[37m︸\x1B[0m            \x1B[32m|         |\x1B[0m ")) << endl;
	std::cout << BOLD(FYEL("\t                \x1B[0m\x1B[32m,'          |\x1B[0m  ")) << endl;
	std::cout << BOLD(FGRN("\t+-+-+-+-+-+-+-+-+-+-+-+-+-+-+			")) << endl;
	std::cout << BOLD(FGRN("\t|     Mensaje a Encriptar   |			")) << endl;
	std::cout << BOLD(FGRN("\t+-+-+-+-+-+-+-+-+-+-+-+-+-+-+			")) << endl;
	std::cout << texto << endl;
	
	codificado = encriptar(texto,genPassword());
	std::cout << BOLD(FYEL("\t\t    \x1B[0m\x1B[32m.'|\x1B[0m       \x1B[1m\x1B[37m✫\x1B[0m            \x1B[1m\x1B[37m☽\x1B[0m ")) << endl;
	std::cout << BOLD(FYEL("\t\t   \x1B[0m\x1B[32m|   |\x1B[0m         \x1B[1m\x1B[37m✫\x1B[0m           ")) << endl;
	std::cout << BOLD(FYEL("\t\t  \x1B[0m\x1B[32m|     |\x1B[0m     \x1B[1m\x1B[37m✫\x1B[0m              ")) << endl;
	std::cout << BOLD(FYEL("\t\t \x1B[0m\x1B[32m|       |\x1B[0m           \x1B[1m\x1B[37m︸\x1B[0m      ")) << endl;
	std::cout << BOLD(FYEL("\t\t\x1B[0m\x1B[32m|         |\x1B[0m                 ")) << endl;
	std::cout << BOLD(FYEL("\t\t\x1B[0m\x1B[32m|          ',\x1B[0m               ")) << endl;
	std::cout << BOLD(FGRN("\t\t+-+-+-+-+-+-+-+-+-+-+-+-+-+-+")) << endl;
	std::cout << BOLD(FGRN("\t\t|      Mensaje Cifrado      |")) << endl;
	std::cout << BOLD(FGRN("\t\t+-+-+-+-+-+-+-+-+-+-+-+-+-+-+")) << endl;
	std::cout << codificado << endl << endl;
	
	descrifrado = desencriptar(codificado,genPassword());
	std::cout << BOLD(FYEL("\t\t\t \x1B[1m\x1B[37m☾\x1B[0m   \x1B[1m\x1B[37m✫\x1B[0m                \x1B[32m|'.\x1B[0m     ")) << endl;
	std::cout << BOLD(FYEL("\t\t\t        \x1B[1m\x1B[37m✫\x1B[0m            \x1B[32m|   |\x1B[0m    ")) << endl;
	std::cout << BOLD(FYEL("\t\t\t \x1B[1m\x1B[37m✫\x1B[0m          \x1B[1m\x1B[37m︸\x1B[0m      \x1B[32m|     |\x1B[0m   ")) << endl;
	std::cout << BOLD(FYEL("\t\t\t           \x1B[1m\x1B[37m︸\x1B[0m \x1B[1m\x1B[37m︸\x1B[0m   \x1B[32m|       |\x1B[0m  ")) << endl;
	std::cout << BOLD(FYEL("\t\t\t                  \x1B[0m\x1B[32m|         |\x1B[0m ")) << endl;
	std::cout << BOLD(FYEL("\t\t\t                \x1B[0m\x1B[32m,'          |\x1B[0m  ")) << endl;
	std::cout << BOLD(FGRN("\t\t\t+-+-+-+-+-+-+-+-+-+-+-+-+-+-+")) << endl;
	std::cout << BOLD(FGRN("\t\t\t|     Mensaje Descifrado    |")) << endl;
	std::cout << BOLD(FGRN("\t\t\t+-+-+-+-+-+-+-+-+-+-+-+-+-+-+")) << endl;
	std::cout << descrifrado << endl << endl;
	
	return 0;
}

string genPassword() {
	string pass;
	
	pass = "TerjeSorgjerd"; //13
	
	return pass;
}

string getText() {
	char c;
	string textoplano;
	ifstream in("texto.txt", ios::in);

	if (in.fail()) {
		std::cout << FRED("ERROR AL INTENTAR ABRIR EL FICHERO (texto.txt)") << endl << endl;
		exit(1);
	}else{
		while (!in.eof()) {
			in.get(c);
			textoplano += c;
		}
	}
	
	in.close();
	
	return textoplano;
}

string encriptar(string A, string B) {
	int lenA = A.length();
	int lenB = B.length();
	int filas = (((int)(lenA / lenB))); if ((lenA%lenB) != 0) filas += 1; 
	int i=0,j=0,k=0,mayor=0,menor=300,vprimo=0,vnoprimo=0;
	int Primos[lenB], NoPrimos[lenB];
	string tabla[filas][lenB];
	string result;
	bool band = false;
	ofstream out("MensajeCifrado.txt", ios::out | ios::binary | ios::trunc);
	
	/* Vacia el texto en la matriz por filas */
	while (i < filas && (!band)) {
		while ((j < lenB) && (!band)) {
			
			//letra = A[k];
			char y = A[k];
			
			if (esPermitido(y)) tabla[i][j] = A[k];
			else tabla[i][j] = y;
			
			k++;
			j++;
			
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
				tabla[i][k] = "+";
		}
	}	
	
	/* Muestra matriz */
	/*for (i=0 ; i<filas ; i++) {
		for (j=0 ; j<lenB ; j++)
			std::cout << tabla[i][j] << " ";
		cout << endl;
	}*/
	
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
	
	/* Escribe el fichero de salida */
	out << result;
	
	out.close();
	
	return result;
}

string desencriptar(string A, string B) {
	int lenA = A.length();
	int lenB = B.length();
	int filas = ((int)(lenA / lenB));
	int i,j=0,k,mayor=0,menor=300,vprimo=0,vnoprimo=0,cont=0;
	int Primos[lenB], NoPrimos[lenB];
	string tabla[filas][lenB];
	string result;
	ofstream out("MensajeDescifrado.txt", ios::out | ios::binary | ios::trunc);
	
	/* Construyo los arrays Primos y NoPrimos */
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
	
	/* Primero Todas las columnas Primas */
	while (vprimo > 0) {
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
	
	/* Luego Todas las columnas NoPrimas */
	while ((vnoprimo > 0) ){//&& (cont <= lenA)) {
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
	
	/* Limpia result del relleno */
	for (i=0 ; i<lenA ; i++) {
		if (result[i] == '+') result[i] = ' ';
	}
	
	/* Escribe el fichero de salida */
	out << result;
	
	out.close();
	
	return result;
}

bool esPrimo(int X) {
	bool band = false;
	
    if (X == 1 || X == 2) band = true;
    if (X == 0) band = false;
    
    for (int i=2 ; i<X/2 ; i++) {
		if ((X % i) == 0)
			band = false;
    }
  
   return band;
}

bool esPar(int X) {
	bool band;
	
	if (X == 0) band = true;
	else if ((X % 2) == 0) band = true;
	else if ((X % 2) != 0) band = false;
	
	return band;
}

bool esPermitido(char p) {
	int num = static_cast<int>(p);
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

