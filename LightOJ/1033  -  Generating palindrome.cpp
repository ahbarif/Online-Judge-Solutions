#include<stdio.h>
#include<string.h>

int dp[101][101];
char a[105];

int f(int i, int j)
{
    if(i>=j)    return 0;

    if(dp[i][j]!=-1)    return dp[i][j];

    if(a[i]==a[j]) return dp[i][j] = f(i+1, j-1);

    else
    {
        int x = 0, y = 0;

        x = f(i+1, j) + 1;
        y = f(i, j-1) + 1;

        dp[i][j] = (x>y?y:x);

        return dp[i][j];
    }

}

int main()
{

    int test, cs = 1;

    scanf("%d", &test);

    while(test--)
    {
        memset(dp, -1, sizeof(dp));

        scanf("%s", a);

        int res = f(0, strlen(a)-1);

        printf("Case %d: %d\n", cs++, res);
    }

    return 0;

}
