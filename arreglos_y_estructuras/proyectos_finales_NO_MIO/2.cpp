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

#define Mensaje1 "Registrar Empleado"
#define Mensaje2 "Buscar/editar/eliminar Empleados"
#define Mensaje3 "Registrar movimientos de cuentas"
#define Mensaje4 "Consultar Empleados"
#define Mensaje5 "Consultar Movimientos de cuentas"
#define Mensaje6 "Salir"
#define Mensaje7 "L O G I N"
#define Mensaje8 "UNIVERSIDAD CATOLICA DEL CIBAO"
#define Mensaje9 "UCATECI"
#define Mensaje10 "C O N T R O L   D E   C U E N T A S   D E   E M P L E A D O S"

void setcolor( unsigned short color );
void gotoxy( short x, short y );
void cuadro(int x1, int x2, int y1, int y2);
void hora(void);
void loading();
int login();
void Salir();
void presentacion();
void RegistrarEmp(void);
void RegistrarMov(void);
void ConsultarEmp(void);
void buscar_editar_eliminar_emp(void);
void ConsultarMov(void);


// Estructura de empleados
struct empleados
{
    int IDEmpleado;
    char nombre[100];
    char telefono[30];
    char ciudad[50];
    char estado[50];

  struct empleados *sig;
}
*CAB=NULL,*AUX=NULL,*FIN=NULL;


//Estructura de los movimientos de cuentas
struct cuentas
{
    int no_cuenta;
    int IDEmpleado;
    char fecha[12];
    int tipomovimiento;
    float monto;
    char concepto[250];
  struct cuentas *sig;
}
*CABC=NULL,*AUXC=NULL,*FINC=NULL;


// Asignar los colores
void setcolor( unsigned short color )
{
    HANDLE hCon = GetStdHandle( STD_OUTPUT_HANDLE );
    SetConsoleTextAttribute( hCon, color );
}


// Posisiones x y 
void gotoxy( short x, short y )
{
    HANDLE hConsoleOutput;
    COORD Cursor_an_Pos = { x, y };
    hConsoleOutput = GetStdHandle( STD_OUTPUT_HANDLE );
    SetConsoleCursorPosition( hConsoleOutput, Cursor_an_Pos );
}


//Creacion de los cuadros
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


//Menu para iniciar sesion
int login()
{
    int acumulador=0;
    
    while (acumulador!=3)
    {
        system("CLS");
        acumulador++;
        cuadro(1, 30, 1, 6);
        setcolor(GREEN);
		gotoxy( (30-strlen(Mensaje7)) / 2,2); printf(Mensaje7); //Mensaje L O G I N
		setcolor(WHITE); 
		
		
        char user[7], pass[7];
        
        gotoxy(2, 4); printf("Usuario......: ");
		scanf("%s",&user);
		
        gotoxy(2, 5); printf("Contrase%ca...: ",164); scanf("%s",&pass);
        

        if((strcmp(user, "admin")==0) && (strcmp(pass, "admin")==0)  ){
            printf("\n");
            setcolor(GREEN); system("pause");setcolor(WHITE); 
            break;
        }
        else {
            printf("\n");
            setcolor(RED);printf("\nERROR: el uaurio o la clave es incorrecta\n"); 
            printf("\n");
            system("pause");
            setcolor(WHITE); 
		}
    }
    return acumulador;
}

// Ver lla fecha y hora actual del sistema
void hora(){
	time_t tiempo = time(0);
        struct tm *tlocal = localtime(&tiempo);
        char output[128];
        strftime(output,128,"%d/%m/%Y %H:%M:%S",tlocal);
        gotoxy((101-19)/2, 5); printf("%s\n",output); 
}

// Barra de carga
void loading()
{   
    system("CLS");
    cuadro(6, 40, 3, 6);
    gotoxy(8,4);printf("Alisson Almonte Paulino ");
    gotoxy(8,5);printf("2019-0627");
    
    cuadro(43, 77, 3, 6);
    gotoxy(45,4);printf("John Anthony Garcia");
    gotoxy(45,5);printf("2019-0691");
    
	cuadro(9,62,8,10);
	gotoxy(30,7); printf("LOADING...");
	for (int i = 10; i<=60;i++)
	{
		setcolor(GREEN);
		gotoxy(i,9); printf("%c ",219);
		Sleep(20);
	}
	
	gotoxy(10,12);system("pause");
	setcolor(WHITE);
    presentacion();
}


