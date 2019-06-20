// Greedy - task scheduling

#include<bits/stdc++.h>
using namespace std;

struct point{
    int x, type;

    point(int p, int q)
    {
        x = p;
        type = q;
    }

    bool operator<(const point &p) const{
        if(x==p.x)  return type<p.type;
        return x<p.x;
    }
};

vector<point> v;

int main()
{

       int test, cs = 0;

       scanf("%d", &test);

       while(test--)
       {
           int n, res = -1, cur = 0, i;

           scanf("%d", &n);

           while(n--)
           {
               int x, y;
               scanf("%d %d", &x, &y);
               v.push_back(point(x, 0));
               v.push_back(point(y, 1));
           }

           sort(v.begin(), v.end());

           int sz = v.size();

           for(int i = 0; i<sz; i++)
           {
               if(v[i].type == 0)
               {
                   cur++;
                   res = max(res, cur);
               }
               else cur--;
           }

           printf("Case %d: %d\n", ++cs, res);

           v.clear();
       }
}
