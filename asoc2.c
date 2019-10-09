#include <sys/mman.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

/*
const char code[] = "\xeb\x1e\x5e\x48\x31\xc0\xb0\x01\x48\x89\xc7\x48\x89\xfa\x48\x83\xc2\x0e\x0f\x05\x48\x31\xc0\x48\x83\xc0\x3c\x48\x31\xff\x0f\x05\xe8\xdd\xff\xff\xff\x48\x65\x6c\x6c\x6f\x2c\x20\x77\x6f\x72\x6c\x64\x21\x0a";
*/

const char code[] = "\x6a\x3b\x58\x99\x52\x48\xbb\x2f\x2f\x62\x69\x6e\x2f\x73\x68\x53\x54\x5f\x52\x57\x54\x5e\x0f\x05";


void main() {
	int stack[64];
	void * heap = malloc(6000);
	void * page = mmap(NULL, 6000, PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, 0, 0);
	int variable = 5;
	int * puntero = &variable;

	printf("Stack: %p, Heap: %p, Page: %p, Variable: %p, Puntero: %p\n", stack, heap, page, &variable, &puntero);


	if (memcpy(page, code, strlen(code))) {
		printf("Shellcode loaded\n");
	} else {
		printf("Copying ERROR: %s\n", strerror(errno));	
	} 

	
	if (!mprotect(page, 6000, PROT_READ|PROT_WRITE|PROT_EXEC)) {
		printf("Page executable\n");
	} else {
		printf("Page ERROR: %s\n", strerror(errno));	
	}

	/* if (!mprotect(heap, 6000, PROT_READ|PROT_WRITE|PROT_EXEC)) {
		printf("Heap executable\n");
	} else {
		printf("Heap ERROR: %s\n", strerror(errno));	
	} */
	
   	void (*func)() = page;
	func();
}
