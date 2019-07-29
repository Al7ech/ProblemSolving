#include <stdio.h>

int N, M;
char data[200][200];

int main(void)
{
    scanf("%d%d", &N, &M);

    for (int i = 0; i < N; i++)
        scanf("%s", data[i]);

    for (int i = M - 1; i >= 0; i--)
    {
        for (int j = 0; j < N; j++)
        {
            if (data[j][i] == '-')
                printf("|");
            else if (data[j][i] == '|')
                printf("-");
            else if (data[j][i] == '/')
                printf("\\");
            else if (data[j][i] == '\\')
                printf("/");
            else if (data[j][i] == '^')
                printf("<");
            else if (data[j][i] == '<')
                printf("v");
            else if (data[j][i] == 'v')
                printf(">");
            else if (data[j][i] == '>')
                printf("^");
            else
                printf("%c", data[j][i]);
        }
        puts("");
    }

    return 0;
}