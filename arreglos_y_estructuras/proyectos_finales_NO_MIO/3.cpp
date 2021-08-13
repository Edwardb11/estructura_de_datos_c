#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <iostream>
#include <cstdlib>
#include <vector>

#define ENTER 13
#define BACKSPACE 8
#define INTENTOS 3

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

#define Mensaje1 "1- Registrar empleado"
#define Mensaje2 "2- Buscar/editar/eliminar empleados"
#define Mensaje3 "3- Registrar movimientos de cuentas"
#define Mensaje4 "4- Consultar empleados"
#define Mensaje5 "5- Consultar movimientos de cuentas"
#define Mensaje6 "6- Salir"

using namespace std;

int main();

struct Empleados{

	char IDEmpleado[20];
	char Nombre[100];
	char telefono[15];
	char Ciudad[100];
	char Estado[100];

	struct Empleados *sig;
}
*primero_empleados=NULL,
*cola_empleados=NULL,
*fin_empleados=NULL;
int cantidad_empleados=0;

struct Cuentas_empleados{

	int No_cuenta;
	char IDempleado[20];
	char fecha[20];
	char TipoMovimiento[8];
	int monto;
	char Concepto[100];

	struct Cuentas_empleados *sig;
}
*primero_cuentas=NULL,
*cola_cuentas=NULL,
*fin_cuentas=NULL;
int cantidad_cuentas=0;

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

void cuadro(int x1, int x2, int y1, int y2){

	int x,y;
	//crear las lineas horizontales
	for (x=x1;x<=x2;x++){

		gotoxy(x,y1); printf("%c",205); 
		gotoxy(x,y2); printf("%c",205); 
	}

	//crear las lineas verticales
	for (y=y1;y<=y2;y++){

		gotoxy(x1,y); printf("%c",186); 
		gotoxy(x2,y); printf("%c",186); 
	}
	
	gotoxy(x2,y1); printf("%c",187);
	gotoxy(x2,y2); printf("%c",188);
	gotoxy(x1,y1); printf("%c",201);
	gotoxy(x1,y2); printf("%c",200);
}

void Registrar(){
	system("CLS");
	gotoxy(30,1);printf("~~~Registrar nuevo empleado~~~\n");
	
	cola_empleados=new(Empleados);
	
	printf("IDEmpleado: ");
	gets(cola_empleados->IDEmpleado);
	fflush(stdin);
	
	printf("Nombre: ");
	gets(cola_empleados->Nombre);
	fflush(stdin);
	
	printf("Telefono: ");
	gets(cola_empleados->telefono);
	fflush(stdin);
	
	printf("Ciudad: ");
	gets(cola_empleados->Ciudad);
	fflush(stdin);
	
	printf("Estado: ");
	gets(cola_empleados->Estado);
	fflush(stdin);
	
	if(fin_empleados!=NULL){
		fin_empleados->sig=cola_empleados;
		cola_empleados->sig=NULL;
		fin_empleados=cola_empleados;
		
	}else{
		primero_empleados=fin_empleados=cola_empleados;
	}
	
	system("CLS");
	gotoxy(44,10); printf("Empleado insertado con exito ");
	cantidad_empleados++;
	getch();
}

void eliminar(){//funcion para eliminar empleados
	system("CLS");

	cola_empleados=primero_empleados;
	cola_cuentas=primero_cuentas;
	bool encontrado=false;
	bool cuentaencontrada=false;
	char buscarempleado[20];
	fflush(stdin);
	gotoxy(46,9);printf("Ingrese el id del empleado a eliminar: "); gets(buscarempleado);

	for(int i=0;i<cantidad_cuentas;i++){
		
		
			if(strcmp(buscarempleado,cola_cuentas->IDempleado)==0){	
				gotoxy(46,9);printf("No se puede eliminar el empleado ya que tiene una cuenta abierta");	
				cuentaencontrada=true;
				break;
			}
			cola_cuentas=cola_cuentas->sig;
	}
	if(cuentaencontrada==false){
		for(int i=0;i<cantidad_empleados;i++){
	
	
			if(strcmp(buscarempleado,cola_empleados->IDEmpleado)==0){	
				gotoxy(46,9);printf("El empleado %s fue eliminado con exito",cola_empleados->Nombre);	
				delete(cola_empleados);	
				encontrado=true;
				break;
			}
			cola_empleados=cola_empleados->sig;
		}
		if(encontrado==false){
			gotoxy(46,9);printf("El empleado no fue encontrado");
		}
		
		cantidad_empleados--;
	}
	
	getch();
}

