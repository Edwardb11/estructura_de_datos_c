#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
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

#define Mensaje1 "RegistrarEmpleado"
#define Mensaje2 "Buscar/Editar/EliminarEmpleados"
#define Mensaje3 "RegistrarMovimientosCuentas"
#define Mensaje4 "ConsultarEmpleados"
#define Mensaje5 "ConsultarMovimientosCuentas"
#define Mensaje6 "Salir"
//#define Mensaje7 "Mostrar"
//#define Mensaje8 "Salir"

#define L 4
#define t1 "Universidad Catolica Tecnologica del Cibao"
#define t2 "UCATECI"
#define t3 "Teoria - Diego Orlando Matias"
#define t4 "Laboratorio - Jose Ramon Capellan"
#define t5 "Proyecto Final Estructura de Datos"
#define t6 "tiempo"

#define TECLA_ENTER 13
#define TECLA_BACKSPACE 8
#define LONGITUD 5
#define MAX_INTENTOS 3

#define NUMERO_USUARIOS 5

int main();

struct Empleados{

	char id_empleado[20];
	char nombre[100];
	char telefono[15];
	char ciudad[100];
	char estado[100];

	struct Empleados *sig;
}
*inicio_empleados=NULL,
*cola_reg_empleados=NULL,
*final_empleados=NULL;
int cantidad_empleados=0;

struct Cuentas_empleados{

	int No_cuenta;
	char idempleado[20];
	char fecha[20];
	char Tipo_Movimiento[8];
	int monto;
	char motivo[100];

	struct Cuentas_empleados *sig;
}
*inicio_cuentas=NULL,
*cola_cuentas=NULL,
*final_cuentas=NULL;
int cantidad_cuentas=0;


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


void Login();
void bienvenida();
void progresbar();
void Pantalla();
void Time();
void Registrar();
void Editar();
void RegistrarMovimiento();
void Consultar();
void ConsultarMovimiento();
void buscar_edit_delete();
void Salir();



int main()

