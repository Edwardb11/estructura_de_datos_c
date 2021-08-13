#include<conio.h>
#include<dos.h>
#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <windows.h> 
#include <cstring> 
using namespace std;
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
//funcion para poder usar el gotoxy
 void gotoxy(int x,int y){  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
 }  
 
void setcolor( unsigned short color ){

    HANDLE hCon = GetStdHandle( STD_OUTPUT_HANDLE );
    SetConsoleTextAttribute( hCon, color );
}
 //Estructura que almacena los datos de los empleados
 struct Empleados
{
char idEmpleado[20];
char nombre[20];
char telefono[20];
char ciudad[20];
char estado[20];

Empleados *sig;//punterdo que permite avanzar hacia adelante

}
//punteros de la estructura de empleados
*primero_empleados=NULL,
*cola_empleados=NULL,
*fin_empleados=NULL;
int cantidad_empleados=0;

//estructura para almacenar los datos de las cuentas
struct cuentas
{
char numcuenta[20];
char idempleado[20];
char fecha[20];
char tipomovimiento[20];
char monto[20];
char concepto[20];
cuentas *sig;//punterdo que permite avanzar hacia adelante
}
//punteros de la estructura de cuentas
*primero_cuentas=NULL,
*cola_cuentas=NULL,
*fin_cuentas=NULL;
int cantidad_cuentas=0;


void Salir();
void barra();
void borrarE();
void registar();
void agregar();
void agregarcuenta();  
void buscar();
void editar();
void consultar();
void eliminar();
void menu();
void menu_modificar();
void consultarcuentas();
//Informacion
char t1[]= "-----------------Examen Final-----------------", 
t3[]= "______________________",
t4[]= "Marcos Matias",
t5[]= "2019-0866",
t6[]= "Julio Enrique ",
t7[]= "2019-0828",
esp[]= "                    ",
BIEN[]= "VALIDO",
ini[]= "INICIO DE SESION",
MAL[]= "ERRONEO";

//definiendo las opciones del menu
#define M1 "1-Registro de Empleado"
#define M2 "2-Buscar editar y elimina empleado"
#define M3 "3-Registros de movimientos cuentas"
#define M4 "4-Consultas de empleados"
#define M5 "5-Consultas de movimientos cuenta"
#define M6 "0-Cerrar el programa"




int main()
{
	
	int x, y, p=1,cont=3,final=0;
	char usua[10],contra[10];
	


	do
	{	
		//Inicio de sesion
		x= 30, y= 5;
		setcolor(LIGHTCYAN);
		gotoxy( (80-strlen(ini)) / 1.25,7); printf(ini);
		
		gotoxy( 50,8); printf("____");		
		gotoxy( 39,11); printf("           ");
		gotoxy( 50,11); printf("Usuario: ");

		gotoxy( 43,13); printf("       ");
		gotoxy( 50,13); printf("Contrase%ca: ",164);
		gotoxy( 50,15); printf("____");		

		gotoxy( 60,11);gets(usua); fflush(stdin);
		gotoxy( 63,13);gets(contra); fflush(stdin);
		
	
		if(strcmp(usua,"admin")==0 && strcmp(contra,"admin")==0)
		{
			
			gotoxy( (80-strlen(esp)) / 1.25,17); printf(esp); gotoxy(30,19);printf("%c",179);//Borrar intentos
		
			gotoxy( (80-strlen(BIEN)) / 1.25,17); printf(BIEN);//CORRECTO
			Sleep(500);
			final=1;

		}
		else
		{
			cont-=1;
			
			gotoxy( (80-strlen(MAL)) / 1.25,17); printf(MAL);//INCORRECTO			
		
			gotoxy(51,19); printf("Intentos disponibles %i",cont);gotoxy(80,25);//intentos		
			getch();

			gotoxy( (80-strlen(esp)) / 1.25,17); printf(esp);//borra incorrecto
			
			if(cont==0)
			{
				Salir();
			}

		}
	}while(final==0);//INICIO DE SESION
	
	
 	system("cls");
	for(int X=40 ; X<=80 ; X++)//CUADRO DE CARGA
	{
		
		gotoxy(X,19);printf("%c",205);
		gotoxy(X,16);printf("%c",205);
	}
	gotoxy(40,16);printf("%c",201);//esquina superior Izquierda
	gotoxy(40,19);printf("%c",200);//esquina inferior Izquierda
	gotoxy(80,16);printf("%c",187);//esquina superior derecha
	gotoxy(80,19);printf("%c",188);//esquina inferior derecha
	
	gotoxy(80,18);printf("%c",186);
	gotoxy(80,17);printf("%c",186);//palos verticales
	gotoxy(40,18);printf("%c",186);
	gotoxy(40,17);printf("%c",186);
		
	
	int carga=41;

		
	for(carga=41;carga<=79;carga++)	
	{
		
		gotoxy(carga,17);printf("%c",186);
		gotoxy(carga,18);printf("%c",186);
		Sleep(100);
	}

	menu();//llamando al menu principal
}

