#include<bits/stdc++.h>
using namespace std;

int main()
{

    int test, cs = 1;

    scanf("%d", &test);

    vector<int> v;

    while(test--)
    {
        int n, i, query, x;

        v.clear();

        char t[3];

        scanf("%d %d", &n, &query);

        for(i=0; i<n; i++)  scanf("%d", &x), v.push_back(x);

        printf("Case %d:\n", cs++);

        while(query--)
        {
            scanf("%s %d", &t, &x);

            if(t[0]=='a')    v.push_back(x);

            else
            {

                if(v.size()<x)  puts("none");
                else
                {
                    printf("%d\n", v[x-1]);
                    x--;
                    v.erase(v.begin()+x);
                }
            }

        }

    }

    return 0;

}
