#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int dp[105][105];

void f()
{
    dp[2][2] = dp[4][4] = dp[4][6] = dp[6][4] = dp[8][12] = dp[10][10] = dp[12][8] = 1;

}

int main()
{
    int test, cs = 0;

    int c[] = {1, 2};

    // patter found. grundy is 0 for values of f()

    memset(dp, 0, sizeof dp);

    f();


    scanf("%d", &test);

    while(test--)
    {
        int a, b;

        scanf("%d %d", &a, &b);

        cout<< c[dp[a][b]]<<endl;
    }

    return 0;
}


