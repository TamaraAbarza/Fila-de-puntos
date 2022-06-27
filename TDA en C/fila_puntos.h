#include "punto.h"
#define max 100
typedef struct {
    int ult;
    objeto vipd[max];
}fila;

void InicializarFila(fila *f){
    (*f).ult= -1;
}
int FilaVacia(fila f){
    if (f.ult == -1)
        return 1;
    else{
        return 0;
    }
}
int FilaLLena(fila f){
    if (f.ult == max-1)
        return 1;
    else{
        return 0;
    }
}
void insertarFila(fila *f, objeto elemento){
    (*f).ult++;
    (*f).vipd[(*f).ult]= elemento;
}
void EliminarFila(fila *f){
    int i=0;
    while(i<(*f).ult){
        (*f).vipd[i]= (*f).vipd[i+1];
        i++;
    }
    (*f).ult--;
}
objeto MostrarFila(fila f){
    return f.vipd[0];
}
int MostrarX(fila f){
    return f.vipd[0].punto[0];
}
int MostrarY(fila f){
    return f.vipd[0].punto[1];
}
int MostrarZ(fila f){
    return f.vipd[0].punto[2];
}
