#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include "/run/media/josec/Jose Cruz/Documentos/VIMProjects/ProyectoII/prioridades.h"

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

procesosT1;
procesosT1 *procTT = NULL;
procesosT1 *procTT2 = NULL;
procesos *Leer();

void ABPX(procesos *proc, procesos *proT, int cont);

void *atiende(void *args){
    int cont = 0;
    procTT = Leer();
    cont = procTT[0].cont;
    procTT2 = Leer();    
    ABPX(procTT, procTT2, cont); 
}
