#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct{
    char Nombre[30];
    char Apellido[30];
    char Mail[30];
    int dni;
}Persona;

void inic(Persona *p){
    p->Nombre[0] = '\0';
    p->Apellido[0] = '\0';
    p->Mail[0] = '\0';
    p->dni = 0;
}

void setNombre(Persona *p, char n[]){
    strcpy(p->Nombre, n);
}
void setApellido(Persona *p, char a[]){
    strcpy(p->Apellido, n);
}

char* getNombre(Persona p){
    char *c;
    c = (char*)malloc(strlen(p.Nombre)+1);
    if(c==NULL){
        printf("Memoria insuficiente.\n");
    }else{
        strcpy(c,p.Nombre);
        return c;
    }
}
#endif // PERSONA_H_INCLUDED
