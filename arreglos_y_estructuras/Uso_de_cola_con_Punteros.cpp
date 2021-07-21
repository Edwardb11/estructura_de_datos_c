/* Ejemplo de una cola. */
#include <string.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <iostream>

#define BLACK 0x00
#define BLUE 0x01
#define GREEN 0x02
#define CYAN 0x03
#define RED 0x04
#define MAGENTA 0x05
#define BROWN 0x06
#define LIGHTGRAY 0x07
#define DARKGRAY 0x08
#define LIGHTBLUE 0x09
#define LIGHTGREEN 0x0A
#define LIGHTCYAN 0x0B
#define LIGHTRED 0x0C
#define LIGHTMAGENTA 0x0D
#define YELLOW 0x0E
#define WHITE 0x0F

#define Mensaje2 "Recibir datos de los Estudiantes"
#define Mensaje3 "Informacion de la cola"
#define Mensaje4 "Datos recibidos de  los estudiantes"
#define Mensaje5 "Sacar Estudiante"
#define Mensaje6 "Ultimo Estudiante"
#define Mensaje7 "Salir"
#define Mensaje8 "Cantidad De Registros"

char t1[]= "Universidad Catolica del Cibao",
     t2[]= "Estructura de datos",
     t3[]= "Menu Principal";


void setcolor(unsigned short color){

    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(hCon, color);
}

void gotoxy(short x, short y)

{

    HANDLE hConsoleOutput;

    COORD Cursor_an_Pos = {x, y};

    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}
void cuadro(int x1, int x2, int y1, int y2)

{
    int x, y;
    for (x = x1; x <= x2; x++)
    {
        gotoxy(x, y1);
        printf("%c", 205);
        gotoxy(x, y2);
        printf("%c", 205);
    }

    for (y = y1; y <= y2; y++)

    {
        gotoxy(x1, y);
        printf("%c", 186);
        gotoxy(x2, y);
        printf("%c", 186);
    }

    gotoxy(x2, y1);
    printf("%c", 187);
    gotoxy(x2, y2);
    printf("%c", 188);
    gotoxy(x1, y1);
    printf("%c", 201);
    gotoxy(x1, y2);
    printf("%c", 200);
}

int cantidad=0;


void insertar();
void vacia();
void extraer();
void visualizar();
void Mostrar();
void Salir();
void mostrar();
void cantidades();
void ultimo();

struct cola
{
char nombre[200],matricula[20],carrera[3];
float indice;
struct cola *sig;
}
    *CAB = NULL,
    *AUX = NULL, *FIN = NULL;
    
int main()
{
    int Opcion = 1, Tecla;
    do
    {
        do
        {
         system("CLS");
             cuadro(1,78,1,6);
            setcolor(YELLOW);
              cuadro(5,75,7,20);
            		gotoxy( (80-strlen(t1)) / 2,2); printf(t1);
		gotoxy( (80-strlen(t2)) / 2,3); printf(t2);
		gotoxy( (80-strlen(t3)) / 2,4); printf(t3);
    gotoxy(32,5);printf("Edward Brito Diaz");

            setcolor(LIGHTBLUE);
            gotoxy(10, 11);
            printf(Mensaje2);
            gotoxy(10, 12);
            printf(Mensaje3);
            gotoxy(10, 13);
            printf(Mensaje4);
            gotoxy(10, 14);
            printf(Mensaje5);
            gotoxy(10, 15);
            printf(Mensaje8);
            gotoxy(10, 16);
            printf(Mensaje6);
            gotoxy(10, 17);
            printf(Mensaje7);

            switch (Opcion)
            {

            case 1:
                setcolor(WHITE);
                gotoxy(10, 11);
                printf(Mensaje2);
                break;

            case 2:
                setcolor(WHITE);
                gotoxy(10, 12);
                printf(Mensaje3);
                break;

            case 3:
                setcolor(WHITE);
                gotoxy(10, 13);
                printf(Mensaje4);
                break;

            case 4:
                setcolor(WHITE);
                gotoxy(10, 14);
                printf(Mensaje5);
                break;

            case 5:

                setcolor(WHITE);
                gotoxy(10, 15);
                printf(Mensaje8);
                break;
            case 6:

                setcolor(WHITE);
                gotoxy(10, 16);
                printf(Mensaje6);
                break;

            case 7:
                setcolor(WHITE);
                gotoxy(10, 17);
                printf(Mensaje7);
                break;
            }
            do
                Tecla = getch();

            while (Tecla != 13 && Tecla != 72 && Tecla != 80);
            if (Tecla == 72)
            {
                if (Opcion == 1)
                    Opcion = 7;
                else if (Opcion > 1)
                    Opcion--;
            }

            else if (Tecla == 80)
                if (Opcion ==7)
                    Opcion = 1;
                else if (Opcion < 7)
                    Opcion++;

        } while (Tecla != 13);

        switch (Opcion)
        {
    
        case 1:
            insertar();
            break;

        case 2:
            vacia();
            break;

        case 3:
            visualizar();
            break;

        case 4:
            extraer();
            break;

        case 5:
            cantidades();
            break;
            
        case 6:
        	ultimo();
            
            break;
        }

    } while (Opcion != 7);
    Salir();
    return 0;
}

