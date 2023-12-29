#include <stdio.h>
#include <string.h>

int main()
{
    int i, j, k;
    char str1[6], str2[6], str3[15];
    
    printf("str1=");
    scanf("%s", &str1);

    printf("\nstr2=");
    scanf("%s", &str2);

    j = strlen(str1);
    k = strlen(str2);

    strcpy(str3, str1);

    for ( i = 0; i < k; i++ )
    {
        str3[j++] = str2[i];
    }
    str3[j+k] = '\0';
    printf("%s",str3);
    return 0;
}