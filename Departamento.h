#ifndef DEPARTAMENTO_H_INCLUDED
#define DEPARTAMENTO_H_INCLUDED
#include<stdio.h>


typedef enum {CANELONES, MALDONADO, ROCHA, TREINTAYTRES, CERROLARGO, RIVERA, ARTIGAS,SALTO, PAYSANDU, RIONEGRO, SORIANO, COLONIA, SANJOSE, FLORES, FLORIDA,LAVALLEJA, DURAZNO, TACUAREMBO, MONTEVIDEO} Departamentos;

void Seleccionedepartamento (Departamentos &d);

void ImprimrDepartamento (Departamentos d);

#endif // DEPARTAMENTO_H_INCLUDED