// Menu con la informacion de las materias
void presentacion()
{
	
	system("CLS");
    setcolor(GREEN);
    cuadro(1,100,1,15);

    setcolor(WHITE);
    gotoxy( (101-strlen(Mensaje8)) / 2,2); printf(Mensaje8); //UNIVERSIDAD CATOLICA DEL CIBAO
    setcolor(YELLOW);
	gotoxy( (101-strlen(Mensaje9)) / 2,3); printf(Mensaje9); // UCATECI
	setcolor(WHITE);
	
	hora();
	
    gotoxy( (101-strlen(Mensaje10)) / 2,7); printf(Mensaje10); //C O N T R O L   D E   C U E N T A S   D E   E M P L E A D O S

    gotoxy(7,12);printf("Ing. Jose Ramon Capellan Maria");
    setcolor(YELLOW);
    gotoxy(5,13);printf("Laboratorio de Estructura de Datos");
    setcolor(WHITE);
    
	gotoxy(65,12);printf("Ing. Diego Orlando Matias ");
    setcolor(YELLOW);
	gotoxy(68,13);printf("Estructura de Datos");
    setcolor(WHITE);
    
	gotoxy(38,17);system("pause");
}


// Registrar los epleado
void RegistrarEmp(void)
{
    setcolor(WHITE);
    AUX=(struct empleados *)malloc(sizeof(struct empleados));
    system("CLS");
	
	cuadro(1, 80, 1, 10);
    gotoxy(2,2);printf("Codigo......: "); scanf("%i",&AUX->IDEmpleado);
    fflush(stdin);

    gotoxy(2,3);printf("Nombre......: "); gets(AUX->nombre);
    fflush(stdin);

    gotoxy(2,4);printf("Telefono.....: "); scanf("%s",&AUX->telefono);
    fflush(stdin);

    gotoxy(2,5);printf("Ciudad.......: "); gets(AUX->ciudad);
    fflush(stdin);

    gotoxy(2,6);printf("Estado.......: "); gets(AUX->estado);
    fflush(stdin);


    AUX->sig=NULL;

    if (FIN==NULL)
    {
        FIN=CAB=AUX;
        setcolor(GREEN);
		gotoxy(2,8); printf("Empleado registrado con exito!!\n");setcolor(WHITE);
    }
    else
    {
        FIN->sig=AUX;
        FIN=AUX;
        setcolor(GREEN);
		gotoxy(2,8); printf("Empleado registrado con exito!!\n");setcolor(WHITE);
    }
    system("pause");
}


// Registrar los movimientos de las cuentas de los emlpeados
void RegistrarMov(void)
{
	int tipo = 0, cont = 0;
    setcolor(WHITE);
    
    if (CAB==NULL){
        setcolor(RED);
        system("CLS");
        printf("No se han registrado empleados!!!");
        setcolor(WHITE);
        getch();
    }
    else{
	    AUXC=(struct cuentas *)malloc(sizeof(struct cuentas));
	    system("CLS");
	    
	    cuadro (1, 85, 1, 15);
	
		gotoxy(2, 2);printf("No de cuenta......: "); scanf("%i",&AUXC->no_cuenta);
	    fflush(stdin);
	
		
	    gotoxy(2, 3);printf("Codigo del empleado......: "); scanf("%i",&AUXC->IDEmpleado);
	    fflush(stdin);
	
		AUX=CAB;
		
		while (AUX!=NULL && cont == 0)
		{
			if (AUX->IDEmpleado == AUXC->IDEmpleado && cont == 0)
			{
				cont = 1;
				gotoxy(2, 4);printf("Fecha......: "); gets(AUXC->fecha);
			    fflush(stdin);
			
			
			    gotoxy(2, 6);printf("TIPO DE MOVIMIENTO.....: ");
			    gotoxy(2, 7);printf("1. Cr%cdito", 130);
			    gotoxy(2, 8);printf("2. D%cbito", 130);
			    gotoxy(2, 9); setcolor (RED); printf("En caso de no seleccionar una opcion valida, tomar%c Debito por defecto", 160); setcolor(WHITE);
			    gotoxy(2, 10);printf("Opcion: ");
				scanf("%i", &tipo);
			
				if(tipo == 1){
					AUXC->tipomovimiento = 1;
				}
				else if (tipo == 2 ){
					AUXC->tipomovimiento = 2;
				}
				
				else {
					AUXC->tipomovimiento = 2;
					}
			    		
			
			    gotoxy(2, 11);printf("Monto.......: "); scanf("%f", &AUXC->monto);
			    fflush(stdin);
			
			    gotoxy(2, 12);printf("Concepto.......: "); scanf("%s", &AUXC->concepto);
			    fflush(stdin);
			
			    AUXC->sig=NULL;
			
			    if (FINC==NULL)
			    {
			        FINC=CABC=AUXC;
			        setcolor(GREEN); gotoxy(2, 14);printf("Movimiento registrado con exito!!\n");setcolor(WHITE);
			    }
			    else
			    {
			        FINC->sig=AUXC;
			        FINC=AUXC;
			        setcolor(GREEN);gotoxy(2, 14); printf("Movimiento registrado con exito!!\n\n");setcolor(WHITE);
			    }
			    cont = 1;
			}
			AUX=AUX->sig;
		}
	    
	    system("pause");
	}
}