void menu(){//menu principal
	system("cls");
	int Opcion = 1, Tecla;
    system("cls");
    fflush(stdin);
    
	gotoxy( (90-strlen(t1)) / 2,2); printf(t1); 
	gotoxy( (90-strlen(t3)) / 2,3); printf(t3);
	
	gotoxy( (95-strlen(t4)) / 4,4); printf(t4);
	gotoxy( ((95-strlen(t5)) / 4) + 35 ,4); printf(t5);
	
	gotoxy( (95-strlen(t6)) / 4,5); printf(t6);
	gotoxy( ((95-strlen(t7)) / 4) + 35 ,5); printf(t7);
	


	

    do
    {
		do
		{
		    int x=5, y =1;
			for(x=5;x<=90;x++)
			{
				gotoxy(x,y);printf("%c",196);
				gotoxy(x,y+5);printf("%c",196);
				gotoxy(x,y+22);printf("%c",196);
				
				
			}
			x=4;
			for(y=2;y<=23;y++)
			{
				gotoxy(x,y);printf("%c",179);
				gotoxy(x+86,y);printf("%c",179);
			}
			x=40;
			for(y=7;y<=23;y++)
			{
				gotoxy(x,y);printf("%c",179);
			}
		
			gotoxy(4,1);printf("%c",218);
			gotoxy(90,1);printf("%c",191);
			

			gotoxy(4,6);printf("%c",195);
			gotoxy(90,6);printf("%c",180);
			gotoxy(40,6);printf("%c",194);
			

		
			gotoxy( (70-strlen(" Menu Principal "))/ 4 ,7); printf("-Men%c Principal-",163);
			
			
			gotoxy(5,9);printf(M1);
			gotoxy(5,11);printf(M2);
			gotoxy(5,13);printf(M3);
			gotoxy(5,15);printf(M4);
			gotoxy(5,17);printf(M5);
			gotoxy(5,19);printf(M6);
			
		    switch(Opcion)
		    {
			case 1:
			    setcolor(LIGHTGREEN); gotoxy(5, 9); printf(M1);
			   
			    break;
			case 2:
		 		setcolor(LIGHTGREEN); gotoxy(5, 11); printf(M2);
			   
			    break;
			case 3:
			    setcolor(LIGHTGREEN); gotoxy(5, 13); printf(M3);
			  
			    break;
			case 4:
			    setcolor(LIGHTGREEN); gotoxy(5, 15); printf(M4);
			   
			    break;
			case 5:
			    setcolor(LIGHTGREEN); gotoxy(5, 17); printf(M5);
			   
			    break;
			case 6:
				setcolor(RED); gotoxy(5, 19); printf(M6);
			   
			    break;
			
		    }

		    do
			Tecla = getch();
		    while(Tecla != 13 && Tecla != 72 && Tecla != 80);

		    if(Tecla == 72)
		    {
				if(Opcion == 1)
				Opcion = 6;
				else
				if(Opcion > 1)
						Opcion--;
		    }
		    else
			if(Tecla == 80)
			    if(Opcion == 6)
					Opcion = 1;
			    else
					if(Opcion < 6)
					Opcion++;
		}while(Tecla != 13);

		switch(Opcion)
		{
		    case 1:
				agregar();
				menu();
				borrarE();
				break;
				
		    case 2:
				menu_modificar();
				menu();
				borrarE();
				break;
				
		    case 3:
		    	agregarcuenta();
		    	menu();
				borrarE();
				break;
				
		    case 4:
				consultar();
				menu();
				borrarE();
				break;
				
			case 5:
				consultarcuentas();
				menu();
				borrarE();
				break;
			case 6:
				Salir();
				break;
	
	
		}
    }while(Opcion < 6);
    fflush(stdin);
    Salir();
}

