#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <iostream>

#define L 4
#define t1 "Universidad Catolica Tecnologica del Cibao"
#define t2 "UCATECI"
#define t3 "Estructura de Datos"
#define t4 "Registro de estudiantes"
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


struct Estud
 {
   int id;
   char nombre[30], carrera[3];
   char sexo;
 } vestud, aestud[L];


int x;


void llenar()
{
  int s=1;
   do{
     system("CLS");
     gotoxy(20,8);printf("ID........: "); scanf("%d",&aestud[x].id);
     gotoxy(20,9);printf("Nombre....: "); scanf("%s",&aestud[x].nombre);
     gotoxy(20,10);printf("Carrera...: "); scanf("%s",&aestud[x].carrera);
     gotoxy(20,11);printf("Sexo......: "); scanf("%s",&aestud[x].sexo);
     gotoxy(20,13);printf("Presione 0 para salir | otra tecla continua");scanf("%d",&s);
     
	 if (s==0)
   		break;
     x++;
   }while ( (x<=L) || (s==0) );
}

void ordenar() //metodo de burbujas
 {
 	int i,j;
	//metodo burbuja
	for (i=0; i<=x-1; i++)
   	for (j=i+1; j<=x; j++)
   	{
       if (aestud[i].id > aestud[j].id)
 	   {
  		vestud = aestud[i];
  		aestud[i] = aestud[j];
  		aestud[j] = vestud;
 	   }
 	}
}

void mostrar()
{
  int y;
  system("CLS");
  printf(" ID |  Nombre      | Carrera | Sexo \n");
  printf("====================================\n");
  
  for (y=0;y<=x;y++)
    {
      printf("%d \t %s \t \t%s \t \t %c \n", aestud[y].id, aestud[y].nombre,aestud[y].carrera, aestud[y].sexo);
    }
	system("PAUSE");
}

void mostrarxcarrera()
{
  int y;
  char car[25];
  system("CLS");
  gotoxy(20,5); printf("Carrera a mostrar: "); scanf("%s",&car);
  gotoxy(1,6);
  printf(" ID |  Nombre      | Carrera | Sexo \n");
  printf("====================================\n");

  for (y=0;y<=x;y++)
    if (aestud[y].carrera==car)
    {
     printf("%d \t %s \t \t%s \t \t %c ", aestud[y].id, aestud[y].nombre,aestud[y].carrera, aestud[y].sexo);
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
    gotoxy(20,10); printf("1- Registrar Datos");
    gotoxy(20,11); printf("2- Ordenar");
    gotoxy(20,12); printf("3- Mostrar Todo");
    gotoxy(20,13); printf("4- Mostrar por Carrera");
    gotoxy(20,14); printf("0- Salir");
    gotoxy(20,16); printf("Su opcion: ");scanf("%d",&op);
    switch(op)
      {
	case(1):llenar(); break;
	case(2):ordenar(); break;
	case(3):mostrar(); break;
	case(4): mostrarxcarrera(); break;
	case(0): break;
      }
      
  }while (op!=0);

  system("CLS");

  return 0;

}
