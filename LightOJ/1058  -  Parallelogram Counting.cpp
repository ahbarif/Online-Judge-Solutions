#include<bits/stdc++.h>
using namespace std;

struct point
{
    int x, y;

    point() {}

    bool operator<(const point &p)const
    {
        if(x==p.x)  return y<p.y;
        return x<p.x;
    }

    bool operator==(const point &p)const
    {
        return x==p.x && y == p.y;
    }

} a[1005];

vector<point> v;

int main()
{

    int n, test, cs = 0;

    scanf("%d", &test);

    while(test--)
    {


        scanf("%d", &n);

        for(int i = 0; i<n; i++)    scanf("%d %d", &a[i].x, &a[i].y);

        v.clear();

        point inf;
        inf.x = INT_MIN;
        inf.y = INT_MIN;

       // v.push_back(inf);

        for(int i = 0; i<n; i++)
        {

            for(int j = i+1; j<n; j++)
            {
                point p;

                p.x = a[i].x + a[j].x;
                p.y = a[i].y + a[j].y;
                v.push_back(p);
            }
        }

        sort(v.begin(), v.end());

        v.push_back(inf);

        long long res = 0;

        int cnt = 0;

        for(int i = 1; i<v.size(); i++)
        {

            if(v[i]==v[i-1])    cnt++;

            else
            {
                long long temp = ((cnt)*(cnt-1))/2;
                res+=temp;
                cnt = 1;
            }
        }
        printf("Case %d: %lld\n", ++cs, res);
    }
}
