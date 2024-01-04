#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

/**
Desarrollar un programa en C que permita resolver el siguiente problema implementando las funciones necesarias:
Un grupo de investigadores se encuentran realizando un estudio geomorfológico sobre la superficie del Partido de La Costa.
Actualmente necesitan procesar los datos provistos por las métricas que censan los satélites para intentar obtener nueva información
para el planeamiento urbano.
Se plantea un proyecto de software que haga uso de 4 vectores con los siguientes datos: latitudes, longitudes, alturas, zonas.
Los datos provistos por los satélites se utilizarán para cargar los 3 primeros vectores con números de precisión flotante.
Respecto a la zona, es un campo de tipo cadena de caracteres que se deberá generar a partir de los datos suministrados por el satélite:
- LATITUDES: contiene el dato de coordenada respecto a la latitud
Ejemplo: {-36.59, -36.44, -36.65, -36.90, -36,43}
- LONGITUDES: contiene el dato de coordenada respecto a la longitud
Ejemplo: {-56.71, -56.70, -56.67, -56.72, 56.70}
- ALTURAS: contiene el dato de altura sobre el nivel del mar en metros
Ejemplo: {-0.1, 1.4, 2.1, 0.1, 2.1}
- ZONAS: texto descriptivo de la zona referenciada (se genera en punto 2)

Se le solicita a usted escriba un programa en lenguaje C para colaborar con el grupo de investagadores a procesar los datos de manera semi-automatizada.
1. "Cargar los Vectores con Datos del Satélite": esta opción debe solicitar al usuario 3 datos: latitud, longitud y altura, y almacenarlos en los
vectores correspondientes. Limite maximo asignado (MAX_VEC 50).
2. "Generar el Vector de Zonas": esta opción debe recorrer las LATITUDES y según el rango en que se encuentre deberá gennerar la ZONA donde guardará
el detalle con el texto pertinente teniendo en cuenta que si el dato en el vector LATITUDES:
* es mayor o igual a -37.00 y menor a -36.63 guardar en ZONAS "Zona Sur".
* es mayor o igual a -36.63 y menor o igual -36.51 guardar en ZONAS "Zona Centro".
* es mayor a -36.51 guardar en ZONAS "Zona Norte".
3. "Mostrar Picos (alturas maximas)": esta opción deberá recorrer las ALTURAS y mostrar latitud, longitud y zona de aquellas alturas que sean las máximas.
4. "Mostrar Depresiones (alturas minimas)": esta opción deberá recorrer las ALTURAS y mostrar latitud, longitud y zona de aquellas alturas que sean minimas.
5. "Porcentaje de mediciones por Zonas": Recorrer ZONAS para calcular el porncetaje de mediciones realizadas por zonas.
**/

#define MAX_VEC 2

void CargaVector (float latitud[], float longitud[], float altura[]);
void VectorZona (float latitud[], float longitud[], float altura[], char zona[][50]);
void Picos (float latitud[], float longitud[], float altura[], char zona[][50]);
void Depresiones (float latitud[], float longitud[], float altura[], char zona[][50]);
void Porcentaje (float latitud[], float longitud[], float altura[], char zona[][50]);

void main()
{
    float latitud[MAX_VEC];
    float longitud[MAX_VEC];
    float altura[MAX_VEC];
    float zona[MAX_VEC][50];

    CargaVector(latitud,longitud,altura);
    VectorZona(latitud,longitud,altura,zona);
    Picos(latitud,longitud,altura,zona);
    Depresiones(latitud,longitud,altura,zona);
    Porcentaje(latitud,longitud,altura,zona);


}

void CargaVector (float latitud[], float longitud[], float altura[])
{
    for(int i=0;i<MAX_VEC;i++)
    {
        printf("Ingrese latitud %d: \n", i+1);
        scanf("%f", &latitud[i]);

        printf("Ingrese longitud %d: \n", i+1);
        scanf("%f", &longitud[i]);

        printf("Ingrese altura %d: \n", i+1);
        scanf("%f", &altura[i]);
    }
}

void VectorZona (float latitud[], float longitud[], float altura[], char zona[][50])
{
    for(int i=0;i<MAX_VEC;i++)
    {
        if(latitud[i]>=(-37.00) && latitud[i]<(-36.63))
        {
            strcpy(zona[i],"Zona Sur");
        }
        else if(latitud[i]>=(-36.63) && latitud[i]<=(-36.51))
        {
            strcpy(zona[i],"Zona Centro");
        }
        else if(latitud[i]>(-36.51))
        {
            strcpy(zona[i],"Zona Sur");
        }

    }
}

void Picos (float latitud[], float longitud[], float altura[], char zona[][50])
{
    float alturaMax=altura[0];
    float longitudM;
    float latitudM;
    char zonaM[50];

    for(int i=0;i<MAX_VEC;i++)
    {
        if(altura[i]>alturaMax)
        {
            alturaMax=altura[i];
            longitudM=longitud[i];
            latitudM=latitud[i];
            strcpy(zonaM,zona[i]);
        }
    }
    printf("La zonas con mayores alturas son: %s\n", zonaM);
    printf("Altura:: %.2f %%\n", alturaMax);
    printf("Latitud: %.2f %%\n", latitudM);
    printf("Longitud: %.2f %%\n\n", longitudM);
}

void Depresiones (float latitud[], float longitud[], float altura[], char zona[][50])
{
    float alturaMin=altura[0];
    float longitudMin;
    float latitudMin;
    char zonaMin[50];

    for(int i=0;i<MAX_VEC;i++)
    {
        if(alturaMin<altura[i])
        {
            alturaMin=altura[i];
            longitudMin=longitud[i];
            latitudMin=latitud[i];
            strcpy(zonaMin,zona[i]);
        }
    }

    printf("La zonas con menores alturas son: %s\n", zonaMin);
    printf("Altura:: %.2f %%\n", alturaMin);
    printf("Latitud: %.2f %%\n", latitudMin);
    printf("Longitud: %.2f %%\n\n", longitudMin);
}

void Porcentaje (float latitud[], float longitud[], float altura[], char zona[][50])
{
    int cantZonaS=0;
    int cantZonaC=0;
    int cantZonaN=0;
    float porcentajeS;
    float porcentajeN;
    float porcentajeC;

    for(int i=0;i<MAX_VEC;i++)
    {
        if(strcmp(zona[i],"Zona Sur"))
        {
            cantZonaS++;
        }
        else if(strcmp(zona[i],"Zona Centro"))
        {
            cantZonaC++;
        }
        else if(strcmp(zona[i],"Zona Norte"))
        {
            cantZonaN++;
        }
    }
    porcentajeS=cantZonaS*100/MAX_VEC;
    porcentajeN=cantZonaN*100/MAX_VEC;
    porcentajeC=cantZonaC*100/MAX_VEC;

    printf("El porcentaje de Zona Sur es de: %.2f %%\n", porcentajeS);
    printf("El porcentaje de Zona Norte es de: %.2f %%\n", porcentajeN);
    printf("El porcentaje de Zona Centro es de: %.2f %%\n", porcentajeC);
}