// Consultar empleados
void ConsultarEmp(void)
{
	int conty = 4;
    if (CAB==NULL){
        setcolor(RED);
        system("CLS");
        printf("Aun no se han registrado empleados\n");
        printf("Base de Datos Vacia!!!\n");
        setcolor(WHITE);
        getch();
    }
    else
    {
        
        setcolor(WHITE);
        system("CLS");
        printf("_______________________________________________________________________________________\n");
        printf("Codigo\t|Nombre\t\t\t|Telefono\t|Ciudad|\t|Estado|\t|Balance|\n");
        printf("---------------------------------------------------------------------------------------\n");
        AUX=CAB;
        
        while (AUX!=NULL)
        {
            AUXC=CABC;
            float total = 0;
            //Calculando el balance del usuario
                while (AUXC!=NULL)
        		{
        			if(AUXC->IDEmpleado == AUX->IDEmpleado)
					{
						if(AUXC->tipomovimiento == 1)
						{
							total = total - AUXC->monto;
						}
						if(AUXC->tipomovimiento == 2)
						{
							total = total + AUXC->monto;
						}
            		}
            		AUXC=AUXC->sig;
            	}

            gotoxy(2, conty);printf("%i", AUX->IDEmpleado);
            gotoxy(10, conty);printf("%s", AUX->nombre);
            gotoxy(34, conty);printf("%s", AUX->telefono);
            gotoxy(49, conty);printf("%s", AUX->ciudad);
            gotoxy(66, conty);printf("%s", AUX->estado);

            if(total == 0)
            {
                setcolor(WHITE);
                gotoxy(83, conty);printf("%.2f", total);
            }
            else if(total > 0)
            {
                setcolor(GREEN);
                gotoxy(83, conty);printf("%.2f", total);
            }
            else 
            {
                setcolor(RED);
                gotoxy(83, conty);printf("%.2f", total);
            }



            setcolor(WHITE);
            conty++;
            printf("\n");
            AUX=AUX->sig;
        }
        getch();
    }
}


