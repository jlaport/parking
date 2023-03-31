#include"Camioneta.h"

void CargarCamioneta(camionetas &c){
    boolean valido=FALSE;

    printf("\nIngrese el modelo de la camioneta: ");
    fflush(stdin);
    scan(c.modelo);
    printf("\nIngrese la capacidad de carga de la camioneta: ");
    do{
        scanf("%d",&c.capcarga);
        if(c.capcarga < 0){
            printf("\nERROR. No se admite valor negativo.");
            printf("\nVolver a ingresar: ");
        }
        else
            valido = TRUE;

    }while(!valido);
}

void DevolverModeloCamio(camionetas c,strings &str1){
    strcop(c.modelo,str1);
}

int DevolverCapcarga(camionetas c){
    return c.capcarga;
}

void MostrarCamioneta(camionetas c){
    strings str1;

    DevolverModeloCamio(c, str1);
    printf("\nEl modelo de la camioneta es: ");
    print(str1);
    printf("La capacidad de carga es de: %d.",DevolverCapcarga(c));
}
