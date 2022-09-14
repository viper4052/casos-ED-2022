#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class Flight {

    private: 
        time_t flightTime;
        int aerolinea;
        int numeroVuelo;
        int cantidadPasajeros;

        
    public: 
        Flight(int pHour, int pMinutes, int pAerolinea, int pNumVuelo, int pCantPasajeros) {
            flightTime = time(NULL);
            tm *currentTime = localtime(&flightTime);
            aerolinea = pAerolinea;
            numeroVuelo = pNumVuelo;
            cantidadPasajeros = pCantPasajeros;

            currentTime->tm_hour = pHour;    // define la hora del vuelo con el valor del parametro
            currentTime->tm_min = pMinutes;  // define los minutos del vuelo con el valor del parametro

        }

        char* flightTimeString() {
            char* result = ctime(&flightTime);
            return result;
        }

        int getIntTimeValue() {
            char buffer[5];
            int result = 0;

            time (&flightTime);
            strftime(buffer,sizeof(buffer),"%H%M",localtime(&flightTime)); // obtiene como string de 4 digitos la hora en formato HHMM
            string str(buffer);
            result = stoi(str); // convierte el string de HHMM dentro de buffer[5], a integer

            return result;
        }

        void setAerolinea(int pAerolinea){
            aerolinea = pAerolinea;
        }

        int getAerolinea(){
            return aerolinea;
        }

        void setNumVuelo(int pNumVuelo){
            numeroVuelo = pNumVuelo;
        }

        int getNumVuelo(){
            return numeroVuelo;
        }

        void setCantPasajeros(int pCantPasajeros){
            cantidadPasajeros = pCantPasajeros;
        }

        int getCantPasajeros(){
            return cantidadPasajeros;
        }

};
