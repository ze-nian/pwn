#include<stdio.h>
int function(int a, int b)
{
char buffer[15]="";
gets(buffer);
return a+b;
}
int main()
{
function(2,3);
return 1;
}