void editar(){//funcion para editar empleados
	system("CLS");
	
	cola_empleados=primero_empleados;
	bool encontrado=false;
	char buscarempleado[20];
	fflush(stdin);
	gotoxy(46,9);printf("Ingrese el id del empleado a editar: "); gets(buscarempleado);

	for(int i=0;i<cantidad_empleados;i++){
		
			if(strcmp(buscarempleado,cola_empleados->IDEmpleado)==0){
				system("CLS");
				
				gotoxy(46,9);printf("~~~Editar empleado~~~");		
				gotoxy(44,11); printf("Ingrese el nombre: "); gets(cola_empleados->Nombre);
				fflush(stdin);
				gotoxy(44,12); printf("Ingrese el telefono: "); gets(cola_empleados->telefono);
				fflush(stdin);
				gotoxy(44,13); printf("Ingrese la ciudad: "); gets(cola_empleados->Ciudad);
				fflush(stdin);
				gotoxy(44,14); printf("Ingrese el estado: "); gets(cola_empleados->Estado);
				encontrado=true;
				gotoxy(46,9);printf("Datos actualizados con exito");
				break;
			}
			cola_empleados=cola_empleados->sig;
	}
	
	if(encontrado==false){
		gotoxy(46,9);printf("El empleado no fue encontrado");
	}
	getch();
}

