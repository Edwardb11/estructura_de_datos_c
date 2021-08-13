#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string>
#include <windows.h>
#include <ctime>
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

#define ENTER 13
#define BACKSPACE 8
#define INTENTOS 3
#define Mensaje1 "1.Registrar Empleado"
#define Mensaje2 "2.Buscar/Editar/Eliminar Empleado"
#define Mensaje3 "3.Registrar Movimientos de Cuentas"
#define Mensaje4 "4.Consultar Empleados"
#define Mensaje5 "5.Consultar Mov. de Cuentas"
#define Mensaje6 "6.Salir"

/////////////////////////////////// FUNCIONES///////////////////////////////////
void login();
void Carga();
void presentacion();
int principal();
void insertarE();
void editarE();
void insertarC();
void consultarE();
void consultarC();
int existeEmpleadoConsultado (int id_empleado);
void existeCuenta (int id_empleado);
void existeCuenta1 (int id_empleado);
void existeCuenta2 (int id_empleado);
int existeEC(int id_empleado);
int BuscarEmpleado(char nombre_empleado[500]);
void consultarE();
void consultarC();
void consultarMov();
void editar();
void eliminar();
void mostrar();
void buscar();
void Salir();
///////////////////////////////////////////////////////////////////////////

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
	    time_t tiempo = time(0);
        struct tm *tlocal = localtime(&tiempo);
        char output[128];
        strftime(output,128,"%d/%m/%y %H:%M:%S",tlocal);
        printf("%s\n",output);
}

void Salir(){
	system("CLS");
    setcolor(YELLOW);
    gotoxy(39,9);
    printf("~%cGracias, regrese pronto! ~", 173);
    getch();
    exit(-1);
}

struct empleado
{
int id;
char nombre[500],telefono[500],ciudad[500],estado[500];
struct empleado *sigE;
}
*CABE = NULL,
*AUXE = NULL, *FINE = NULL;

struct cuenta
{
int ncuenta,idE,monto, balance;
char fecha[500],tipo[500],concepto[500];
struct cuenta *sigC;
}
    *CABC = NULL,
    *AUXC = NULL, *FINC = NULL,*CT=NULL;
     int cantidad=0,total=0, cantC=0,contador=0,vacio=0,vacioc=0;  
/////////////////////////////////////////////////////////////////////////////////////     

void login(){  
    const string usuarioof="admin";
    const string claveof="admin";
    string usuario, password; 
    contador = 0;
    bool ingresa = false;
    do
    {
        system("CLS");
        setcolor(LIGHTMAGENTA);
        cuadro(28,83,2,15);
        setcolor(YELLOW);
        gotoxy(48, 4);printf("INICIAR SESION");
        setcolor(WHITE);
        gotoxy(37,6);printf("Usuario: ");
        getline(cin,usuario);
        char caracter;
        gotoxy(37,8);printf("Password: ");
        caracter = getch();
        password = "";
        while (caracter != ENTER)
        {
            if (caracter != BACKSPACE)//PARA IDENTIFICAR LAS LETRAS Y SUSTITUIR CON ASTERISCOS
            {
                password.push_back(caracter);
                printf("*");
            }
            else
            {
                if (password.length() > 0) 
                {
                    printf("\b \b");
                    password = password.substr(0, password.length() - 1);
                }
            }
            caracter = getch();
        }
        if (usuarioof==usuario&& claveof==password) // SI LA CLAVE Y USUARIO SON CORRECTOS SE DEVUELVE TRUE
            {
                ingresa = true;
                break;
            }
        if (!ingresa)
        {
            setcolor(YELLOW);
            contador++;
			gotoxy(30,10);printf("El usuario y/o password son incorrectos, Intento %i/3",contador);
			getch();
			setcolor(WHITE);
            
        }
    } while (ingresa == false && contador < INTENTOS);
    if (ingresa == false)
    {   setcolor(LIGHTRED);
        gotoxy(39,12);printf("Ha Excedido el N%cmero de Intentos",163);
        setcolor(WHITE);
        getch();
        getch();
    }
    else
    {
    	setcolor(YELLOW);
    	gotoxy(37,10);printf("El Usuario y Password Son Correctos.");
    	Sleep(1150);
    	system("CLS");
        //Carga();
    }
}     
/////////////////////////////////////////////////////////////////////////////////////

