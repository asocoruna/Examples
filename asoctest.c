void suma(int * a) {
	*a+=3;
	
	printf("A vale: %d\n", a);
}

void main() {
	int numero = 5;
	
	suma(&numero);

	printf("Numero vale: %d\n", numero);
}
