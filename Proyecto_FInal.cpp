#include <string.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>

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

#define Mensaje1 "Crear pila"
#define Mensaje2 "Registrar Empleado"
#define Mensaje3  "Buscar/editar/eliminar Empleados"
#define Mensaje4  "Registrar movimientos de cuentas"
#define Mensaje5  "Consultar Empleados"
#define Mensaje6  "Consultar Movimientos de cuentas"
#define Mensaje7 "Salir del programa"
#define Maximo 5

char t1[]= "Universidad Catolica del Cibao", 
	t2[]= "UCATECI", 
t3[]= "Proyecto Final Estructura de datos",
LO[]= "LOG-IN",
MAL[]= "INCORRECTO",
BIEN[]= "CORRECTO",
esp[]= "                    ";

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

int Posicion = Maximo + 1, Pila[Maximo], I;

struct pila{
	char IDEmpleado[20];
	char nombre[50];
	char ciudad[50];
	char telefono[50];
	char estado[50];
	struct pila *ant;
}


*CAB=NULL,
*AUX=NULL;

struct cuenta{
	char No_cuenta[20];
	char IDEmpleadoc[20];
	char Fecha[50];
	char TipoMovimiento[50];
	char Monto[50];
	char Concepto[52];

	struct cuenta *anti;
}
*CABE=NULL,
*AUXI=NULL;

void Crear();
void Registrar();
void RegistrarCuenta();
void MostrarEmpleados();
void ConsultarMovimientos();
void Bus_Edi_Eli();
void Salir();
void editar();
void eliminar();

