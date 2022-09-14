#include "stack.h"
#include "colaDePila.h"
#include <iostream>
#include <string>

using namespace std;

/*  PUNTO 1  */
int precedencia(char &caracter){             // define la precedencia (o importancia) del caracter dado
    if(caracter == '+' || caracter =='-')
        return 1;
    if(caracter == '*' || caracter =='/')
        return 2;
    if(caracter == '^')
        return 3;
    
    return 0;
}


string conversor(string pHilera)
{
    int indice = 0;
    string resultadoPostfijo = "";
    
    Stack<char>* pilaOperaciones = new Stack<char>() ; // instancia una pila para guardar elementos char
    while(pHilera[indice]!='\0') // mientras el caracter no sea nulo:
    {
       if(pHilera[indice]>='a' && pHilera[indice]<='z'|| pHilera[indice]>='A'&& pHilera[indice]<='Z') // si encuentra un operando (en este caso, caracteres) los concatena al string postfijo
       {
            resultadoPostfijo += pHilera[indice]; 
            indice++; 
       } 
        // si encuentra parentesis de abertura, haga pop de lo de adentro
        else if(pHilera[indice]=='(') {
           pilaOperaciones->push(&pHilera[indice]);
           indice++; 
           
       } 
    // hace pop hasta que encuentre el parentesis de cierre,
    // y si no, concatena al string postFijo
    else if(pHilera[indice]==')') { 
        while(*pilaOperaciones->top()!='(')
            resultadoPostfijo += *pilaOperaciones->pop(); 
        pilaOperaciones->pop(); 
        indice++;
        } 
    else { 
        while (!pilaOperaciones->isEmpty() && precedencia(pHilera[indice]) <= precedencia(*pilaOperaciones->top())){
            resultadoPostfijo += pilaOperaciones->pop();
        } 
        pilaOperaciones->push(&pHilera[indice]);
        indice++;
    }
    } 
    while(!pilaOperaciones->isEmpty()){
        resultadoPostfijo += *pilaOperaciones->pop();
        }
    cout << "Infijo es: " << pHilera << endl;
    cout << "Postfijo es : " << resultadoPostfijo; 
    return resultadoPostfijo;
    
} 

/*  PUNTO 2  */
// revisar colaConPila.h ademas de lo que esta escrito en main con respecto a PUNTO 2



int main()
{
    // Ejercicio 1
    string hilera1 = "(A+C)*B";            // primera operacion de ejemplo
    string hilera2 = "(C+c)*(A+B)";        // segunda operacion de ejemplo
    string hilera3 = "(H+K)+(H^E)*B";      // tercera operacion de ejemplo

    conversor(hilera1); // funciona con hileras de chars letras

    // Ejercicio 2
    // ColaDePila<int>* nCola; // = new colaDePila<int>();

    // int *nuevoElemento = (int*)2;
    // int *nuevoElemento2 = (int*)3;
    // int *nuevoElemento3 = (int*)5;

    // nCola->enQueue(nuevoElemento);
    // nCola->enQueue(nuevoElemento2);
    // nCola->deQueue();
    
    return 0;
};