void barra(){//barra de cargar
	int x, y, i, z, a;
	gotoxy(35,10); printf("cargando");
	for(i=1;i<101;i++){
		gotoxy(i,13); printf("%c",177);
		gotoxy(50,10); printf("%i",i);
		for(x=50;x<70;x++){
			for(y=1; y<70; y++){
				gotoxy(y,24);
				
			}
		}
	}
}


void borrarE(){//funcion para limpiar la pantalla
	int xC=42,yC=7;
	for(xC=42;xC<=86;xC++)
	{
		for(yC=7;yC<=20;yC++)
		{
			gotoxy(xC,yC);printf(" ");
		}
	}

}
void agregarcuenta(){//funcion para agregar un nuevo movimiento en la cuenta
	borrarE();
	cola_empleados=primero_empleados;
	bool encontrado=false;
	char buscarempleado[20];
	fflush(stdin);
	gotoxy(46,9);printf("Ingrese el id del empleado: "); gets(buscarempleado);

	int num_vueltas=0;

		for(int i=0;i<cantidad_empleados;i++){
		
		
			if(strcmp(buscarempleado,cola_empleados->idEmpleado)==0){	
					borrarE();
					cola_cuentas=new(cuentas);
					gotoxy(44,10); printf("Insertar numero de cuenta: "); gets(cola_cuentas->numcuenta);
					fflush(stdin);
					
					for(int i=0; i<20;i++){
						cola_cuentas->idempleado[i]=buscarempleado[i];
					}
					
					fflush(stdin);
					gotoxy(44,11); printf("Inserte la fecha: "); gets(cola_cuentas->fecha);
					fflush(stdin);
					gotoxy(44,12); printf("Inserte el tipo de movimiento: "); gets(cola_cuentas->tipomovimiento);
					fflush(stdin);
					gotoxy(44,13); printf("Inserte el monto: "); gets(cola_cuentas->monto);
					fflush(stdin);
					gotoxy(44,14); printf("Inserte el concepto: "); gets(cola_cuentas->concepto);
					fflush(stdin);
					if(fin_cuentas!=NULL){
						fin_cuentas->sig=cola_cuentas;
						cola_cuentas->sig=NULL;
						fin_cuentas=cola_cuentas;
						
					}else{
						primero_cuentas=fin_cuentas=cola_cuentas;
					}
					borrarE();
					gotoxy(44,10); printf("Movimiento de cuenta insertado con exito ");
					cantidad_cuentas++;
					getch();
					encontrado=true;
					break;
			}
			cola_empleados=cola_empleados->sig;
	}
	if(encontrado==false){
		borrarE();
		gotoxy(46,9);printf("El empleado no fue encontrado");
	}
	getch();

}

void agregar(){//funcion para agregar un nuevo empleado
	cola_empleados=new(Empleados);
	gotoxy(44,10); printf("Inserte el id: "); gets(cola_empleados->idEmpleado);
	fflush(stdin);
	gotoxy(44,11); printf("Inserte el nombre: "); gets(cola_empleados->nombre);
	fflush(stdin);
	gotoxy(44,12); printf("Inserte el telefono: "); gets(cola_empleados->telefono);
	fflush(stdin);
	gotoxy(44,13); printf("Inserte la ciudad: "); gets(cola_empleados->ciudad);
	fflush(stdin);
	gotoxy(44,14); printf("Inserte el estado: "); gets(cola_empleados->estado);
	fflush(stdin);
	if(fin_empleados!=NULL){
		fin_empleados->sig=cola_empleados;
		cola_empleados->sig=NULL;
		fin_empleados=cola_empleados;
		
	}else{
		primero_empleados=fin_empleados=cola_empleados;
	}
	borrarE();
	gotoxy(44,10); printf("Empleado insertado con exito ");
	cantidad_empleados++;
	getch();
	
}
	
