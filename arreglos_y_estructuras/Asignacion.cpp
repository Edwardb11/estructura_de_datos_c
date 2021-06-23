//A través de este espacio podrán subir su programa en C++ que, utilizando arreglos
// y método de ordenamiento, permita registrar los datos de un grupo de doctores de
// la clínica Buena Salud (código, nombre, especilidad, cantidadpacientes), que 
//permita ordenar los datos a través del método de Burbujas, que permita mostrar
// todos los datos (tanto ordenados como sin ordenar) de los médicos y una opción
// que muestre los médicos de acuerdo a la especialidad indicada. 
//Deben hacer un menú con los títulos y las opciones correspondientes para cada
// tarea solicitada.
#include <string.h>
//#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <iostream>

#define L 4
#define t1 "Universidad Catolica Tecnologica del Cibao"
#define t2 "2019-0823"
#define t3 "Estructura de Datos"
#define t4 "Manejo de arreglos con el metodo de burbuja"
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

int x, vnum[L], almacen, a1[L], a3[L], a4[L];
char a2[L][50];

void ingresarDoctores(){
	int x;
	system("CLS");
	printf("Registrar datos de doctores\n");

	for (x=0; x<=L; x++){
		printf("\nIngrese el codigo del doctor: ");scanf("%d", &a1[x]);
		printf("Ingrese el nombre del doctor: ");scanf("%s", &a2[x]);
		printf("1- Cardiologia\n2- Neumologia\n3- Neurologia\n4- Nutrilogia\n5- Pedatria\n6- Hepatologia\nIngrese la especialidad del doctor: ");scanf("%d", &a3[x]);
		printf("Ingrese la cantidad de pacientes del doctor: ");scanf("%d", &a4[x]);
		vnum[x] = a1[x];
	}
	
	system("PAUSE");
}

void ordenar(){//metodo de burbujas
	int i,j;
	//metodo burbuja
	for (i=1; i<=L; i++){
		for (j=0; j<=L-i; j++){
	      if (vnum[j] > vnum[j+1]){
			almacen = vnum[j+1];
			vnum[j] = vnum[j+1];
			vnum[j+1] = almacen;
			}
		}
	}

}

void mostrar(){
	system("CLS");
	int x, y=7;
	
	gotoxy(20,2); printf("Mostrando los datos de doctores \n");
	gotoxy(5,5); printf("   Codigo    	Nombre    	Especialidad		Cantidad de pacientes\n");
	
	for (x=0; x<=L; x++){
		gotoxy(8,y);printf("%d ",a1[x]);
		gotoxy(22,y);printf("%s ",a2[x]);
		switch(a3[x]){
			case(0):
				gotoxy(40,y);printf("Sin datos"); 
				break;
				
			case(1):
				gotoxy(40,y);printf("Cardiologia");
				break;
	
			case(2):
				gotoxy(40,y);printf("Neumologia");
				break;
	
			case(3):
				gotoxy(40,y);printf("Neurologia"); 
				break;
	
			case(4): 
				gotoxy(40,y);printf("Nutrilogia");
				break;
				
			case(5):
				gotoxy(40,y);printf("Pedatria");
				break;
	
			case(6):
				gotoxy(40,y);printf("Hepatologia"); 
				break;
		}
		gotoxy(72,y);printf("%d ",a4[x]);
		y++;
	}
	
	system("PAUSE");
}

