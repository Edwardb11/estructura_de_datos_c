/* PROYECTO FINAL DE ESTRUCTURA DE DATOS POR YUDERMI HERNANDEZ Y ENMANUEL RUIZ*/

#include <string.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
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

#define t1 "Universidad Catolica Tecnologica del Cibao"
#define t2 "UCATECI"
#define t3 "LAB Estructura de Datos"
#define t4 "Pilas con punteros"
#define t5 "M e n u   P r i n c i p a l"
#define t7 "Enmanuel Ruiz Valdez               20190890"
#define Usuario "admin"
#define Clave "admin"

#define Mensaje1		"- Registrar Empleado"    
#define Mensaje2		"- Buscar/editar/eliminar Empleados" 
#define Mensaje3		"- Registrar movimientos de cuentas"     
#define Mensaje4		"- Consultar Empleados"     
#define Mensaje5		"- Consultar Movimientos de cuentas"     
// #define Mensaje6  		"- Observar promedio maximo "           
// #define Mensaje7  		"- Observar promedio minimo "           
#define Mensaje0  		"- Salir del programa "           


void setcolor( unsigned short color )
{
    HANDLE hCon = GetStdHandle( STD_OUTPUT_HANDLE );
    SetConsoleTextAttribute( hCon, color );
}
void iraxy( short x, short y )
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
        iraxy(x,y1); printf("%c",205);
        iraxy(x,y2); printf("%c",205);
    }

    for (y=y1;y<=y2;y++)
    {
        iraxy(x1,y); printf("%c",186);
        iraxy(x2,y); printf("%c",186);
    }

    iraxy(x1,y1); printf("%c",201);
    iraxy(x2,y1); printf("%c",187);
    iraxy(x1,y2); printf("%c",200);
    iraxy(x2,y2); printf("%c",188);
}
void Insertar(void);
void InsertarEmpleado(void);
void InsertarCuenta(void);
void consultarEmpleados(void);
void consultarCuenta(void);
void buscarEmpleado(void);
void editarEmpleado(int IDEmpleadoBusqueda);
void eliminarEmpleado(int IDEmpleadoBusqueda);
void Salir(void);



struct empleados{
    int IDEmpleado;
    int Balance;
    char Nombre[25];
    char Telefono[12];
    char Ciudad[50];
    char Estado[2];
    struct empleados *ant;
    struct empleados *sig;
}
*CAB_E=NULL,
*AUX_E=NULL;

struct cuentas{
    int No_cuenta;
    int IDEmpleado;
    char Fecha[10];
    char TipoMovimiento[15];
    float Monto;
    char Concepto[10];
    struct cuentas *ant;
    struct cuentas *sig;
}
*CAB_C=NULL,
*AUX_C=NULL;
int idE=1,idC=1;


int login (){
	string usuarioLogin;
	string claveLogin;
	int cont = 0;
	bool acceder = false;
	
	do {
        system("CLS");
        setcolor(BLUE);
        cuadro(18,102,1,28);
        setcolor(WHITE);
	    iraxy( (130-strlen(t5))/2, 13); printf("Inicio de Sesi%cn",162);
	    iraxy(30,16);printf("\tUsuario: ");
	    getline(cin,usuarioLogin);
	    iraxy(30,18);printf("\tClave: ");
	    char y;
	    y = getch();
	    claveLogin = "";
	    while (y != 13) {
	    	claveLogin.push_back(y);
			printf("*"); 
			y = getch();
	    }
	    if(usuarioLogin == Usuario && claveLogin == Clave) {
		   acceder = true;
	    }else{
            printf("\n\n\tLo sentimos, Usuario o Clave introducida es incorrecta.\n");
		    cin.get();
		    cont++;
		}
      } while (acceder == false && cont < 3);	
	if (acceder == false){
        system("CLS");
        setcolor(BLUE);
        cuadro(18,102,1,28);
        setcolor(WHITE);
        iraxy(25,15);printf("Has superado el limite de tres intento, intente m%cs tarde",160);
        Sleep(200);
		return 6;
	}else{
        system("CLS");
        setcolor(BLUE);
        cuadro(18,102,1,28);
        setcolor(WHITE);
        iraxy(25, 15); printf("ACCESO CONCEDIDO. CARGANDO...\n\n");
        Sleep(200);
        return 1; 
	}	
}

