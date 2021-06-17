#include <stdio.h>
#include <stdlib.h>
typedef void (*func_ptr)(char *);
void evil_fuc(char command[])
{
system(command);
}
void echo(char content[])
{
printf("%s",content);
}
int main()
{
func_ptr *p1 =(func_ptr *)malloc(4*sizeof(int));
printf("malloc addr: %p\n",p1);
p1[3]=echo;
p1[3]("hello world\n");
free(p1); //在這裡free了p1,但並未將p1置空,導致後續可以再使用p1指針
p1[3]("hello again\n"); //p1指針未被置空,雖然free了,但仍可使用.
func_ptr *p2 =(func_ptr *)malloc(4*sizeof(int));//malloc在free一塊內存後,再次申請同樣大小的指針會把剛剛釋放的內存分配出來
printf("malloc addr: %p\n",p2);
printf("malloc addr: %p\n",p1);//p2與p1指針指向的內存為同一地址
p2[3]=evil_fuc; //在這裡將p1指針裡面保存的echo函數指針覆蓋成為了evil_func指針
p1[3]("whoami");
return 0;
}
