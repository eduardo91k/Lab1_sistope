#include <stdio.h>
#include <string>
#include <unistd.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <ctype.h>
#include <vector>

using namespace std;


/*
 Funcion leer palabras desde un archivo
 devuelve un arreglo con todas las palabras de un archivo
 */ 
vector <string> leerPalabras(char *nombre){
	
	ifstream archivo;
	archivo.open(nombre, ios::in);
	vector <string> palabras;
	if (archivo.fail() != 0) {
			cerr << "no se ha podido abrir el fichero." << endl;
			cout << "error al abrir el archivo llamado: " << nombre << "- archivo no existe" << endl;	
			//exit(1);
		}
	else {
		while (!archivo.eof()) {
			
			string palabra;
			archivo >> palabra;
			palabras.push_back(palabra);
			
			}
		}
	return palabras;
}

/*
Funcion buscarRepetidos que recibe un arreglo con todas las palabras
y devuelve uno con todas las palabras repetidasde la lista pasada
*/

vector <string> buscarRepetidos (vector <string> lista_palabras){
	vector <string> repetidas;
	for (int i = 0; i < int(lista_palabras.size()); i++){
		for (int j = i+1; j < int(lista_palabras.size()); j++ ){
			if (lista_palabras[i] == lista_palabras[j]){
				bool repet = false;
				for(int k=0; k < int(repetidas.size()); k++){
					if (lista_palabras[i] == repetidas[k]){
						repet = true;
						break;	
					}
				}
				if (repet == false){
					repetidas.push_back(lista_palabras[i]);
					break;
				}
					
			}	
		}
	}
	return repetidas;
}

/*
buscarIntersecciones recibe dos listas de palabras y busca las palabras que se encuentran en ambas
*/
vector <string> buscarIntersecciones (vector <string> lista_palabras1, vector <string> lista_palabras2){
	vector <string> intersecciones;
	for (int i = 0; i < int(lista_palabras1.size()); i++){
		for (int j = 0; j < int(lista_palabras2.size()); j++ ){
			if (lista_palabras1[i] == lista_palabras2[j]){
				bool repet = false;
				for(int k = 0; k < int(intersecciones.size()); k++){
					if (lista_palabras1[i] == intersecciones[k]){
						repet = true;
						break;	
					}
				}
				if (repet == false){
					intersecciones.push_back(lista_palabras1[i]);
					break;
				}
					
			}	
		}
	}
	return intersecciones;
}

/*
 nProcesos verifica la bandera que sea un numero entero y la muestra por pantalla si lo es
 */
void nProcesos(string valor_p) {	
int esEntero = 0;	
	for(int i=0; i < int(valor_p.length()); ++i){
		if ( valor_p[i] <= '9' && valor_p[i] >= '0') {
			//std::cout << valor_p[i] << endl;
			//cout << "p es un numero " << esEntero << endl;	
		}
		else {
			esEntero = esEntero + 1;
			//cout << "error en -p " << esEntero << endl;
		}
	}
	if (esEntero == 0){
		cout << "numero de procesos: "<< valor_p << endl;
	}
	else {
		cout << "error al ingresar la entrada, debe ser numero -> p = " << valor_p << endl;
	}
}
/*
 nHebras verifica la bandera que sea un numero entero y la muestra por pantalla si lo es
*/
void nHebras (string valor_h){
int esEntero = 0;
	for(int i=0; i < int(valor_h.length()); ++i){
		if ( valor_h[i] <= '9' && valor_h[i] >= '0') {
			//std::cout << valor_h[i] << endl;
			//cout << "h es un numero " << esEntero << endl;
		}
		else {
			esEntero = esEntero + 1;
			//cout << "error en -h" << esEntero << endl;
		}
	}	
	if (esEntero == 0){
		cout << "numero de Hebras: " << valor_h << endl;
	}		
	else {
		cout << "error al ingresar la entrada, debe ser numero -> h = " << valor_h << endl;
	}
}

// mostrar tipo de archivo por parametro

void mostrarTipo (char * nombre) {
		FILE *tmp_o;
		char buff[512];
		string comando_o = "file -i ";
		string nombre_archivo_o = nombre;
		comando_o = comando_o + nombre;
		ifstream archivo1_o;
		archivo1_o.open(nombre, ios::in);
		
		if (archivo1_o.fail() != 0) {
			cerr << "no se ha podido abrir el fichero." << endl;
			cerr << "error al abrir el archivo llamado " << nombre << " - archivo no existe" << endl;	
			//exit(1);
		}
		
		else {
			
			if(!(tmp_o = popen(comando_o.c_str(), "r"))){	
				cout << "error al ejecutar system(file)" << endl;
			}
			
			while(fgets(buff, sizeof(buff), tmp_o)!=NULL){
				cout << buff << endl;
			}
			pclose(tmp_o);
			archivo1_o.close();
		}
		
		
		
}