void consultar(){//funcion para consultar los datos de los empleados
	int posicion=2;
	borrarE();
	int montototal=0;
	if(fin_empleados ==NULL){
		gotoxy(44,9); printf("La cola esta vacia");
	}else{
		system("cls");
		cola_empleados=primero_empleados;
		for(int i=0;i<cantidad_empleados;i++){
			
			if(fin_cuentas ==NULL){
				montototal=0;
			}else{
				cola_cuentas=primero_cuentas;
				for(int i=0;i<cantidad_cuentas;i++){
					if(strcmp(cola_empleados->idEmpleado,cola_cuentas->idempleado)==0){	
						montototal=montototal+atoi(cola_cuentas->monto);
					}
				
					if(i==cantidad_cuentas){
						break;
					}else{
						cola_cuentas=cola_cuentas->sig;
					
					}
				}
	
			}
			
				gotoxy(2,posicion);printf("____");
				posicion=posicion+2;
				gotoxy(2,posicion); printf("Id Empleado: %s",cola_empleados->idEmpleado);
				posicion++;
				gotoxy(2,posicion); printf("Nombre: %s",cola_empleados->nombre);
				posicion++;
				gotoxy(2,posicion); printf("Telefono: %s",cola_empleados->telefono);
				posicion++;
				gotoxy(2,posicion); printf("Ciudad: %s",cola_empleados->ciudad);
				posicion++;
				gotoxy(2,posicion); printf("Balance de la cuenta: %i",montototal);
				posicion++;
				gotoxy(2,posicion); printf("Estado: %s",cola_empleados->estado);
				posicion++;
				gotoxy(2,posicion);printf("____");
				posicion=posicion+2;
				montototal=0;
				if(i==cantidad_empleados){
					break;
				}else{
					cola_empleados=cola_empleados->sig;
				
				}
		}
		
	}
	getch();
	system("cls");
}
void consultarcuentas(){//funcion para consultar los movimientos de las cuentas de los empleados
	int posicion=2;
	borrarE();
	
	if(fin_cuentas ==NULL){
		gotoxy(44,9); printf("La cola esta vacia");
	}else{
		system("cls");
		cola_cuentas=primero_cuentas;
		for(int i=0;i<cantidad_cuentas;i++){
			
				gotoxy(2,posicion);printf("____");
				posicion=posicion+2;			
				gotoxy(2,posicion); printf("No. Cuenta: %s",cola_cuentas->numcuenta);
				posicion++;
				gotoxy(2,posicion); printf("id del empleado: %s",cola_cuentas->idempleado);
				posicion++;
				gotoxy(2,posicion); printf("Fecha: %s",cola_cuentas->fecha);
				posicion++;
				gotoxy(2,posicion); printf("Tipo de moviento: %s",cola_cuentas->tipomovimiento);
				posicion++;
				gotoxy(2,posicion); printf("Monto: %s",cola_cuentas->monto);
				posicion++;
				gotoxy(2,posicion); printf("Concepto: %s",cola_cuentas->concepto);
				posicion++;
				gotoxy(2,posicion);printf("____");
				posicion=posicion+2;
				if(i==cantidad_cuentas){
					break;
				}else{
					cola_cuentas=cola_cuentas->sig;
				
				}
		}
		
	}
	getch();
	system("cls");
	
}

