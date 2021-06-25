#include <stdio.h>

int main(){
	int dato=5, *ptrdato;
	
	ptrdato=&dato;
	printf("Direccion en decimal: %d\nDireccion en hexadecimal %p",ptrdato);
}
