#include <stdio.h>
#include <stdlib.h>
#include "pantalla.h"
#include "contratacion.h"
#include "compartida.h"
#include "validar.h"

#define TAM_PANTALLAS 100
#define TAM_CONTRATACIONES 1000
int main()
{
    EPantalla arrayPantallas[TAM_PANTALLAS];
    pant_initPantalla(arrayPantallas,TAM_PANTALLAS);

    EContratacion arrayContrataciones[TAM_CONTRATACIONES];
    cont_initProductos(arrayContrataciones,TAM_CONTRATACIONES);
    char bufferInt[40];

    do
    {
        val_getUnsignedInt(bufferInt,"\n1-ALTA DE PANTALLA\n2-MODIFICAR DATOS PANTALLA\n3-BAJA DE PANTALLA\n4-CONTRATAR PUBLICACION\n5-MODIFICAR PUBLICACION\n6-CANCELAR CONTRATACION\n7-CONSULTAR FACTURACION\n8-LISTAR CONTRATACIONES\n9-LISTAR PANTALLAS\n10-INFORMES\n11-SALIR\n","\nSolo de 1 a 6\n",2,40);
        switch(atoi(bufferInt))
        {
            case 1:
                pant_cargarPantalla(arrayPantallas,pant_buscarIndicePantallaLibre(arrayPantallas,TAM_PANTALLAS),TAM_PANTALLAS);
                break;
            case 2:
                pant_editarPantalla(arrayPantallas,TAM_PANTALLAS);
                break;
            case 3:
                pant_bajarPantalla(arrayPantallas,TAM_PANTALLAS);
                break;
            case 4:
                pant_printPantalla(arrayPantallas,TAM_PANTALLAS);
                cont_nuevaContratacion(arrayContrataciones,cont_buscarIndiceContratacionLibre(arrayContrataciones,TAM_CONTRATACIONES),TAM_CONTRATACIONES,pant_pideId(arrayPantallas,TAM_PANTALLAS));
                break;
            case 5:
                listaPantallasCliente(arrayContrataciones, TAM_CONTRATACIONES,arrayPantallas, TAM_PANTALLAS);
                cont_editarContratacion(arrayContrataciones,TAM_CONTRATACIONES);
                break;
            case 6:
                listaPantallasCliente(arrayContrataciones, TAM_CONTRATACIONES,arrayPantallas, TAM_PANTALLAS);
                cont_cancelarContratacion(arrayContrataciones,TAM_CONTRATACIONES);
                break;
            case 9:
                pant_printPantalla(arrayPantallas,TAM_PANTALLAS);
                break;
        }

    }while( atoi(bufferInt) != 11);
    return 0;
}