int main(){
    int Opcion = 1, Tecla;
    Opcion = login();
    if(Opcion != 6){
        system("CLS");
        setcolor(BLUE);
        cuadro(18,102,1,30);
        
        setcolor(YELLOW);
        iraxy( (120-strlen(t1))/2, 8);printf(t1);
        iraxy( (120-strlen(t2))/2, 9);printf(t2);
        time_t  tiempoahora;
	    time(&tiempoahora);
	    printf("\n\t\t\t\t\t\t%s", ctime(&tiempoahora));
	    struct tm* mitiempo = localtime(&tiempoahora); 
	    printf("\t\t\t\t\t\t\t%d/%d/%d", mitiempo->tm_mday,mitiempo->tm_mon+1, mitiempo->tm_year+1900);
        iraxy( (120-strlen(t3))/2, 12);printf(t3);
        iraxy( (120-strlen(t4))/2, 13);printf(t4);
        iraxy( (120-strlen(t5))/2, 14);printf(t5);
        getch();
        // system("CLS");
        // setcolor(BLUE);
        // cuadro(18,102,1,28);
        
        // setcolor(YELLOW);
        // iraxy( (120-strlen(t1))/2, 2);printf(t1);
        // iraxy( (120-strlen(t2))/2, 3);printf(t2);
        // iraxy( (120-strlen(t3))/2, 4);printf(t3);
        // iraxy( (120-strlen(t4))/2, 5);printf(t4);
        // getch();
        // // Pantalla de carga
        // system("CLS");
        // setcolor(BLUE);
        // cuadro(18,102,1,28);
        //     setcolor(WHITE);
        for(int i=25; i<95; i++){
            iraxy(((102-strlen(t5))/2)+18, 25); printf("CARGANDO...\n\n");
            iraxy(i,26); setcolor(CYAN); printf ("%c",219);
            Sleep(70);
	    }
    }
    while(Opcion != 6){
        system("CLS");
        setcolor(WHITE);
        cuadro(18,102,1,28);

        do
        {
            setcolor(WHITE);
            iraxy( (120-strlen(t5))/2, 10);printf(t5);
            iraxy(30, 12); printf(Mensaje1);
            iraxy(30, 13); printf(Mensaje2); 
            iraxy(30, 14); printf(Mensaje3);
            iraxy(30, 15); printf(Mensaje4);
            iraxy(30, 16); printf(Mensaje5);
            iraxy(30, 17); printf(Mensaje0);

            switch(Opcion)
            {
                case 1:
                    setcolor(BLUE); iraxy(30, 12); printf(Mensaje1);
                    break;

                case 2:
                    setcolor(BLUE); iraxy(30, 13); printf(Mensaje2);
                    break;

                case 3:
                    setcolor(BLUE); iraxy(30, 14); printf(Mensaje3);
                    break;

                case 4:
                    setcolor(BLUE); iraxy(30, 15); printf(Mensaje4);
                    break;

                case 5:
                    setcolor(BLUE); iraxy(30, 16); printf(Mensaje5);
                    break;

                case 6:
                    setcolor(BLUE); iraxy(30, 17); printf(Mensaje0);
                    break;
            }
            setcolor(WHITE);

            do {
                Tecla = getch();
            }while(Tecla != 13 && Tecla != 72 && Tecla != 80);

            if(Tecla == 72){
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
                if(Tecla == 80){
                    if(Opcion == 6){
                        Opcion = 1;
                    }

                    else{
                        if(Opcion < 6){
                            Opcion++;
                        }
                    }
                }
            }
        }while(Tecla != 13);

        switch(Opcion)
		{
			case 1: InsertarEmpleado();break;
			
			case 2: buscarEmpleado();break;
			
			case 3: InsertarCuenta();break;
			
			case 4: consultarEmpleados();break;
			
			case 5: consultarCuenta();break;
		}
    }
    Salir();
    return 0;
}

