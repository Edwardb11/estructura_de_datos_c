#include <string.h>
#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <iostream>
#define L 4
#define t1 "Universidad Catolica Tecnologica del Cibao"
#define t2 "UCATECI"
#define t3 "Estructura de Datos"
#define t4 "Manejo de arreglos"
#define t5 "M e n u   P r i n c i p a l"
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

int anum[L],  x, vnum;

void llenar()
{
  int x;
  system("CLS");
  for (x=0; x<=L; x++)
    {
     printf("Introduzca un numero: \n"); scanf("%d",&anum[x]);
    }
}


void ordenar() //metodo de burbujas
{
int i,j;
//metodo burbuja
for (i=0; i<=L-1; i++)
   for (j=i+1; j<=L; j++)
   {
      if (anum[i] > anum[j])
    {
   	  vnum = anum[i];
      anum[i] = anum[j];
      anum[j] = vnum;
    }
   }
 system("PAUSE");
}


void mostrar()
{
  int y;
  system("CLS");
   for (y=0;y<=L;y++)
    {
       printf("%d \n", anum[y]);
    }

  system("PAUSE");

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

int main()
{
  x=0;
  int op=1;
  do{
    system("CLS");
    setcolor(GREEN);
    cuadro(1,78,1,6);
    setcolor(YELLOW);
    gotoxy( (80-strlen(t1))/2, 2);printf(t1);
    gotoxy( (80-strlen(t2))/2, 3);printf(t2);
    gotoxy( (80-strlen(t3))/2, 4);printf(t3);
    gotoxy( (80-strlen(t4))/2, 5);printf(t4);
    setcolor(WHITE);
    cuadro(10,70,7,20);
    gotoxy( (80-strlen(t5))/2, 8);printf(t5);
    gotoxy(20,10); printf("1- Ingresar numeros");
    gotoxy(20,11); printf("2- Ordenar");
    gotoxy(20,12); printf("3- Mostrar ");
    gotoxy(20,14); printf("0- Salir");
    gotoxy(20,16); printf("Su opcion: ");scanf("%d",&op);
    
    switch(op)
	  {
        case(1):llenar(); break;
		case(2):ordenar(); break;
		case(3):mostrar(); break;
		//case(4): mostrarxcarrera(); break;
		case(0): break;

      }

  }while (op!=0);

  system("CLS");

  return 0;

}


