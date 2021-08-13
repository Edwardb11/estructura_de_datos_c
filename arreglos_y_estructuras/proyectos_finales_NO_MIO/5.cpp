#include <iostream>
#include <stdio.h> 
#include <stdlib.h>  
#include <cstdlib>
#include <string>
#include <limits>
#include <vector>
#include <sstream>
#include <numeric>
#include <ctime>
#include <cmath>
#include <windows.h>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
string USER = "admin";
string PASSWORD = "admin";
int intentos_permitidos = 3;
bool LOGUEADO = false;
string NOMBRE = "Eidher Cruz Ramirez y Helmer Enrique Sosa";
string MATRICULA = "2019-0198 y 2019-0163";
string MATERIA = "Estrunctura de datos";
string PRESENTACION = "UNIVERSIDAD CATOLICA DEL CIBAO";
string ERRORS = "";
string SUCCESS = "";
int LASD_ID = 0;
INT LASD_ID_CUENTA = 0;
class CUENTA {
	public:
		int no_cuenta;
		int IDEmpleado;
//		auto Fecha = std::chrono::system_clock::now();
		string Fecha;
		string TipoMovimiento;
		double Monto;
		string Concepto;
		void mostrar(){
    	printf("\n no_cuenta: %i \n IDEmpleado: %i \n Fecha: %s \n Tipo Movimiento: %s \n Monto: %f \n Concepto: %s \n",no_cuenta, IDEmpleado, Fecha.c_str(), TipoMovimiento.c_str(), Monto, Concepto.c_str() );
		};
		void mostrarln(){
	    	printf("\n %i             %i             %s            %s              %f           %s \n", no_cuenta, IDEmpleado, Fecha.c_str(), TipoMovimiento.c_str(), Monto, Concepto.c_str() );
		};
		
};

struct NodoCuenta{
	CUENTA datos;
	NodoCuenta *siguiente;	
};

class PERSON {       
  public:             
    int IDEmpleado;        
    string Nombre;  
    string Telefono;
    string Ciudad;
    string Estado;
    void mostrar(){
    	printf("\n IDEmpleado: %i \n Nombre: %s \n Telefono: %s \n Ciudad: %s \n Estado: %s \n", IDEmpleado, Nombre.c_str(), Telefono.c_str(), Ciudad.c_str(), Estado.c_str() );
	};
	void mostrarln(){
    	printf("\n %i                 %s            %s              %s            %s \n", IDEmpleado, Nombre.c_str(), Telefono.c_str(), Ciudad.c_str(), Estado.c_str() );
	};
	void Cabeza(){
    	printf("\n IDEmpleado     Nombre      Telefono     Ciudad      Estado     \n");
	};
};

vector<PERSON> PERSONAS;

struct NodoPersona{
	PERSON datos;
	NodoPersona *siguiente;	
};

void agregarPilaPersonas(NodoPersona *&,PERSON);
void sacarPilaPersonas(NodoPersona *&, int);
void MostrarPilaPersonas(NodoPersona *&);
void EncontrarPilaPersonas(NodoPersona *&, string);

