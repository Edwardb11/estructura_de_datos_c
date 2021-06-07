//#include <conio.h>
#include <stdio.h>
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

void Limpia(int x1, int x2, int y1, int y2)
{
	int x,y;
	for (x=x1;x<=x2;x++)
		for (y=y1;y<=y2;y++)
			{
				gotoxy(x,y); printf(" "); //Alt+ 186
			}
}

void Relleno(int x1, int x2, int y1, int y2)
{
	int x,y;
	for (x=x1;x<=x2;x++)
		for (y=y1;y<=y2;y++)
			{
				gotoxy(x,y); printf("%c",219);
			}
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

void MoverCaracter()
{
	Limpia(1,80,7,20);
	cuadro(1,80,8,12);
	for (int i = 2; i<=78; i++)
	{
		gotoxy(i,10); printf(" %c",219);
		Sleep(75);
	}
}

void MoverCaracterAlrevez()
{
	Limpia(1,80,7,20);
	cuadro(1,80,8,12);
	for (int i = 78; i>=2; i--)
	{
		gotoxy(i,10); printf("El mundo es mio ",219);
		Sleep(75);
	}

}

void ArribaAbajo()
{
	Limpia(1,80,7,20);
	cuadro(1,80,8,12);

		for (int i = 2; i<=30; i++)
	{
		gotoxy(10,i); printf(" ",219);
		Sleep(75);}
		for (int i = 30; i>=2; i--)
	{
		gotoxy(15,i); printf(" ",219);
		Sleep(75);
	}

}
void Cuadros(){
	system("CLS");
	int x= 21,x2=55,y=4,y2=18;

	for (int i=1;i<=7;i++){
	
	cuadro(x,x2,y,y2);
	x++;
	x2--;
	y++;
	y2--;
	Sleep(100);
}

printf("\n\n\n\n\n\n\n\n\n");
system("PAUSE");
}

void CaracterAbajo()
{
	gotoxy(20,22); printf("Entre a Caracter Abajo");

	system("PAUSE");
}

void Bandera()
{
	Limpia(1,80,7,20);
	setcolor(WHITE);
	Relleno(5,55, 8,20);
	
	setcolor(BLUE);
	Relleno(5,25, 8,12);
	
	setcolor(RED);
	Relleno(5,25, 16,20);
	
	setcolor(BLUE);
	Relleno(33,55, 16,20);
	
	setcolor(RED);
	Relleno(33,55, 8,12);
	system("PAUSE");	
}

int main()

{	
	int op = 1;

  do{
    system("CLS");
    cuadro(1,80,1,6);
    cuadro(10,70,8,18);
    cuadro(1,80,21,25);
    setcolor(YELLOW);
    gotoxy(30,2);printf("UNIVERSIDAD CATOLICA DEL CIBAO");
    setcolor(WHITE);
    gotoxy(42,3);printf("UCATECI");
    gotoxy(30,4);printf("Laboratorio de Estructura de Datos");
    gotoxy(39,5);printf("Menu Principal");
    setcolor(WHITE);
    gotoxy(20,9);  printf("1- Mover caracter");
    gotoxy(20,10); printf("2- caracter abajo");
    gotoxy(20,11); printf("3- Bandera");
    gotoxy(20,12); printf("4- Mover Caracter Alrevez ");
    gotoxy(20,13); printf("5- Mover de arriba hacia abajo");
    gotoxy(20,14); printf("6- Cuadros");
    gotoxy(20,15); printf("0- Salir");
    gotoxy(20,16); printf("Su opcion..: ");scanf("%d",&op);
    
    switch (op)
    {
    	case 1: MoverCaracter();
    			break;
    	case 2: CaracterAbajo();
    			break;
    	case 3: Bandera();
				break;
		case 4: MoverCaracterAlrevez();
				break;	
		case 5: ArribaAbajo();
				break;	
		case 6: Cuadros();
				break;			
	}
	}while(op!=0);

}