//Consultar movimientos de las cuentas de los empleados
void ConsultarMov(void)
{
	int cuenta = 0;
	float total = 0;
	
    if (CABC==NULL && CAB==NULL){
        setcolor(RED);
        system("CLS");
        printf("Base de Datos Vacia!!!");
        setcolor(WHITE);

    }
    else if (CAB==NULL){
        setcolor(RED);
        system("CLS");
        printf("No se han registrado empleados!!!");
        setcolor(WHITE);

    }
    else if (CABC==NULL){
        setcolor(RED);
        system("CLS");
        printf("No se ha registro movimientos en las cuentas!!!");
        setcolor(WHITE);

    }
    else
    {
    	int conty = 4; //Contador en la posicion Y
        setcolor(WHITE);
        system("CLS");
        
        cuadro(1, 47, 1, 3);
        gotoxy(2,2);printf("N%cero de cuenta del empleado a consultar: ", 163);
       	scanf("%i", &cuenta);
        system("CLS");
        
        printf("_______________________________________________________________________________________\n");
        printf("No. de cuenta\t|Codigo\t|Nombre\t|Fecha\t\t|Movimiento|\t|Monto|\t|Concepto\n");
        printf("---------------------------------------------------------------------------------------\n");
        AUXC = CABC;
        AUX = CAB;
        while(AUX!=NULL)
		{
        	if(cuenta == AUX->IDEmpleado){
				while (AUXC!=NULL)
			    {
		        	if(AUXC->IDEmpleado == AUX->IDEmpleado){
						if(AUXC->tipomovimiento == 1){
							total = total - AUXC->monto;
						}
						if(AUXC->tipomovimiento == 2){
							total = total + AUXC->monto;
						}
		        		gotoxy(2, conty); printf("%i\t", AUXC->no_cuenta);
		        		gotoxy(17, conty); printf("%d\t", AUXC->IDEmpleado);
		        		gotoxy(25, conty);printf("%s\t",AUX->nombre);
		        		gotoxy(33, conty);printf("%s\t",AUXC->fecha);
		        		if(AUXC->tipomovimiento == 1){
							gotoxy(49, conty);printf("Cr%cdito",130);
						}
						if(AUXC->tipomovimiento == 2){
							gotoxy(49, conty);printf("D%cdito",130);
						}
		        		
		        		if(AUXC->tipomovimiento == 1){
							setcolor(RED); 
							gotoxy(63, conty);printf("%.2f\t", AUXC->monto);
							setcolor(WHITE);
						}
						if(AUXC->tipomovimiento == 2){
							setcolor(GREEN); 
							gotoxy(63, conty);printf("%.2f\t", AUXC->monto);
							setcolor(WHITE);
						}
		        		gotoxy(74, conty);printf("%s\n",AUXC->concepto);
		            	printf("\n");
		            	conty++;
			        }
			        
					else if(AUX == NULL){
						printf("No se encontrio el empleado");
					}
					
					else{
						setcolor(BLACK); printf(".");
						setcolor (WHITE);
					}
			
					AUXC=AUXC->sig;
				}
			}
			AUX=AUX->sig;
		}	
		gotoxy (80, 10); printf("El total actual del cliente es:");
		if(total > 0){
			setcolor(GREEN);
			printf(" %.2f", total);
		}
		else if(total < 0){
			setcolor(RED);
			printf(" %.2f", total);
		}
		if(total == 0){
			setcolor(WHITE);
			printf(" %.2f", total);
		}
		 
    }
    getch();
}


