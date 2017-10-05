#ifndef CONTRATACION_H_INCLUDED
#define CONTRATACION_H_INCLUDED

typedef struct
{
    int idContratacion;
    int idPantalla;
    int cuitCliente;
    int diasQueDuraPublicacion;
    char nombreArchivoDelVideo[100];
    int flagDeEstado;
}EContratacion;

#endif // CONTRATACION_H_INCLUDED
#define ESTADO_CONTRATACION_LIBRE 0
#define ESTADO_CONTRATACION_OCUPADA 1
