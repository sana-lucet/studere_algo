#include<cstdio>
#include<cstdlib>
#include<cstring>

int main()
{
    int i, n, d[5001]={0};
    char str[5001]={0};
    scanf("%s", str);
    n = strlen(str);
    for(i = 0; i < n; i++)
    {
        str[i] -= '0';
    }

    if(str[0] == 0)
    {
        printf("0\n");
        return 0;
    }

    d[0] = 1;
    if(str[0] * 10 + str[1] <= 26 && str[0] * 10 + str[1] >= 11 && str[1] > 0)
        d[1] = 2;
    else
        d[1] = 1;

    for(i = 2; i < n; i++)
    {
        if(str[i] >= 1 && str[i] <= 9)
        {
            d[i] += d[i-1];
            d[i] %= 1000000;
        }
        if(str[i-1] * 10 + str[i] <= 26 && str[i-1] > 0)
        {
            d[i] += d[i-2];
            d[i] %= 1000000;
        }
    }
    /*
    for(i = 0; i < n; i++)
        printf("%d ", d[i]);
    printf("\n");
    */
    printf("%d\n", d[n-1]);
    return 0;
}