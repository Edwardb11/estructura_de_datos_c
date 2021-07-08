//A continuación les presento las instrucciones para realizar el segundo parcial de la asignatura. Tiene un valor de 20 puntos para lo
//s del nuevo pensum y 7 puntos para los del pensum anterior. Pueden trabajar en parejas 

//INDICACIONES:

//Crear un programa que, SIMULANDO CON ARREGLOS Y ESTRUCTURAS EL FUNCIONAMIENTO DE LAS PILAS,  permita llevar el control del almacenamiento en
// un furgón frio de diversos lotes de distintas vacunas contra el COVID-19, teniendo en cuenta que:

//       dicho furgón solo tiene una entrada que también funciona como salida

//        cada lote ocupa el ancho casi completo del furgón por lo que solo cabe una hilera de contenedores (lotes)

//       los contenedores deben organizarse uno inmediatamente a continuación del otro y por fecha de caducidad teniendo en cuenta
// que las de caducidad más cercana deben quedar más próximas a la puerta de salida del furgón.

//Para esto deberá crear la/s estructura/s (y arreglo/s correspondiente/s) con los siguientes datos del lote: NumeroLote, Vacuna, 
//Cantidad viales, Fecha Caducidad y Observaciones.

//Cuando se vayan a colocar los lotes en el lugar que le corresponda en la pila debe mostrarse una animación en la que se vea el número 
//de lote + Vacuna + Fecha Caducidad   entrando a la pila del furgón.

//Cuando se vayan a entregar los lotes (desapilar el lote)  debe mostrarse una animación en la que se vea el número de lote + Vacuna + 
//Fecha Caducidad   saliendo de la pila del furgón.

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <iostream>

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

#define Mensaje1 "1- Crear pila"
#define Mensaje2 "2- Recibir lote"
#define Mensaje3 "3- Ordenar lote por fecha de caducidad"
#define Mensaje4 "4- Colocar lotes recibidos"
#define Mensaje5 "5- Sacar lote"
#define Mensaje6 "6- Ultimo lote"
#define Mensaje7 "7- Salir"

#define Maximo 5

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


//ASCII = American Standard Code for Information Interchange
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

//funciones

void Crear();
void Recibir();
void Ordenar();
void Mostrar();
void Desapilar();
void Ultimo();
void Salir();

struct pila{
	int NumeroLote;
	char vacuna[50];
	int cantidad;
	int dia, mes, year;
	char observacion[100];
}pila_vacuna[Maximo];

int Posicion = Maximo + 1, Pila[Maximo], I;

void Crear(){

    Posicion = Maximo;

    system("CLS");
    setcolor(WHITE);
    gotoxy(46,10);printf("Pila creada.\n\n\n\n");

    getch();
}

void Recibir(){

    system("CLS");

    if(Posicion == Maximo + 1){    
    	setcolor(WHITE);
    	gotoxy(46,10);printf("Pila no creada.");
    }else{

        if(Posicion == Maximo - Maximo){

            setcolor(LIGHTCYAN);
   
    
    		setcolor(WHITE);
    		gotoxy(46,10);printf("Pila llena.");
        }else{
			setcolor(WHITE);


			setcolor(WHITE);
    		gotoxy(46,2);printf("Recibir lote.");
			
            gotoxy(12,6);printf("Ingrese el numero del lote de la vacuna: "); scanf("%i", &pila_vacuna[Posicion].NumeroLote);
			fflush(stdin);
			gotoxy(12,7);printf("Ingrese el nombre de la vacuna: "); scanf("%[^\n]", &pila_vacuna[Posicion].vacuna);
			fflush(stdin);
			gotoxy(12,8);printf("Ingrese la cantidad de viales de la vacuna: "); scanf("%i", &pila_vacuna[Posicion].cantidad);
			fflush(stdin);
			gotoxy(12,9);printf("Ingrese la fecha de caducida de la vacuna");gotoxy(60,9);printf("-Dia:");scanf("%i", &pila_vacuna[Posicion].dia); fflush(stdin);gotoxy(68,9);printf("-Mes:");scanf("%i", &pila_vacuna[Posicion].mes);fflush(stdin);gotoxy(76,9);printf("-A%co:",164);scanf("%i", &pila_vacuna[Posicion].year);
			fflush(stdin);
			gotoxy(12,10);printf("Ingrese una observaci%cn de la vacuna: ",162); scanf("%[^\n]", &pila_vacuna[Posicion].observacion);
			
            system("CLS");
    
    		setcolor(WHITE);
    		gotoxy(46,10);printf("Lote recibido.");
            Posicion--;
        }
	}
    getch();
}

