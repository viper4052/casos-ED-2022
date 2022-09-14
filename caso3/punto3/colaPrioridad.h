#include "queue.h"

using namespace std;

template <class T>
class ColaPrioridad {
    private:
        Queue<T> queuesByPriority[];
        int maxPriority;

    public:
        FastPriorityQueue(int pMaxPriority) {
            queuesByPriority = Queue<T>[pMaxPriority];
            maxPriority = pMaxPriority;

            for(int i=0; i<pMaxPriority;i++) {
                queuesByPriority[i] = new Queue<T>();
            }
        }

        void enqueue(T* pData, int pPriority) {
            if (pPriority<maxPriority) {
                queuesByPriority[pPriority].enqueue(pData);
            }
        }

        T* dequeue() {
            T* result = NULL;
            
            for(int i=0; i<maxPriority;i++) {
                if (!queuesByPriority[i].isEmpty()) {
                    result = queuesByPriority[i].dequeue();
                    break;
                }
            }

            return result;
        }


};