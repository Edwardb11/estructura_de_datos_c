//PARA REALIZAR CON: Puntero
//Analizar el siguiente código y expresar después de la corrida que hace el
//programa, es decir, que lógica realiza para desplegar ese resultado.
int main (){
	int *punto, i;
	int x[5] = {1,2,3,4,5};
	punto=x+4;
	*(punto-2)= 9;
	punto --;
	*(punto)=7;
	punto[1]= 15; // favor cambiar en vez de que sea 11, correrlo con el 15
	for(i=0;i<5;i++)
		printf("%d", *(x+i)); // que resultado imprime.. 129715
	return 0;
}

//basicamente que hace es que en el puntero --> “punto” el va asigandole diferentes
//espacio de memoria y luego lo recorre con el for cabe destacar que los  únicos
//valores que no son cambios son los 2 primeros, porque dijimos que punto vale 5
//entonces cuando le restas 2 queda en 3 y el cambia a nueve, asi sucesivamente. 
//Esa es la logica de este programa.
