#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string>
#include <windows.h>
#include <ctime>




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

#define L 4
#define M 4
#define Mensaje1 "- Registrar empleado"
#define Mensaje2 "- Buscar/editar/eliminar empleados."
#define Mensaje3 "- Registrar movimientos de cuentas."
#define Mensaje4 "- consultar empleados."
#define Mensaje5 "- Consultar movimientos de cuentas."
#define Mensaje6 "- SALIR"

#define Maximo 6

using namespace std;

void gotoxy(int x, int y);
void login();
void Carga();

int main(){
	login();
	getch(); 
}

struct empleado{
   int IDEMPLEADO;
   char nombre[30], ciudad[30], estado[30];
   int telefono;
 } vestud, aestud[L];
 
 struct cuenta{
    int Numero;
	int IDEMPLEADO;
	int fecha;
	char tipomovimiento[30];
	int monto;
	char concepto[30];
	struct cuenta * sig;
 	
 }
 *CAB=NULL,*AUX=NULL,*FIN=NULL;

int x;

void setcolor( unsigned short color ){

    HANDLE hCon = GetStdHandle( STD_OUTPUT_HANDLE );

    SetConsoleTextAttribute( hCon, color );

}

void gotoxy(int x, int y){
	HANDLE hCon;
	hCon=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X=x;
	dwPos.Y=y;
	SetConsoleCursorPosition(hCon, dwPos);
}

void Limpia(int x1, int x2, int y1, int y2){
	int x,y;
	for (x=x1;x<=x2;x++)
		for (y=y1;y<=y2;y++)
			{
				gotoxy(x,y); printf(" "); //Alt+ 186
			}
}

void Relleno(int x1, int x2, int y1, int y2){
	
	int x,y;
	for (x=x1;x<=x2;x++)
		for (y=y1;y<=y2;y++)
			{
				gotoxy(x,y); printf("%c",219);
			}
}

void cuadro(int x1, int x2, int y1, int y2){
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

	gotoxy(x2,y1); printf("%c",187);
	gotoxy(x2,y2); printf("%c",188);
	gotoxy(x1,y1); printf("%c",201);
	gotoxy(x1,y2); printf("%c",200); 
}

void fecha(){
	    char fecha[25];
	    time_t current_time;
	    current_time=time(NULL);
	    ctime(&current_time);
	    strcpy(fecha, ctime(&current_time));
	    printf("%s", fecha);
}

int Posicion = Maximo + 1, Pila[Maximo], I;

void Registrarempleados(){

  int s=1;

   do{

    system("CLS");
    setcolor(YELLOW);
     gotoxy(49,2);printf("REGISTRAR EMPLEADOS\n\n");
     setcolor(WHITE);
    
	 gotoxy(5,4);printf("ID: "); scanf("%d",&aestud[x].IDEMPLEADO);

     gotoxy(5,5);printf("1ER NOMBRE: "); scanf("%s",&aestud[x].nombre);

     gotoxy(5,6);printf("TELEFONO:"); scanf("%s",&aestud[x].telefono);
     
     gotoxy(5,7);printf("CIUDAD: "); scanf("%s",&aestud[x].ciudad);
     
     gotoxy(5,8);printf("ESTADO: "); scanf("%s",&aestud[x].estado);
     
     gotoxy(5,9);printf("PRESIONE 0 PARA SALIR | 1 PARA SEGUIR: ");scanf("%d",&s);

     if (s==0)

   		break;

     x++;

   }while ( (x<=L) || (s==0) );

}

void editaryeliminar(){
 	int i,j;
	for (i=0; i<=x-1; i++)
   	for (j=i+1; j<=x; j++)
   	{
       if (aestud[i].IDEMPLEADO > aestud[j].IDEMPLEADO)
 	   {
  		vestud = aestud[i];
  		aestud[i] = aestud[j];
  		aestud[j] = vestud;
 	   }
 	}
}

