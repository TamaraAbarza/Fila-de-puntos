#include <stdio.h>
#include <stdlib.h>
#include "fila_puntos.h"
void multiplicacion_escalar(fila *, int);
void Mostrar_elemento(fila *);
void multiplicacion_vectores(fila *f);
void nuevo_punto(fila *f);
void suma_puntos(fila *f);
int igualdad_vectores(fila *f);
int main()
{
    fila f;
    objeto p;
    int aux,cantidad;
    int opcion=-1,i,escalar;
    InicializarFila(&f);
    printf("\n\t\t\t\tBienvenido!\n");
    printf("\n\n\n\tIngrese la cantidad de puntos que quiera agregar a la fila\n\t");
    scanf("%d",&cantidad);
    for(i=0;i<cantidad;i++){
    nuevo_punto(&f);
    }

    opcion=0;
    //cambios
    while(opcion!=10){
    printf("\n\n******************************************************************************\n");
    printf("\t\t\t   Menu de opciones\n\n");
    printf("\n\t\t\tOperaciones sobre la fila:\n");
    printf("\t\t1-Agregar un nuevo punto a la fila\n\t\t2-Ver un punto de la fila\n\t\t3-Eliminar un punto de la fila\n");
    printf("\n\t\t\tOtras operaciones:\n");
    printf("\t\t4-Suma de puntos\n\t\t5-Multiplicacion por escalar\n\t\t6-Igualdad (Cantidad de puntos iguales dentro de la fila)\n\t\t7-Pertenencia (Buscar un punto en la fila)\n\t\t8-Multiplicacion de puntos\n\t\t9-Ver todos los puntos de la fila\n\t\t10-Salir");
    printf("\n\n******************************************************************************\n");
    printf("\n\n\t\tIngrese su opcion: ");
    scanf("%d",&opcion);
    printf("\n\n");
    switch(opcion){
case 1:
        nuevo_punto(&f);break;
case 2:
        if(FilaVacia(f)==1){
            printf("\n\t\tError, la fila esta vacia.\n\t\tDebe ingresar al menos un punto a la fila\n");
        }
        else{
            printf("\n\t\t%d, %d, %d\n",MostrarX(f),MostrarY(f),MostrarZ(f));
            }break;
case 3:
        if(FilaVacia(f)==1){
            printf("\n\t\tError, la fila esta vacia.\n\t\tDebe ingresar al menos un punto a la fila\n");
        }
        else{
            EliminarFila(&f);
            printf("\n\t\tSe ha eliminado el primer punto de la fila");
        }break;
case 4:
        if(FilaVacia(f)==1){
            printf("\n\t\tError, la fila esta vacia.\n\t\tDebe ingresar al menos un punto a la fila\n");
        }
        else{
            suma_puntos(&f);
        }break;

case 5:
        if(FilaVacia(f)==1){
            printf("\n\t\tError, la fila esta vacia.\n\t\tDebe ingresar al menos un punto a la fila\n");
        }
        else{
            printf("\n\t\tProducto por escalar\n");
            printf("\n\t\tIngrese el numero por el que quiere multiplicar la fila\n\t\t");
            scanf("%d",&escalar);
            printf("\n\t\tResultado de la multiplicacion:\n");
            multiplicacion_escalar(&f,escalar);
        }break;
case 6:
            if(FilaVacia(f)==1){
                printf("\n\t\tError, la fila esta vacia.\n\t\tDebe ingresar al menos un punto a la fila\n");
            }
            else{
                printf("\n\t\tIngrese un punto tridimencional\n\t\t");
                aux=igualdad_vectores(&f);
                if(aux==0)
                    printf("\n\t\tNo hay puntos iguales al ingresado en la fila\n");
                else{
                    printf("\n\t\tHay %d puntos iguales al ingresado dentro de la fila",aux);
                    }
            }break;
case 7:
        if(FilaVacia(f)==1){
            printf("\n\t\tError, la fila esta vacia.\n\t\tDebe ingresar al menos un punto a la fila\n");
        }
        else{
            printf("\n\t\tIngrese el punto tridimencional que quiere buscar en la fila\n\t\t");
            aux=igualdad_vectores(&f);
            if(aux==0)
                printf("\n\t\tEl punto ingresado no pertenece a la fila\n");
            else{
                printf("\n\t\tEl punto pertenece a la fila");
                }
        }break;
case 8:
        if(FilaVacia(f)==1){
            printf("\n\t\tError, la fila esta vacia.\n\t\tDebe ingresar al menos un punto a la fila\n");
        }
        else{
            multiplicacion_vectores(&f);
        }break;
case 9:
        if(FilaVacia(f)==1){
            printf("\n\t\tError, la fila esta vacia.\n\t\tDebe ingresar al menos un punto a la fila\n");
        }
        else{
            printf("\n\t\tLos puntos ingresados en la fila son los siguientes:\n");
            Mostrar_elemento(&f);
        }break;
case 10: printf("\n\n\t\tGracias por utilizar el programa :)\n\n\n");break;
default: printf("\n\t\tOpcion incorrecta\n\t\t");
        }
    }
    printf("\n");
    return 0;
}
void suma_puntos(fila *f){
    objeto vector,resultado;
    fila FilaSuma;
    InicializarFila(&FilaSuma);
    insertar_punto(&resultado,0,0,0);
    while (FilaVacia(*f)!=1){
        vector=MostrarFila(*f);
        suma(vector, &resultado);
        insertarFila(&FilaSuma,MostrarFila(*f));
        EliminarFila(&(*f));
    }
    insertarFila(&(*f),resultado);
    printf("\n\t\tEl resultado de la suma es: ");
    Mostrar_elemento(&(*f));
    InicializarFila(&(*f));

    while(FilaVacia(FilaSuma)!=1){
        insertarFila(&(*f),MostrarFila(FilaSuma));
        EliminarFila(&FilaSuma);
    }
}
void Mostrar_elemento(fila *f){
    fila auxiliar;
    InicializarFila(&auxiliar);
    int i;
    while(FilaVacia(*f)!=1){
        printf("\n\t\t");
        printf("%d, ",MostrarX(*f));
        printf("%d, ",MostrarY(*f));
        printf("%d\n ",MostrarZ(*f));
        insertarFila(&auxiliar,MostrarFila(*f));
        EliminarFila(&(*f));
    }
    InicializarFila(&(*f));
    while(FilaVacia(auxiliar)!=1){
        insertarFila(&(*f),MostrarFila(auxiliar));
        EliminarFila(&auxiliar);
    }
}
//cambios:
void multiplicacion_escalar(fila *f,int escalar){
    objeto auxiliar;
    fila fila_aux,fila_aux2;
    InicializarFila(&fila_aux);
    InicializarFila(&fila_aux2);

    while(FilaVacia(*f)!=1){
        auxiliar=MostrarFila(*f);
        producto_escalar(&auxiliar,escalar);
        insertarFila(&fila_aux,auxiliar);
        insertarFila(&fila_aux2,MostrarFila(*f));
        EliminarFila(&(*f));
    }
    InicializarFila(&(*f));
    while(FilaVacia(fila_aux)!=1){
        auxiliar=MostrarFila(fila_aux);
        insertarFila(&(*f),auxiliar);
        EliminarFila(&fila_aux);
    }
    Mostrar_elemento(&(*f));
     //
    while(FilaVacia(*f)!=1){
        EliminarFila(&(*f));
    }
    InicializarFila(&(*f));
    while(FilaVacia(fila_aux2)!=1){
        insertarFila(&(*f),MostrarFila(fila_aux2));
        EliminarFila(&fila_aux2);
    }
}

