#include <stdio.h>

//#include <conio.h>

#include <string.h>

#include <windows.h>

#include <stdlib.h>

#include <iostream>



#define BLACK         0x00

#define BLUE          0x01

#define GREEN         0x02

#define CYAN          0x03

#define RED           0x04

#define MAGENTA       0x05

#define BROWN         0x06

#define LIGHTGRAY     0x07

#define DARKGRAY      0x08

#define LIGHTBLUE     0x09

#define LIGHTGREEN    0x0A

#define LIGHTCYAN     0x0B

#define LIGHTRED      0x0C

#define LIGHTMAGENTA  0x0D

#define YELLOW        0x0E

#define WHITE         0x0F



#define Mensaje1 "Crear"

#define Mensaje2 "Tama"

#define Mensaje3 "Apilar"

#define Mensaje4 "Desapilar"

#define Mensaje5 "Cima"

#define Mensaje6 "Vac"

#define Mensaje7 "Mostrar"

#define Mensaje8 "Salir"

#define Maximo 5



void setcolor( unsigned short color )

{

    HANDLE hCon = GetStdHandle( STD_OUTPUT_HANDLE );

    SetConsoleTextAttribute( hCon, color );

}



void gotoxy( short x, short y )

{

    HANDLE hConsoleOutput;

    COORD Cursor_an_Pos = { x, y };

    hConsoleOutput = GetStdHandle( STD_OUTPUT_HANDLE );

    SetConsoleCursorPosition( hConsoleOutput, Cursor_an_Pos );

}



void Crear();

void Tamanio();

void Apilar();

void Desapilar();

void Cima();

void Vacia();

void Mostrar();

void Salir();



int Posicion = Maximo + 1, Pila[Maximo], I;



int main()

{

    int Opcion = 1, Tecla;



    do

    {

        do

        {

            system("CLS");

            setcolor(YELLOW);

            gotoxy(1, 1); printf(Mensaje1);

            gotoxy(1, 2); printf(Mensaje2 "%co", 164);

            gotoxy(1, 3); printf(Mensaje3);

            gotoxy(1, 4); printf(Mensaje4);

            gotoxy(1, 5); printf(Mensaje5);

            gotoxy(1, 6); printf(Mensaje6 "%ca", 161);

            gotoxy(1, 7); printf(Mensaje7);

            gotoxy(1, 8); printf(Mensaje8);



            switch(Opcion)

            {

                case 1:

                    setcolor(WHITE); gotoxy(1, 1); printf(Mensaje1);

                    break;

                case 2:

                    setcolor(WHITE); gotoxy(1, 2); printf(Mensaje2 "%co", 164);

                    break;

                case 3:

                    setcolor(WHITE); gotoxy(1, 3); printf(Mensaje3);

                    break;

                case 4:

                    setcolor(WHITE); gotoxy(1, 4); printf(Mensaje4);

                    break;

                case 5:

                    setcolor(WHITE); gotoxy(1, 5); printf(Mensaje5);

                    break;

                case 6:

                    setcolor(WHITE); gotoxy(1, 6); printf(Mensaje6 "%ca", 161);

                    break;

                case 7:

                    setcolor(WHITE); gotoxy(1, 7); printf(Mensaje7);

                    break;

                case 8:

                    setcolor(WHITE); gotoxy(1, 8); printf(Mensaje8);

            }



            do

                Tecla = system("PAUSE");

            while(Tecla != 13 && Tecla != 72 && Tecla != 80);



            if(Tecla == 72)

            {

                if(Opcion == 1)

                    Opcion = 8;

                else

                    if(Opcion > 1)

                        Opcion--;

            }

            else

                if(Tecla == 80)

                    if(Opcion == 8)

                        Opcion = 1;

                    else

                        if(Opcion < 8)

                            Opcion++;

        }while(Tecla != 13);



        switch(Opcion)

        {

            case 1:

                Crear();

                break;

            case 2:

                Tamanio();

                break;

            case 3:

                Apilar();

                break;

            case 4:

                Desapilar();

                break;

            case 5:

                Cima();

                break;

            case 6:

                Vacia();

                break;

            case 7:

                Mostrar();

                break;

        }

    }while(Opcion != 8);



    Salir();

    return 0;

}



void Crear()

{

    Posicion = Maximo;



    system("CLS");

    printf("Pila creada.");

    system("PAUSE");

}



void Tamanio()

{

    system("CLS");



    if(Posicion == Maximo + 1)

        printf("Pila no creada.");

        else

            printf("%i", Maximo - Posicion);



   system("PAUSE");

}



void Apilar()

{

    system("CLS");



    if(Posicion == Maximo + 1)

        printf("Pila no creada.");

        else

            if(Posicion == Maximo - Maximo)

                printf("Pila llena.");

            else

            {

                printf("Elemento: "); scanf("%i", &Pila[Posicion]);

                system("CLS");

                printf("Elemento apilado.");



                Posicion--;

            }



   system("PAUSE");

}



void Desapilar()

{

    system("CLS");



    if(Posicion == Maximo + 1)

        printf("Pila no creada.");

        else

            if(Posicion == Maximo)

                printf("Pila vac%ca.", 161);

            else

            {

                Posicion++;

                Pila[Posicion] = -999999999;



                printf("Elemento desapilado.");

            }



   system("PAUSE");

}



void Cima()

{

    system("CLS");



    if(Posicion == Maximo + 1)

        printf("Pila no creada.");

        else

            if(Posicion == Maximo)

                printf("Pila vac%ca.", 161);

            else

                printf("%i", Pila[Posicion + 1]);



system("PAUSE");

}



void Vacia()

{

    system("CLS");



    if(Posicion == Maximo + 1)

        printf("Pila no creada.");

    else

        if(Posicion == Maximo)

            printf("Cierto.");

        else

            printf("Falso.");



   system("PAUSE");

}



void Mostrar()

{

    system("CLS");



    if(Posicion == Maximo + 1)

        printf("Pila no creada.");

        else

            if(Posicion == Maximo)

                printf("Pila vac%ca.", 161);

            else

                for(I = 1; I <= Maximo; I++)

                {

                    if(Pila[I] == -999999999)

                    {

                        gotoxy(1, I); printf("0");

                    }

                    else

                    {

                        gotoxy(1, I); printf("%i", Pila[I]);

                    }

                }



   system("PAUSE");

}



void Salir()

{

    system("CLS");

    printf("%cGracias, regrese pronto!", 173);

  system("PAUSE");

}


