#include <string.h>
#include <stdio.h>
#include <conio.h>
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
char t1[]= "Universidad Catolica del Cibao",
     t2[]= "Estructura de datos",
     t3[]= "Menu Principal";

void setcolor( unsigned short color ){
    HANDLE hCon = GetStdHandle( STD_OUTPUT_HANDLE );
    SetConsoleTextAttribute( hCon, color );
}

void gotoxy( short x, short y ){
    HANDLE hConsoleOutput;
    COORD Cursor_an_Pos = { x, y };
    hConsoleOutput = GetStdHandle( STD_OUTPUT_HANDLE );
    SetConsoleCursorPosition( hConsoleOutput, Cursor_an_Pos );
}

void cuadro(int x1, int x2, int y1, int y2)
{
  int x,y;
  for (x=x1;x<=x2;x++)
    {
      gotoxy(x,y1); printf("%c",205);
      gotoxy(x,y2); printf("%c",205);
    }

  for (y=y1;y<=y2;y++)
    {
      gotoxy(x1,y); printf("%c",186);
      gotoxy(x2,y); printf("%c",186);
    }
      gotoxy(x1,y1); printf("%c",201);
      gotoxy(x2,y1); printf("%c",187);
      gotoxy(x1,y2); printf("%c",200);
      gotoxy(x2,y2); printf("%c",188);

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
struct pila{
	char matricula[10], promedio[3];
	char nombre[20];
	char carrera[3];
	struct pila *ant;
}

*CAB=NULL,
*AUX=NULL;

int main(){
    int Opcion = 1, Tecla;
    do{
        do{
            system("CLS");
             cuadro(1,78,1,6);
            setcolor(YELLOW);
                cuadro(10,70,7,20);
            		gotoxy( (80-strlen(t1)) / 2,2); printf(t1);
		gotoxy( (80-strlen(t2)) / 2,3); printf(t2);
		gotoxy( (80-strlen(t3)) / 2,4); printf(t3);
    gotoxy(32,5);printf("Edward Brito Diaz");

                  setcolor(YELLOW);
            gotoxy(20, 10); printf(Mensaje1);
            gotoxy(20, 11); printf(Mensaje2 "%co", 164);
            gotoxy(20, 12); printf(Mensaje3);
            gotoxy(20, 13); printf(Mensaje4);
            gotoxy(20, 14); printf(Mensaje5);
            gotoxy(20, 15); printf(Mensaje6 "%ca", 161);
            gotoxy(20, 16); printf(Mensaje7);
            gotoxy(20, 17); printf(Mensaje8);

            switch(Opcion){
                case 1:
                    setcolor(WHITE); 
					gotoxy(20, 10); 
					printf(Mensaje1);
                    break;

                case 2:
                    setcolor(WHITE); 
					gotoxy(20, 11); 
					printf(Mensaje2 "%co", 164);
                    break;

                case 3:
                    setcolor(WHITE); 
					gotoxy(20, 12); 
					printf(Mensaje3);
                    break;

                case 4:
                    setcolor(WHITE); gotoxy(20, 13); printf(Mensaje4);
                    break;

                case 5:
                    setcolor(WHITE); gotoxy(20, 14); printf(Mensaje5);
                    break;

                case 6:
                    setcolor(WHITE); gotoxy(20, 15); printf(Mensaje6 "%ca", 161);
                    break;

                case 7:
                    setcolor(WHITE); gotoxy(20, 16); printf(Mensaje7);
                    break;
                case 8:

                    setcolor(WHITE); gotoxy(20, 17); printf(Mensaje8);
            }

            do
                Tecla = getch();
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

void Crear(){
    Posicion = Maximo;
    system("CLS");

    printf("Pila creada.");
    getch();
}



void Tamanio()

{
    system("CLS");
    if(Posicion == Maximo + 1)
        printf("Pila no creada.");
        else
            printf("%i", Maximo - Posicion);
    getch();
}

void Apilar(){
    system("CLS");
    if(Posicion == Maximo + 1)
        printf("Pila no creada.");
        else
            if(Posicion == Maximo - Maximo)
                printf("Pila llena.");
            else{
                AUX=(struct pila *)malloc(sizeof(struct pila));
				system("CLS");
				printf("Matricula: ");
				gets(AUX->matricula);
				printf("Nombre: ");
				gets(AUX->nombre);
				printf("Carrera: ");
				gets(AUX->carrera);
				printf("Promedio cuatrimestral: ");
				gets(AUX->promedio);
				
				if (CAB==NULL)
				
				{
				CAB=AUX;
				AUX->ant=NULL;
				}
				else
				{
				AUX->ant=CAB;
				
				CAB=AUX;
				}
                Posicion--;
            }
    getch();
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
                if (CAB==NULL)
				   return;
				AUX=CAB;
				CAB=CAB->ant;
				free(AUX);
                printf("Elemento desapilado.");
            }
    getch();
}

void Cima(){

    system("CLS");
    if(Posicion == Maximo + 1)
        printf("Pila no creada.");
        else
            if(Posicion == Maximo)
                printf("Pila vac%ca.", 161);
            else
                if (CAB==NULL)
				  return;
				system("CLS");
				AUX=CAB;
				while (AUX!=NULL)
				{
				
				printf("Matricula: %s\n",AUX->matricula);
				printf("Nombre: %s\n",AUX->nombre);
				printf("Carrera: %s\n",AUX->carrera);
				printf("Promedio Cuatrimestral: %s\n",AUX->promedio);
				AUX=AUX->ant;
				}
    getch();
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
    getch();

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
                if (CAB==NULL)
				  return;
				system("CLS");
				AUX=CAB;
				while (AUX!=NULL)
				{
				printf("Matricula: %s\n",AUX->matricula);
				printf("Nombre: %s\n",AUX->nombre);
				printf("Carrera: %s\n",AUX->carrera);
				printf("Promedio Cuatrimestral: %s\n",AUX->promedio);
				AUX=AUX->ant;	
			}		
    getch();
}

void Salir()
{
    system("CLS");
    printf("%cGracias, regrese pronto!", 173);
    getch();

}