void mostrarPlano(char * nombre){
		string linea;
		ifstream archivo1_O;
		FILE *tmp_O;
		char buff[512];
		int esPlano = 0;
		string comando_O = "file -i ";
		string nombre_archivo_O = nombre;
		comando_O = comando_O + nombre;
		archivo1_O.open(nombre, ios::in);
		
		if (archivo1_O.fail() != 0) {
			cerr << "no se ha podido abrir el fichero." << endl;
			cerr << "error al abrir el archivo llamado: " << nombre << " - archivo no existe" << endl;	
			//exit(1);
			}
		
		else {
			
			if(!(tmp_O = popen(comando_O.c_str(), "r"))){	
				cout << "error al ejecutar system(file)" << endl;
			}
			
			while(fgets(buff, sizeof(buff), tmp_O)!=NULL){

				//cout << buff << endl;
				//cout << "767868768" << endl;
				esPlano = string(buff).find("text/plain");
				if (esPlano > 0){
					//cout << "es texto plano" << endl;
					while(!archivo1_O.eof()){
						getline(archivo1_O,linea);
						cout<<linea;
						if (!archivo1_O.eof()){
							cout<<endl;
						}
					}
				}
			}

			pclose(tmp_O);
			archivo1_O.close();
            
		}	
			
	}


int main (int argc, char **argv){
	int oflag = 0;
    int Oflag = 0;
    int hflag = 0;
    int pflag = 0;
    int sflag = 0;
    int Sflag = 0;
    int fflag = 0;
    int gflag = 0;
    char *ovalue = NULL;
    char *Ovalue = NULL;
    char *hvalue = NULL;
    char *pvalue = NULL;
    char *svalue = NULL;
    char *Svalue = NULL;
    char *fvalue = NULL;
    char *gvalue = NULL; 	
    int c;
       
    opterr = 0;
    
    while ((c = getopt (argc, argv, ":o:O:h:p:s:S:f:g:")) != -1) 
		switch (c){
			case 'o':
				oflag = 1;
				ovalue = optarg;
				break;
			case 'O':
				Oflag = 1;
				Ovalue = optarg;
				break;
			case 'h':
				hflag = 1;
				hvalue = optarg;
				break;
			case 'p':
				pflag = 1;
				pvalue = optarg;
				break;
			case 's':
				sflag = 1;
				svalue = optarg;
				break;
			case 'S':
				Sflag = 1;
				Svalue = optarg;
				break;
			case 'f':
				fflag = 1;
				fvalue = optarg;
				break;
			case 'g':
				gflag = 1;
				gvalue = optarg;
				break;
			case '?':
				if (optopt == 'c')
					fprintf (stderr, "Option -%c requires an argument.\n", optopt);
				else if (isprint (optopt))
					fprintf (stderr, "Unknown option `-%c'.\n", optopt);
				else
					fprintf (stderr,"Unknown option character `\\x%x'.\n",optopt);
				return 1;
			default:
				abort ();
           }
     
	if (pflag == 1 && hflag ==1) {
	
		//bandera -o 
		if (oflag == 1){
			mostrarTipo (ovalue); 
		}
		// bandera -O
		if (Oflag == 1){
			mostrarPlano(Ovalue);
		}
		// bandera -h
		/*
		se pasa el valor de la bandera h a un string para poder analizar cada char
		*/
		if (hflag == 1){
			std::string hString(hvalue);
			nHebras(hString);
		}
		// bandera -p
		/*
		se pasa el valor de la bandera p a un string para poder analizar cada char
		*/
		if (pflag == 1){
			std::string pString(pvalue);
			nProcesos(pString);
		}
		
		// bandera -f
		if (fflag == 1 && gflag == 0){
			vector <string> palabra_f = leerPalabras(fvalue);
			vector <string> repetidas_f = buscarRepetidos(palabra_f);	
			for (int i = 0; i < int(repetidas_f.size()); i++) {
				cout << repetidas_f[i] << endl;
			}
		}
		// bandera -f -g
		if (gflag == 1 && fflag ==1){
			vector <string> palabra_f = leerPalabras(fvalue);
			vector <string> palabra_g = leerPalabras(gvalue);
			vector <string> interseccion = buscarIntersecciones(palabra_f, palabra_g);	
			for (int i = 0; i < int(interseccion.size()); i++) {
				cout << interseccion[i] << endl;
			}
		}
		
		// bandera -s = 0, -S = 0 ---> solo se muestra por pantalla
		if (sflag == 0 && Sflag ==0){
		}
		// bandera -s = 1, -S = 0 ---> por pantalla y por archivo de salida
		if (sflag == 1 && Sflag ==0){	
		}
		// bandera -s = 0, -S = 1 ---> solo por archivo de salida
		if ((sflag == 0 && Sflag == 1) || (sflag == 1 && Sflag == 1) ){	
		}
		
		if (sflag == 1 && Sflag == 1){
		}
	}
	else {
		cerr << "banderas p y h	son obligatorias" << endl;
	}
	
}	
	

	
	
	     /*
	printf ("oflag = %d ---> ovalue = %s \n", oflag, ovalue);
	printf ("Oflag = %d ---> Ovalue = %s \n", Oflag, Ovalue);
	printf ("hflag = %d ---> hvalue = %s \n", hflag, hvalue);
	printf ("pflag = %d ---> pvalue = %s \n", pflag, pvalue);
	printf ("sflag = %d ---> svalue = %s \n", sflag, svalue);
	printf ("Sflag = %d ---> Svalue = %s \n", Sflag, Svalue);
	printf ("fflag = %d ---> fvalue = %s \n", fflag, fvalue);
	printf ("gflag = %d ---> gvalue = %s \n", gflag, gvalue);
	printf ("\n");
	*/