void cantidades(){
	system("CLS");
	setcolor(YELLOW);
	printf("%i Estudiante registrado dentro de la cola",cantidad);
	setcolor(WHITE);
	getch();
}

void ultimo()
{
    if (CAB == NULL)
{
    system("CLS");
    setcolor(YELLOW);
    printf("La cola  esta vacia!");
    setcolor(WHITE);
    getch();
}
    else
    {
        mostrar();
    }
}

void Salir(){
	system("CLS");
    setcolor(YELLOW);
    printf("%cGracias, regrese pronto!", 173);
    getch();
}

void mostrar()
{
    if (CAB == NULL)
        return;
    system("CLS");
    AUX = CAB;
    setcolor(YELLOW);
    gotoxy(30,2);printf("Estudiante Registrado\n\n");
    setcolor(WHITE);
    gotoxy(5,5);printf("Nombre: %s\n", AUX->nombre);
    gotoxy(5,6);printf("Carrera: %s\n", AUX->carrera);
    gotoxy(5,7);printf("Matricula: %s\n", AUX->matricula);
    gotoxy(5,8);printf("Indice Academico: %.2f\n", AUX->indice);
    getch();
}
	
void insertar(void)
{
    AUX = (struct cola *)malloc(sizeof(struct cola));
    system("CLS");
    setcolor(YELLOW);
    gotoxy(49,2);printf("Registro de Estudiantes\n\n");
    setcolor(WHITE);
    gotoxy(5,5);printf("Nombre : ");
	fflush(stdin);gets(AUX->nombre);
    gotoxy(5,6);printf("Carrera: ");
	fflush(stdin);gets(AUX->carrera);
    gotoxy(5,7);printf("Matricula: ");
	fflush(stdin);gets(AUX->matricula);
    gotoxy(5,8);printf("Promedio: ");
	scanf("%f",&AUX->indice);
	
    AUX->sig = NULL;
    if (FIN == NULL)
        FIN = CAB = AUX;
    else
    {
        FIN->sig = AUX;
        FIN = AUX;
    }
    cantidad++;
}

void extraer(void)
{
    if (CAB == NULL)
        return;
    AUX = CAB;
    CAB = CAB->sig;
    free(AUX);
    cantidad--;
}

void visualizar(void)
{
    if (CAB == NULL)
        return;
    system("CLS");
    setcolor(YELLOW);
    gotoxy(49,2);printf("Estudiantes Registrados\n\n");
    AUX = CAB;
    while (AUX != NULL)
    {
    	
   setcolor(WHITE);
   printf("\nNombre: %s", AUX->nombre);
   printf("\nCarrera: %s", AUX->carrera);
   printf("\nMatricula: %s", AUX->matricula);
   printf("\nIndice Academico: %.2f\n\n", AUX->indice);
   AUX = AUX->sig;
    }
    getch();
}
void vacia(void)
{
    system("CLS");
    if (CAB == NULL)
    {
        gotoxy(28, 5);
        setcolor(YELLOW);
        printf("Cola Vacia");
        setcolor(WHITE);
    }
    else
    {
        gotoxy(28, 5);
        setcolor(LIGHTMAGENTA);
        printf("Cola con %i Registros", cantidad);
        setcolor(WHITE);
    }
    getch();
}
