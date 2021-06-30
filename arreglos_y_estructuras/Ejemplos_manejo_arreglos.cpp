#include <string.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include <time.h>
#include <dos.h>
#include <windows.h>
#include <iostream>

#define L 4
#define palabras 100
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


void cuadro(int x1, int x2, int y1, int y2)
{
	int x,y;
	//crear las lineas horizontales
	for (x=x1;x<=x2;x++)
	{
		gotoxy(x,y1); printf("%c",205); //Alt+ 205
		gotoxy(x,y2); printf("%c",205); //Alt+ 205
		//Sleep(100);
	}

	//crear las lineas verticales
	for (y=y1;y<=y2;y++)
	{
		gotoxy(x1,y); printf("%c",186); //Alt+ 186
		gotoxy(x2,y); printf("%c",186); //Alt+ 186
	}

	gotoxy(x2,y1); printf("%c",187); //esquina superior derecha
	gotoxy(x2,y2); printf("%c",188); //esquina inferior derecha
	gotoxy(x1,y1); printf("%c",201); //esquina superior izquierda
	gotoxy(x1,y2); printf("%c",200); //esquinasinferior izquierda

}


int a1[L], op;
int a2[L];
char t1[]= "Universidad Catolica del Cibao",
     t2[]= "Estructura de datos",
     t3[]= "Menu Principal";

void LlenaArreglo()
{

	int x;
	system("CLS");
	printf("Llenando los arreglos\n");
	for (x=0; x<=L; x++)
	{
		printf("Valor del arreglo1[%i]: ",x+1);scanf("%d", &a1[x]);
		printf("\nValor del arreglo2[%i]: ",x+1);scanf("%d", &a2[x]);
	}
 system("PAUSE");
}

void mostrardatos()
{
	system("CLS");
	int x;
	gotoxy(20,5); printf("Mostrando las operaciones con los arreglos \n");
	gotoxy(5,7); printf(" Arr1    Arr2    Suma     Resta  Producto  Division\n");
	for (x=0; x<=L; x++)
	{
		printf("[%i]:\t%d \t%d \t%d \t%d \t%d  \t%d \n",x+1,a1[x],a2[x],(a1[x]+a2[x]),(a1[x]-a2[x]),(a1[x]*a2[x]),(a1[x]/a2[x]));
	}
system("PAUSE");

}


int main()
{
	int op=0;
	do{
		system("CLS");
		cuadro(1,79,1,5);
		gotoxy( (80-strlen(t1)) / 2,2); printf(t1);
		gotoxy( (80-strlen(t2)) / 2,3); printf(t2);
		gotoxy( (80-strlen(t3)) / 2,4); printf(t3);
		gotoxy(25,7); printf("1- Llenar arreglos");
		gotoxy(25,8); printf("2- Mostrar operaciones con arreglo");
		gotoxy(25,9); printf("3- Factorial");
		gotoxy(25,10); printf("0- Salir");
		gotoxy(25,11); printf("Opcion: "); scanf("%d",&op);
switch (op)

	{
	case 1: LlenaArreglo(); break;
	case 2: mostrardatos(); break;
	//case 3: break;
	case 0: gotoxy(10,24); printf("Gracias por utilizar este programa. Pulse una tecla. ");
	system("PAUSE"); break;

}

}while (op!=0); 

return 0;

}
