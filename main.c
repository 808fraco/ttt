#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "persona.h"
#define MAX 1
void cargaPersona(Persona p[], int c, int *carga){
    int i,d;
    char n[30];
    char a[30];
    char m[30];
    if(*carga == MAX){
        printf("No se puede cargar mas personas.\n");
        return;
    }else{
        for(i=0;i<c;i++){
        inic(&p[*carga]);
        printf("\nPersona #%d\n", *carga+1);
        printf("Nombre: \n");
        fgets(n,30,stdin);
        setNombre(&p[*carga],n);

        printf("Apellido: \n");
        fgets(a,30,stdin);
        setApellido(&p[*carga],a);

        printf("Mail: \n");
        fgets(m,30,stdin);
        setMail(&p[*carga],m);

        printf("DNI: \n");
        scanf("%d", &d);
        setDNI(&p[*carga], d);
        getchar();
        (*carga)++;
        }
    }
}
void mostrarPersona(Persona p[], int c){
    int i;
    printf("====================\n");
    for(i=0;i<c;i++){
        printf("Persona #%d\n", i+1);
        printf("Nombre: %s", getNombre(p[i]));
        printf("Apellido: %s", getApellido(p[i]));
        printf("Mail: %s", getMail(p[i]));
        printf("DNI: %d\n", getDNI(p[i]));
        printf("\n");
    }
    printf("====================\n");
}
void test(void){
#ifdef _WIN32
    system("cls");
#endif
}
void dig(int n){
    printf("Digite 1 para continuar\n");
    scanf("%d", &n);
    while(n<0 || n>1){
        printf("Numero incorrecto.\n");
        scanf("%d", &n);
    }
}
int main(){
    int c,n,o, dispo;
    o = 0;
    c = 0;
    dispo = MAX;
    Persona p[MAX];
    while(o!=3){
        printf("Que desea hacer?\n");
        printf("1. Cargar personas\n");
        printf("2. Mostrar personas\n");
        printf("3. Salir\n");
        scanf("%d", &o);
        while(o<1 || o>3){
            printf("Numero incorrecto\n");
            scanf("%d", &o);
        }
        switch(o){
        case 1:
            if(dispo==0){
                test();
                printf("No se puede cargar mas personas.\n");

            }else{
                test();
                printf("Cuantas personas desea cargar? (disponibles: %d)\n", dispo);
                scanf("%d", &n);
                while(n<1 || n>dispo){
                    printf("Numero fuera del limite.\n");
                    scanf("%d", &n);
                }
                getchar();
                cargaPersona(p,n,&c);
                dispo = dispo - c;
                break;
            }
        case 2:
            if(c==0){
                test();
                printf("No hay personas cargadas aun. \n");
            }else{
                test();
                mostrarPersona(p,c);
            }
            break;
        case 3:
            return 777;
        }
    }
}
