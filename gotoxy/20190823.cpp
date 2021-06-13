#include<stdio.h>
//#include<conio.h>
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

#define t1 "UCATECI"

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

//ASCII = American Standard Code for Information Interchange
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

//Para limpiar la pantalla
void Limpia(int x1, int x2, int y1, int y2)
{
	int x,y;
	for (x=x1;x<=x2;x++)
		for (y=y1;y<=y2;y++)
			{
				gotoxy(x,y); printf(" "); //Alt+ 186
			}
}

//Relleno para los colores
void Relleno(int x1, int x2, int y1, int y2)
{
	int x,y;
	for (x=x1;x<=x2;x++)
		for (y=y1;y<=y2;y++)
			{
				gotoxy(x,y); printf("%c",219);
			}
}

//Bandera de bulgaria
void Bandera()
{
	Limpia(1,80,9,20);

	//color blanco
	setcolor(WHITE);
	Relleno(5,70, 9,12);
	//color verde
	setcolor(GREEN);
	Relleno(5,70, 13,16);
	//color rojo
	setcolor(RED);
	Relleno(5,70, 17,20);
	
	system("PAUSE");	
}

//triangulo lateral izquierdo
void triangulo(){
    int altura =4, k = 0, espacio = 0;  
    gotoxy(1,15); //posicion 
    for(int i = 0; i < altura; ++i){
        for(int j = 0; j < espacio; ++j){
             printf(" ");
        }
        for(int j = 0; j < altura - i; ++j){
           	 setcolor(LIGHTBLUE); printf("%c",219); //color
	         ++k;
        }
        printf("\n");
        printf("");
        ++espacio;
	
    }
    //	gotoxy(1,15);//posicion
}
	

//triangulo lateral derecho 
void triangulo2(){
	int i, espacio, fila=4, k = 0;
	gotoxy(42,15);
	   for (i = 1; i <= fila; ++i) {
	      for (espacio = 1; espacio <= fila - i; ++espacio) {
	         printf(" ");
	      }
	      while (k != 2 * i - 1) {
	        setcolor(LIGHTBLUE); printf("%c",219);
	         ++k;
	      }
	      printf("\n");
	      printf("                                          ");
	  }
	  //gotoxy(60,15);
}
void Barco()
{
	Limpia(1,80,9,20); //limpiar pantalla
	//color azul claro parte abajo 
	setcolor(LIGHTBLUE);
	Relleno(2,43, 15,18); //Relleno sin incluir las esquinas
	
	triangulo2(); //triangulo de la esquina derecha 	
	Relleno(2,43, 15,18); //Relleno sin incluir las esquinas
	triangulo();  //triangulo de la esquina izquierda
	//color rojo parte abajo
//	setcolor(RED);
//	Relleno(4,42,19,19);
	
	//farol
	setcolor(RED);
	Relleno(30,32,10,14);
	setcolor(LIGHTBLUE);
	//capa azul del farol
	Relleno(30,32,9,9);
	
	//cabina
	setcolor(LIGHTGRAY);
	Relleno(10,20,12,14);
	
	//ventana de la cabina
	setcolor(CYAN);
	Relleno(10,12,13,13);
	
	//ventanas en general 
	setcolor(WHITE);
	Relleno(10,10,16,16);
	
	setcolor(WHITE);
	Relleno(14,14,16,16);
	
	setcolor(WHITE);
	Relleno(18,18,16,16);
	
	setcolor(WHITE);
	Relleno(22,22,16,16);
	
	setcolor(WHITE);
	Relleno(26,26,16,16);
	
	setcolor(LIGHTBLUE);
	Relleno(44,44,15,15); //relleno a una brecha de los triangulos
	//color rojo parte abajo
	setcolor(RED);
	Relleno(4,42,19,19);
	
	system("PAUSE");
		
}


//mover caracter 
void MoverCaracter()
{
int x;
	Limpia(1,80,1,30);
	//cuadro(1,80,9,13);
	for (int i = 1; i<=20; i++){
		system("CLS");
		gotoxy(i+x,i);printf("Todo cambia");
		Sleep(30);
		x+=4;
	}
	for (int j=28;j>=1;j--){
		gotoxy(j+x,j);printf("Todo cambia");
		Sleep(30);
		x-=4;
		system("CLS");
	}
	system("PAUSE");

}
//Cupero principal
int main()

{	
	int op = 1;

  do{
    system("CLS");
    cuadro(1,80,0,8); //Primer cuadro
    cuadro(10,70,9,18);// segundo cuadro
    cuadro(1,80,21,25); //tercer cuadro
    setcolor(YELLOW);
    gotoxy(30,1);printf("UNIVERSIDAD CATOLICA DEL CIBAO");
    setcolor(WHITE);
    gotoxy(42,2);printf("UCATECI");
    gotoxy(37,3);printf("Estructura de Datos");
    gotoxy(39,4);printf("Menu Principal");
    //nombres de integrantes
    setcolor(LIGHTBLUE);
    gotoxy(2,6);printf("2019-0823");
    gotoxy(2,7);printf("Edward Brito");
    gotoxy(32,6);printf("2019-0974");
    gotoxy(32,7);printf("Daniel Orrego");
    gotoxy(62,6);printf("2019-1056");
    gotoxy(62,7);printf("Yessica Villavizar");
     
    setcolor(WHITE);
    gotoxy(20,10);  printf("1- Bandera de bulgaria");
    gotoxy(20,11);  printf("2- Figura");
    gotoxy(20,12);  printf("3- Frase");
    gotoxy(20,13); printf("0- Salir");
    gotoxy(20,15); printf("Su opcion..: ");scanf("%d",&op);
    
    switch (op)
    {
    	case 1: Bandera();
    			break;
		case 2: Barco();
    			break;
		case 3: MoverCaracter();
    			break;
	}
	}while(op!=0);

}

