# include<bits/stdc++.h>
using namespace std;

int main()
{

    int i, ans, test, x, n;
    string s;

    scanf("%d", &test);

    for(x=1; x<=test; x++)
    {
        ans=0;

        cin>>n>>s;

        s=s+"####";

        for(i=0; i<n; i++)
        {
            if(s[i]=='.')
            {
                ans++;
                s[i]='#';
                s[i+1]='#';
                s[i+2]='#';
            }
            else
            {
                continue;
            }
        }

        printf("Case %d: %d\n", x, ans);

    }

   return 0;
}