// Buscar, Editar o eliminar empleados
void buscar_editar_eliminar_emp(void)
{
	int conty = 7;
	int cuenta = 0, verify;
	float total = 0;
    if (CAB==NULL){
        setcolor(RED);
        system("CLS");
        printf("Base de Datos Vacia");
        setcolor(WHITE);
        getch();
    }
    else
    {
        system("CLS");
        char buscar[100];
        int b=0;
        printf("BUSCAR/EDITAR/ELIMINAR EMPLEADOS\n\n");
        setcolor(WHITE);
        fflush(stdin);
        printf("Nombre del Empleado......: "); gets(buscar);
        fflush(stdin);
        printf("\n");
        printf("_______________________________________________________________________________________\n");
        printf("Codigo\t|Nombre\t\t\t|Telefono\t|Ciudad|\t|Estado|\n");
        printf("---------------------------------------------------------------------------------------\n");
        AUX=CAB;
        AUXC=CABC;
        
        while (AUX!=NULL)
        {
            if (strcmp(buscar, AUX->nombre)==0)
			{
                gotoxy(2, conty);printf("%i", AUX->IDEmpleado);
	            gotoxy(10, conty);printf("%s", AUX->nombre);
	            gotoxy(34, conty);printf("%s", AUX->telefono);
	            gotoxy(49, conty);printf("%s", AUX->ciudad);
	            gotoxy(66, conty);printf("%s", AUX->estado);
	            conty++;
                printf("\n");
                b=1;
                
                //Calculando el balance del usuario
                while (AUXC!=NULL)
        		{
        			if(AUXC->IDEmpleado == AUX->IDEmpleado)
					{
						if(AUXC->tipomovimiento == 1)
						{
							total = total - AUXC->monto;
						}
						if(AUXC->tipomovimiento == 2)
						{
							total = total + AUXC->monto;
						}
            		}
            		AUXC=AUXC->sig;
            	}
                
            }
            AUX=AUX->sig;
        }

        if (b==0){
            setcolor(RED);
			printf("ERROR: empleado no encontrado");
			setcolor(WHITE);
        }
		else
        {
            int op=1;
            do
            {
            	cuadro(1, 20, conty+5, conty+13);
                gotoxy(2,conty+6);printf("M E N U  ");
                gotoxy(2,conty+8);printf("1. Editar ");
                gotoxy(2,conty+9);printf("2. Eliminar");
                gotoxy(2,conty+10);printf("0. Salir");
                gotoxy(2,conty+12);printf("Su opcion..: ");scanf("%d",&op);
                switch (op)
                {
                    case 1:	
                        system("CLS");
                        setcolor(GREEN);printf("EDITAR EMPLEADO\n");setcolor(WHITE);
                        AUX=CAB;
                        while (AUX!=NULL)
                        {
                            if (strcmp(buscar, AUX->nombre)==0)
							{
                                printf("Codigo......: "); scanf("%i",&AUX->IDEmpleado);
							    fflush(stdin);
							
							    printf("Nombre......: "); gets(AUX->nombre);
							    fflush(stdin);
							
							    printf("Telefono.....: "); scanf("%s",&AUX->telefono);
							    fflush(stdin);
							
							    printf("Ciudad.......: "); gets(AUX->ciudad);
							    fflush(stdin);
							
							    printf("Estado.......: "); gets(AUX->estado);
							    fflush(stdin);

                                setcolor(GREEN);printf("\nEmpleado modificado con exito!!\n");setcolor(WHITE);
                                break;
                            }
                            AUX=AUX->sig;
                        }
                        op=0;
                        break;
                    case 2: 
                        system("CLS");
                        if (total != 0){
                            int id;
                        	printf("\nEl balance es %.2f, y es distinto de 0 (cero), esta seguro de eliminar este empleado? ", total);
                        	cuadro (2, 25, 4, 7);
                        	gotoxy(4, 5);printf("1. Si \t2. No");
                        	gotoxy(4, 6);printf("Opci%cn: ", 162);
                        	scanf("%d", &verify);
                        	system("CLS");
                        	if (verify == 1)
							{
                        		empleados *tmp;
		                        tmp=CAB;
		                        AUX=CAB;
		                        if (strcmp(buscar, tmp->nombre)==0)
		                        {
		                            CAB=CAB->sig;
                                    id=tmp->IDEmpleado;
		                            free(tmp);
		                            setcolor(GREEN);printf("\nEmpleado eliminado con exito!!\n");setcolor(WHITE);
		                            Sleep(50);
		                        }
		                        else
		                        {
		                            while (strcmp(buscar, (tmp->sig)->nombre)!=0)
		                            {
		                                tmp=tmp->sig;
		                            }
		                            empleados *tmp2=tmp->sig;
		                            tmp->sig=(tmp->sig)->sig;
                                    id=tmp2->IDEmpleado;
		                            free(tmp2);
		                            setcolor(GREEN);printf("\nEmpleado eliminado con exito!!\n");setcolor(WHITE);
		                            Sleep(500);
		                        }

                                //eliminando cuentas
                                cuentas *eliminar;
                                AUXC=CABC;

                                while (AUXC!=NULL)
                                {
                                    if(AUXC->IDEmpleado == id)
                                    {
                                        eliminar=CABC;
                                        CABC=CABC->sig;
                                        AUXC=AUXC->sig;
                                        free(eliminar);
                                        setcolor(RED);printf("\nCuenta y Movimiento eliminado con exito!!\n");setcolor(WHITE);
                                        Sleep(500);
                                    }
                                    else
                                    {
                                        if ((AUXC->sig!=NULL)&& (AUXC->sig->IDEmpleado==id))
                                        {
                                            eliminar=AUXC->sig;
                                            AUXC->sig=AUXC->sig->sig;
                                            free(eliminar);
                                            setcolor(RED);printf("\nCuenta y Movimiento eliminado con exito!!\n");setcolor(WHITE);
                                            Sleep(500);
                                        }
                                        else
                                        {
                                            AUXC=AUXC->sig;
                                        }
                                    }
                                }

		                        op=0;
							}
							
							else{
                                setcolor(YELLOW);printf("\nEmpleado no eliminado \n");setcolor(WHITE);
                                Sleep(500);
                                op=0;
							}
							
						}
						else{
                            int id;
							empleados *tmp;
	                        tmp=CAB;
	                        AUX=CAB;
	                        if (strcmp(buscar, tmp->nombre)==0)
	                        {
	                            CAB=CAB->sig;
	                            free(tmp);
	                            setcolor(GREEN);printf("\nEmpleado eliminado con exito!!\n");setcolor(WHITE);
	                            Sleep(500);
                                id=tmp->IDEmpleado;
	                        }
	                        else
	                        {
                                //eliminando empleados
	                            while (strcmp(buscar, (tmp->sig)->nombre)!=0)
	                            {
	                                tmp=tmp->sig;
	                            }
	                            empleados *tmp2=tmp->sig;
	                            tmp->sig=(tmp->sig)->sig;
                                id=tmp2->IDEmpleado;
	                            free(tmp2);
	                            setcolor(GREEN);printf("\nEmpleado eliminado con exito!!\n");setcolor(WHITE);
	                            Sleep(500);
                            }

                                //eliminando cuentas
                                cuentas *eliminar;
                                AUXC=CABC;

                                while (AUXC!=NULL)
                                {
                                    if(AUXC->IDEmpleado == id)
                                    {
                                        eliminar=CABC;
                                        CABC=CABC->sig;
                                        AUXC=AUXC->sig;
                                        free(eliminar);
                                        setcolor(RED);printf("\nCuenta y Movimiento eliminado con exito!!\n");setcolor(WHITE);
                                        Sleep(500);
                                    }
                                    else
                                    {
                                        if ((AUXC->sig!=NULL)&& (AUXC->sig->IDEmpleado==id))
                                        {
                                            eliminar=AUXC->sig;
                                            AUXC->sig=AUXC->sig->sig;
                                            free(eliminar);
                                            setcolor(RED);printf("\nCuenta y Movimiento eliminado con exito!!\n");setcolor(WHITE);
                                            Sleep(500);
                                        }
                                        else
                                        {
                                            AUXC=AUXC->sig;
                                        }
                                    }
                                }

	                        op=0;
						}
						break;
                }
            } while (op!=0);
        }
    }
}


