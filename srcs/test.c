#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    char **test;
    int index = -1;

    test = (char **)malloc(sizeof(char *) * 5);
    *test = (char *)malloc(sizeof(char) * 10);
    while (++index < 5)
    {
        test[index] = "hello";
    }
    test[index] = "does this work nxa";
   printf("%s\n",  test[index]);

}