void Ordenar(){

    system("CLS");
    pila temp_vacuna;
    
    if(Posicion == Maximo + 1){
    
    	setcolor(WHITE);
    	gotoxy(46,10);printf("Pila no creada.");
    }else{
    	int i,j;

		//metodo burbuja
		for (i=0; i<=Maximo-1; i++){
			for (j=i+1; j<=Maximo; j++){
				if(pila_vacuna[i].year > pila_vacuna[j].year){
					
					temp_vacuna = pila_vacuna[i];
					pila_vacuna[i] = pila_vacuna[j];
					pila_vacuna[j] = temp_vacuna;
					
				}else{
					
					if(pila_vacuna[i].year == pila_vacuna[j].year && pila_vacuna[i].mes > pila_vacuna[j].mes){
						
						temp_vacuna = pila_vacuna[i];
						pila_vacuna[i] = pila_vacuna[j];
						pila_vacuna[j] = temp_vacuna;
						
					}else{
						if(pila_vacuna[i].mes == pila_vacuna[j].mes && pila_vacuna[i].dia > pila_vacuna[j].dia){
							
							temp_vacuna = pila_vacuna[i];
							pila_vacuna[i] = pila_vacuna[j];
							pila_vacuna[j] = temp_vacuna;
								
						}
					}
				}
			}
		}

	    
		setcolor(WHITE);
		gotoxy(46,10);printf("Lote ordenado.\n\n\n\n");
	}
    
	getch();
}

void Mostrar(){
    system("CLS");
    int y = 8, veces = 1;

    if(Posicion == Maximo + 1){

    
    	setcolor(WHITE);
   		gotoxy(46,10);printf("Pila no creada.");
    }else{
    	
    	if(Posicion == Maximo){

    
    		setcolor(WHITE);
    		gotoxy(46,10);printf("Pila vac%ca.", 161);
        }else{

        	for(I = 5; I >= veces; I--){
        		
    			Sleep(120);
    
    			setcolor(WHITE);
        		gotoxy(2,2);printf("N%cmero del lote |\t Vacuna \t| Cantidad de viales | Fecha de Caducidad | Observaci%cn", 163, 162);
				Sleep(120);

                if(Pila[I] == -999999999){

                    gotoxy(1, y); printf("0");
                    y--;
                    Sleep(120);
                }else{

                    gotoxy(8, y);printf("%i", pila_vacuna[I].NumeroLote);gotoxy(22, y);printf("%s", pila_vacuna[I].vacuna);gotoxy(50, y);printf("%i\t", pila_vacuna[I].cantidad);gotoxy(68, y);printf("%i/%i/%i\t", pila_vacuna[I].dia, pila_vacuna[I].mes, pila_vacuna[I].year);gotoxy(85, y);printf("%s", pila_vacuna[I].observacion);
                    y--;
                    Sleep(120);
                }
            }
		}
	}
    getch();
}

