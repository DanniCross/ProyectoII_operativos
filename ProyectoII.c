#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>
#include "/run/media/josec/Jose Cruz/Documentos/VIMProjects/ProyectoI/LosLadrones/LeerTXT.h"
#include "/run/media/josec/Jose Cruz/Documentos/VIMProjects/ProyectoII/hora.h"
#include "/run/media/josec/Jose Cruz/Documentos/VIMProjects/ProyectoII/cajas.h"

typedef struct{
    char *proceso;
    int TLlegada;
    int TEjecucion;
    int Tipo;
    char *Type;
    int cont;
    int wt;
    int ft;
    int status;
}

procesosT;
procesosT *procT = NULL;
procesosT *procT2 = NULL;
procesos *Leer();
void hora();
void *atiende(void *args);

void main(int argc, char *argv[]){
    int cont = 0;
    int cajas = 0;
    procT = Leer();
    cont = procT[0].cont;
    pthread_t caja;
    Hora();
    printf("                         TABLA DE PROCESOS                               \n");
    printf("Cliente    Tiempo de Llegada:    Tiempo de ejecucion:    Tipo de cliente:");
    for(int a = 0; a < cont - 1; a++){ 
        printf("\n%s               ",procT[a].proceso);
        if(procT[a].TLlegada < 10){
            printf("   %i                  ",procT[a].TLlegada);
        }else if(procT[a].TLlegada < 100){
            printf("  %i                  ",procT[a].TLlegada);
        }else{
            printf(" %i                  ",procT[a].TLlegada);
        }
        if(procT[a].TEjecucion < 10){
            printf("   %i               ",procT[a].TEjecucion);
        }else if(procT[a].TEjecucion < 100){
            printf("  %i               ",procT[a].TEjecucion);
        }else{
	    printf(" %i               ",procT[a].TEjecucion);
        }
        printf("%s", procT[a].Type);	
    }
    printf("\n");
    printf("¿Cuantas cajas estarán abiertas el día de hoy? ");
    scanf("%d",&cajas);
    for(int i = 0; i < cajas; i++){
        pthread_create(&caja, NULL, atiende, NULL);
	sleep(1);
    }

}