void agregarPilaCuenta(NodoCuenta *&,CUENTA);
void sacarPilaCuenta(NodoCuenta *&, int);
void MostrarPilaCuenta(NodoCuenta *&);
void EncontrarPilaCuenta(NodoCuenta *&, string);
void EncontrarPilaCuentaByEmpleado(NodoCuenta *&, string);
void EstadoPilaCuentaByEmpleado(NodoCuenta *&, string);
int main(int argc, char** argv) {
	string user, password;
	NodoPersona *pilaPersonas = NULL;
	NodoCuenta *pilaCuentas = NULL;
	
	while (intentos_permitidos > 0){
		system("cls");
		printf("Manager de Cuentas de Bancos <=======> tiene %d intentos permitidos", intentos_permitidos);
		cout << endl;
		cout << "user: ";
		cin >> user;
		
		cout << "password: ";
		cin >> password;
		
		if (user != USER || password != PASSWORD){
			intentos_permitidos = intentos_permitidos - 1;
		}else {
			LOGUEADO = true;
		}
		
		if (LOGUEADO) {
		
			system("cls");
			printf("Bienvenido al Manager de Cuentas de Bancos \n");
			printf("%s %s \n", NOMBRE.c_str(), MATRICULA.c_str());
			for (int i = 0; i < 100; i++) {
			  cout << "#";
			  Sleep(5);
			}
			
			system("cls");
			
			int opcion = 0;
			
			while(LOGUEADO){
				
				
				printf("%s \n \n", PRESENTACION.c_str());
				
				if(ERRORS.length() > 0){
					printf("%s \n \n", ERRORS.c_str());
				}
				
				if(SUCCESS.length() > 0){
					printf("%s \n \n", SUCCESS.c_str());
				}
				
				printf("1 = Registrar Empleado \n");
				printf("2 = Buscar/Editar/Eliminar Empleado \n");
				printf("3 = Registrar Movimiento de Cuenta \n");
				printf("4 = Consultar Empleado \n");
				printf("5 = Consultar Movimientos de Cuentas \n");
				printf("6 = Obserbar Promedio Maximo \n");
				printf("0 = Salir del Programa \n");
				cout << "\n |==> Opcion: ";
				cin >> opcion;
				
				if(cin.fail()){
					opcion = 20;
					cin.clear();
					cin.ignore();
				}else {
					ERRORS = "";
					SUCCESS = "";
				}
				
				system("cls");
				
				switch(opcion){
					case 1:{
				
						printf("Registrar Empleado \n \n");
						
						PERSON persona;
						persona.IDEmpleado = LASD_ID + 1;
						
						printf("\n Nombre: ");
						cin >> persona.Nombre;
						
						printf("\n Telefono: ");
						cin >> persona.Telefono;
						
						printf("\n Ciudad: ");
						cin >> persona.Ciudad;
						
						printf("\n Estado: ");
						cin >> persona.Estado;
						
						system("cls");
						
						persona.mostrar();
						char guardar = 'n';
						printf("Es Esta Informacion Correcta ? [y/n]: ");
						cin >> guardar;
						
						if(guardar == 'y'){
							LASD_ID = LASD_ID + 1;
							agregarPilaPersonas(pilaPersonas, persona);
							PERSONAS.push_back(persona);
							SUCCESS = "Datos Guardados Exitosamente";
						} else {
							ERRORS = "Datos no Guardados";
						};
						
						system("cls");
						break;
					}
						
					case 2:{
						int opt;
						bool back = true;
						while(back){
							printf("Buscar/Editar/Eliminar Empleado \n ");
							printf("\n 1 = Buscar\n");
							printf("2 = Editar\n");
							printf("3 = Eliminar \n");
							printf("4 = Mostrar Todo\n");
							printf("0 = Atras \n");
							cout << "\n |==> Opcion: ";
							cin >> opt;
							switch(opt){
								case 1: {
									string param;
									string none = "pop";
									system("cls");
									printf("Busqueda de Empleado \n \n");
									printf("Introduce un Parametro: ");
									cin >> param;
									
									EncontrarPilaPersonas(pilaPersonas, param);
									
									cout << "Presione Enter Para Volver atras..." << endl;
									
									getline(cin, none);
									if(cin.get() == '\n'){
										break;
									}
									
									
								}
								case 2: {
									system("cls");
									printf("Editar Empleado \n \n");
									printf("Introduce Id del empleado: ");
									int id;
									string na;
									cin >> id;
									int indexOld = 0;
									for (int i = 0; i < PERSONAS.size(); i++) {
										 
									  if(PERSONAS[i].IDEmpleado == id ){
									  	printf("\n IDEmpleado     Nombre      Telefono     Ciudad      Estado     \n");
									  	PERSONAS[i].mostrarln();
									  	indexOld = i;
									  }
									}
									PERSON NewPersona;
									NewPersona.IDEmpleado = PERSONAS[indexOld].IDEmpleado;
									
									printf("\n Nombre[ %s ]: ", PERSONAS[indexOld].Nombre.c_str());

									cin >> NewPersona.Nombre;
																	

									
									printf("\n Telefono[ %s ]: ", PERSONAS[indexOld].Telefono.c_str());
									
									cin >> NewPersona.Telefono;

									
									printf("\n Ciudad[ %s ]: ", PERSONAS[indexOld].Ciudad.c_str());
									
									cin >> NewPersona.Ciudad;

									
									printf("\n Estado[ %s ]: ", PERSONAS[indexOld].Estado.c_str());
									
									cin >> NewPersona.Estado;

									
									system("cls");
									
									NewPersona.mostrar();
									char guardar = 'n';
									printf("Es Esta Informacion Correcta ? [y/n]: ");
									cin >> guardar;
									
									if(guardar == 'y'){
										PERSONAS[indexOld] = NewPersona;
										SUCCESS = "Datos Guardados Exitosamente";
									} else {
										ERRORS = "Datos no Guardados";
									};
									
									system("cls");
									break;
								}
								
								case 3: {
									system("cls");
									printf("Eliminar Empleado \n \n");
									printf("Introduce Id del empleado: ");
									int id;
									string na;
									cin >> id;
									
									sacarPilaPersonas(pilaPersonas, id);
									
									system("cls");
									break;
								}
								
								case 4: {
									
									system("cls");
									string none;
									printf("Emppleados: ");
									MostrarPilaPersonas(pilaPersonas);
									cout << "Presione Enter Para Volver atras... \n" << endl;
									
									getline(cin, none);
									if(cin.get() == '\n'){
										break;
									}
								}
								
								case 0: {
									back = false;
									break;
								}
							}
							system("cls");
						}
						break;
					}
						
						
					case 3:{
				
						printf("Registrar Movimiento de Cuenta \n \n");
						
						CUENTA cuenta;
						cuenta.no_cuenta = LASD_ID_CUENTA + 1;
						
						printf("\n ID_Empleado: ");
						cin >> cuenta.IDEmpleado;
						
						printf("\n Fecha: ");
						cin >> cuenta.Fecha;
						
						printf("\n Tipo Movimiento (Debito[d]/Credito[c]): ");
						cin >> cuenta.TipoMovimiento;
						
						while(cuenta.TipoMovimiento != "d" and cuenta.TipoMovimiento != "c"){
							printf("estrinctamente [d] o [c] \n");
							printf("\n Movimiento (Debito[d]/Credito[c]): ");
							cin >> cuenta.TipoMovimiento;
						}
						
						printf("\n Monto: ");
						cin >> cuenta.Monto;
						
						
						printf("\n Concepto: ");
						cin >> cuenta.Concepto;
						
						system("cls");
						
						cuenta.mostrar();
						char guardar = 'n';
						printf("Es Esta Informacion Correcta ? [y/n]: ");
						cin >> guardar;
						
						if(guardar == 'y'){
							LASD_ID_CUENTA = LASD_ID_CUENTA + 1;
							agregarPilaCuenta(pilaCuentas, cuenta);
							SUCCESS = "Datos Guardados Exitosamente";
						} else {
							ERRORS = "Datos no Guardados";
						};
						
						system("cls");
						break;
					}
						
					case 4:{
					 string params;
					 string none = "pop";
				     system("cls");
					 printf("Busqueda de Cuentas \n \n");
					 printf("Introduce un ID de empleado: ");
					 cin >> params;
					 EncontrarPilaPersonas(pilaPersonas, params);
					 EstadoPilaCuentaByEmpleado(pilaCuentas, params);		
					 EncontrarPilaCuentaByEmpleado(pilaCuentas, params);
									
				     cout << "Presione Enter Para Volver atras..." << endl;
									
					 getline(cin, none);
					 if(cin.get() == '\n'){
						break;
					 }
									
									
					}
						
					case 5:{
					 string params;
					 string none = "pop";
				     system("cls");
					 printf("Consultar Movimientos de Cuentas \n \n");
					 printf("Introduce un ID de empleado: ");
					 cin >> params;
//					 EncontrarPilaPersonas(pilaPersonas, params);
					EstadoPilaCuentaByEmpleado(pilaCuentas, params);			
					 EncontrarPilaCuentaByEmpleado(pilaCuentas, params);
									
				     cout << "Presione Enter Para Volver atras..." << endl;
									
					 getline(cin, none);
					 if(cin.get() == '\n'){
						break;
					 }
									
									
					}
						
					case 6:
						printf("6 = Obserbar Promedio Maximo \n");
						break;
						
					case 0:
						printf("0 = Salir del Programa \n");
						return 0;
						break;
						
					default:
						ERRORS = "OPCION INVALIDA: Elija Opciones del menu.";
						break;
				}
			}
		}
		
	
	}
	
	if(intentos_permitidos == 0){
		system("cls");
		cout << "========> Intentos Maximos permitidos han sido superado <========" << endl;	
	}
	return 0;
}