void InsertarEmpleado(void){
    char tituloFuncion[50]="Ingresar empleado";
    AUX_E=(struct empleados *)malloc(sizeof(struct empleados));
    system("CLS");
    setcolor(BLUE);
    cuadro(18,102,1,28);
    setcolor(WHITE);
	iraxy( (130-strlen(tituloFuncion))/2, 8); printf("%s",tituloFuncion);
    fflush(stdin);
    AUX_E->IDEmpleado=idE;
    iraxy(30,10);printf("Codigo del Empleado: %d",AUX_E->IDEmpleado);
    idE++;
    fflush(stdin);
    iraxy(30,11);printf("Nombre: ");
    gets(AUX_E->Nombre);
    fflush(stdin);
    iraxy(30,12);printf("Telefono: ");
    gets(AUX_E->Telefono);
    fflush(stdin);
    iraxy(30,13);printf("Ciudad: ");
    gets(AUX_E->Ciudad);
    strcpy (AUX_E->Estado, "A");

    if (CAB_E==NULL){
        CAB_E=AUX_E;
        AUX_E->ant=NULL;
        AUX_E->sig=NULL;
    }
    else{
        AUX_E->ant=CAB_E;
        CAB_E->sig=AUX_E->ant;
        CAB_E=AUX_E;
    }
}
void InsertarCuenta(void){
    int nRegistros=0;
    char tituloFuncion[50]="Registrar movimientos de cuentas";
    int IDEmpleado;
    char Fecha[10];
    char TipoMovimiento[15];
    float Monto;
    char Concepto[10];
    AUX_C=(struct cuentas *)malloc(sizeof(struct cuentas));
    system("CLS");
    setcolor(BLUE);
    cuadro(18,102,1,28);
    setcolor(WHITE);
	iraxy( (130-strlen(tituloFuncion))/2, 8); printf("%s",tituloFuncion);
    
    fflush(stdin);
    AUX_C->No_cuenta=idC;
    iraxy(30,10);printf("Numero de cuenta: %d",AUX_C->No_cuenta);
    idE++;
    fflush(stdin);
    iraxy(30,11);printf("Codigo del Empleado: ");
    scanf("%d",&IDEmpleado);
    fflush(stdin);
    iraxy(30,12);printf("Fecha: ");
    gets(Fecha);
    fflush(stdin);
    iraxy(30,13);printf("Tipo de Movimiento: ");
    do
        {
            setcolor(WHITE);
            iraxy(30, 14); printf("-Deposito");
            iraxy(30, 15); printf("-Retiro");

            switch(Opcion)
            {
                case 1:
                    setcolor(BLUE); iraxy(30, 14); printf("-Deposito");
                    break;

                case 2:
                    setcolor(BLUE); iraxy(30, 15); printf("-Retiro");
                    break;

            }
            setcolor(WHITE);
            do {
                Tecla = getch();
            }while(Tecla != 13 && Tecla != 72 && Tecla != 80);

            if(Tecla == 72){
                if(Opcion == 1){
                    Opcion = 2;
                }

                else{
                    if(Opcion > 2){
                        Opcion--;
                    }
                }
            }

            else{
                if(Tecla == 80){
                    if(Opcion == 2){
                        Opcion = 1;
                    }

                    else{
                        if(Opcion < 2){
                            Opcion++;
                        }
                    }
                }
            }
        }while(Tecla != 13);

    switch(Opcion)
    {
        case 1: 
            TipoMovimiento="Deposito";
            break;
        case 2: 
            TipoMovimiento="Retiro";
            break;
    }
    fflush(stdin);
    iraxy(30,16);printf("Monto: ");
    scanf("%f",&Monto);
    fflush(stdin);
    iraxy(30,17);printf("Concepto: ");
    gets(Concepto);

    while (AUX_E != NULL)
    {
        AUX_E = CAB_E;
        // comp=strcmp(AUX_E->IDEmpleado, IDEmpleadoBusqueda);
        if (AUX_E->IDEmpleado == IDEmpleado)
        {
            nRegistros++;
            break;
        }
        else
        {
            AUX_E=AUX_E->ant;
        }
    }
    if (nRegistros==1)
    {
        AUX_C->IDEmpleado=IDEmpleado;
        strcpy (AUX_C->Fecha,Fecha);
        strcpy (AUX_C->TipoMovimiento,TipoMovimiento);
        strcpy (AUX_C->Fecha,Fecha);
        strcpy (AUX_C->Monto,Monto);
        strcpy (AUX_C->Concepto,Concepto);
        comp=strcmp(AUX_C->TipoMovimiento,"Deposito");
        if (comp==0){
            AUX_E->Balance= AUX_E->Balance + Monto;
        }
        comp=strcmp(AUX_C->TipoMovimiento,"Retiro");
        if (comp==0){
            AUX_E->Balance= AUX_E->Balance - Monto;
        }
    }


    if (CAB_C==NULL){
        CAB_C=AUX_C;
        AUX_C->ant=NULL;
        AUX_C->sig=NULL;
    }
    else{
        AUX_C->ant=CAB_C;
        CAB_C->sig=AUX_C;
        CAB_C=AUX_C;
    }
}
void consultarEmpleados(void){
    int y=10,comp;
    char tituloFuncion[50]="Consultar empleados";
    system("CLS");
    setcolor(BLUE);
    cuadro(18,102,1,28);
    setcolor(WHITE);
	iraxy((125-strlen(tituloFuncion))/2, 5); printf("%s",tituloFuncion);
    AUX_E=CAB_E;

    if (CAB_E==NULL){
        iraxy(22,13);printf("No hay empleados todavia");
        iraxy(22,14);printf("Pulse cualquier tecla para volver al menu principal y regitrarlos");
        iraxy(22,15);printf("...");
        getch();
        return;
    }
    else {
        iraxy(20,7);printf("---------------------------------------------------------------------------------");
        setcolor(BLUE);
        iraxy(20,8);printf("| ID | Nombre                   | Tel%cfono     | Ciudad                | Estado |",130);
        setcolor(WHITE);
        iraxy(20,8);printf("|");
        iraxy(25,8);printf("|");
        iraxy(52,8);printf("|");
        iraxy(67,8);printf("|");
        iraxy(91,8);printf("|");
        iraxy(100,8);printf("|");
        iraxy(20,9);printf("---------------------------------------------------------------------------------");
        while (AUX_E != NULL)
        {
            comp=strcmp(AUX_E->Estado,"A");
            if (comp==0)
            {
                iraxy(20,y);printf("| %d",AUX_E->IDEmpleado);
                iraxy(25,y);printf("| %s",AUX_E->Nombre);
                iraxy(52,y);printf("| %s",AUX_E->Telefono);
                iraxy(67,y);printf("| %s",AUX_E->Ciudad);
                iraxy(91,y);printf("| %s",AUX_E->Estado);
                iraxy(100,y);printf("|");
                y++;
            }
            AUX_E=AUX_E->ant;
        }
        iraxy(20,y);printf("---------------------------------------------------------------------------------");
        getch();
    }
}
void consultarCuenta(void){
    int y=10;
    char tituloFuncion[50]="Consultar Movimientos de Cuentas";
    system("CLS");
    setcolor(BLUE);
    cuadro(18,102,1,28);
    setcolor(WHITE);
	iraxy((125-strlen(tituloFuncion))/2, 5); printf("%s",tituloFuncion);
    AUX_C=CAB_C;

    if (CAB_C==NULL){
        iraxy(22,13);printf("No hay movimiento de cuentas todavia");
        iraxy(22,14);printf("Pulse cualquier tecla para volver al menu principal y regitrarlos");
        iraxy(22,15);printf("...");
        getch();
        return;
    }
    else {
        iraxy(20,7);printf("---------------------------------------------------------------------------------");
        setcolor(BLUE);
        iraxy(20,8);printf("| No.Cuenta | ID Empleado | Fecha | Tipo Movimiento | Monto          | Concepto |");
        setcolor(WHITE);
        iraxy(20,8);printf("|");
        iraxy(32,8);printf("|");
        iraxy(46,8);printf("|");
        iraxy(54,8);printf("|");
        iraxy(72,8);printf("|");
        iraxy(89,8);printf("|");
        iraxy(100,8);printf("|");
        iraxy(20,9);printf("---------------------------------------------------------------------------------");
        while (AUX_C != NULL)
        {
            iraxy(20,y);printf("| %d",AUX_C->No_cuenta);
            iraxy(32,y);printf("| %d",AUX_C->IDEmpleado);
            iraxy(46,y);printf("| %s",AUX_C->Fecha);
            iraxy(54,y);printf("| %s",AUX_C->TipoMovimiento);
            iraxy(72,y);printf("| %.2f",AUX_C->Monto);
            iraxy(89,y);printf("| %s",AUX_C->Concepto);
            iraxy(100,y);printf("|");
            y++;
            AUX_C=AUX_C->ant;
        }
        iraxy(20,y);printf("---------------------------------------------------------------------------------");
        getch();
    }
}
void buscarEmpleado(void){
    int y=10,nRegistros=0,comp,Opcion = 1, Tecla;
    char nombreBusqueda[25];
    char tituloFuncion[50]="Buscar empleados";
    system("CLS");
    setcolor(BLUE);
    cuadro(18,102,1,28);
    setcolor(WHITE);
	iraxy(((102-strlen(tituloFuncion))/2)+18, 5); printf("%s",tituloFuncion);
    AUX_E=CAB_E;
    if (CAB_E==NULL){
        iraxy(22,13);printf("No hay empleados todavia");
        iraxy(22,14);printf("Pulse cualquier tecla para volver al menu principal y regitrarlos");
        iraxy(22,15);printf("...");
        getch();
        return;
    }
    else 
    {
        iraxy(30,15);printf("Ingrese del empleado que desea buscar ");
        fflush(stdin);
        iraxy(30,16);printf("Nombre: ");
        gets(nombreBusqueda);
        system("CLS");
        setcolor(BLUE);
        cuadro(18,102,1,28);
        setcolor(WHITE);
        iraxy((125-strlen(tituloFuncion))/2, 5); printf("%s (%s)",tituloFuncion,nombreBusqueda);
        while (AUX_E != NULL)
        {
            comp=strcmp(AUX_E->Nombre, nombreBusqueda);
            if (comp == 0)
            {
                if (nRegistros==0)
                {
                    iraxy(20,7);printf("---------------------------------------------------------------------------------");
                    setcolor(BLUE);
                    iraxy(20,8);printf("| ID | Nombre                   | Tel%cfono     | Ciudad                | Estado |",130);
                    setcolor(WHITE);
                    iraxy(20,8);printf("|");
                    iraxy(25,8);printf("|");
                    iraxy(52,8);printf("|");
                    iraxy(67,8);printf("|");
                    iraxy(91,8);printf("|");
                    iraxy(100,8);printf("|");
                    iraxy(20,9);printf("---------------------------------------------------------------------------------");
                }
                iraxy(20,y);printf("| %d",AUX_E->IDEmpleado);
                iraxy(25,y);printf("| %s",AUX_E->Nombre);
                iraxy(52,y);printf("| %s",AUX_E->Telefono);
                iraxy(67,y);printf("| %s",AUX_E->Ciudad);
                iraxy(91,y);printf("| %s",AUX_E->Estado);
                iraxy(100,y);printf("|");
                y++;
                nRegistros++;
                break;
            }
            else{
                AUX_E=AUX_E->ant;
            }
        }
        if(nRegistros!=0)
        {
            iraxy(20,y);printf("---------------------------------------------------------------------------------");
            do
            {
                setcolor(WHITE);
                iraxy(30, 22);printf("O P C I O N E S");
                iraxy(30, 23); printf("-Editar");
                iraxy(30, 24); printf("-Eliminar"); 
                iraxy(30, 25); printf("-Atras");

                switch(Opcion)
                {
                    case 1:
                        setcolor(BLUE); iraxy(30, 23); printf("-Editar");
                        break;

                    case 2:
                        setcolor(BLUE); iraxy(30, 24); printf("-Eliminar");
                        break;

                    case 3:
                        setcolor(BLUE); iraxy(30, 25); printf("-Atras");
                        break;
                }
                setcolor(WHITE);
                do {
                    Tecla = getch();
                }while(Tecla != 13 && Tecla != 72 && Tecla != 80);

                if(Tecla == 72){
                    if(Opcion == 1){
                        Opcion = 3;
                    }

                    else{
                        if(Opcion > 1){
                            Opcion--;
                        }
                    }
                }

                else{
                    if(Tecla == 80){
                        if(Opcion == 3){
                            Opcion = 1;
                        }

                        else{
                            if(Opcion < 3){
                                Opcion++;
                            }
                        }
                    }
                }
            }while(Tecla != 13);

            switch(Opcion)
            {
                case 1: editarEmpleado(AUX_E->IDEmpleado);break;
                
                case 2: eliminarEmpleado(AUX_E->IDEmpleado);break;
            }
        }
        else
        {
            iraxy(30,16);printf("No se escontraron registros con este nombre");
            getch();
        }
    }
}
void editarEmpleado(int IDEmpleadoBusqueda){
    int y=10,nRegistros=0,comp,Opcion = 1, Tecla;
    char nombreBusqueda[25];
    char tituloFuncion[50]="Editar empleado";
    system("CLS");
    setcolor(BLUE);
    cuadro(18,102,1,28);
    setcolor(WHITE);
	iraxy(((102-strlen(tituloFuncion))/2)+9, 5); printf("%s",tituloFuncion);
    AUX_E = CAB_E;
    while (AUX_E != NULL)
    {
        // comp=strcmp(AUX_E->IDEmpleado, IDEmpleadoBusqueda);
        if (AUX_E->IDEmpleado == IDEmpleadoBusqueda)
        {
            nRegistros++;
            break;
        }
        else
        {
            AUX_E=AUX_E->ant;
        }
    }
    if (nRegistros==1)
    {
        iraxy(30,8);printf("Editando Empleado: %s",AUX_E->Nombre);
        iraxy(30,10);printf("Codigo del Empleado: %d",AUX_E->IDEmpleado);
        fflush(stdin);
        iraxy(30,11);printf("Nombre: ");
        gets(AUX_E->Nombre);
        fflush(stdin);
        iraxy(30,12);printf("Telefono: ");
        gets(AUX_E->Telefono);
        fflush(stdin);
        iraxy(30,13);printf("Ciudad: ");
        gets(AUX_E->Ciudad);
        system("CLS");
        setcolor(BLUE);
        cuadro(18,102,1,28);
        iraxy(30,8);printf("Empleado ID%d editado con exito",AUX_E->IDEmpleado);
        setcolor(WHITE);
    }
    else
    {
        iraxy(30,8);printf("No se encontro un registro unico");
    }
    getch();
}
void eliminarEmpleado(int IDEmpleadoBusqueda){
    int y=10,nRegistros=0,comp,Opcion = 1, Tecla;
    char nombreBusqueda[25];
    char tituloFuncion[50]="Eliminar empleado";
    system("CLS");
    setcolor(BLUE);
    cuadro(18,102,1,28);
    setcolor(WHITE);
	iraxy(((102-strlen(tituloFuncion))/2)+9, 5); printf("%s",tituloFuncion);
    AUX_E = CAB_E;
    while (AUX_E != NULL)
    {
        // comp=strcmp(AUX_E->IDEmpleado, IDEmpleadoBusqueda);
        if (AUX_E->IDEmpleado == IDEmpleadoBusqueda)
        {
            nRegistros++;
            break;
        }
        else
        {
            AUX_E=AUX_E->ant;
        }
    }
    if (nRegistros==1)
    {
        iraxy(30,8);printf("En realidad desea eliminar Empleado: %s Codigo: %d",AUX_E->Nombre,AUX_E->IDEmpleado);
        do
        {
            setcolor(WHITE);
            iraxy(30, 15); printf("-Confirmar");
            iraxy(30, 16); printf("-Cancelar");

            switch(Opcion)
            {
                case 1:
                    setcolor(BLUE); iraxy(30, 15); printf("-Confirmar");
                    break;

                case 2:
                    setcolor(BLUE); iraxy(30, 16); printf("-Cancelar");
                    break;

            }
            setcolor(WHITE);
            do {
                Tecla = getch();
            }while(Tecla != 13 && Tecla != 72 && Tecla != 80);

            if(Tecla == 72){
                if(Opcion == 1){
                    Opcion = 2;
                }

                else{
                    if(Opcion > 2){
                        Opcion--;
                    }
                }
            }

            else{
                if(Tecla == 80){
                    if(Opcion == 2){
                        Opcion = 1;
                    }

                    else{
                        if(Opcion < 2){
                            Opcion++;
                        }
                    }
                }
            }
        }while(Tecla != 13);

        switch(Opcion)
        {
            case 1: 
                if(AUX_E->Balance>=0){
                    strcpy (AUX_E->Estado, "I");
                }
                else{
                }
                break;
        }
        system("CLS");
        setcolor(BLUE);
        cuadro(18,102,1,28);
        iraxy(30,8);printf("Empleado ID%d editado con exito",AUX_E->IDEmpleado);
        setcolor(WHITE);
    }
    else
    {
        iraxy(30,8);printf("No se encontro un registro unico");
        getch();
    }
}
void Salir(){
    system("CLS");
    printf("%cGracias, regrese pronto!", 173);
    getch();
}