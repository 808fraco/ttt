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
    strcpy(p->Apellido, a);
}
void setMail(Persona *p, char m[]){
    strcpy(p->Mail, m);
}
char* getNombre(Persona p){
    char *c;
    c = (char*)malloc(strlen(p.Nombre)+1);
    if(c==NULL){
        printf("Memoria insuficiente.\n");
        return NULL;
    }else{
        strcpy(c,p.Nombre);
        return c;
    }
}
char* getApellido(Persona p){
    char *a;
    a = (char*)malloc(strlen(p.Apellido)+1);
    if(a==NULL){
        printf("Memoria insuficiente\n");
        return NULL;
    }else{
        strcpy(a,p.Apellido);
        return a;
    }
}

#endif // PERSONA_H_INCLUDED
