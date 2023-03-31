#ifndef ESTACIONAMIENTO_H_INCLUDED
#define ESTACIONAMIENTO_H_INCLUDED
#include"Vehiculo.h"



const int tam = 50;
typedef struct{
                Vehiculo arreglo[tam];
                int tope;
            }ArregloConTope;

boolean EstaRegistrado (ArregloConTope a, strings mat);

void IngresarVehiculo(ArregloConTope &a);

void ResgistrarPartida(ArregloConTope &a, strings Mat, int &total);

int TotRecaudado(int total);

void CantAutosYCamionetas(ArregloConTope a);

int TotVehiculoXDepartamento(ArregloConTope a, Departamentos d);

void ListadoVehiculos(ArregloConTope a);

void MostrarDatosXMatricula(ArregloConTope a);

void IngresosXHora(ArregloConTope a);

void SuperaCapDeCarga(ArregloConTope a);

void cargadevehiculos(ArregloConTope &a);

void Valorticket(ArregloConTope a, hora h, int j, int &ticket);

#endif // ESTACIONAMIENTO_H_INCLUDED