int main()
{
	
	system("CLS");	

	int x, y, p=1,cont=3, fin =0;
	char usua[10],contra[10];

	do
	{	
		setcolor(WHITE);
		cuadro(1,80,0,8); //Primer cuadro
   		cuadro(10,70,10,20);// segundo cuadro
  	
		setcolor(RED);
		gotoxy(2,6);printf("Usuario: admin");
		gotoxy(2,7);printf("Contrase%ca: admin",164);
		setcolor(YELLOW);
    	gotoxy(25,1);printf("UNIVERSIDAD CATOLICA DEL CIBAO");
   		setcolor(WHITE);
   		gotoxy(37,2);printf("UCATECI");
   		gotoxy(23,3);printf("Proyecto Final Estructura de Datos");
    	gotoxy(34,4);printf("Iniciar Sesion ");
    		
		setcolor(YELLOW);
		x= 30, y= 5;
		gotoxy( (80-strlen(LO)) / 2,7); printf(LO);//iniciar sesion	
	
            
		setcolor(CYAN);		
		gotoxy( 39,11); printf("           ");//Borrar usuario si entra mal
		gotoxy( 31,11); printf("Usuario: ");//Usuario

		gotoxy( 43,13); printf("       ");//Borrar Contraseña si entra mal
		gotoxy( 31,13); printf("Contrase%ca: ",164);//Contraseña
		

		gotoxy( 40,11);gets(usua); fflush(stdin);
		gotoxy( 43,13);gets(contra); fflush(stdin);
		
	
		if(strcmp(usua,"admin")==0 && strcmp(contra,"admin")==0)
		{
			
			gotoxy( (80-strlen(esp)) / 2,19); printf(esp); gotoxy(30,19);printf("%c",179);//Borrar intentos
			setcolor(WHITE);
			gotoxy( (80-strlen(BIEN)) / 2,17); printf(BIEN);//CORRECTO
			 getch();
			fin=1;

		}
		else
		{
			cont-=1;
			setcolor(RED);
			gotoxy( (80-strlen(MAL)) / 2,17); printf(MAL);//INCORRECTO			
			setcolor(WHITE);
			gotoxy(31,19); printf("Intentos restante %i",cont);gotoxy(80,25);//intentos		
			getch();

			gotoxy( (80-strlen(esp)) / 2,17); printf(esp);//borra incorrecto
			
			if(cont==0)
			{
				Salir();
			}

		}
	}while(fin==0);//INICIO DE SESION
		system("CLS");
		    setcolor(WHITE);
			cuadro(1,80,0,8); //Primer cuadro
   		cuadro(10,70,9,21);// segundo cuadro
    
			setcolor(YELLOW);
    		gotoxy(25,1);printf("UNIVERSIDAD CATOLICA DEL CIBAO");
   			setcolor(WHITE);
   			gotoxy(37,2);printf("UCATECI");
   			gotoxy(23,3);printf("Proyecto Final Estructura de Datos");
    		gotoxy(35,4);printf("Bienvenido/a ");
    		
  			setcolor(LIGHTBLUE);
   		 	gotoxy(2,6);printf("2019-0823");
    		gotoxy(2,7);printf("Edward Brito");
    		gotoxy(32,6);printf("2019-0974");
   			gotoxy(32,7);printf("Daniel Orrego");
    		gotoxy(62,6);printf("2019-1056");
   			gotoxy(62,7);printf("Yessica Villavizar");
			setcolor(WHITE);
		
			gotoxy(23, 11); printf("Espere mientras cargan los datos");

	for(int X=20 ; X<=60 ; X++)//CUADRO DE CARGA
	{
		gotoxy(X,16);printf("%c",205);
		gotoxy(X,19);printf("%c",205);
	}

	gotoxy(20,16);printf("%c",201);//esquina superior Izquierda
	gotoxy(20,19);printf("%c",200);//esquina inferior Izquierda
	gotoxy(60,16);printf("%c",187);//esquina superior derecha
	gotoxy(60,19);printf("%c",188);//esquina inferior derecha
	gotoxy(60,18);printf("%c",186);
	gotoxy(60,17);printf("%c",186);
	gotoxy(20,18);printf("%c",186);
	gotoxy(20,17);printf("%c",186);

	int carga=21;

	for(carga=21;carga<=59;carga++)	
	{
		gotoxy(carga,17);printf("%c",176);
		gotoxy(carga,18);printf("%c",176);
		Sleep(100);
	}
 system("CLS");


   time_t t;
    struct tm *tm;
   char fechayhora[100];

    t=time(NULL);
    tm=localtime(&t);
   strftime(fechayhora, 100, "%d/%m/%Y  %H:%M:%S", tm);
  
  	setcolor(WHITE);
	cuadro(1,80,0,8); //Primer cuadro
   
	setcolor(YELLOW);
    gotoxy(25,1);printf("UNIVERSIDAD CATOLICA DEL CIBAO");
 	setcolor(WHITE);
   	gotoxy(37,2);printf("UCATECI");
  	gotoxy(23,3);printf("Proyecto Final Estructura de Datos");
  	gotoxy(23,4);  printf ("Fecha y Hora: %s\n", fechayhora);
   		
	setcolor(LIGHTBLUE);
   	gotoxy(2,6);printf("Facilitador: Teoria");
   	gotoxy(2,7);printf("Diego Orlando Matias Casta%cos",164);
  	gotoxy(54,6);printf("Facilitador: Laboratorio");
	gotoxy(58,7);printf("Jose Ramon Capellan  ");

  	// getch();
  	// printf(" ");
	gotoxy(38,17);system("pause");

  
   system("CLS");
 
 	
	//=======================================PROGRAMA===============================================================
	    int Opcion = 1, Tecla;
 do{
    do{
    		setcolor(WHITE);
			cuadro(1,80,0,8); //Primer cuadro
    		cuadro(10,70,9,19);// segundo cuadro
    		cuadro(1,80,21,26); //tercer cuadro
		

			setcolor(YELLOW);
			gotoxy(58,1);  printf ("%s\n", fechayhora);
    		gotoxy(25,1);printf("UNIVERSIDAD CATOLICA DEL CIBAO");
   			setcolor(WHITE);
   			gotoxy(37,2);printf("UCATECI");
   			gotoxy(23,3);printf("Proyecto Final Estructura de Datos");
    		gotoxy(34,4);printf("Menu Principal");
    		
  			setcolor(LIGHTBLUE);
   		 	gotoxy(2,6);printf("2019-0823");
    		gotoxy(2,7);printf("Edward Brito");
    		gotoxy(32,6);printf("2019-0974");
   			gotoxy(32,7);printf("Daniel Orrego");
    		gotoxy(62,6);printf("2019-1056");
   			gotoxy(62,7);printf("Yessica Villavizar");
			


            setcolor(YELLOW);
            gotoxy(23, 11); printf(Mensaje1);
            gotoxy(23, 12); printf(Mensaje2);
            gotoxy(23, 13); printf(Mensaje3);
            gotoxy(23, 14); printf(Mensaje4);
            gotoxy(23, 15); printf(Mensaje5);
            gotoxy(23, 16); printf(Mensaje6);
            gotoxy(23, 17); printf(Mensaje7);

            switch(Opcion){

                case 1:
                    setcolor(WHITE); gotoxy(23, 11); printf(Mensaje1);
                    break;

                case 2:
                    setcolor(WHITE); gotoxy(23, 12); printf(Mensaje2);
                    break;

                case 3:
                    setcolor(WHITE); gotoxy(23, 13); printf(Mensaje3);
                    break;

                case 4:
                    setcolor(WHITE); gotoxy(23, 14); printf(Mensaje4);
                    break;

                case 5:
                    setcolor(WHITE); gotoxy(23, 15); printf(Mensaje5);
                    break;

                case 6:
                    setcolor(WHITE); gotoxy(23, 16); printf(Mensaje6);
                    break;

                case 7:
                    setcolor(WHITE); gotoxy(23, 17); printf(Mensaje7);
                    break;


            }

            do{
			
                Tecla = getch();
            }while(Tecla != 13 && Tecla != 72 && Tecla != 80);

            if(Tecla == 72){

                if(Opcion == 1){
                
                    Opcion = 7;

                }else

                    if(Opcion > 1){
                    	Opcion--;
					}
            }else{
            	
            	if(Tecla == 80){
            		
            		if(Opcion == 7){
            			
            			Opcion = 1;
					}else{
						
						if(Opcion < 7){
							
							Opcion++;
						}
					}

				}
			}

        }while(Tecla != 13);

        switch(Opcion){

            case 1:
                Crear();
                break;

            case 2:
            	Registrar();
                break;

            case 3:
				 Bus_Edi_Eli();
                break;

            case 4:
            	RegistrarCuenta();
                break;

            case 5:
                MostrarEmpleados();
                break;

            case 6:
				ConsultarMovimientos();
                break;

        }
    }while(Opcion != 7);
    Salir();
    return 0;
	
}


