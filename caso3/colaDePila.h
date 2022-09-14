#include "List.h"
#include "stack.h"

template <class T>
class ColaDePila {
    private:
        Stack<T>* pila1;
        Stack<T>* pila2;
    
    public:
        ColaDePila() {
            pila1 = NULL;
            pila1 = new Stack<T>();

            pila2 = NULL;
            pila2 = new Stack<T>();
        }

        // agregar al final
        void enQueue(T* pElemento){
            while (pila1->isEmpty() == false) // mientras pila1 no esté vacía:
            {
                pila2->push(pila1->top()); // pasa el top de pila1 a pila2
                pila1->pop();            // elimina el top actual de pila1
            }
            pila1->push(pElemento);

            while (pila2->isEmpty() == false) // mientras pila2 no esté vacía:
            {
                pila1->push(pila2->top());
                pila2->pop();
            }
        
        }

        T* deQueue(){  // no lleva argumentos porque hace la funcion de sacar por el "frente" (pila1 es el frente) como una cola normalmente lo haría
            if (pila1->isEmpty())
            {
                cout << "La pila está vacía." << endl;
                return 0; // si pila1 esta vacia, termina retornando 0
            }
            T* cabeza = pila1->top();  // define la "cabeza" de la cola de pilas
            pila1->pop(); // elimina el top de pila1 al haber salido de la "cola"

            return cabeza;
        }

        T* front() {
            T* result = NULL;
            if (!pila1->isEmpty()) {
                result = pila1->find(0);
            }
            return result;
        }

        bool isEmpty() {
            return pila1->isEmpty();
        }
};