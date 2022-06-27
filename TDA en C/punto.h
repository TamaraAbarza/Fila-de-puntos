typedef struct{
 int punto[3];
}objeto;

void insertar_punto(objeto *p, int x, int y, int z){
    (*p).punto[0]=x;
    (*p).punto[1]=y;
    (*p).punto[2]=z;
}

void suma(objeto p,objeto *resultado){
    (*resultado).punto[0]+=p.punto[0];
    (*resultado).punto[1]+=p.punto[1];
    (*resultado).punto[2]+=p.punto[2];
}
void producto_escalar(objeto *p, int escalar){
    (*p).punto[0]=(*p).punto[0]*escalar;
    (*p).punto[1]=(*p).punto[1]*escalar;
    (*p).punto[2]=(*p).punto[2]*escalar;
}
void multiplicacion(objeto p, objeto *resultado){
    (*resultado).punto[0]*=p.punto[0];
    (*resultado).punto[1]*=p.punto[1];
    (*resultado).punto[2]*=p.punto[2];
}
int igualdad(objeto p,objeto s){
    if(p.punto[0]==s.punto[0] && p.punto[1]==s.punto[1] && p.punto[2]==s.punto[2])
    return 1;
    else{
        return 0;
    }
}
//Cambios:
int getX(objeto p){
return p.punto[0];
}
int getY(objeto p){
return p.punto[1];
}
int getZ(objeto p){
return p.punto[2];
}
void setX(int x, objeto *p){
    (*p).punto[0]=x;
}
void setY(int y,objeto *p){
    (*p).punto[1]=y;
}
void setZ(int z, objeto *p){
    (*p).punto[2]=z;
}

