#include <stdio.h>
#include <math.h>

int main(void)
{
    int v = 5;
    int *p;
    p = &v;
    *p = *p + 2;
    
    printf("v=%d, *p=%d\n", v, *p);

    return 0;
}