void presentacion(){
    setcolor(LIGHTMAGENTA);
	cuadro(30,80,3,20);
	setcolor(WHITE);
	gotoxy(40,7);printf("UNIVERSIDAD CATOLICA DEL CIBAO");
	setcolor(YELLOW);
    gotoxy(45,9);fecha();
	setcolor(LIGHTMAGENTA);
	gotoxy(48,11);printf("~ Maestros ~");
	setcolor(WHITE);
	gotoxy(47,13);printf("Diego Casta%cos",164);
	gotoxy(45,14);printf("Jos%c Capell%cn Mar%ca",130,160,161);
	setcolor(YELLOW);
	gotoxy(44,16);printf("~ SISTEMA G&R BANK ~");
	setcolor(WHITE);
	getch();
	principal();
}

////////////////////////////////////////////////////////////////////////////////////////
void Carga(){
    setcolor(LIGHTMAGENTA);
	cuadro(30,80,3,22);
	setcolor(WHITE);
	gotoxy(45,7);printf("Estructura De Datos");
	setcolor(LIGHTMAGENTA);
	gotoxy(48,9);printf("~ Creadoras ~");
	setcolor(WHITE);
	gotoxy(43,11);printf("G%cnesis D%caz (2019-0212)",130,161);
	gotoxy(40,12);printf("Roberlina Caminero (2019-0322)");
	setcolor(YELLOW);
	gotoxy(41,14);printf("Bienvenidos/as a G&R Bank");
	gotoxy(50,19); printf("CARGANDO...");

	for(int i=0; i < 41; i++) 
	{
		setcolor(LIGHTGREEN);
		gotoxy(35+i,17);
		printf("%c",219);
		Sleep(150);
		if(i==5)Sleep(200);
		if(i==10)Sleep(300);
		if(i==16)Sleep(500);
		if(i==21)Sleep(300);
		if(i==28)Sleep(200);
		if(i==30)Sleep(500);
	}
	Sleep(10);
	system("CLS");
	setcolor(WHITE);
	presentacion();
}
/////////////////////////////////////////////////////////////////////////////////////
int principal(){
	int Opcion = 1, Tecla;
    do
    {
        do
        {
            system("CLS");
            cuadro(15, 93, 1, 9);
            setcolor(LIGHTMAGENTA);
            gotoxy(50, 2);
            printf("UCATECI");
            setcolor(WHITE);
            gotoxy(44, 3);
            printf("ESTRUCTURA DE DATOS");
            gotoxy(46, 4);
            printf("Proyecto Final");
            gotoxy(45, 5);
            setcolor(YELLOW);
            fecha();
            setcolor(LIGHTMAGENTA);
            gotoxy(20, 7);
            printf("2019-0212");
            gotoxy(73, 7);
            printf("2019-0322");
            setcolor(WHITE);
            gotoxy(20, 8);
            printf("G%cnesis D%caz", 130, 161);
            gotoxy(73, 8);
            printf("Roberlina Caminero");

            setcolor(WHITE);
            cuadro(30, 78, 11, 21);
            gotoxy(45, 11);
            printf(" MENU PRINCIPAL");

            setcolor(LIGHTMAGENTA);
            gotoxy(39, 13);
            printf(Mensaje1);
            gotoxy(39, 14);
            printf(Mensaje2);
            gotoxy(39, 15);
            printf(Mensaje3);
            gotoxy(39, 16);
            printf(Mensaje4);
            gotoxy(39, 17);
            printf(Mensaje5);
            gotoxy(39, 18);
            printf(Mensaje6);

            switch (Opcion)
            {
            case 1:
                setcolor(WHITE);
                gotoxy(39, 13);
                printf(Mensaje1);
                break;

            case 2:
                setcolor(WHITE);
                gotoxy(39, 14);
                printf(Mensaje2);
                break;

            case 3:
                setcolor(WHITE);
                gotoxy(39, 15);
                printf(Mensaje3);
                break;

            case 4:
                setcolor(WHITE);
                gotoxy(39, 16);
                printf(Mensaje4);
                break;

            case 5:
                setcolor(WHITE);
                gotoxy(39, 17);
                printf(Mensaje5);
                break;

            case 6:

                setcolor(WHITE);
                gotoxy(39, 18);
                printf(Mensaje6);
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
                if (Opcion == 6)
                    Opcion = 1;
                else if (Opcion < 6)
                    Opcion++;

        } while (Tecla != 13);

        switch (Opcion)
        {
        case 1:
            insertarE();
            break;

        case 2:
            buscar();
            break;

        case 3:
        	//mostrar();
            insertarC();
            //Mostrar();
            break;

        case 4:
            consultarE();
            break;

        case 5:
            consultarMov();
            break;
        }

    } while (Opcion != 6);
    Salir();
 return 0;
}
/////////////////////////////////////////////////////////////////////////////////////
int main(){
	login();
	Carga();
	principal();
	existeCuenta2(AUXE->id);
	//getch(); 
}
//////////////////////////// REGISTRO DE EMPLEADOS ////////////////////////////////////////////////////////
void insertarE()
{
    AUXE= (struct empleado *)malloc(sizeof(struct empleado));
    system("CLS");
    setcolor(LIGHTMAGENTA);
    gotoxy(49,2);printf("~Registro de Empleados~\n\n");
    setcolor(WHITE);
    gotoxy(5,5);printf("ID: ");fflush(stdin);scanf("%i",&AUXE->id);
    existeCuenta1(AUXE->id);
    gotoxy(5,6);printf("Nombre Completo: ");fflush(stdin);gets(AUXE->nombre);
    gotoxy(5,7);printf("Tel%cfono: ",130);fflush(stdin);gets(AUXE->telefono);
    gotoxy(5,8);printf("Ciudad: ");fflush(stdin);gets(AUXE->ciudad);
    gotoxy(5,9);printf("Estado: ");fflush(stdin);gets(AUXE->estado);
    AUXE->sigE = NULL;
    if (FINE == NULL)
        FINE = CABE = AUXE;
    else
    {
        FINE->sigE = AUXE;
        FINE= AUXE;
    }
    cantidad++;
    getch();
}
///////////////////////////////REGISTRO DE CUENTAS BANCARIAS ///////////////////////////////////////////

void insertarC()
{
	if (vacio==cantidad){
		system("CLS");
		setcolor(RED);
   		gotoxy(28, 5);
   		printf("No hay empleados registrados.",161);
   		setcolor(WHITE);
   		getch();
   		return;
	}else{
    AUXC= (struct cuenta *)malloc(sizeof(struct cuenta));
    system("CLS");
    setcolor(LIGHTMAGENTA);
    gotoxy(49,2);printf("~Registro de Cuenta Bancaria~\n\n");
    setcolor(WHITE);
    printf("\t~No. Cuenta: ");fflush(stdin);scanf("%i",&AUXC->ncuenta);
    
    AUXE = CABE; //NOS UBICAMOS EN EMPLEADO PARA TRAER LOS REGISTRADOS
    setcolor(LIGHTMAGENTA);
    printf("\n\tEmpleados Registrados:\n\n");
    setcolor(WHITE);  
    printf("\tID \tNombre\n");
	for(int x = 0; x < cantidad; x++)// RECORREMOS DEPENDIENDO LA CANTIDAD DE EMPLEADOS
	{
		if(AUXE->id!=-99999999){ // SOLO PRESENTA LOS ID'S DIFERENTES A -9999999
		setcolor(YELLOW);
		printf("\t%i.\t%s\n", AUXE->id,AUXE->nombre);}
		AUXE = AUXE->sigE;
	}
	int existeEmpleado = 0;
	printf("\n\n");
	do
	{	
		setcolor(WHITE);
		printf("\tIngrese el Id del empleado que desea ingresar: ");
		fflush(stdin);
		scanf("%i", &AUXC->idE);
		if(AUXC->idE)

		existeEmpleado = existeEmpleadoConsultado(AUXC->idE); //LA FUNCION VERIFICA SI EN LA CUENTA EXISTE ESE ID INGRESADO
		if(existeEmpleado == 0)
		{
			setcolor(RED);
			printf("\n\t\tEl empleado ingresado no existe. Por favor, intente de nuevo.\n\n");
		}

	} while(existeEmpleado == 0); 

    printf("\n\t~Fecha: ");fflush(stdin);gets(AUXC->fecha);
    int op=0;
    do{
    	setcolor(WHITE);
    	printf("\n\t~Tipo Movimiento: \n");
    	printf("\t 1) D%cbito\n",130);
    	printf("\t 2) Cr%cdito\n",130);
    	printf("\n\tSeleccione un tipo: ");scanf("%i",&op);
    
    	if (op<=0 or op>2){
    		setcolor(RED);
    		printf("\n\t\tEl tipo de movimiento ingresado no existe. Por favor, intente de nuevo.\n");
		}
    
    	switch (op) //SI LA OPCION ES 1 O TAL, SE COPIA UN VALOR EN EL CAMPO DE LA ESTRUCTURA TIPO
    	{
    		case 1: strcpy(AUXC->tipo,"Debito");//TIPO DE MOVIMIENTOS
    			break;
    		case 2: strcpy(AUXC->tipo,"Credito");
    			break;
		}
	existeCuenta1(AUXE->id);// LLAMAMOS A LA FUNCION QUE CALCULA EL BALANCE TOTAL DEPENDIENDO DEL TIPO DE MOV. BANC
	 if (op==2&&total==0){
     		setcolor(RED);
     		printf("\n\t\tUsted no cuenta con suficiente balance.\n");
     		setcolor(WHITE);
     		getch();
     		principal();//TE DEVUELVE AL MENU PRINICPAL
		}
     		
	}while(op<=0 or op>2);
	
    printf("\n\t~Monto: ");fflush(stdin);scanf("%i",&AUXC->monto);
    while(op==2&&AUXC->monto>total){//EVALUAMOS SI EL BALANCE TOTAL EXCEDE A LO QUE SE DESEA SACAR
     	setcolor(RED);
     	printf("\n\t\tEl monto solicitado excede el balance de su cuenta ($%i). Intente de nuevo.\n",total);
     	setcolor(WHITE);
     	printf("\n\t~Monto: ");fflush(stdin);scanf("%i",&AUXC->monto);
	}
    printf("\t~Concepto: ");fflush(stdin);gets(AUXC->concepto);
    
    AUXC->sigC = NULL;
    if (FINC == NULL) //SI ES POR PRIMERA VEZ CABC=AUXC
        FINC = CABC = AUXC;
    else //SI YA HAY VALORES REGISTRADOS
    {
        FINC->sigC= AUXC;
        FINC = AUXC;
    }
    
    cantC++;// CUENTA LOS REGISTROS QUE SE VAN INGRESANDO
	}
    getch();
}

////////////////////////////////////// FUNCION BUSCAR EDITAR ELIMINAR ///////////////////////////
void buscar(){
	if (vacio==cantidad){ //SI NO HAY EMPLEADOS REGISTRADOS, ESTAN INICIALIZADOS EN 0
		system("CLS");
		setcolor(RED);
   		gotoxy(28, 5);
   		printf("No hay empleados registrados.",161);
   		setcolor(WHITE);
   		getch();
   		return;
   		
	}else{
	int existeEmpleado = 0;
	printf("\n\n");
	char nombre[500];
	do
	{	
		system("CLS");
		setcolor(LIGHTMAGENTA);
    	gotoxy(49,2);printf("~B%csqueda de empleados~\n\n",163);
		setcolor(WHITE);
		printf("\tIngrese el Nombre del empleado que desea buscar: ");
		fflush(stdin);
		setcolor(YELLOW);gets(nombre); 
        setcolor(WHITE);
		existeEmpleado = BuscarEmpleado(nombre); // FUNCION QUE VERIFICA SI EL NOMBRE INGRESADO SE ENCUENTRA EN R_EMPLEADOS
				
		if(existeEmpleado == 0)// SI SE RETORNA UN 0 NO HAY COINCIDENCIAS
		{
			setcolor(RED);
			printf("\n\t\tEl empleado ingresado no existe. Por favor, intente de nuevo.\n\n");
			getch();
			
		}else{ // DE LO CONTRARIO TE DESPLIEGA TODAS LAS COINCIDENCIAS
			AUXE = CABE;
    		setcolor(LIGHTMAGENTA);
    		printf("\n\tResultados de la b%csqueda:\n\n",163);
    		setcolor(WHITE);  
    		printf("\tDatos de Empleado/a: %s\n",nombre);
			for(int x = 0; x < cantidad; x++){
				if ((strcmp(strupr(AUXE->nombre),strupr(nombre))== 0)&&(AUXE->id!=-99999999)){
					setcolor(YELLOW);
					printf("\n\t%i.\t%s \t%s \t%s \t%s \n", AUXE->id,AUXE->nombre,AUXE->telefono,AUXE->ciudad,AUXE->estado);
				}
				AUXE = AUXE->sigE;
			}
			
		}

	} while(existeEmpleado == 0);
	
	int op1=0;
	do{
		setcolor(WHITE);
		printf("\n\t~Acciones: \n\n");
    	printf("\t 1) Editar\n");
    	printf("\t 2) Eliminar\n");
    	printf("\n\tSeleccione la acci%cn que desea: ",162);scanf("%i",&op1);
    
    	if (op1<=0 or op1>2){
    		setcolor(RED);
    		printf("\n\tLa acci%cn seleccionada es incorrecta. Intente de nuevo.\n",162);
    		getch();
		}
		
    	switch (op1) //SI SE ENCONTRO EL EMPLEADO Y SE ELIGIO LA OP=1 SE PROCEDE A EDITAR
    	{
    			case 1: 
    		system("CLS");
    		setcolor(LIGHTMAGENTA);
    		AUXE = CABE;
    		for(int x = 0; x < cantidad; x++){
    			if (strcmp(strupr(AUXE->nombre),strupr(nombre))== 0){//COMPROBAMOS LOS NOMBRES
    				gotoxy(49,2);printf("~Edici%cn del Empleado/a: %s~\n\n",162,AUXE->nombre);
    				setcolor(WHITE);
    				gotoxy(5,5);printf("ID: ");fflush(stdin);scanf("%i",&AUXE->id);
    				gotoxy(5,6);printf("Nombre Completo: ");fflush(stdin);gets(AUXE->nombre);
    				gotoxy(5,7);printf("Tel%cfono: ",130);fflush(stdin);gets(AUXE->telefono);
    				gotoxy(5,8);printf("Ciudad: ");fflush(stdin);gets(AUXE->ciudad);
    				gotoxy(5,9);printf("Estado: ");fflush(stdin);gets(AUXE->estado);}
				AUXE = AUXE->sigE; 
			}
    		getch();
    			break;
    			
    			
    		case 2: 
    		system("CLS");
    		setcolor(RED);
    		AUXE = CABE;
    		while(AUXE!=NULL){
    			existeCuenta1(AUXE->id); //LLAMAMOS A LA FUNCION QUE TRAE EL BALANCE DEL EMPLEADO
    			if ((strcmp(strupr(AUXE->nombre),strupr(nombre))== 0)&&(total<=0)){
    				gotoxy(35,9);printf("~Eliminaci%cn del Empleado/a: %s~\n\n",162,AUXE->nombre);
    				setcolor(WHITE);
    				AUXE->id=-99999999; //ASIGNAMOS AL AUXE ID UN VALOR CASI IMPOSIBLE QUE SE DIGITE
    				vacio++;
					}
			    if ((strcmp(strupr(AUXE->nombre),strupr(nombre))== 0)&&(total!=0)){//SI EL EMPLEADO COINCIDE Y EL TOTAL !=0 
				//ENTONCES LLAMA AL LOGIN
					cin.ignore();// PARA IGNORAR CUALQUER # QUE INTERFIERA CON EL GETLINE
					login();
					system("CLS");
					if (contador < INTENTOS){// SI ACERTASTE EL USER Y PASSWORD ELIMINA EL EMPLEADO ELEGIDO
					   setcolor(RED);
					   gotoxy(35,9);printf("~Eliminaci%cn del Empleado/a: %s~\n\n",162,AUXE->nombre);
    				    setcolor(WHITE);
    				    AUXE->id=-99999999;
    				    vacio++;
    				    vacioc++;
    				    break;
    				    getch();
    			    }
    				    else{ //DE LO CONTRARIO TE MANDA A PRINCIPAL
    				    setcolor(RED);
    				    gotoxy(35,9);printf("~Usted no tiene autorizaci%cn para eliminar este empleado",162);
    				    setcolor(WHITE);
					}
					}	AUXE = AUXE->sigE;
					}
    		    getch();
    		
    			break;
    		
	}}while(op1<=0 or op1>2);
	//principal();
}}

///////////////////// CONSULTAR EMPLEADOS //////////////////////////////////
void consultarE(){
	if (vacio==cantidad){
		system("CLS");
		setcolor(RED);
   		gotoxy(28, 5);
   		printf("No hay empleados registrados.",161);
   		setcolor(WHITE);
   		getch();
   		return;}
   		
	else{
    system("CLS");
    setcolor(LIGHTMAGENTA);
    gotoxy(49,2);printf("~Consulta De Empleados~\n\n");
    AUXE = CABE;
   for (int x = 0; x < cantidad; x++){
   if(AUXE->id!=-99999999){
   setcolor(WHITE);
   printf("\n\tID: %i", AUXE->id);
   printf("\n\tNombre: %s", AUXE->nombre);
   printf("\n\tTel%cfono: %s",130, AUXE->telefono);
   printf("\n\tCiudad: %s", AUXE->ciudad);
   printf("\n\tEstado: %s", AUXE->estado);
   existeCuenta(AUXE->id);//SE LLAMA LA FUNCION QUE IMPRIME EL MONTO-TIPO DE MOVIMIENTO MAS EL BALANCE
   setcolor(YELLOW);
   printf("\n\t~Balance Total: $%d~\n", total);
    setcolor(WHITE);}
   AUXE=AUXE->sigE;}}
   getch();
}

//////////////////// CONSULTAR CUENTA BANCARIA ////////////////////////////////

void consultarMov(){
	if (vacioc==cantC){
		system("CLS");
		setcolor(RED);
		gotoxy(28, 5);
		printf("No hay cuentas bancarias registradas.",161);
		setcolor(WHITE);
		getch();
		return;
		
	}else{
		int existeEmpleado = 0;
		int id=0;
	do
	{	
		system("CLS");
		setcolor(LIGHTMAGENTA);
		gotoxy(49,2);printf("~Consulta De Cuentas Bancarias~\n\n");
		int res=0;
		AUXE = CABE;
		setcolor(LIGHTMAGENTA);
    	printf("\n\tEmpleados con cuentas bancarias:\n\n");
    	setcolor(WHITE);  
    	printf("\tID \tNombre\n");
		for(int x = 0; x < cantidad; x++){
			res=existeEC(AUXE->id);// VERIFICA SI EL ID EMPLEADO ESTE REGISTRADO EN UNA CUENTA BANCARIA Y PRESENTA EL NOMBRE
			if (res==1){
			setcolor(YELLOW);
			printf("\t%i.\t%s\n", AUXE->id,AUXE->nombre);}
			AUXE = AUXE->sigE;
		}
		printf("\n\n");
		setcolor(WHITE);
		printf("\tIngrese el Id del empleado que desea ingresar: ");
		fflush(stdin);
		scanf("%i", &id);
		existeEmpleado=existeEC(id);// VERIFICA QUE EL ID INGRESADO COINCIDA CON EL DE EMPLEADOS REGISTRADOS
		if(existeEmpleado == 0)
		{
			setcolor(RED);
			printf("\n\t\tEl empleado ingresado no existe. Por favor, intente de nuevo.\n\n");
			getch();
		}else
		{
			system("CLS");
			CT = CABC;
			AUXE=CABE;
            char nom[500];
            for(int x = 0; x < cantidad; x++){
                if (id==AUXE->id){
                  strcpy(nom,AUXE->nombre);} //SE UBICA EL NOMBRE RELACIONADO CON ESE ID Y SE COPIA EN NOM PARA MOSTRAR
                     AUXE = AUXE->sigE;
                }
			setcolor(LIGHTMAGENTA);
            gotoxy(49,2);printf("~Consulta De Movimientos Bancarios~\n\n");
            setcolor(YELLOW);
			gotoxy(55,4);printf("\tEmpleado/a: %s\n",nom);
			setcolor(WHITE);
    		for (int x = 0; x < cantC; x++){
        			if (CT->idE==id){// SE UTILIZA *CT PARA EVITAR CHOQUES CON AUXC QUE SE LLAMA EN PRINCIPAL
        				setcolor(WHITE);
						printf("\n\tCuenta: %i", CT->ncuenta);
						printf("\n\tFecha: %s", CT->fecha);
						printf("\n\tTipo: %s Monto: $%d", CT->tipo, CT->monto);
						printf("\n\tConcepto: %s", CT->concepto);
						existeCuenta2(id);
						setcolor(YELLOW);
						printf("\n\t~Balance: $%i~\n\n", CT->balance);
	                    setcolor(WHITE);
					}
        		CT = CT->sigC;
			}
		
		}
	} while(existeEmpleado == 0);
	getch();
}
}

/////////////////////////////////////// FUNCIONES SECUNDARIAS ///////////////////////////

void existeCuenta(int id_empleado)// SI EL ID EMP ESTA EN CUENTA ME TRAIGA MONTO TIPO Y CALCULE 
{
	AUXC = CABC;
	 total = 0;
    while(AUXC != NULL)
    {
    	if(id_empleado == AUXC->idE)
		{
			printf("\n\tTipo: %s  Monto: $%d", AUXC->tipo, AUXC->monto);
			if(strcmp(AUXC->tipo,("Debito"))==0){
				total += AUXC->monto;
				AUXC->balance=total;
			}else{
				total -= AUXC->monto;
				AUXC->balance=total;
			}
		}
		AUXC = AUXC->sigC;
    }
    
}

void existeCuenta1(int id_empleado) // PARA TRAER EL BALANCE EN CONSULTAR MOV DE CUENTAS
{
	CT=CABC;
	total=0;
    while(CT != NULL)
    {
    	if(id_empleado == CT->idE)
		{
			if(strcmp(CT->tipo,("Debito"))==0){
				total += CT->monto;
				CT->balance=total;
			}else{
				total -= CT->monto;
				CT->balance=total;
			}
		}
		CT = CT->sigC;
    }
}

void existeCuenta2(int id_empleado)
{
	AUXC=CABC;
	total=0;
    while(AUXC != NULL)
    {
    	if(id_empleado == AUXC->idE)
		{
			if(strcmp(AUXC->tipo,("Debito"))==0){
				total += AUXC->monto;
				AUXC->balance=total;
			}else{
				total -= AUXC->monto;
				AUXC->balance=total;
			}
		}
		AUXC = AUXC->sigC;
    }
}


int existeEmpleadoConsultado(int id_empleado)//TRAE EL NOMBRE RELACIONADO CON EL ID INGRESADO
{
    AUXE = CABE;
    for (int x = 0; x < cantidad; x++)
    {
        if ((id_empleado == AUXE->id)&&(AUXE->id!=-99999999 ))
            return 1;
        AUXE = AUXE->sigE;
    }
    return 0;
}


int existeEC(int id_empleado) //VERIFICA SI HAY EMPLEADOS EN UNA CUENTA
{
    AUXC = CABC;
    for (int x = 0; x < cantC; x++)
    {
        if ((id_empleado == AUXC->idE)&&(id_empleado!=-99999999 )){
				return 1;
		}
        AUXC = AUXC->sigC;
}
    return 0;
}

int BuscarEmpleado(char nombre_empleado[500])//TRAE LOS NOMBRES DE LOS EMPLEADOS SEGUN EL NOMBRE INGRESADO EN BUSCAR
{
    AUXE = CABE;
    for (int x = 0; x < cantidad; x++)
    {
        if ((strcmp(strupr(nombre_empleado), strupr(AUXE->nombre)) == 0)&&(AUXE->id!=-99999999))
            return 1;
        AUXE = AUXE->sigE;
    }
    return 0;
}
//GENESIS & ROBERLINA R2-2021 ESTRUCTURA DE DATOS//


