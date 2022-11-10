#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Configuraciones.h"

using namespace std;



Configuraciones::Configuraciones() {
    this->lista = new Lista<Configuracion *>;
    this->primeraConf = new Configuracion;
    this->obtenerConfiguraciones();
}

void Configuraciones::obtenerConfiguraciones() {
    string rutaArchivo = "data.txt";
    ifstream archivo;
    archivo.open(rutaArchivo.c_str());
    string linea;
    getline(archivo, linea);
    int i = 1;
    while(! archivo.eof()) {
        this->configAux = new Configuracion;
        int largo, ancho, profundidad, x1, x2, x3, cantidadCeldasTipo1, cantidadCeldasTipo2, cantidadCeldasTipo3, cantidadCeldasTipo4, cantidadCeldasTipo5;
        string dificultad;

        archivo >> this->configAux->dificultad;
        archivo >> this->configAux->largo;
        archivo >> this->configAux->ancho;
        archivo >> this->configAux->profundidad;
        archivo >> this->configAux->x1;
        archivo >> this->configAux->x2;
        archivo >> this->configAux->x3;
        archivo >> this->configAux->cantidadCeldasContaminadas;
        archivo >> this->configAux->cantidadCeldasEnvenenadas;
        archivo >> this->configAux->cantidadCeldasProcreadoras;
        archivo >> this->configAux->cantidadCeldasPortales;
        archivo >> this->configAux->cantidadCeldasRadioactivas;
        this->configAux->id = i;
        Configuracion *punteroAuxiliar = configAux;this->lista->add(this->configAux);
        if (this->primeraConf->dificultad == "")
        {
            this->primeraConf = this->configAux;
        }
        i++;
    }
    this->cantidadDeConfiguraciones = this->configAux->id;

    archivo.close();
}

void Configuraciones::mostrarConfiguraciones() {
    this->lista->inicializarCursor();
    if(!this->lista->estaVacia()) {
        do
        {
            cout<<this->lista->getCursor()->id<<" - "<<this->lista->getCursor()->dificultad<<endl;
            this->lista->avanzarCursor();
        } while (this->lista->getCursor()->id != this->primeraConf->id);
    }
    cout<<this->cantidadDeConfiguraciones + 1<<" - Carga manual"<<endl;
    
}

Configuracion * Configuraciones::seleccionarUnaConfiguracion() {
    int idElegido;
    Configuracion * confElegida;
    cout<<"Elija una dificultad o seleccione 'Carga manual' con uno de los numeros: "<<endl;
    cin>>idElegido;
    this->lista->inicializarCursor();
    if (idElegido < 1 || idElegido > (this->cantidadDeConfiguraciones + 1)) {
        throw "Esa opcion no existe.";
    }
    do
    {
        this->lista->avanzarCursor();
        confElegida = this->lista->getCursor();
    } while (idElegido != this->lista->getCursor()->id);
    return confElegida;
}

Configuraciones::~Configuraciones() {
    delete this->lista;
}

int main() {
    Configuraciones * config = new Configuraciones;
    config->mostrarConfiguraciones();
    Configuracion * confElegida = config->seleccionarUnaConfiguracion();
    cout<<confElegida->dificultad;
    delete config;
    return 0;
}