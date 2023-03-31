#include"Discriminante.h"

void CargarDiscriminante(discriminante &dis){
    int a=0;
    do{
        printf("\nIngrese el tipo de vehiculo: \n1 - AUTO.\n2 - CAMIONETA.\n");
        scanf("%d",&a);

        if (a == 1)
            dis = AUTO;
        else{
            if (a == 2)
                dis = CAMIONETA;

        }
    }while(a<1 || a>2);
}

void MostrarDiscriminante(discriminante dis){
    if (dis == AUTO)
        printf("AUTO.");
    else {
        if(dis== CAMIONETA)
            printf("CAMIONETA.");
        else
            printf("\nFUERA DE RANGO.");
            }
}