int igualdad_vectores(fila *f){
    objeto auxiliar,p;
    fila FilaAux;
    InicializarFila(&FilaAux);
    int contador=0,x,y,z;
    printf("\n\t\tIngrese un valor para la coordenada x\n\t\t");
    scanf("%d",&x);
    printf("\n\t\tIngrese un valor para la coordenada y\n\t\t");
    scanf("%d",&y);
    printf("\n\t\tIngrese un valor para la coordenada z\n\t\t");
    scanf("%d",&z);
    insertar_punto(&p,x,y,z);
    while (FilaVacia(*f)!=1){
        auxiliar=MostrarFila(*f);
        if(igualdad(p,auxiliar)==1){
            contador+=1;
        }
        insertarFila(&FilaAux,MostrarFila(*f));
        EliminarFila(&(*f));
    }
    InicializarFila(&(*f));
    while (FilaVacia(FilaAux)!=1){
        insertarFila(&(*f),MostrarFila(FilaAux));
        EliminarFila(&FilaAux);
    }
    return contador;
}
void nuevo_punto(fila *f){
    int x,y,z;
    objeto p;
    if(FilaLLena(*f)==1){
        printf("\n\tError, no se pueden ingresar mas puntos porque la fila esta llena\n");
    }
    else{
        printf("\n\n");
        printf("\n\t\tIngrese un valor para la coordenada x\n\t\t");
        scanf("%d",&x);
        printf("\n\t\tIngrese un valor para la coordenada y\n\t\t");
        scanf("%d",&y);
        printf("\n\t\tIngrese un valor para la coordenada z\n\t\t");
        scanf("%d",&z);
        insertar_punto(&p,x,y,z);
        insertarFila(&(*f),p);
    }

}
void multiplicacion_vectores(fila *f){
    objeto vector,resultado;
    fila FilaAuxiliar;
    InicializarFila(&FilaAuxiliar);
    insertar_punto(&resultado,1,1,1);
    while (FilaVacia(*f)!=1){
        vector=MostrarFila(*f);
        multiplicacion(vector, &resultado);
        insertarFila(&FilaAuxiliar,MostrarFila(*f));
        EliminarFila(&(*f));
    }
    insertarFila(&(*f),resultado);
    printf("\n\t\tEl resultado de la multiplicacion es el siguiente vector: ");
    Mostrar_elemento(&(*f));
    InicializarFila(&(*f));
    while(FilaVacia(FilaAuxiliar)!=1){
        insertarFila(&(*f),MostrarFila(FilaAuxiliar));
        EliminarFila(&FilaAuxiliar);
    }

}
