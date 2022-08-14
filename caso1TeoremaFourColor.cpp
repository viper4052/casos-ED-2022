#include <iostream>
#include <cstdio>
#include <string>

/* si se quiere un mapa cuadrado, ambos deben ser iguales,
*  si no, se modifica a gusto pero se debe modificar el array
*  en el método main() al final del programa
*/
#define Vertices 5
#define VerticesAux 5

using namespace std;

struct region
{
    int color;
};

struct mapa
{
    int regiones[Vertices*VerticesAux];
    struct region colorRegion;
};


// lista de colores a utilizar
int colores[5] = {'a', 'b', 'c', 'd', 'e'};
int coloresPar[2] = {'b', 'c'};
int coloresImpar[2] = {'d', 'e'};

// mapa auxiliar. aqui se almacenarán los colores.
int mapaAux[Vertices*Vertices] = {
        0, 0, 0, 0, 0, 
        0, 0, 0, 0, 0,
        0, 0, 0, 0, 0,
        0, 0, 0, 0, 0};



int imprimeMapaAux(int mapaAux[]){
    for (int i = 0; i < (Vertices*Vertices)-Vertices; i++) 
    {
        cout << mapaAux[i] << " "; // imprime el mapa con unos y ceros
        if ((i + 1) % 5 == 0) { // imprime por linea cada 5 elementos
            cout << endl;
        }
    }
    return 0;
}


// funcion que recorre el array que representa el mapa y define regiones en blanco
int recorreMapa(int nMapa[Vertices*VerticesAux]){
    cout << "Mapa regional: \n";
    for (int i = 0; i < (Vertices*VerticesAux)-Vertices; i++) 
    {
        cout << nMapa[i] << " "; // imprime el mapa con unos y ceros
        if ((i + 1) % 5 == 0) { // imprime por linea cada 5 elementos
            cout << endl;
            }
        if (nMapa[i] == 1){ // encuentra las posiciones de las regiones
            mapaAux[i] = colores[0]; // utiliza valor 'a' como color en blanco para las regiones
            }
    }
    cout << "\n";
    cout << "Mapa de colores: \n";
    imprimeMapaAux(mapaAux);
    return 0;
}


// struct mapa nMapa[] como parámetro de prueba
bool puedeColorearse(int mapaAux[], int indice, int color){ // se fija en los valores de la region e indica si se puede proseguir
    for (int i = 0; i < Vertices; i++)                      // con el color indicado retornando true o false
    {
        if (indice == 0 && mapaAux[indice] != 50)
        {
            return false;
        }
        else if (mapaAux[indice-1] == color || mapaAux[indice-Vertices] == color)
        {
            return false;
        }
        else{
            return true;
        }
    }
    return false;
}


int coloreaMapa(int indice, int color, int mapaAux[], mapa nMapa[]){
    for (int i = indice; i < Vertices; i++) // trabaja la primer fila del mapa
    {
        if (i == 0 && mapaAux[0] == 'a')
        {
            mapaAux[0] = colores[1];
        }
        if (i != 0 && mapaAux[i]=='a')
        {
            if (mapaAux[i-1] == 0)
            {
                mapaAux[i] = colores[1];
            }
            mapaAux[i] = colores[i-1];
            
        } 
    for (int k = 5; k < Vertices*Vertices; k++) // trabaja el resto del mapa
        {   
            if (mapaAux[k] == 'a')
            {
                if ((k%Vertices) == 0 && mapaAux[k-Vertices] == colores[i]) // pregunta por el de arriba a los bordes izquierdos
                {
                    mapaAux[k] = colores[i+1];
                    nMapa[k].colorRegion.color = colores[i+1];
                }

                if (mapaAux[k-1] == colores[i] && k%Vertices!=0) // pregunta por el de la izquierda y arriba
                {    
                    //mapaAux[k] = colores[i+1]; esta es la linea que funcionaba al principio
                    if (k%2 == 0 && puedeColorearse(mapaAux, k, 'b')) // si esta en columna PAR y sirve el primer color
                    {
                        mapaAux[k] = coloresPar[0];
                        nMapa[k].colorRegion.color = coloresPar[0];
                        
                    }
                    else if (k%2 == 0 && puedeColorearse(mapaAux, k, 'c')) // si esta en columna PAR y sirve el segundo color
                    {
                        mapaAux[k] = coloresPar[1];
                        //nMapa[k].colorRegion.color = coloresPar[1];
                    }
                    else if (k%2 != 0 && puedeColorearse(mapaAux, k, 'd')) // si esta en columna IMPAR y sirve el primer color
                    {
                        mapaAux[k] = coloresImpar[0];
                        nMapa[k].colorRegion.color = coloresImpar[0];
                    }
                    else if (k%2 != 0 && puedeColorearse(mapaAux, k, 'e')) // si esta en columna IMPAR y sirve el segundo color
                    {
                        mapaAux[k] = coloresImpar[1];
                        nMapa[k].colorRegion.color = coloresImpar[1];
                    }
                }
                
                
            }
        }
    }
    
    cout << "\n";
    cout << "El mapa coloreado es: \n";
    imprimeMapaAux(mapaAux);
    return 0;
}


// funcion main que permite probar
int main() {

    mapa nMapa = {
    1, 0, 0, 1, 0, 
    1, 1, 1, 1, 1,
    1, 1, 1, 1, 1,
    1, 1, 1, 1, 1
    };

    recorreMapa(nMapa.regiones); // inicializa el mapa
    coloreaMapa(0, 0, mapaAux, &nMapa); // colorea el mapa

    return 0;
}
