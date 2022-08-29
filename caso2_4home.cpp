#include <list>
#include <string>
#include <iostream>

using namespace std;


enum TipoDisp {  // enums literales para identificar dispositivos
	bombillo=0,       
	coffee_maker=1,   
	sensorPuertas=2,
    sensorHumo=3,
    parlante=4
};

struct Parametro
{
    string Llave;
    string Valor;
};

struct Accion{
	string Nombre;
	Parametro params[3]; // PLACEHOLDER
};


struct AccionesPorTipo {
	TipoDisp type;
	list<Accion> actions;
};


typedef struct TDispositivo{ // struct que define como debe ser un dispositivo

    string Nombre;
    TipoDisp Tipo;
    int Cuarto;

    AccionesPorTipo ListaAcciones;
    //list<Parametro> ListaParametros;
    
    TDispositivo* SiguienteDispositivo; 

}*PtrTDispositivo; // genera un pointer de Tipo Dispositivo para la lista

typedef struct Tarea // struct que define que aspectos debe contener una tarea
{
	string NombreTarea;					
	list<PtrTDispositivo> AccionesAEjecutar;

	Tarea* SiguienteTarea;

}*PtrTareas;

PtrTDispositivo ListaDispositivos; // lista enlazada global de dispositivos
PtrTareas ListaTareas; // lista global de tareas

// ================================ METODOS ==========================================


AccionesPorTipo retornaAccionesPorDisp(TipoDisp pTipo){
    list<Accion> nListaAcc; 
    list<Parametro> nListaParam;

    AccionesPorTipo var; // del struct acciones por tipo

    Accion acc1, acc2, acc3;          // maximo van a existir 3 acciones por dispositivo
    Parametro param1, param2, param3; // hay 3 parametros maximos para cada accion
    if (pTipo == 0) // si es tipo bombillo
    {
        acc1.Nombre = "encender";
        acc1.params->Llave = "estado_encendido";
        acc1.params->Valor = "apagado";
        nListaAcc.push_back(acc1);
        nListaParam.push_back(param1);

        acc2.Nombre = "cambiar_color";
        acc2.params->Llave = "color";
        acc2.params->Valor = "blanco";
        nListaAcc.push_back(acc2);
        nListaParam.push_back(param2);

        acc3.Nombre = "cambiar_brillo";
        acc3.params->Llave = "brillo";
        acc3.params->Valor = "40";
        nListaAcc.push_back(acc3);
        nListaParam.push_back(param3);

        
        var.type = bombillo;
        var.actions = nListaAcc;

        
    }

    else if (pTipo == 1) // si es tipo coffeemaker
    {
        acc1.Nombre = "encender";
        acc1.params->Llave = "estado_encendido";
        acc1.params->Valor = "apagado";
        nListaAcc.push_back(acc1);
        nListaParam.push_back(param1);

        acc2.Nombre = "elegir_sabor";
        acc2.params->Llave = "sabor";
        acc2.params->Valor = "3";
        nListaAcc.push_back(acc2);
        nListaParam.push_back(param2);

        var.type = coffee_maker;
        var.actions = nListaAcc;
    }

    else if (pTipo == 2) // si es tipo sensor de puertas
    {
        acc1.Nombre = "armar";
        acc1.params->Llave = "estado";
        acc1.params->Valor = "desarmado";
        nListaAcc.push_back(acc1);
        nListaParam.push_back(param1);

        acc2.Nombre = "activar";
        acc2.params->Llave = "se_activo";
        acc2.params->Valor = "falso";
        nListaAcc.push_back(acc2);
        nListaParam.push_back(param2);

        acc3.Nombre = "enviar_notificacion";
        acc3.params->Llave = "notifica";
        acc3.params->Valor = "falso";
        nListaAcc.push_back(acc3);
        nListaParam.push_back(param3);

        var.type = sensorPuertas;
        var.actions = nListaAcc;
    }

    else if (pTipo == 3) // si es sensor humo
    {
        acc1.Nombre = "armar";
        acc1.params->Llave = "estado";
        acc1.params->Valor = "desarmado";
        nListaAcc.push_back(acc1);
        nListaParam.push_back(param1);

        acc2.Nombre = "activar";
        acc2.params->Llave = "se_activo";
        acc2.params->Valor = "falso";
        nListaAcc.push_back(acc2);
        nListaParam.push_back(param2);

        acc3.Nombre = "ajusta_sens";
        acc3.params->Llave = "sensibilidad";
        acc3.params->Valor = "4";
        nListaAcc.push_back(acc3);
        nListaParam.push_back(param3);

        var.type = sensorHumo;
        var.actions = nListaAcc;
    }

    else if (pTipo == 4) // si es parlante
    {
        acc1.Nombre = "encender";
        acc1.params->Llave = "estado_encendido";
        acc1.params->Valor = "apagado";
        nListaAcc.push_back(acc1);
        nListaParam.push_back(param1);

        acc2.Nombre = "ajusta_vol";
        acc2.params->Llave = "volumen"; 
        acc2.params->Valor = "20";
        nListaAcc.push_back(acc2);
        nListaParam.push_back(param2);

        var.type = parlante;
        var.actions = nListaAcc;
        return var;
    
    }

    return var;
};


