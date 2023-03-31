#include"Hora.h"

void CargarHoras(hora &h){
    boolean valida=FALSE;
    do{
    printf("\nIngrese hora: ");
    scanf("%d",&h.Horas);
        if(h.Horas >= 8 && h.Horas <=22){
            printf("\nIngrese minutos: ");
            scanf("%d",&h.Minutos);
            if (h.Horas == 22 && h.Minutos > 0)
                    printf("\nError Garage Cerrado. \nVolver a ingresar hora: ");
            else
                if(h.Minutos >= 0 && h.Minutos <=59)
                    valida = TRUE;
                else
                    printf("\nError minutos no validos");
        }
        else
            printf("\nERROR Hora no valida.\nVolver a ingresar hora: ");

    }while(!valida);
}

int DevolverHoras(hora h){
    return h.Horas;
}

int DevolverMinutos(hora h){
    return h.Minutos;
}

void MostrarHoras(hora h){
    if (DevolverMinutos(h) < 10)
        printf("HORA: %d:0%d",DevolverHoras(h),DevolverMinutos(h));
    else
        printf("HORA: %d:%d",DevolverHoras(h),DevolverMinutos(h));
}
