#include"Estacionamiento.h"

boolean EstaRegistrado (ArregloConTope a, strings mat){
    int i=0;
    strings str1;
    boolean encontre = FALSE;

    do{
        DevolverMatricula(a.arreglo[i],str1);
        if(streq(str1, mat))
            encontre = TRUE;
        else
            i++;

    }while(i<a.tope && !encontre);
    return encontre;
}

void cargadevehiculos(ArregloConTope &a){
    boolean listo;
    Vehiculo v;
    listo=FALSE;
    strings str1;
    int i=0, b=0;

    printf("\n--Cargando informacion del vehiculo--\n");
    if(a.tope < tam){
        CargarVehiculo(v);
        DevolverMatricula(v, str1);
        if(!EstaRegistrado(a,str1)){
            a.arreglo[a.tope] = v;
            a.tope++;
        }
        else
            printf("\nERROR. El vehiculo ya esta registrado.\n");
        }
    else
        printf("\nERROR. El garage esta lleno.\n");
}

void ResgistrarPartida(ArregloConTope &a, strings Mat, int &total){
    hora h;
    boolean esta=FALSE;
    strings str1;
    int i=0;
    int thoras=0, tminutos=0;

    do{
        DevolverMatricula(a.arreglo[i], str1);
        if(streq(str1, Mat)){

            int ticket=0;
            printf("\nIngrese la hora de salida: ");
            CargarHoras(h);
            if(DevolverHoras(h) < DevolverHoras(a.arreglo[i].hor)){
                printf("\nError, hora de entrada es mayor a hora de salida.");
            }
            else{
                thoras = DevolverHoras(h) - DevolverHoras(a.arreglo[i].hor);
                tminutos = DevolverMinutos(h) - DevolverMinutos(a.arreglo[i].hor);
                if (tminutos==0)
                    ticket= thoras*100;
                else
                    ticket=(thoras*100)+60;

                printf("\nEl valor del ticket es de: %d pesos.\n",ticket);
                total= total + ticket;
                esta= TRUE;
            }

        }
        else
        i++;
    }while(i<a.tope && !esta);
    if(esta){
        for(i;i<a.tope;i++){
                a.arreglo[i] = a.arreglo[i+1];
            }
        a.tope--;
    }
    else
        printf("\nERROR. La matricula no se encuentra en el estacionamiento.\n");
}

int TotRecaudado(int total){
    return total;
}

void CantAutosYCamionetas(ArregloConTope a){
    int contAut=0, contCam=0;

    for(int i=0; i<a.tope; i++){
        if(DevolverDisc(a.arreglo[i]) == AUTO)
            contAut++;
        else if (DevolverDisc(a.arreglo[i]) == CAMIONETA)
                contCam++;
    }
    printf("\nLa cantidad de AUTOS es de: %d.",contAut);
    printf("\nLa cantidad de CAMIONETAS es de: %d.",contCam);
}

int TotVehiculoXDepartamento(ArregloConTope a, Departamentos d){
    int contador=0;
    for(int i=0;i<a.tope;i++){
        if(DevolverDepartamento(a.arreglo[i]) == d)
            contador++;
    }
    return contador;

}

void ListadoVehiculos(ArregloConTope a){
    strings str1;
    int i=0;

    if(i == a.tope){
        printf("\nNo hay vehiculos registrados en el estacionamiento.\n");
    }
    else{
        for(i=0;i<a.tope;i++){
            ImprimrDepartamento(DevolverDepartamento(a.arreglo[i]));
            printf(", CI: %ld",DevolverCI(a.arreglo[i]));printf(",");
            MostrarHoras(DevolverHora(a.arreglo[i]));
            printf(", MATRICULA: ");
            DevolverMatricula(a.arreglo[i], str1);
            print(str1);
            printf("\n");
        }
    }

}

void MostrarDatosXMatricula(ArregloConTope a){
    strings str1,str2;
    int i=0;
    boolean encontre=FALSE;

    printf("\nIngrese su Matricula a continuacion: ");
    fflush(stdin);
    scan(str1);
    while(i<a.tope && !encontre){
        DevolverMatricula(a.arreglo[i], str2);
        if(streq(str2, str1)){
            MostrarVehiculo(a.arreglo[i]);
            encontre = TRUE;
        }
        i++;
    }
    if(!encontre){
        printf("\nERROR. La matricula no esta registrada en el estacionamiento.");
    }


}

void IngresosXHora(ArregloConTope a){
    int horIngre;
    strings str1;
    boolean encontre=FALSE;

    printf("\nIngrese una hora: ");
    scanf("%d",&horIngre);
    if(horIngre >= 8 && horIngre <=22){
        for(int i=0;i<a.tope;i++){
            if(horIngre == DevolverHoras(a.arreglo[i].hor)){
                encontre=TRUE;
                printf("\nLa CI es: %ld",DevolverCI(a.arreglo[i]));
                printf("\nLa matricula es: ");
                DevolverMatricula(a.arreglo[i],str1);
                print(str1);
            }
        }
    }
    else
        printf("\nHora no valida.");
    if(!encontre)
        printf("\nNo se ingresaron vehiculos en esa hora.");
}

void SuperaCapDeCarga(ArregloConTope a){
    int valcarga=0;
    boolean positivo=FALSE;
    int contador=0;

    printf("\nIngrese el limite de la capcidad de carga para el estacionamiento: ");
    do{
        scanf("%d",&valcarga);
        if(valcarga < 0){
            printf("\nError, no se puede ingresar un valor negativo.");
            printf("\nVolver a ingresar: ");
        }
        else{
            positivo = TRUE;
            for(int i=0;i<a.tope;i++){
                if(DevolverDisc(a.arreglo[i])==CAMIONETA){
                    if(DevolverCapcarga(DevovlerCamionetas(a.arreglo[i])) > valcarga){
                        contador++;
                        printf("\nSu CI es: %ld.", DevolverCI(a.arreglo[i]));
                        MostrarCamioneta(DevovlerCamionetas(a.arreglo[i]));
                    }
                }
            }
        }
    if(contador == 0){
        printf("\nNo se encontraron camionetas que superen el valor de carga limite del estacionamiento.\n");
    }
    }while(!positivo);
}
