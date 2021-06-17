#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct stu{
    int id;
    char name[20];
}Stu;

typedef struct movement{
     void (*playctf)();
     void (*playball)();
     void (*playgame)();
     char name[12];
}Movement;

void testsh()
{
    system("/bin/sh");
}

int main()
{
    Stu *p;
    Movement *q;
    p = (Stu*)malloc(sizeof(Stu));
    free(p);
    q = (Movement*)malloc(sizeof(Movement));
/*    if(read(0, &(q->id), 4) == -1)
    {
        printf("error");
        exit(1);
    }  */
    p->id=(int) testsh;
    q->playctf();
    return 0;
}