void agregarPilaPersonas(NodoPersona *&pila,PERSON n){
	NodoPersona *nuevo_nodo = new NodoPersona();
	nuevo_nodo->datos = n;
	nuevo_nodo->siguiente = pila;
	pila = nuevo_nodo;
}

void sacarPilaPersonas(NodoPersona *&pila, int id){
	NodoPersona *aux = pila;
		while(aux != NULL){
								 
		if(aux->datos.IDEmpleado == id){
			printf("\n IDEmpleado     Nombre      Telefono     Ciudad      Estado     \n");
			aux->datos.mostrarln();
			break;
		}
		
		
		aux = aux->siguiente;
	}
	if(aux == NULL){
		printf("Persona Nno Encontrada");
	}else {
		printf("Esta Seguro que desea eliminar Empleado ? [y/n]: ");
									
		char guardar = 'n';
									
		cin >> guardar;
									
		if(guardar == 'y'){
			pila = aux->siguiente;
			delete aux;
			
		} 
	}
	

}

void MostrarPilaPersonas(NodoPersona *&pila){
	NodoPersona *aux = pila;
	printf("\n IDEmpleado     Nombre      Telefono     Ciudad      Estado     \n");
	while(aux != NULL){
		aux->datos.mostrarln();
		aux = aux->siguiente;
	}
}