//Salir -> para finalizar el programa
void Salir()
{
    setcolor(WHITE);
    system("CLS");
    printf("%cGracias, regrese pronto!", 173);
    getch();
}



int main()
{
    int entrar=0;
    entrar=login();
    if(entrar==3){
        Salir();
        return 0;
    }
    loading();

    int Opcion = 1, Tecla;
    do
    {
        do
        {
            system("CLS");
            
            setcolor(WHITE);
            cuadro(2,50,2,5);
            setcolor(GREEN);
            gotoxy(12, 2); printf(" M E N U   P R I N C I P A L");
            setcolor(WHITE);
            
            gotoxy(1, 8); printf(Mensaje1);
            gotoxy(1, 9); printf(Mensaje2);
            gotoxy(1, 10); printf(Mensaje3);
            gotoxy(1, 11); printf(Mensaje4);
            gotoxy(1, 12); printf(Mensaje5);
            gotoxy(1, 13); printf(Mensaje6);
            
            switch(Opcion)
            {

                case 1:
                    setcolor(GREEN); gotoxy(1, 8); printf(Mensaje1);
                    break;

                case 2:
                    setcolor(GREEN); gotoxy(1, 9); printf(Mensaje2);
                    break;

                case 3:
                    setcolor(GREEN); gotoxy(1, 10); printf(Mensaje3);
                    break;

                case 4:
                    setcolor(GREEN); gotoxy(1, 11); printf(Mensaje4);
                    break;

                case 5:
                    setcolor(GREEN); gotoxy(1, 12); printf(Mensaje5);
                    break;

                case 6:
                    setcolor(RED); gotoxy(1, 13); printf(Mensaje6);
                    break;
            }
            do{
                Tecla = getch();
            }while(Tecla != 13 && Tecla != 72 && Tecla != 80);

            if(Tecla == 72)
            {
                if(Opcion == 1){
                    Opcion = 6;
                }
                else{
                    if(Opcion > 1){
                        Opcion--;
                    }
                }
            }
            else{
                if(Tecla == 80)
                {
                    if(Opcion == 6)
                    {
                        Opcion = 1;
                    }
                    else
                    {
                        if(Opcion < 6)
                        {
                            Opcion++;
                        }
                    }
                }
            }
        }while(Tecla != 13);
        
        switch(Opcion)
        {
            
            case 1:
                RegistrarEmp();
                break;

            case 2:
                buscar_editar_eliminar_emp();
                break;

            case 3:
				RegistrarMov();
                break;
                
			case 4:
                ConsultarEmp();
                break;
                
            case 5:
                ConsultarMov();
                break;

        }
    }while(Opcion != 6);
    Salir();
    return 0;
}