void Salir(){

    system("CLS");    
    setcolor(WHITE);
    gotoxy(40,10);printf("%cGracias, regrese pronto!\n\n\n\n", 173);

    getch();
    //break;
}

void Crear(){
	
    Posicion = Maximo;
    system("CLS");

    printf("Pila creada.");
    getch();
    }

void RegistrarCuenta(){
	system("CLS");
    if(Posicion == Maximo + 1)
        printf("Pila no creada.");
        else
            if(Posicion == Maximo - Maximo)
                printf("Pila llena.");
                
            else{
   	           AUXI=(struct cuenta *)malloc(sizeof(struct cuenta));
				system("CLS");
				printf("No_cuenta: ");
				gets(AUXI->No_cuenta);
				    fflush(stdin);
				printf("IDEmpleado: ");
				gets(AUXI->IDEmpleadoc);
				    fflush(stdin);
				printf("Fecha: ");
				gets(AUXI->Fecha);
				    fflush(stdin);
				printf("Debito // Credito:\n");
				printf("TipoMovimiento: ");
				gets(AUXI->TipoMovimiento);
				    fflush(stdin);
				printf("Monto: ");
				gets(AUXI->Monto);
				    fflush(stdin);
				printf("Concepto: ");
				gets(AUXI->Concepto);
				 setcolor(YELLOW);
				    fflush(stdin);
				printf("Cuenta creada con exito!!");

				if (CABE==NULL)
				{
				CABE=AUXI;
				AUXI->anti=NULL;
				}
				else
				{
				AUXI->anti=CABE;
				
				CABE=AUXI;
				}
                Posicion--;
            }
    getch();
    	system("CLS");

}

void Registrar(){
	system("CLS");
    if(Posicion == Maximo + 1)
        printf("Pila no creada.");
        else
            if(Posicion == Maximo - Maximo)
                printf("Pila llena.");
            else{
					//system("CLS");
                AUX=(struct pila *)malloc(sizeof(struct pila));
				system("CLS");
				printf("IDEmpleado: ");
				gets(AUX->IDEmpleado);
				    fflush(stdin);
				printf("Nombre:");
				gets(AUX->nombre);
				    fflush(stdin);
				printf("Ciudad: ");
				gets(AUX->ciudad);
				    fflush(stdin);
				printf("Telefono: ");
				gets(AUX->telefono);
				    fflush(stdin);
				printf("Estado: ");
				gets(AUX->estado);
				 setcolor(YELLOW);
				    fflush(stdin);
				printf("Empleado registrado con exito.");
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
            }
   	          
    getch();
    	system("CLS");

}

void MostrarEmpleados()
{
    system("CLS");

    if(Posicion == Maximo + 1)
        printf("Pila no creada.");
        else

            if(Posicion == Maximo)
                printf("Pila vac%ca.", 161);
            else{
			
                if (CAB==NULL)
				  return;
				system("CLS");	
					AUXI=CABE;
					AUX=CAB;
					while (AUXI!=NULL && AUX!=NULL){
				
						if (AUXI->IDEmpleadoc == AUX->IDEmpleado)
							printf("\n");
							printf("\n--------------------------------- \n");
							printf("IDEmpleado: %s\n",AUX->IDEmpleado);
							printf("Nombre: %s\n",AUX->nombre);
							printf("Ciudad: %s\n",AUX->ciudad);
							printf("Telefono: %s\n",AUX->telefono);
							printf("Estado: %s\n",AUX->estado);
							AUX=AUX->ant;
							printf("\n");
							printf("No_cuenta: %s\n",AUXI->No_cuenta);
							printf("IDEmpleado: %s\n",AUXI->IDEmpleadoc);
							printf("Fecha: %s\n",AUXI->Fecha);
							printf("TipoMovimiento: %s\n",AUXI->TipoMovimiento);
							printf("Monto: %s\n",AUXI->Monto);
							printf("Concepto: %s\n",AUXI->Concepto);
							printf("\n--------------------------------- \n");
							AUXI=AUXI->anti;		
						}		
	}
    		getch();
        	system("CLS");

}