void especialidades(){
	int y=7, op=1;
	system("CLS");
	printf("Mostrar datos de doctores por especialidad\n\n");
	
  	do{
  		printf("\nPresione 0 para regresar al menu\n1- Cardiologia\n2- Neumologia\n3- Neurologia\n4- Nutrilogia\n5- Pedatria\n6- Hepatologia\n\nIngrese la especialidad del doctor que desea visualizar: ");scanf("%d", &op);
  		
  		switch(op){
			case(1):
				system("CLS");
	        	gotoxy(20,2); printf("Mostrando los datos de doctores por especialidad\n");
				gotoxy(5,5); printf("   Codigo    	Nombre    	Especialidad		Cantidad de pacientes\n");
	
				for (x=0; x<=L; x++){
					if(a3[x] == 1){
						gotoxy(8,y);printf("%d ",a1[x]);
						gotoxy(22,y);printf("%s ",a2[x]);
						gotoxy(40,y);printf("Cardiologia"); 
						gotoxy(72,y);printf("%d ",a4[x]);
						y++;
					}
				}
				break;

			case(2):
				system("CLS");
	        	gotoxy(20,2); printf("Mostrando los datos de doctores por especialidad\n");
				gotoxy(5,5); printf("   Codigo    	Nombre    	Especialidad		Cantidad de pacientes\n");
	
				for (x=0; x<=L; x++){
					if(a3[x] == 2){
						gotoxy(8,y);printf("%d ",a1[x]);
						gotoxy(22,y);printf("%s ",a2[x]);
						gotoxy(40,y);printf("Neumologia");
						gotoxy(72,y);printf("%d ",a4[x]);
						y++;
					}
				}
				break;
	
			case(3):
				system("CLS");
	        	gotoxy(20,2); printf("Mostrando los datos de doctores por especialidad\n");
				gotoxy(5,5); printf("   Codigo    	Nombre    	Especialidad		Cantidad de pacientes\n");
	
				for (x=0; x<=L; x++){
					if(a3[x] == 3){
						gotoxy(8,y);printf("%d ",a1[x]);
						gotoxy(22,y);printf("%s ",a2[x]);
						gotoxy(40,y);printf("Neurologia");  
						gotoxy(72,y);printf("%d ",a4[x]);
						y++;
					}
				}
				break;
	
			case(4):
				system("CLS");
	        	gotoxy(20,2); printf("Mostrando los datos de doctores por especialidad\n");
				gotoxy(5,5); printf("   Codigo    	Nombre    	Especialidad		Cantidad de pacientes\n");
	 
				for (x=0; x<=L; x++){
					if(a3[x] == 4){
						gotoxy(8,y);printf("%d ",a1[x]);
						gotoxy(22,y);printf("%s ",a2[x]);
						gotoxy(40,y);printf("Nutrilogia"); 
						gotoxy(72,y);printf("%d ",a4[x]);
						y++;
					}
				}
				break;
				
			case(5):
				system("CLS");
	        	gotoxy(20,2); printf("Mostrando los datos de doctores por especialidad\n");
				gotoxy(5,5); printf("   Codigo    	Nombre    	Especialidad		Cantidad de pacientes\n");
	
				for (x=0; x<=L; x++){
					if(a3[x] == 5){
						gotoxy(8,y);printf("%d ",a1[x]);
						gotoxy(22,y);printf("%s ",a2[x]);
						gotoxy(40,y);printf("Pedatria");
						gotoxy(72,y);printf("%d ",a4[x]);
						y++;
					}
				}
				break;
			case(6):
				system("CLS");
	        	gotoxy(20,2); printf("Mostrando los datos de doctores por especialidad\n");
				gotoxy(5,5); printf("   Codigo    	Nombre    	Especialidad		Cantidad de pacientes\n");
	
				for (x=0; x<=L; x++){
					if(a3[x] == 6){
						gotoxy(8,y);printf("%d ",a1[x]);
						gotoxy(22,y);printf("%s ",a2[x]);
						gotoxy(40,y);printf("Hepatologia"); 
						gotoxy(72,y);printf("%d ",a4[x]);
						y++;
					}
				} 
				break;
				
			default:
				system("CLS");
				printf("Error, La opcion seleccionada no existe\n");
      }
	}while (op!=0);

	system("CLS");
	system("PAUSE");
}

void cuadro(int x1, int x2, int y1, int y2){
  int x,y;
  for (x=x1;x<=x2;x++){
      gotoxy(x,y1); printf("%c",205);
      gotoxy(x,y2); printf("%c",205);
    }

  for (y=y1;y<=y2;y++){
      gotoxy(x1,y); printf("%c",186);
      gotoxy(x2,y); printf("%c",186);
    }
      gotoxy(x1,y1); printf("%c",201);
      gotoxy(x2,y1); printf("%c",187);
      gotoxy(x1,y2); printf("%c",200);
      gotoxy(x2,y2); printf("%c",188);
}

int main(){
  x=0;
  int op=1;
  do{
    system("CLS");
    
    setcolor(LIGHTBLUE);
    cuadro(1,78,1,6);
    cuadro(10,70,7,20);
    
    setcolor(LIGHTRED);
    gotoxy( (80-strlen(t1))/2, 2);printf(t1);
    
    setcolor(WHITE);
    gotoxy( (80-strlen(t2))/2, 3);printf(t2);
    gotoxy( (80-strlen(t3))/2, 4);printf(t3);
    gotoxy( (80-strlen(t4))/2, 5);printf(t4);
    gotoxy( (80-strlen(t5))/2, 8);printf(t5);
    gotoxy(20,10); printf("1- Ingresar datos de los doctores");
    gotoxy(20,11); printf("2- Ordenar");
    gotoxy(20,12); printf("3- Mostrar");
    gotoxy(20,13); printf("4- Mostrar por especialidad");
    gotoxy(20,15); printf("0- Salir");
    gotoxy(20,18); printf("Su opcion: ");scanf("%d",&op);

    switch(op){
        case(1):
			ingresarDoctores(); 
			break;

		case(2):
			ordenar(); 
			break;

		case(3):
			mostrar(); 
			break;
			
		case(4):
			especialidades();
			break;

		case(0): 
			break;
      }

  }while (op!=0);

  system("CLS");

  return 0;
}
