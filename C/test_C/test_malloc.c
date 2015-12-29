#include <stdio.h>
#include<malloc.h>
int main() {
int *p; 
char *s;
//printf("\n%d %p %d %p", *p,p,*s,s);
*p = malloc(0);
*p = 455;
*s = (char *)p;

printf("\n%d %p %d %p", *p,p,*s,s);

}

