#include<bits/stdc++.h>
using namespace std;

bool prefix(string a, string b)
{
    if(b.length()<a.length())   return false;

    for(int i=0; i<a.length(); i++)
    {
        if(a[i]!=b[i])  return false;
    }

    return true;
}

string a[10005];

int main()
{
    int test, cs = 0;

    scanf("%d", &test);

    while(test--)
    {
        int n;
        scanf("%d", &n);

        bool res = true;

        for(int i=0; i<n; i++)  cin>>a[i];

        sort(a, a+n);

        for(int i=0; i<n-1; i++)
        {
            if(prefix(a[i], a[i+1]))
            {
                res = false;
                break;
            }
        }

        printf("Case %d: ", ++cs);

        puts(res?"YES":"NO");
    }

    return 0;

}