void EncontrarPilaPersonas(NodoPersona *&pila, string param){
	NodoPersona *aux = pila;
	printf("\n IDEmpleado     Nombre      Telefono     Ciudad      Estado     \n");
	while(aux != NULL){
										
		std::size_t found1 = aux->datos.Nombre.find(param);
		std::size_t found2 = aux->datos.Telefono.find(param);
		std::size_t found3 = aux->datos.Ciudad.find(param);
		std::size_t found4 = aux->datos.Estado.find(param);
										 
		if(aux->datos.IDEmpleado == atoi(param.c_str()) or  found1 != std::string::npos or found2 != std::string::npos or found3  != std::string::npos or found4 != std::string::npos){
			aux->datos.mostrarln();
		}
		
		aux = aux->siguiente;
	}
}


void agregarPilaCuenta(NodoCuenta *&pila,CUENTA n){
	NodoCuenta *nuevo_nodo = new NodoCuenta();
	nuevo_nodo->datos = n;
	nuevo_nodo->siguiente = pila;
	pila = nuevo_nodo;
}

void sacarPilaCuenta(NodoCuenta *&pila, int id){
	NodoCuenta *aux = pila;
		while(aux != NULL){
								 
		if(aux->datos.IDEmpleado == id){
			printf("\n IDEmpleado     Nombre      Telefono     Ciudad      Estado     \n");
			aux->datos.mostrarln();
			break;
		}
		
		
		aux = aux->siguiente;
	}
	if(aux == NULL){
		printf("Persona Nno Encontrada");
	}else {
		printf("Esta Seguro que desea eliminar Empleado ? [y/n]: ");
									
		char guardar = 'n';
									
		cin >> guardar;
									
		if(guardar == 'y'){
			pila = aux->siguiente;
			delete aux;
			
		} 
	}
	

}

void MostrarPilaCuenta(NodoCuenta *&pila){
	NodoCuenta *aux = pila;
	printf("\n IDEmpleado     Nombre      Telefono     Ciudad      Estado     \n");
	while(aux != NULL){
		aux->datos.mostrarln();
		aux = aux->siguiente;
	}
}

void EncontrarPilaCuenta(NodoCuenta *&pila, string param){
	NodoCuenta *aux = pila;
	printf("\n IDEmpleado     Nombre      Telefono     Ciudad      Estado     \n");
	while(aux != NULL){
										
		std::size_t found1 = aux->datos.TipoMovimiento.find(param);
		std::size_t found2 = aux->datos.Concepto.find(param);
		std::size_t found3 = aux->datos.Fecha.find(param);
//		std::size_t found4 = aux->datos.Estado.find(param);
										 
		if(aux->datos.IDEmpleado == atoi(param.c_str()) or  found1 != std::string::npos or found2 != std::string::npos or found3  != std::string::npos or aux->datos.no_cuenta == atoi(param.c_str()) or aux->datos.Monto == atoi(param.c_str())){
			aux->datos.mostrarln();
		}
		
		aux = aux->siguiente;
	}
}

void EncontrarPilaCuentaByEmpleado(NodoCuenta *&pila, string param){
	NodoCuenta *aux = pila;
	printf("no_cuenta           IDEmpleado          Fecha               Tipo Movimiento                Monto               Concepto");
	while(aux != NULL){
																				 
		if(aux->datos.IDEmpleado == atoi(param.c_str())){
			aux->datos.mostrarln();
		}
		
		aux = aux->siguiente;
	}
}

void EstadoPilaCuentaByEmpleado(NodoCuenta *&pila, string param){
	double Estado = 0;
	double debito = 0;
	double credito = 0;
	
	NodoCuenta *aux = pila;
	printf("ESTADO DE CUENTA: ");
	while(aux != NULL){
																				 
		if(aux->datos.IDEmpleado == atoi(param.c_str())){
			if(aux->datos.TipoMovimiento == "d"){
				debito = debito + aux->datos.Monto;
			}
			if(aux->datos.TipoMovimiento == "c"){
				credito = credito + aux->datos.Monto;
			}
		}
		
		aux = aux->siguiente;
	}
	
	Estado = debito - credito;
	cout << Estado << endl;
}