void cuenta()
{

	AUX=(struct cuenta *)malloc(sizeof(struct cuenta));
	system("CLS");
    setcolor(YELLOW);
    gotoxy(49,2);printf("Registro de movimiento de cuenta\n\n");
    setcolor(WHITE);
    gotoxy(5,5);printf("Numero de cuenta: ");scanf("%i",&AUX->Numero);
    gotoxy(5,6);printf("ID empleado: ");scanf("%i",&AUX->IDEMPLEADO);
    gotoxy(5,7);printf("fecha: ");scanf("%i",&AUX->fecha);
    gotoxy(5,8);printf("tipo de moviminto(debito o credito)): ");scanf("%S",&AUX->tipomovimiento);
    gotoxy(5,9);printf("introduzca un monto: ");scanf("%i",&AUX->monto);
    gotoxy(5,10);printf("concepto: ");scanf("%S",&AUX->concepto);
    AUX->sig = NULL;
    if (FIN == NULL)
    FIN = CAB = AUX;
    else
    {
    FIN->sig = AUX;
    FIN = AUX;
}
 
   
}

void  Consultarempleados(){

	int y;
	
	char vur[30];
	
	system("CLS");
	setcolor(YELLOW);
	gotoxy(30,2);printf("VULNERABILIDADES");
	setcolor(WHITE);
	gotoxy(15,3);printf("CONSULTA DE CUENTA"); scanf("%s",&vur);
	printf(" ID |     NOMBRE      |    TELEFONO  |   CIUDAD   |    \t ESTADO\n");
	printf("__________________________________________________________________________\n");
	
	
	for (y=0;y<=x;y++)
	
	if (strcmp (aestud[y].ciudad,vur ) ==0 ){
	
	printf("\n%i \t %s \t \t %s \t %s \t \t \t %c \n", aestud[y].IDEMPLEADO, aestud[y].nombre,aestud[y].telefono,aestud[y].ciudad, aestud[y].estado);
	}
	
	else{
		
		gotoxy(15,15);printf("VULNERAVIVLIDAD INTRODUCIDA NO HA SIDO ENCONTRADA... ");
		
	}
	
	getch();
}

void Consultarcuentas(){
	
}



void salir(){
	gotoxy(20,20);printf("USTED HA ELEGIDO SALIR");
	getch();
}

void Carga(){
	setcolor(GREEN);
	cuadro(12,85,3,22);
	setcolor(WHITE);
	gotoxy(43,18); printf("CARGANDO...");
	
	gotoxy(43,5);printf("BIENVENIDO!");
	
	setcolor(YELLOW);
	gotoxy(35,7);printf("ESTRUCTURA DINAMICA DE DATOS");
	setcolor(WHITE);
	gotoxy(40,8);printf("TEORIA/LABORATORIO");
	gotoxy(30,11);printf("Dodanin upia (2018-1481)",160,130);
	gotoxy(30,13);printf("Ramon Ant. Cruz Rosario (2017-1222)");
	setcolor(CYAN);
	gotoxy(38,10);printf("INTEGRANTES DEL EQUIPO");
	
	for(int i=0; i < 35; i++) 
	{
		gotoxy(30+i,17);
		printf("%c",176);
		Sleep(150);
		if(i==5)Sleep(400);
		if(i==10)Sleep(500);
		if(i==16)Sleep(900);
		if(i==21)Sleep(500);
		if(i==28)Sleep(400);
		if(i==30)Sleep(800);
	}
	setcolor(RED);
	gotoxy(29,20);printf("PULSE LA TECLA 'ENTER' PARA CONTINUAR");	
	getch();
	
}
	
