#ifndef DEPARTAMENOS_H_INCLUDED
#define DEPARTAMENOS_H_INCLUDED
#include<stdio.h>
#include"Estacionamiento.h"
#include"Vehiculo.h"

typedef enum {Canelones,Maldonado,Rocha,Treina_y_Tres,Cerro_Largo,Rivera,Artigas,Salto,Paysandu,Rio_Negro,Soriano,Colonia,
                San_Jose,Flores,Florida,Lavalleja,Durazno,Tacuarembo,Montevideo}DEPARTAMENTOS;

void Seleccionedepartamento(ArregloConTope &est);

#endif // DEPARTAMENOS_H_INCLUDED