void Desapilar(){

    system("CLS");
    int i;

    if(Posicion == Maximo + 1){
    	setcolor(WHITE);
   		gotoxy(46,10);printf("Pila no creada.");
    }else{
	
    	if(Posicion == Maximo){    
    		setcolor(WHITE);
   			gotoxy(46,10);printf("Pila vac%ca.", 161);
        }else{
        	
        	setcolor(WHITE);
       		gotoxy(2,2);printf("N%cmero del lote |\t Vacuna \t| Cantidad de viales | Fecha de Caducidad | Observaci%cn", 163, 162);
			Sleep(120);
			
            gotoxy(8, 3);printf("%i", pila_vacuna[Posicion + 1].NumeroLote);gotoxy(22, 3);printf("%s", pila_vacuna[Posicion + 1].vacuna);gotoxy(50, 3);printf("%i\t", pila_vacuna[Posicion + 1].cantidad);gotoxy(68, 3);printf("%i/%i/%i\t", pila_vacuna[Posicion + 1].dia, pila_vacuna[Posicion + 1].mes, pila_vacuna[Posicion + 1].year);gotoxy(85, 3);printf("%s", pila_vacuna[Posicion + 1].observacion);
			
			for (i=8; i<=98; i++){
				gotoxy(i, 3);printf(" ");
				Sleep(80);
			}

            Posicion++;
        	Pila[Posicion] = -999999999;
        	
        	system("CLS");

    
    		setcolor(WHITE);
   			gotoxy(42,10);printf("Elemento desapilado.\n\n\n");
        }
	}
    getch();
}

void Ultimo(){
	system("CLS");

    if(Posicion == Maximo + 1){
    	setcolor(WHITE);
   		gotoxy(46,10);printf("Pila no creada.");

    }else{
    	if(Posicion == Maximo){
		
            setcolor(LIGHTCYAN);
    		cuadro(39,65,9,11);
    
    		setcolor(WHITE);
   			gotoxy(46,10);printf("Pila vac%ca.", 161);

        }else{
		
    		Sleep(120);
    
    		setcolor(WHITE);
       		gotoxy(2,2);printf("N%cmero del lote |\t Vacuna \t| Cantidad de viales | Fecha de Caducidad | Observaci%cn", 163, 162);
			Sleep(120);
			
            gotoxy(8, 3);printf("%i", pila_vacuna[Posicion + 1].NumeroLote);gotoxy(22, 3);printf("%s", pila_vacuna[Posicion + 1].vacuna);gotoxy(50, 3);printf("%i\t", pila_vacuna[Posicion + 1].cantidad);gotoxy(68, 3);printf("%i/%i/%i\t", pila_vacuna[Posicion + 1].dia, pila_vacuna[Posicion + 1].mes, pila_vacuna[Posicion + 1].year);gotoxy(85, 3);printf("%s", pila_vacuna[Posicion + 1].observacion);
		}
	}
		
    getch();
}

void Salir(){

    system("CLS");    
    setcolor(WHITE);
    gotoxy(40,10);printf("%cGracias, regrese pronto!\n\n\n\n", 173);

    getch();
}

int main(){

    int Opcion = 1, Tecla;

    do{
        do{

            system("CLS");
            
 			cuadro(1,80,0,8); //Primer cuadro
    		cuadro(10,70,9,18);// segundo cuadro
    		cuadro(1,80,21,25); //tercer cuadro
            
   			setcolor(YELLOW);
    		gotoxy(30,1);printf("UNIVERSIDAD CATOLICA DEL CIBAO");
   			setcolor(WHITE);
    		gotoxy(42,2);printf("UCATECI");
    		gotoxy(37,3);printf("Estructura de Datos");
    		gotoxy(39,4);printf("Menu Principal");
    		
    		//nombres de integrantes
			
			setcolor(LIGHTMAGENTA);
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
                Recibir();
                break;

            case 3:
                Ordenar();
                break;

            case 4:
                Mostrar();
                break;

            case 5:
                Desapilar();
                break;

            case 6:
                Ultimo();
                break;
        }
    }while(Opcion != 7);
    Salir();
    return 0;
}
