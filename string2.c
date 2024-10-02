// Online C compiler to run C program online
#include <stdio.h>
#include <string.h>
int main() {
    char T[100];
    int a=0;
    puts("entre une chain ");
    gets(T);
    for(int i=0;T[i]!='\0';i++)
    a++;
    printf("la chaine et: %d",a);
    

    return 0;
}