PtrTDispositivo creaDispositivo(string pNombre, TipoDisp pTipo, int pCuarto){

    PtrTDispositivo nDispositivo = new(TDispositivo);
    nDispositivo->Nombre = pNombre;
    nDispositivo->Tipo = pTipo;
    nDispositivo->Cuarto = pCuarto;

    nDispositivo->ListaAcciones = retornaAccionesPorDisp(pTipo);    

    nDispositivo->SiguienteDispositivo = NULL; // define un nuevo espacio siguiente como nulo

    return nDispositivo;

};


void AgregarAListasDispositivos(PtrTDispositivo &ListaDispositivos, PtrTDispositivo& Nuevo) // crea un punto de inicio en la lista para comenzar a enlazar elementos. Pega elementos hacia atras
{
    PtrTDispositivo auxiliar;
    auxiliar = ListaDispositivos;
    if (auxiliar != NULL)
    {
        while (auxiliar->SiguienteDispositivo != NULL)
        {
            auxiliar = auxiliar->SiguienteDispositivo;
        }
        auxiliar->SiguienteDispositivo = Nuevo;
    }
    else{
        ListaDispositivos = Nuevo;
    }
};


PtrTDispositivo buscaDispositivos(PtrTDispositivo &ListaDispositivos, string elemento){  // funcion que retorna posicion de memoria (pointer) de un dispositivo a encontrar
    bool encontrado = false;
    PtrTDispositivo auxiliar;
    auxiliar = ListaDispositivos;

    while (encontrado != true && auxiliar != NULL)
    {
        if (auxiliar->Nombre == elemento){
            encontrado = true;
        }
        else
        {
            auxiliar = auxiliar->SiguienteDispositivo;
        }
    }
    return auxiliar;
};


PtrTDispositivo editaDispositivo(string pNombre, int pCuarto, string pLlave, string pValor, PtrTDispositivo &ListaDispositivos){
    PtrTDispositivo var1 = buscaDispositivos(ListaDispositivos, pNombre);
    
    for (Accion acc : var1->ListaAcciones.actions){
        cout << "\nValor inicial " << acc.params->Llave << ": "  << acc.params->Valor << "\n";
        if (acc.params->Llave == pLlave){
            acc.params->Valor = pValor;
        }
        cout << "valor final " << acc.params->Llave << ": " << acc.params->Valor;
    };
    cout << endl;
    return var1;
};

list<PtrTareas> listaGlobTareas;
PtrTareas creaTarea(string pNombre, PtrTDispositivo &ListaDispositivos, list<PtrTDispositivo> listaDispAAgregar){
    PtrTareas nTarea = new(Tarea);

    nTarea->NombreTarea = pNombre;
    nTarea->AccionesAEjecutar = listaDispAAgregar;

    return nTarea;
};

void AgregarAListasTareas(PtrTareas &ListaTareas, PtrTareas& Nuevo) // crea un punto de inicio en la lista para comenzar a enlazar elementos. Pega elementos hacia atras
{
    PtrTareas auxiliar;
    auxiliar = ListaTareas;
    if (auxiliar != NULL)
    {
        while (auxiliar->SiguienteTarea != NULL)
        {
            auxiliar = auxiliar->SiguienteTarea;
        }
        auxiliar->SiguienteTarea = Nuevo;
    }
    else{
        ListaTareas = Nuevo;
    }
};

int main(){

    PtrTDispositivo NuevoDisp, NuevoDisp2, NuevoDisp3; // crea una instancia
    NuevoDisp = creaDispositivo("bombillo1", bombillo, 3);       // genera dispositivo
    NuevoDisp2 = creaDispositivo("parlante1", parlante, 1);      // genera otro dispositivo
    NuevoDisp3 = creaDispositivo("alarma humo", sensorHumo, 2);
    AgregarAListasDispositivos(ListaDispositivos, NuevoDisp);    // comienza la lista
    AgregarAListasDispositivos(ListaDispositivos, NuevoDisp2);   // agrega un otro dispositivo a la lista
    AgregarAListasDispositivos(ListaDispositivos, NuevoDisp3);


    // parametros son: (nombre, cuarto, llave de param, valor de llave de param, lista global)
    editaDispositivo("bombillo1", 3, "brillo", "50", ListaDispositivos); 
    editaDispositivo("parlante1", 1, "encender", "encendido", ListaDispositivos); // enciende el dispositivo

    PtrTDispositivo a = editaDispositivo("bombillo1", 3, "brillo", "0", ListaDispositivos); 
    PtrTDispositivo b = editaDispositivo("parlante", 1, "volumen", "25", ListaDispositivos); 
    list<PtrTDispositivo> listaLocal = {a, b};
    creaTarea("Buenos dias", ListaDispositivos, listaLocal); // crea una tarea
    AgregarAListasTareas(ListaTareas, listaGlobTareas); // agrega a lista de tareas

};
