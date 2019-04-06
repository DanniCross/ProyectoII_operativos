#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

void Hora(){
    time_t tiempo = time(0);
    struct tm *tlocal = localtime(&tiempo);
    printf("         BIENVENIDO AL SIMULADOR DEL BANCO LOSLA DRONES LTDA.\n");
    char output[128];
    strftime(output,128,"%d/%m/%y   %H:%M:%S",tlocal);
    printf("%s\n",output);
}
