

#include "Celula.h"
#include "ListaDobleCircular.h"
typedef Lista<Lista<Lista<int *> *> *> *cubo;

class Tablero{
    private:
    cubo tablero;

    public:
    /*PRE: 
      POST: Crea una instancia de tablero con las dimensiones pasadas*/
    Tablero(int capas, int filas, int columnas);
    /*PRE: 
      POST: */
    ~Tablero();
    /*PRE: 
      POST: */
    cubo getTablero();
    /*PRE: 
      POST: */
    void incializarTablero();
    /*PRE: 
      POST: */
    void mostrarTablero();
};


