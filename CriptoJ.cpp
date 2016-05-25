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
bool esEnie(char p);
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
	std::cout << texto << endl << endl;
	
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
	
	pass = "Terj3Sorgjerñ";
	
	return pass;
}

string getText() {
	char c;
	bool band = true;
	string textoplano;
	ifstream in("texto.txt", ios::in);

	if (in.fail()) {
		std::cout << FRED("ERROR AL INTENTAR ABRIR EL FICHERO (texto.txt)") << endl << endl;
		exit(1);
	}else{
		while (!in.eof() && band) {
			in.get(c);
			if (c != '\n') textoplano += c;
			else band = false;
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
	char y;
	ofstream out("MensajeCifrado.txt", ios::out | ios::binary | ios::trunc);
	
	/* Vacia el texto en la matriz por filas */
	while (i < filas && (!band)) {
		while ((j < lenB) && (!band)) {
			y = A[k];
			
			if (!(esEnie(y))) tabla[i][j] = A[k];
			else tabla[i][j] = y;
			
			k++;
			j++;
			
			if (k > lenA)
				band = true;
		}
		
		if (j == lenB) {
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
	
	/* Construyo los arrays Primos y NoPrimos */
	for (i=0 ; i<lenB ; i++) {
		k = asciival(B[i]);
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
		k = asciival(B[i]);
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
	while (vnoprimo > 0) {
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

bool esEnie(char p) {
	int num = asciival(p);
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
	int valascii;
	
	switch (c) {
		case ' ': 
			valascii = 32;
		break;
		case 'a': 
			valascii = 97;
		break;
		case 'b': 
			valascii = 98;
		break;
		case 'c': 
			valascii = 99;
		break;
		case 'd': 
			valascii = 100;
		break;
		case 'e': 
			valascii = 101;
		break;
		case 'f': 
			valascii = 102;
		break;
		case 'g': 
			valascii = 103;
		break;
		case 'h': 
			valascii = 104;
		break;
		case 'i': 
			valascii = 105;
		break;
		case 'j': 
			valascii = 106;
		break;
		case 'k': 
			valascii = 107;
		break;
		case 'l': 
			valascii = 108;
		break;
		case 'm': 
			valascii = 109;
		break;
		case 'n': 
			valascii = 110;
		break;
		case 'o': 
			valascii = 111;
		break;
		case 'p': 
			valascii = 112;
		break;
		case 'q': 
			valascii = 113;
		break;
		case 'r': 
			valascii = 114;
		break;
		case 's': 
			valascii = 115;
		break;
		case 't': 
			valascii = 116;
		break;
		case 'u': 
			valascii = 117;
		break;
		case 'v': 
			valascii = 118;
		break;
		case 'w': 
			valascii = 119;
		break;
		case 'x': 
			valascii = 120;
		break;
		case 'y': 
			valascii = 121;
		break;
		case 'z': 
			valascii = 122;
		break;
		case 'A': 
			valascii = 65;
		break;
		case 'B': 
			valascii = 66;
		break;
		case 'C': 
			valascii = 67;
		break;
		case 'D': 
			valascii = 68;
		break;
		case 'E': 
			valascii = 69;
		break;
		case 'F': 
			valascii = 70;
		break;
		case 'G': 
			valascii = 71;
		break;
		case 'H': 
			valascii = 72;
		break;
		case 'I': 
			valascii = 73;
		break;
		case 'J': 
			valascii = 74;
		break;
		case 'K': 
			valascii = 75;
		break;
		case 'L': 
			valascii = 76;
		break;
		case 'M': 
			valascii = 77;
		break;
		case 'N': 
			valascii = 78;
		break;
		case 'O': 
			valascii = 79;
		break;
		case 'P': 
			valascii = 80;
		break;
		case 'Q': 
			valascii = 81;
		break;
		case 'R': 
			valascii = 82;
		break;
		case 'S': 
			valascii = 83;
		break;
		case 'T': 
			valascii = 84;
		break;
		case 'U': 
			valascii = 85;
		break;
		case 'V': 
			valascii = 86;
		break;
		case 'W': 
			valascii = 87;
		break;
		case 'X': 
			valascii = 88;
		break;
		case 'Y': 
			valascii = 89;
		break;
		case 'Z': 
			valascii = 90;
		break;
		case '.': 
			valascii = 46;
		break;
		case ',': 
			valascii = 44;
		break;
		case '0': 
			valascii = 48;
		break;
		case '1': 
			valascii = 49;
		break;
		case '2': 
			valascii = 50;
		break;
		case '3': 
			valascii = 51;
		break;
		case '4': 
			valascii = 52;
		break;
		case '5': 
			valascii = 53;
		break;
		case '6': 
			valascii = 54;
		break;
		case '7': 
			valascii = 55;
		break;
		case '8': 
			valascii = 56;
		break;
		case '9': 
			valascii = 57;
		break;
		
		default:
			valascii = 164;
		break;
	}
	
	return valascii;
}
