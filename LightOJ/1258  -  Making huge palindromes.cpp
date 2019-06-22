#include<bits/stdc++.h>
using namespace std;

int lps[2000005];
char str[2000005], pat[2000005];

void computeLPSArray()
{

    int M = strlen(pat);

    int len = 0, i = 1;

    lps[0] = 0;

    while (i < M)
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len-1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void solve(){

    scanf("%s", str);

    int len;

    for(len = 0; str[len]; len++){}

    int idx = 0;

    for(int i = len-1; i>=0; i--) pat[idx++] = str[i];
    pat[idx++] = '#';
    for(int i = 0; i<len; i++) pat[idx++] = str[i];
    pat[idx] = '\0';

    computeLPSArray();

    printf("%d\n", 2*len - lps[idx-1]);

}
int main()
{

  //  freopen("in.txt", "r", stdin);

    int test, cs = 0;

    scanf("%d", &test);

    while(test--)
    {
        printf("Case %d: ", ++cs);
        solve();

    }
    return 0;
}

