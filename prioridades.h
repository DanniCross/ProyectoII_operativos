#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

procesos *OrdenarTL(procesos *pro, int a, int b);

//Algoritmo de planificación expulsivo basado en prioridad.
void ABPX(procesos *pro, procesos *proT, int cont){
    printf("\nAlgoritmo expulsivo basado en prioridad.\n");
    double tp, tf = 0;
    int pass, f, h = 0;
    int ej, eje = 0;
    int may = 4;

    for(int i = 2; i < cont - 1; i++){
         for(int j = 0; j < cont - i; j++){
	     if(pro[j].TLlegada > pro[j+1].TLlegada){
	         pro = OrdenarTL(pro, j, j);
	     }
	 }
    }
    
    for(int o = 2; o < cont - 1; o++){
	tf = 0;
        for(int p = 1; p < cont - o; p++){
	    tf += pro[p-1].TEjecucion;
            if(pro[p].Tipo > pro[p+1].Tipo){
	        if(tf > pro[p+1].TLlegada){
		    pro = OrdenarTL(pro, p, p);
		}
	    }else if(pro[p].Tipo == pro[p+1].Tipo){
	        if(pro[p].TLlegada > pro[p+1].TLlegada){
		    pro = OrdenarTL(pro, p, p);
		}
	    }
	    
	}
    }

    for(int k = 0; k < cont - 1; k++){
	pass = 0;
        for(int l = 0; l < cont - 1; l++){
            eje = 0;
	    f = l;
	    h = l;
	    if(pro[l].TEjecucion == 0){
	        proT[k].proceso = pro[l].proceso;
		proT[k].TLlegada = pro[l].TLlegada;
		proT[k].TEjecucion = ej;
		proT[k].Tipo = pro[l].Tipo;
		proT[k].Type = pro[l].Type;
		pro[l].TEjecucion = -1;
                pass = 1;
                l = cont - 2;
	    }else if(pro[l].TEjecucion > 0){
	        ej += 1;
		eje += 1;
	        pro[l].TEjecucion = pro[l].TEjecucion - 1;
		while(pass == 0){
		    if(pro[f+1].TEjecucion < 0){
		        f++;
		    }else{
		        l = f;
			pass = 1;
		    }
		}
		pass = 0;
		if(eje == 50){
		    eje = 0;
		    for(int z = 0; z < cont - 1; z++){
		        if(pro[z].proceso != pro[h].proceso && pro[z].Tipo == may && may != 0){
			    pro[z].Tipo = pro[z].Tipo - 1;
			    may = may - 1;
			}
		    }
		}
	        if(ej < pro[l+1].TLlegada && l != cont - 2 || pro[h].Tipo <= pro[l+1].Tipo){
                    l = h - 1;
		}
	   }
           if(l == cont - 2 && pass == 0){
	       k = k - 1;
	   }
	}
    } 
    for(int n = 0; n < cont - 1; n++){
        tp += proT[n].TEjecucion;
	printf("\nCliente %s, terminó su diligencia en %d segundos",proT[n].proceso, proT[n].TEjecucion);
    }

        printf("\n\nLa suma de los tiempos es: %2.1f segundos",tp);
        tp = tp / (cont - 1);
        printf("\nTiempo promedio en ABPX fue: %2.2f segundos\n",tp);
        printf("-------------------------------------------------------------\n");
}

//Ordenamiento
procesos *OrdenarTL(procesos *pro, int d, int e){
    int Llega;
    int Ejecuta;
    int Tipo;
    char *proceso;
    char *Type;
    int wt;
    int ft;
    int status;
    Llega = pro[d].TLlegada;
    Ejecuta = pro[d].TEjecucion;
    proceso = pro[d].proceso;
    Tipo = pro[d].Tipo;
    Type = pro[d].Type;
    wt = pro[d].wt;
    ft = pro[d].ft;
    status = pro[d].status;
    pro[d].TLlegada = pro[e+1].TLlegada;
    pro[d].TEjecucion = pro[e+1].TEjecucion;
    pro[d].proceso = pro[e+1].proceso;
    pro[d].Tipo = pro[e+1].Tipo;
    pro[d].Type = pro[e+1].Type;
    pro[d].wt = pro[e+1].wt;
    pro[d].ft = pro[e+1].ft;
    pro[d].status = pro[e+1].status;
    pro[e+1].TLlegada = Llega;
    pro[e+1].TEjecucion = Ejecuta;
    pro[e+1].proceso = proceso;
    pro[e+1].Tipo = Tipo;
    pro[e+1].Type = Type;
    pro[e+1].wt = wt;
    pro[e+1].ft = ft;
    pro[e+1].status = status;
    return pro;
}