void ConsultarMovimientos()
{
    system("CLS");

    if(Posicion == Maximo + 1)
        printf("Pila no creada.");
        else
            if(Posicion == Maximo)
                printf("Pila vac%ca.", 161);
            else{
			
                if (CAB==NULL)
				  return;
				system("CLS");
				char empleado[20];
				printf("Digite el ID del empleado que desea vizualizar: ");
				gets(empleado);	
				
			AUX=CAB;
			AUXI=CABE;
		if(AUX!=NULL && AUXI!=NULL){
			if(empleado == AUX->IDEmpleado && empleado == AUXI->IDEmpleadoc)
				printf("\n");
				printf("\n-------------Informacion------------------ \n");
				printf("IDEmpleado: %s\n",AUX->IDEmpleado);
				printf("Nombre: %s\n",AUX->nombre);
				printf("Ciudad: %s\n",AUX->ciudad);
				printf("Telefono: %s\n",AUX->telefono);
				printf("Estado: %s\n",AUX->estado);
				AUX=AUX->ant;
										
				printf("No_cuenta: %s\n",AUXI->No_cuenta);
				printf("IDEmpleado: %s\n",AUXI->IDEmpleadoc);
				printf("Fecha: %s\n",AUXI->Fecha);
				printf("TipoMovimiento: %s\n",AUXI->TipoMovimiento);
				printf("Monto: %s\n",AUXI->Monto);
				printf("Concepto: %s\n",AUXI->Concepto);
				printf("\n--------------------------------- \n");
				AUXI=AUXI->anti;
			
		}
	}
    		getch();
        	system("CLS");

}

void Bus_Edi_Eli(){
    system("CLS");

    if(Posicion == Maximo + 1)
        printf("Pila no creada.");
        else
            if(Posicion == Maximo)
                printf("Pila vac%ca.", 161);

            else{
			
                if (CAB==NULL)
				  return;
				system("CLS");
				char empleado[20];
				printf("Digite el ID del empleado que desea vizualizar: ");
				gets(empleado);	
				
			if(empleado == AUX->IDEmpleado)
				printf("\n");
				printf("\n-------------Informacion------------------ \n");
				printf("IDEmpleado: %s\n",AUX->IDEmpleado);
				printf("Nombre: %s\n",AUX->nombre);
				printf("Ciudad: %s\n",AUX->ciudad);
				printf("Telefono: %s\n",AUX->telefono);
				printf("Estado: %s\n",AUX->estado);
				AUX=AUX->ant;
				
				 int x=0;
				  int op=1;
				  do{			
				    cuadro(10,70,7,20);
				    gotoxy(20,10); printf("1- Editar");
				    gotoxy(20,11); printf("2- Eliminar");
				    gotoxy(20,14); printf("0- Salir");
				    gotoxy(20,16); printf("Su opcion: ");scanf("%d",&op);
				    
				    switch(op)
					  {
				        case(1):editar(); break;
						case(2):eliminar(); break;
						case(0): break;
				
				      }
				
				  }while (op!=0);
				
				  system("CLS");	
				
				if(empleado != AUX->IDEmpleado)				
					printf("No Localizado");
			
				
		}
	getch();
    system("CLS");
}


void editar (){
	 AUX=(struct pila *)malloc(sizeof(struct pila));
				system("CLS");
				printf("\n");
				printf("\n--------------------------------- \n");
				fflush(stdin);
				printf("IDEmpleado: ");
				gets(AUX->IDEmpleado);
				    fflush(stdin);
				printf("Nombre: ");
				gets(AUX->nombre);
				    fflush(stdin);
				printf("Ciudad: ");
				gets(AUX->ciudad);
				    fflush(stdin);
				printf("Telefono: ");
				gets(AUX->telefono);
				    fflush(stdin);
				printf("Estado: ");
				gets(AUX->estado);
				    fflush(stdin);
				
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
				    getch();

            }
        

void eliminar(){
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
                printf("Empleado borrado .");
            }
    getch();
	
}

