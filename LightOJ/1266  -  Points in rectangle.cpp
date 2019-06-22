#include<bits/stdc++.h>
using namespace std;

int tree[1005][1005];
bool vis[1005][1005];

void update(int x, int y, int lmx, int lmy, int val)
{


    for(int i = x; i<=lmx; i+= i & (-i))
    {
        for(int j = y; j<=lmy; j+= j & (-j))
        {
            tree[i][j] += val;
        }
    }

}

int query(int x, int y)
{

    int sum = 0;

    for(int i = x; i>0; i-= i & (-i))
    {
        for(int j = y; j>0; j -= j & (-j))
        {
            sum += tree[i][j];
        }

    }

    return sum;

}

int main()
{

  //  freopen("in.txt", "r", stdin);

    int test, cs = 0;

    scanf("%d", &test);

    while(test--)
    {

        memset(vis, 0, sizeof(vis));
        memset(tree, 0, sizeof(tree));

        int q;

        scanf("%d", &q);

        cout<<"Case "<<++cs<<":"<<endl;

        while(q--)
        {

            int t;

            scanf("%d", &t);

            if(t==0)
            {

                int x, y;

                scanf("%d %d", &x, &y);

                ++x;
                ++y;

                if(vis[x][y]) continue;
                vis[x][y] = 1;

                update(x, y, 1001, 1001, 1);
            }

            else
            {

                int lox, loy, hix, hiy;

                scanf("%d %d %d %d", &lox, &loy, &hix, &hiy);

                ++lox;
                ++loy;
                ++hix;
                ++hiy;

                int sum = 0;

                sum += query(hix, hiy);
                sum -= query(hix, loy-1);
                sum -= query(lox-1, hiy);
                sum += query(lox-1, loy-1);

                printf("%d\n", sum);
            }

        }

    }

    return 0;


}