void Buscar_editar_eliminar(){
	system("CLS");
	
	if(cantidad_empleados>0){
		int Opcion = 1, Tecla;
			
		cola_empleados=primero_empleados;
		bool encontrado=false;
		char buscarempleado[100];
		fflush(stdin);
		gotoxy(30,9);printf("Ingrese el nombre del empleado a buscar: "); gets(buscarempleado);
	
		int num_vueltas=0;
	
			for(int i=0;i<cantidad_empleados;i++){
			
			
				if(strcmp(buscarempleado,cola_empleados->Nombre)==0){	
					system("CLS");
					gotoxy(46,9);printf("~~~Datos del empleado~~~");
							
					gotoxy(46,11);printf("Nombre: %s",cola_empleados->Nombre);	
					gotoxy(46,12);printf("Telefono: %s",cola_empleados->telefono);
					gotoxy(46,13);printf("Ciudad: %s",cola_empleados->Ciudad);
					gotoxy(46,14);printf("Estado: %s",cola_empleados->Estado);
					encontrado=true;
					
					do{
						do{
							setcolor(YELLOW);
				            gotoxy(23, 11);printf("Editar  ");
							gotoxy(23, 12);printf("Eliminar  ");
							
							switch(Opcion){
								case 1:
									setcolor(WHITE); gotoxy(23, 11);printf("> Editar");
									break;
									
								case 2:
									setcolor(WHITE); gotoxy(23, 12);printf("> Eliminar");
									break;
									
							}
							
							do{
								Tecla = getch();
							}while(Tecla != 13 && Tecla != 72 && Tecla != 80);
							
							if(Tecla == 72){
		
				                if(Opcion == 1){
				                	Opcion = 2;
								}else{
									if(Opcion > 1){
										Opcion--;
									}
								}
							}else{
								if(Tecla == 80){
									if(Opcion == 2){
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
								editar();
								break;
							case 2:
								eliminar();
								break;
						}
						
					}while(Opcion != 2);
				}
				cola_empleados=cola_empleados->sig;
				
			}
			if(encontrado==false){
				system("CLS");
				
				gotoxy(46,9);printf("El empleado no fue encontrado");
			}
			
		}else{
		gotoxy(46,9);printf("La cola esta vacia");
	}
	
	getch();
}

void Registrar_movimiento(){
	system("CLS");
	cola_empleados=primero_empleados;
	bool encontrado=false;
	char buscarempleado[20];
	fflush(stdin);
	gotoxy(46,9);printf("Ingrese el ID del empleado: "); gets(buscarempleado);

	int num_vueltas=0;
	
	for(int i=0;i<cantidad_empleados;i++){
		
		
			if(strcmp(buscarempleado,cola_empleados->IDEmpleado)==0){	
					cola_cuentas=new(Cuentas_empleados);
					gotoxy(44,10); printf("Insertar numero de cuenta: "); scanf("%i", &cola_cuentas->No_cuenta);
					fflush(stdin);
					
					for(int i=0; i<20;i++){
						cola_cuentas->IDempleado[i]=buscarempleado[i];
					}
					
					fflush(stdin);
					gotoxy(44,11); printf("Inserte la fecha: "); gets(cola_cuentas->fecha);
					fflush(stdin);
					gotoxy(44,12); printf("Inserte el tipo de movimiento: "); gets(cola_cuentas->TipoMovimiento);
					fflush(stdin);
					gotoxy(44,13); printf("Inserte el monto: "); scanf("%i", &cola_cuentas->monto);
					fflush(stdin);
					gotoxy(44,14); printf("Inserte el concepto: "); gets(cola_cuentas->Concepto);
					fflush(stdin);
					if(fin_cuentas!=NULL){
						fin_cuentas->sig=cola_cuentas;
						cola_cuentas->sig=NULL;
						fin_cuentas=cola_cuentas;
						
					}else{
						primero_cuentas=fin_cuentas=cola_cuentas;
					}
					system("CLS");
					gotoxy(44,10); printf("Movimiento de cuenta insertado con exito ");
					cantidad_cuentas++;
					getch();
					encontrado=true;
					break;
			}
			cola_empleados=cola_empleados->sig;
	}
	if(encontrado==false){
		system("CLS");
		gotoxy(46,9);printf("El empleado no fue encontrado");
	}
	getch();
}

void Mostrar(){
	system("CLS");
	
	int posicion=2, montototal=0;
	
	if(fin_empleados ==NULL){
		gotoxy(44,9); printf("La cola esta vacia");
	}else{
		system("CLS");
		cola_empleados=primero_empleados;
		for(int i=0;i<cantidad_empleados;i++){
			
			if(fin_cuentas ==NULL){
				montototal=0;
			}else{
				cola_cuentas=primero_cuentas;
				for(int i=0;i<cantidad_cuentas;i++){
					if(strcmp(cola_empleados->IDEmpleado,cola_cuentas->IDempleado)==0){	
						montototal=montototal+cola_cuentas->monto;
					}
				
					if(i==cantidad_cuentas){
						break;
					}else{
						cola_cuentas=cola_cuentas->sig;
					
					}
				}
	
			}
			gotoxy(2,posicion); printf("Id Empleado: %s",cola_empleados->IDEmpleado);
				posicion++;
				gotoxy(2,posicion); printf("Nombre: %s",cola_empleados->Nombre);
				posicion++;
				gotoxy(2,posicion); printf("Telefono: %s",cola_empleados->telefono);
				posicion++;
				gotoxy(2,posicion); printf("Ciudad: %s",cola_empleados->Ciudad);
				posicion++;
				gotoxy(2,posicion); printf("Balance de la cuenta: %i",montototal);
				posicion++;
				gotoxy(2,posicion); printf("Estado: %s",cola_empleados->Estado);
				posicion++;
				gotoxy(2,posicion);printf("------------------------------------------------------------------------------------------------");
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
}

void Mostrar_movimiento(){
	system("CLS");
	
	int posicion=2;
	
	if(fin_cuentas ==NULL){
		gotoxy(44,9); printf("La cola esta vacia");
	}else{
		system("cls");
		cola_cuentas=primero_cuentas;
		for(int i=0;i<cantidad_cuentas;i++){
			
				gotoxy(2,posicion); printf("No. Cuenta: %i",cola_cuentas->No_cuenta);
				posicion++;
				gotoxy(2,posicion); printf("id del empleado: %s",cola_cuentas->IDempleado);
				posicion++;
				gotoxy(2,posicion); printf("Fecha: %s",cola_cuentas->fecha);
				posicion++;
				gotoxy(2,posicion); printf("Tipo de moviento: %s",cola_cuentas->TipoMovimiento);
				posicion++;
				gotoxy(2,posicion); printf("Monto: %i",cola_cuentas->monto);
				posicion++;
				gotoxy(2,posicion); printf("Concepto: %s",cola_cuentas->Concepto);
				posicion++;
				gotoxy(2,posicion);printf("------------------------------------------------------------------------------------------------");
				posicion=posicion+2;
				if(i==cantidad_cuentas){
					break;
				}else{
					cola_cuentas=cola_cuentas->sig;
				
				}
		}
		
	}
	getch();
}

void Salir(){

    system("CLS");

	setcolor(LIGHTCYAN);
    cuadro(39,65,9,11);
    
    setcolor(WHITE);
    gotoxy(40,10);printf("%cGracias, regrese pronto!\n\n\n\n", 173);

    getch();
}

int main(){
    vector<string> usuarios;
    vector<string> claves;

    // Se añaden usuarios al vector
    usuarios.push_back("admin");
    usuarios.push_back("marielys");
    usuarios.push_back("carlos");

    // Se añaden claves al vector
    claves.push_back("admin");
    claves.push_back("20190090");
    claves.push_back("20190427");

    string usuario, password;

    int segundos=5, contador = 0, Opcion = 1,Tecla;
    float porcentaje = 5;
    bool ingresa = false;

    do{
        system("CLS");
        
        setcolor(LIGHTCYAN);
        cuadro(15,85,1,8);
        
        setcolor(LIGHTMAGENTA);
        gotoxy(40,2);cout << "LOGIN DE USUARIO" << endl;
        gotoxy(20,4);cout << "Usuario: ";
        setcolor(WHITE);
        gotoxy(30,4);getline(cin, usuario);

        char caracter;
		
		setcolor(LIGHTMAGENTA);
        gotoxy(20,5);cout << "Password: ";
        setcolor(WHITE);
        caracter = getch();

        password = "";

        while (caracter != ENTER){

            if (caracter != BACKSPACE){
                password.push_back(caracter);
                cout << "*";
            }else{
                if (password.length() > 0){
                    cout << "\b \b";
                    password = password.substr(0, password.length() - 1);
                }
            }
            caracter = getch();
        }

        for (int i = 0; i < usuarios.size(); i++){
            if (usuarios[i] == usuario && claves[i] == password){
                ingresa = true;
                break;
            }
        }

        if (!ingresa){
        	setcolor(RED);
            gotoxy(30,7);cout << "El usuario y/o password son incorrectos" << endl;
            cin.get();
            contador++;
        }

    }while (ingresa == false && contador < INTENTOS);

    if (ingresa == false){
    	system("CLS");
    	
    	setcolor(LIGHTCYAN);
    	cuadro(20,85,9,11);
    	setcolor(RED);
        gotoxy(24,10);cout << "Haz excedido los 3 intentos, por favor intentelo mas tarde." << endl;
        exit(15);
	}else{
		system("CLS");
		
        gotoxy(37,1);printf("Bienvenido al sistema");
        gotoxy(20,6);printf("Marielys Geraldino Marte");
		gotoxy(55,6);printf("Carlos Miguel Casta%cos Amparo", 164);
		gotoxy(30,7);printf("2019-0090");
		gotoxy(65,7);printf("2019-0427");
        
		gotoxy(40,26);printf("...CARGANDO...");
		
		    
		for(int j=5; j<=84; j++){
		    gotoxy(j,28);cout << "_";
		}
			    
		for(int z=5; z<=84; z++){
			gotoxy(z,28);printf("%c", 219);
			gotoxy(86,28);printf("%.0f %c", ((porcentaje/84)*100), 37);
			porcentaje=porcentaje+1;
			Sleep(segundos*1000/80);
		}
		system("CLS");
		
		setcolor(YELLOW);
		gotoxy(35,2);printf("UNIVERSIDAD CATOLICA DEL CIBAO");
		setcolor(WHITE);
		gotoxy(47,3);printf("UCATECI");
		gotoxy(45,5);printf("FACILITADORES:");
		
		gotoxy(25,6);printf("Jose Maria Capellan");
		gotoxy(60,6);printf("Diego Matias Casta%cos\n\n\n", 164);
		
		
		getch();
		
		do{
	        do{
	
	            system("CLS");
	            
	            setcolor(LIGHTCYAN);
	            cuadro(15,85,1,8);
	            cuadro(20,80,10,18);
	            
	            setcolor(YELLOW);
				gotoxy(35,2);printf("UNIVERSIDAD CATOLICA DEL CIBAO");
				setcolor(WHITE);
				gotoxy(47,3);printf("UCATECI");
				gotoxy(33,4);printf("Examen final de Estructura de Datos");
				gotoxy(44,5);printf("Menu Principal");
				
				setcolor(LIGHTMAGENTA);
				gotoxy(20,6);printf("Marielys Geraldino Marte");
				gotoxy(55,6);printf("Carlos Miguel Casta%cos Amparo", 164);
				gotoxy(30,7);printf("2019-0090");
				gotoxy(65,7);printf("2019-0427");
				
	
	            setcolor(YELLOW);
	            gotoxy(23, 11); printf(Mensaje1);
	            gotoxy(23, 12); printf(Mensaje2);
	            gotoxy(23, 13); printf(Mensaje3);
	            gotoxy(23, 14); printf(Mensaje4);
	            gotoxy(23, 15); printf(Mensaje5);
	            gotoxy(23, 16); printf(Mensaje6);
	
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
	
	            }
	
	            do{
				
	                Tecla = getch();
	            }while(Tecla != 13 && Tecla != 72 && Tecla != 80);
	
	            if(Tecla == 72){
	
	                if(Opcion == 1){
	                
	                    Opcion = 6;
	
	                }else
	
	                    if(Opcion > 1){
	                    	Opcion--;
						}
	            }else{
	            	
	            	if(Tecla == 80){
	            		
	            		if(Opcion == 6){
	            			
	            			Opcion = 1;
						}else{
							
							if(Opcion < 6){
								
								Opcion++;
							}
						}
	
					}
				}
	
	        }while(Tecla != 13);
	
	        switch(Opcion){
	
	            case 1:
	            	Registrar();
	                break;
	
	            case 2:
	                Buscar_editar_eliminar();
	                break;
	
	            case 3:
	                Registrar_movimiento();
	                break;
	
	            case 4:
	                Mostrar();
	                break;
	
	            case 5:
	                Mostrar_movimiento();
	                break;
	
	        }
	    }while(Opcion != 6);
	
	    Salir();
	}
    
    getch();

    return 0;
}
