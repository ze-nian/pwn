#include <unistd.h>

int function(int a)
{
char buffer[150];
read(STDIN_FILENO,buffer,250);
return a;
}
int main()
{
function(1);
write(STDOUT_FILENO,"Hi\n",3);
return 1;
}