void login(){
	string nombre;
	string pass;
	int i, x;
	
	for(i=1; i<4; i++){
	system("cls");
	setcolor(RED);
	cuadro(3,53,1,10);
	setcolor(WHITE);
	cout << endl;
	setcolor(CYAN);
	gotoxy(22,3);printf("INICIO DE SESION");
	setcolor(WHITE);
	printf( "\n\n\tNOMBRE USUARIO: " );
	cin >> nombre;
	
	if(nombre == "admin"){
		printf( "\n\tCONTRASE%CA: ",165);
		cin >> pass;
		
		if(pass == "admin"){
		cout << endl;
		
		Limpia(1,120,1,25);
		Carga();

		Limpia(1,120,1,25);
		

	    int Opcion = 1, Tecla;
	    do
	    {
	        do
	        {
	        	system("CLS");
			    setcolor(RED);
				cuadro(12,85,1,22);
				setcolor(WHITE);
				gotoxy(35,2);printf("UNIVERSIDAD CATOLICA DEL CIBAO");
				gotoxy(37,5); fecha();
				setcolor(CYAN);
				gotoxy(47,3);printf("UCATECI");
				setcolor(WHITE);
				gotoxy(43,4);printf("CONTROL DE CUENTA BANCARIA");
				setcolor(WHITE);
				gotoxy(25,7);printf("DOCENTE DE TEORIA DE ESTRUCTURA DINAMICA DE DATOS: ");
				gotoxy(25,11);printf("DOCENTE DE LABORATORIO DE ESTRUCTURA DINAMICA DE DATOS: ");
				gotoxy(45,15);printf("MENU PRINCIPAL");
	            setcolor(LIGHTBLUE);
	            gotoxy(34,8);printf("Ing. Diego Mat%cas Orlando Casta%cos",140,164);
				gotoxy(34,12);printf("Ing. Jos%c Ram%cn Capell%cn Mar%ca",130,162,131,140);
				setcolor(YELLOW);
	            gotoxy(30, 16); printf(Mensaje1);
	            gotoxy(30, 17); printf(Mensaje2);
	            gotoxy(30, 18); printf(Mensaje3);
	            gotoxy(30, 19); printf(Mensaje4);
	            gotoxy(30, 20); printf(Mensaje5);
	            gotoxy(30, 21); printf(Mensaje6);
	          
	           
	            
	            
	            switch(Opcion)
	            {
	            	
	                case 1:
	                    setcolor(WHITE); gotoxy(30, 16); printf(Mensaje1);
	                    break;
	                    
	                case 2:
	                    setcolor(WHITE); gotoxy(30, 17); printf(Mensaje2);
	                    break;
	                case 3:
	                    setcolor(WHITE); gotoxy(30, 18); printf(Mensaje3);
	                    break;
	                case 4:
	                    setcolor(WHITE); gotoxy(30, 19); printf(Mensaje4);
	                    break;
	                case 5:
	                    setcolor(WHITE); gotoxy(30, 20); printf(Mensaje5);
	                    break;
	                case 6:
	                    setcolor(WHITE); gotoxy(30, 21); printf(Mensaje6);
	                    break;
	               
	                
	            
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
	                Registrarempleados();
	                break;
	            case 2:
	                editaryeliminar();
	                break;
	            case 3:
	                cuenta();
	                break;
	            case 4:
	                Consultarempleados();
	                break;
	            case 5:
	                Consultarcuentas();
	                break;
	            case 6:
	                salir();
	                break;
	            
	            
	        }
	    }
		
		while(Opcion != 6);
		
	    system("CLS");
	
		for(int i=0; i < 35; i++) 
		system("pause>null");
		exit(0);
		}
		else
			if(pass != "admin")
			{
			
			gotoxy(26,11); cout << "\n\tContrase%ca erronea, favor ingrese \n\tun usuario y contrase%ca valida\n\n\t\t    PRECIONE LA TECLA 'ENTER'" << endl,164,164;
			}
	 }
	 	else
			if(nombre != "admin"){
			gotoxy(26,11); cout << "\n\tNombre de usuario erroneo, favor \n\tingrese su nombre de usuario nuevamente\n\n\t\t    PRECIONE LA TECLA 'ENTER'" << endl;
			}
	
	if(i > 0){
		cout << endl;
		gotoxy(15,18); cout << "Usted acaba de usar " << i << " de 3 intentos" << endl;
		system("pause>null");
	}
	if(i == 3){
		cout << endl;
		gotoxy(15,18); cout << "Ha realizado 3 intentos\n \tACCESO DENEGADO..." << endl;
		system("pause>null");
  	}
	}
}


