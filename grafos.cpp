#include <iostream>
#include <cstdlib>

struct Nodo
{
    int Dato;
    Nodo *LigaVertice;
    Nodo *LigaArista;
};

typedef Nodo *Registro; // Apuntadores
Registro SigVer, AntVer, CabVer, SigAri, AntAri, Dir1, Dir2;

Registro NuevoVertice(int dat)
{
    Registro regVer = new Nodo;
    regVer->Dato = dat;
    regVer->LigaVertice = nullptr;
    regVer->LigaArista = nullptr;
    return regVer;
}

void InsertarVertice(int dat)
{
    int sw = 0;
    AntVer = CabVer;
    SigVer = CabVer;

    while (SigVer != nullptr && sw == 0)
    {
        if (SigVer->Dato == dat)
        {
            sw = 1;
        }
        else
        {
            AntVer = SigVer;
            SigVer = SigVer->LigaVertice;
        }
    }

    if (sw == 1)
    {
        printf("EL VERTICE YA EXISTE\n");
    }
    else
    {
        if (CabVer == nullptr)
        {
            CabVer = NuevoVertice(dat);
        }
        else
        {
            AntVer->LigaVertice = NuevoVertice(dat);
        }
        printf("VERTICE AGREGADO\n");
    }
}

Registro RecorrerVertice(int dat)
{
    Registro dir = nullptr;
    SigVer = CabVer;

    while (SigVer != nullptr)
    {
        if (SigVer->Dato == dat)
        {
            dir = SigVer;
        }
        SigVer = SigVer->LigaVertice;
    }
    return dir;
}

Registro NuevaArista(int pes)
{
    Registro regAri = new Nodo;
    regAri->Dato = pes;
    regAri->LigaArista = nullptr;
    regAri->LigaVertice = Dir2;
    return regAri;
}

void InsertarArista(int datoDestino)
{
    int pes, sw2 = 0;
    AntAri = Dir1;
    SigAri = Dir1;

    printf("Ingrese el peso de la arista: ");
    while (scanf("%d", &pes) != 1)
    {
        printf("Error: Ingrese un número válido.\n");
        while (getchar() != '\n'); // Limpiar el buffer de entrada
    }

    while (SigAri != nullptr && sw2 == 0)
    {
        if (SigAri->Dato == datoDestino)
        {
            sw2 = 1;
        }
        else
        {
            AntAri = SigAri;
            SigAri = SigAri->LigaArista;
        }
    }

    if (sw2 == 1)
    {
        printf("LA ARISTA YA EXISTE\n");
    }
    else
    {
        AntAri->LigaArista = NuevaArista(pes);
    }
}

void VerLista()
{
    printf("\n\n VER LISTA  DE VERTICES Y ARISTAS");
    SigVer = CabVer;

    while (SigVer != nullptr)
    {
        printf("\n EL NODO:  ");
        printf("%d", SigVer->Dato);
        printf(" TIENE LOS SIGUIENTES VERTICES COMO ARISTAS: ");
        SigAri = SigVer->LigaArista;
        while (SigAri != nullptr)
        {
            printf(" ");
            Dir1 = SigAri->LigaVertice;
            printf("%d", Dir1->Dato);
            SigAri = SigAri->LigaArista;
        }
        SigVer = SigVer->LigaVertice;
    }
}

int main()
{
    CabVer = nullptr;
    int datoOrigen, datoDestino;
    int sw, opcion;

    do
    {
        printf("\n\tSELECCIONE LA OPCION A REALIZAR \n\n");
        printf("1) CREAR VERTICE\n");
        printf("2) CREAR ARISTAS\n");
        printf("3) MOSTRAR GRAFO\n");
        printf("0) SALIR\n");
        printf("\n Ingrese su opcion: ");
        while (scanf("%d", &opcion) != 1)
        {
            printf("Error: Ingrese un número válido.\n");
            while (getchar() != '\n'); // Limpiar el buffer de entrada
        }

        switch (opcion)
        {
        case 1:
            printf("INGRESE UN NUMERO PARA EL VERTICE: ");
            while (scanf("%d", &datoOrigen) != 1)
            {
                printf("Error: Ingrese un número válido.\n");
                while (getchar() != '\n'); // Limpiar el buffer de entrada
            }
            InsertarVertice(datoOrigen);
            system("pause");
            break;

        case 2:
            printf("INGRESE EL NODO DE ORIGEN: ");
            while (scanf("%d", &datoOrigen) != 1)
            {
                printf("Error: Ingrese un número válido.\n");
                while (getchar() != '\n'); // Limpiar el buffer de entrada
            }
            printf("INGRESE EL NODO DEL DESTINO: ");
            while (scanf("%d", &datoDestino) != 1)
            {
                printf("Error: Ingrese un número válido.\n");
                while (getchar() != '\n'); // Limpiar el buffer de entrada
            }
            Dir1 = RecorrerVertice(datoOrigen);
            Dir2 = RecorrerVertice(datoDestino);
            if (Dir1 == nullptr || Dir2 == nullptr)
            {
                printf("\nEL NODO DE ORIGEN O EL NODO DE DESTINO NO EXISTE\n");
            }
            else
            {
                InsertarArista(datoDestino);
            }
            system("pause");
            break;

        case 3:
            VerLista();
            printf("\n\n");
            system("pause");
            break;

        case 0:
            break;

        default:
            printf("INGRESE UNA OPCION VALIDA\n");
            system("pause");
            break;
        }

        system("cls");
    } while (opcion != 0);

    printf("\nVUELVA PRONTO:)");
    return 0;
}