void menu_modificar(){//menu que permite buscar,editar y eliminar empleados
	borrarE();
	if(cantidad_empleados>0){
		int Opcion = 1, Tecla;
    fflush(stdin);
		do
		{
			
			gotoxy(50,7);printf("Elige una opcion ->>");
			gotoxy(46,9);printf("Busqueda de empleado");
			gotoxy(46,11);printf("Edicion de empleado");
			gotoxy(46,13);printf("Eliminacion de empleado");
			
			
		    switch(Opcion)
		    {
			case 1:
			    setcolor(LIGHTGREEN); gotoxy(46, 9); printf("Busqueda de empleado");
			    break;
			case 2:
		 		setcolor(LIGHTGREEN); gotoxy(46, 11); printf("Edicion de empleado");
			    break;
			case 3:
			    setcolor(LIGHTGREEN); gotoxy(46, 13); printf("Eliminacion de empleado");
			    break;
			
		    }

		    do
			Tecla = getch();
		    while(Tecla != 13 && Tecla != 72 && Tecla != 80);

		    if(Tecla == 72)
		    {
				if(Opcion == 1)
				Opcion = 3;
				else
				if(Opcion > 1)
						Opcion--;
		    }
		    else
			if(Tecla == 80)
			    if(Opcion == 3)
					Opcion = 1;
			    else
					if(Opcion < 3)
					Opcion++;
		}while(Tecla != 13);

		switch(Opcion)
		{
		    case 1:
				buscar();
				borrarE();
				break;
				
		    case 2:
				editar();
				borrarE();
				break;
				
		    case 3:
		    	eliminar();
				borrarE();
				break;	
		}
    fflush(stdin);
	}else{
		gotoxy(46,9);printf("La cola esta vacia");
		getch();
		return;
	}
	
}
void eliminar(){//funcion para eliminar empleados
	borrarE();
	if(primero_empleados==NULL){
		gotoxy(46,9);printf("La cola esta vacia");
		getch();
		return;
	}
	cola_empleados=primero_empleados;
	cola_cuentas=primero_cuentas;
	bool encontrado=false;
	bool cuentaencontrada=false;
	char buscarempleado[20];
	fflush(stdin);
	gotoxy(46,9);printf("Ingrese el id del empleado a eliminar: "); gets(buscarempleado);

	for(int i=0;i<cantidad_cuentas;i++){
		
		
			if(strcmp(buscarempleado,cola_cuentas->idempleado)==0){	
				borrarE();
				gotoxy(46,9);printf("No se puede eliminar el empleado ya que tiene una cuenta abierta");	
				cuentaencontrada=true;
				break;
			}
			cola_cuentas=cola_cuentas->sig;
	}
	if(cuentaencontrada==false){
		for(int i=0;i<cantidad_empleados;i++){
	
	
			if(strcmp(buscarempleado,cola_empleados->idEmpleado)==0){	
				borrarE();
				gotoxy(46,9);printf("El empleado %s fue eliminado con exito",cola_empleados->nombre);	
				delete(cola_empleados);	
				encontrado=true;
				break;
			}
			cola_empleados=cola_empleados->sig;
		}
		if(encontrado==false){
			borrarE();
			gotoxy(46,9);printf("El empleado no fue encontrado");
		}
		
		cantidad_empleados--;
	}

	
	
	
	
	getch();
}
void editar(){//funcion para editar empleados
	borrarE();
	if(primero_empleados==NULL){
		gotoxy(46,9);printf("La cola esta vacia");
		getch();
		return;
	}
	cola_empleados=primero_empleados;
	bool encontrado=false;
	char buscarempleado[20];
	fflush(stdin);
	gotoxy(46,9);printf("Ingrese el id del empleado a editar: "); gets(buscarempleado);

	for(int i=0;i<cantidad_empleados;i++){
		
		
			if(strcmp(buscarempleado,cola_empleados->idEmpleado)==0){
				borrarE();	
				gotoxy(46,9);printf("editar empleado");		
				gotoxy(44,11); printf("Inserte el nombre: "); gets(cola_empleados->nombre);
				fflush(stdin);
				gotoxy(44,12); printf("Inserte el telefono: "); gets(cola_empleados->telefono);
				fflush(stdin);
				gotoxy(44,13); printf("Inserte la ciudad: "); gets(cola_empleados->ciudad);
				fflush(stdin);
				gotoxy(44,14); printf("Inserte el estado: "); gets(cola_empleados->estado);
				encontrado=true;
				borrarE();
				gotoxy(46,9);printf("Datos actualizados con exito");
				break;
			}
			cola_empleados=cola_empleados->sig;
	}
	if(encontrado==false){
		borrarE();
		gotoxy(46,9);printf("El empleado no fue encontrado");
	}
	getch();
}
void buscar(){//funcion para buscar empleados
	borrarE();
	if(primero_empleados==NULL){
		gotoxy(46,9);printf("La cola esta vacia");
		getch();
		return;
	}
	cola_empleados=primero_empleados;
	bool encontrado=false;
	char buscarempleado[20];
	fflush(stdin);
	gotoxy(46,9);printf("Ingrese el id del empleado a buscar: "); gets(buscarempleado);

	int num_vueltas=0;

		for(int i=0;i<cantidad_empleados;i++){
		
		
			if(strcmp(buscarempleado,cola_empleados->idEmpleado)==0){	
				borrarE();
				gotoxy(46,9);printf("datos del empleado ->>");		
				gotoxy(46,10);printf("Nombre: %s",cola_empleados->nombre);	
				gotoxy(46,11);printf("Telefono: %s",cola_empleados->telefono);
				gotoxy(46,12);printf("Ciudad: %s",cola_empleados->ciudad);
				gotoxy(46,13);printf("Estado: %s",cola_empleados->estado);
				encontrado=true;
				break;
			}
			cola_empleados=cola_empleados->sig;
	}
	if(encontrado==false){
		borrarE();
		gotoxy(46,9);printf("El empleado no fue encontrado");
	}
	getch();
}


void Salir(){//funcion para salir del programa

	system("cls");
	gotoxy((80-strlen(" Gracias, regrese pronto!")) / 2,5);printf("%cGracias, regrese pronto!", 173);
	Sleep(10);
	exit (-1);
}
