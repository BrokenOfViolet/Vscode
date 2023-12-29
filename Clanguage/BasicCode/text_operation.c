#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    char ch;

    if (fopen("exp01.txt","w") == NULL)
    {
        printf("Can not open this file.\n");
        exit(0);
    } else {
        printf("Input the word you want.(press '#' to quit.)\n");
    }
    ch = getchar();
    while (ch != '#')
    {
        fputc(ch, fp);
        ch = getchar();
    }
    fclose(fp);

    return 0;
}