{
	Login();
	progresbar();
	Pantalla();
	progresbar();

	
    int Opcion = 1, Tecla;
	

    do

    {

        do

        {

            system("CLS");

            setcolor(YELLOW);

            gotoxy(1, 1); printf(Mensaje1);

            gotoxy(1, 2); printf(Mensaje2);

            gotoxy(1, 3); printf(Mensaje3);

            gotoxy(1, 4); printf(Mensaje4);

            gotoxy(1, 5); printf(Mensaje5);

            gotoxy(1, 6); printf(Mensaje6);



            switch(Opcion)

            {

                case 1:

                    setcolor(WHITE); gotoxy(1, 1); printf(Mensaje1);

                    break;

                case 2:

                    setcolor(WHITE); gotoxy(1, 2); printf(Mensaje2);

                    break;

                case 3:

                    setcolor(WHITE); gotoxy(1, 3); printf(Mensaje3);

                    break;

                case 4:

                    setcolor(WHITE); gotoxy(1, 4); printf(Mensaje4);

                    break;

                case 5:

                    setcolor(WHITE); gotoxy(1, 5); printf(Mensaje5);

                    break;

                case 6:

                    setcolor(WHITE); gotoxy(1, 6); printf(Mensaje6);

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

                Registrar();

                break;

            case 2:

                buscar_edit_delete();

                break;

            case 3:

                RegistrarMovimiento();

                break;

            case 4:

                Consultar();

                break;

            case 5:

                ConsultarMovimiento();

                break;

            case 6:

                Salir();

                break;


        }

    }while(Opcion != 8);
    Salir();
    return 0;

}



void Login()


{
	setcolor(YELLOW);
	char usuario[LONGITUD + 1];
	char clave[LONGITUD + 1];
	int intento = 0;
	int ingresa = 0;
	char caracter;
	int i = 0;
    int j = 0;

    
    char usuarios[NUMERO_USUARIOS][LONGITUD + 1] = {"admin"};
    char claves[NUMERO_USUARIOS][LONGITUD + 1] = {"admin"};
	
	do {
		i = 0;
		system("cls");
		printf("\n\t\t\tINICIO DE SESION\n");
		printf("\t\t\t---------------\n");
		printf("\n\tUSUARIO: ");
		gets(usuario);
		printf("\tCLAVE: ");
		while (caracter = getch()) {
			if (caracter == TECLA_ENTER) {
				clave[i] = '\0';
				break;
				
			} else if (caracter == TECLA_BACKSPACE) {
				if (i > 0) {
					i--;
					printf("\b \b");
				}
				
			} else {
				if (i < LONGITUD) {
					printf("*");
					clave[i] = caracter;
					i++;
				}
			}
		}
		
        /* El usuario y clave debe coincidir con alguno de los que se encuentran en el array */
        for (j = 0; j < NUMERO_USUARIOS; ++j) {
            if (strcmp(usuario, usuarios[j]) == 0 && strcmp(clave, claves[j]) == 0) {
                ingresa = 1;
                break;
                
            }
        }

        if (ingresa == 0) {
            printf("\n\tUsuario y/o clave son incorrectos\n");
            intento++;
            getchar();
        }
		
		
	} while (intento < MAX_INTENTOS && ingresa == 0);
	
	if (ingresa == 1) {
		bienvenida();
		
        /* Aquí va el código del programa cuando el usuario ingresa sus credenciales correctas */

	} else {
		printf("\n\n\tHa sobrepasado el numero maximo de intentos permitidos\n");
		exit(15);
		

	}


}



void Registrar()

{
	setcolor(YELLOW);
	system("cls");
cola_reg_empleados=new(Empleados);
//float pro;
/* Los campos de a reciben valores por medio de una lectura. */
printf("\nIngrese el id del empleado: \n");
gets(cola_reg_empleados->id_empleado);
fflush(stdin);

printf("Ingrese el nombre del empleado: \n");
gets(cola_reg_empleados->nombre);
fflush(stdin);

printf("\nIngrese el telefono del empleado: \n");
gets(cola_reg_empleados->telefono);
fflush(stdin);

printf("Ingrese la ciudad del empleado: \n");
gets(cola_reg_empleados->ciudad);
fflush(stdin);

printf("Ingrese el estado del empleado: \n");
gets(cola_reg_empleados->estado);
fflush(stdin);

if(final_empleados!=NULL){
	final_empleados->sig=cola_reg_empleados;
	cola_reg_empleados->sig=NULL;
	final_empleados=cola_reg_empleados;
		
	}else{
		inicio_empleados=final_empleados=cola_reg_empleados;
	}
	
	system("CLS");
	gotoxy(44,10); printf("EMPLEADO REGISTRADO CON EXITO");
	cantidad_empleados++;
	getch();


}



void Editar()

{
	setcolor(YELLOW);
	system("CLS");
	
	cola_reg_empleados=inicio_empleados;
	bool encontrar=false;
	char busca_empleado[20];
	fflush(stdin);
	gotoxy(46,9);printf("Ingrese el id del empleado a editar: "); gets(busca_empleado);

	for(int i=0;i<cantidad_empleados;i++){
		
		
			if(strcmp(busca_empleado,cola_reg_empleados->id_empleado)==0){
				system("CLS");
				
				gotoxy(46,9);printf("Modificar Empleado");		
				gotoxy(44,11); printf("INGRESE EL NUEVO NOMBRE "); gets(cola_reg_empleados->nombre);
				fflush(stdin);
				gotoxy(44,12); printf("INGRESE EL NUEVO TELEFONO "); gets(cola_reg_empleados->telefono);
				fflush(stdin);
				gotoxy(44,13); printf("INGRESE LA NUEVA CIUDAD "); gets(cola_reg_empleados->ciudad);
				fflush(stdin);
				gotoxy(44,14); printf("INGRESA EL ESTADO "); gets(cola_reg_empleados->estado);
				encontrar=true;
				gotoxy(46,9);printf("DATOS CAMBIADOS!");
			}
			cola_reg_empleados=cola_reg_empleados->sig;
	}
	if(encontrar==false){
		gotoxy(46,9);printf("error! empleado no encontrado");
	}
	getch();
}

	




void RegistrarMovimiento()

{
	setcolor(YELLOW);
    system("CLS");
	cola_reg_empleados=inicio_empleados;
	bool encontrar=false;
	char busca_empleado[20];
	fflush(stdin);
	gotoxy(46,9);printf("Ingrese el ID del empleado: "); gets(busca_empleado);

	int num_vueltas=0;
	
	for(int i=0;i<cantidad_empleados;i++){
		
		
			if(strcmp(busca_empleado,cola_reg_empleados->id_empleado)==0){	
					cola_cuentas=new(Cuentas_empleados);
					gotoxy(44,10); printf("INGRESE NUMERO DE CUENTA "); scanf("%i", &cola_cuentas->No_cuenta);
					fflush(stdin);
					
					for(int i=0; i<20;i++){
						cola_cuentas->idempleado[i]=busca_empleado[i];
					}
					
					fflush(stdin);
					gotoxy(44,11); printf("INGRESE LA FECHA  "); gets(cola_cuentas->fecha);
					fflush(stdin);
					gotoxy(44,12); printf("INGRESE TIPO DE MOVIMIENTO "); gets(cola_cuentas->Tipo_Movimiento);
					fflush(stdin);
					gotoxy(44,13); printf("INGRESE LA CANTIDAD "); scanf("%i", &cola_cuentas->monto);
					fflush(stdin);
					gotoxy(44,14); printf("INGRESE MOTIVO "); gets(cola_cuentas->motivo);
					fflush(stdin);
					if(final_cuentas!=NULL){
						final_cuentas->sig=cola_cuentas;
						cola_cuentas->sig=NULL;
						final_cuentas=cola_cuentas;
						
					}else{
						inicio_cuentas=final_cuentas=cola_cuentas;
					}
					system("CLS");
					gotoxy(44,10); printf("MOVIMIENTO SATISFACTORIO ");
					cantidad_cuentas++;
					getch();
					encontrar=true;
					break;
			}
			cola_reg_empleados=cola_reg_empleados->sig;
	}
	if(encontrar==false){
		system("CLS");
		gotoxy(46,9);printf("EL USUARIO NO FUE ENCONTRADO");
	}
	getch();
}



void Consultar()

{
	setcolor(YELLOW);
	system("CLS");
	progresbar();
	int pos=2, m_total=0;
	
	if(final_empleados ==NULL){
		gotoxy(44,9); printf("El registro esta vacio");
	}else{
		system("CLS");
		cola_reg_empleados=inicio_empleados;
		for(int i=0;i<cantidad_empleados;i++){
			
			if(final_cuentas ==NULL){
				m_total=0;
			}else{
				cola_cuentas=inicio_cuentas;
				for(int i=0;i<cantidad_cuentas;i++){
					if(strcmp(cola_reg_empleados->id_empleado,cola_cuentas->idempleado)==0){	
						m_total=m_total+cola_cuentas->monto;
					}
				
					if(i==cantidad_cuentas){
						break;
					}else{
						cola_cuentas=cola_cuentas->sig;
					
					}
				}
	
			}gotoxy(2,pos++);printf("----------------------------------DATOS EMPLEADO----------------------------------------------");
			gotoxy(2,pos); printf("ID EMPLEADO: %s",cola_reg_empleados->id_empleado);
				pos++;
				gotoxy(2,pos); printf("Nombre: %s",cola_reg_empleados->nombre);
				pos++;
				gotoxy(2,pos); printf("Telefono: %s",cola_reg_empleados->telefono);
				pos++;
				gotoxy(2,pos); printf("Ciudad: %s",cola_reg_empleados->ciudad);
				pos++;
				gotoxy(2,pos); printf("Balance TOTAL : %i",m_total);
				pos++;
				gotoxy(2,pos); printf("Estado: %s",cola_reg_empleados->estado);
				pos++;
				gotoxy(2,pos);printf("------------------------------------------------------------------------------------------------");
				pos=pos+2;
				m_total=0;
				if(i==cantidad_empleados){
					break;
				}else{
					cola_reg_empleados=cola_reg_empleados->sig;
				
				}
		}
		
	}
	
	getch();

}



void ConsultarMovimiento()

{	
	setcolor(YELLOW);
		system("CLS");
	
	int pos=2;
	
	if(final_cuentas ==NULL){
		gotoxy(44,9); printf("NO HAY DATOS");
	}else{
		system("cls");
		cola_cuentas=inicio_cuentas;
		for(int i=0;i<cantidad_cuentas;i++){
			
				gotoxy(2,pos); printf("Numero de  Cuenta: %i",cola_cuentas->No_cuenta);
				pos++;
				gotoxy(2,pos); printf("id del empleado: %s",cola_cuentas->idempleado);
				pos++;
				gotoxy(2,pos); printf("Fecha: %s",cola_cuentas->fecha);
				pos++;
				gotoxy(2,pos); printf("Indique el tipo de movimiento %s",cola_cuentas->Tipo_Movimiento);
				pos++;
				gotoxy(2,pos); printf("Cantidad: %i",cola_cuentas->monto);
				pos++;
				gotoxy(2,pos); printf("Motivo: %s",cola_cuentas->motivo);
				pos++;
				gotoxy(2,pos);printf("------------------------------------------------------------------------------------------------");
				pos=pos+2;
				if(i==cantidad_cuentas){
					break;
				}else{
					cola_cuentas=cola_cuentas->sig;
				
				}
		}
		
	}
	getch();
		
	
}




void eliminar()

{
	
}


void buscar_edit_delete()

{
	setcolor(YELLOW);
	system("CLS");
	
	if(cantidad_empleados>0){
		int Opcion = 1, Tecla;
			
		cola_reg_empleados=inicio_empleados;
		bool encontrado=false;
		char busca_empleado[100];
		fflush(stdin);
		gotoxy(30,9);printf("NOMBRE DEL EMPLEADO "); gets(busca_empleado);
	
		int num_vueltas=0;
	
			for(int i=0;i<cantidad_empleados;i++){
			
			
				if(strcmp(busca_empleado,cola_reg_empleados->nombre)==0){	
					system("CLS");
					gotoxy(46,9);printf("DATOS DE LOS EMPLEADOS");		
					gotoxy(46,10);printf("Nombre del empleado: %s",cola_reg_empleados->nombre);	
					gotoxy(46,11);printf("Telefono del empleado: %s",cola_reg_empleados->telefono);
					gotoxy(46,12);printf("Ciudad del empleado: %s",cola_reg_empleados->ciudad);
					gotoxy(46,13);printf("Estado del empleado: %s",cola_reg_empleados->estado);
					encontrado=true;
					
					do{
						do{
							setcolor(YELLOW);
				            gotoxy(23, 11);printf("Editar empleado ");
							gotoxy(23, 12);printf("Eliminar");
							gotoxy(23, 13);printf("Salir");
							
							switch(Opcion){
								case 1:
									setcolor(YELLOW); gotoxy(15, 11);printf(" ");
									break;
									
								case 2:
									setcolor(YELLOW); gotoxy(15, 12);printf("");
									break;
									
								case 3:
									setcolor(YELLOW); gotoxy(15, 13);printf("Salir");
									break;
							}
							
							do{
								Tecla = getch();
							}while(Tecla != 13 && Tecla != 72 && Tecla != 80);
							
							if(Tecla == 72){
		
				                if(Opcion == 1){
				                	Opcion = 3;
								}else{
									if(Opcion > 1){
										Opcion--;
									}
								}
							}else{
								if(Tecla == 80){
									if(Opcion == 3){
										Opcion = 1;
									}else{
										if(Opcion < 2){
											Opcion++;
										}
									}
								}
							}
						}while(Tecla != 13);
						
						switch(Opcion){
							case 1:
								Editar();
								break;
							case 2:
								eliminar();
								break;
							case 3:
								Salir();
						}
						
					}while(Opcion != 3);
					
					main();
				}
				cola_reg_empleados=cola_reg_empleados->sig;
				
			}
			if(encontrado==false){
				system("CLS");
				
				gotoxy(46,9);printf("ESTA PERSONA NO FUE ENCONTRADA");
			}
			
		}else{
		gotoxy(46,9);printf("La cola esta vacia");
	}
	
	getch();
}

void bienvenida()
{
	setcolor(GREEN);
	cuadro(10,70,7,20);
	setcolor(YELLOW);
	gotoxy( (80-strlen("Bienvenidos"))/2, 10);printf("Bienvenidos");
    gotoxy( (80-strlen("Raudy Garcia"))/2, 12);printf("Raudy Garcia");
    gotoxy( (80-strlen("2019-0091"))/2, 13);printf("2019-0091");
    gotoxy( (80-strlen("Juan Miguel Hernandez"))/2, 15);printf("Juan Miguel Hernandez");
	gotoxy( (80-strlen("2019-0453"))/2, 16);printf("2019-0453      ");
	
}

void progresbar()

{
	
		setcolor(GREEN);
		int segundos = 5;
		for (int i=0; i<=21; i++)
		printf("\n");
		printf("\t\t\t\t CARGANDO... \n");
		for (int i=0; i<=79; i++)
		
			cout<< "_";
		for (int i=0; i<=79; i++)
		{
			cout<<char(219);
			Sleep(segundos*1000/80);
		}
		
		printf("COMPLETADO!");
		
	
	
}

void Pantalla()



{

    system("CLS");

    setcolor(GREEN);
    cuadro(10,70,7,20);
    //cuadro(1,78,1,6);
    setcolor(YELLOW);
    gotoxy( (80-strlen(t1))/2, 9);printf(t1);
    gotoxy( (80-strlen(t2))/2, 10);printf(t2);
    gotoxy( (80-strlen(t3))/2, 11);printf(t3);
    gotoxy( (80-strlen(t4))/2, 12);printf(t4);
	gotoxy( (80-strlen(t5))/2, 13);printf(t5"      ");
	Time();
    //setcolor(WHITE);
    //cuadro(10,70,7,20);
    
      
  //while (op!=0);
  //system("CLS");
  //return 0; 
  //getch();
}  
 
void Time()

    //int main(int argc,char* argv[]) 
	{ 	
        time_t tiempo = time(0);
        struct tm *tlocal = localtime(&tiempo);
        char output[128];
        strftime(output,128,"%d/%m/%y %H:%M:%S",tlocal);
        printf("%s\n",output);

        //return 0;
        getch();
	}

void Salir()

{
    system("CLS");
    printf("%cGracias por participar, Feliz resto del dia!!", 173);
    getch();

}
