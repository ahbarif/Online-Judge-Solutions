#include<bits/stdc++.h>
using namespace std;
 
vector<int> Left, Right;
 
int flag;
 
int a[25];
 
void generate(int i, int last, int sum, vector<int> &subset)
{
    if(i==last) subset.push_back(sum);
 
    else
    {
        generate(i+1, last, sum, subset);
        generate(i+1, last, sum+a[i], subset);
        generate(i+1, last, sum+(2*a[i]), subset);
 
    }
}
 
void init()
{
    Left.clear();
    Right.clear();
    flag = 0;
}
 
int main()
{
 
    int test, cs = 1;
 
    scanf("%d", &test);
 
    while(test--)
    {
        init();
 
        int n, mid, i, x, k;
 
        scanf("%d %d", &n, &k);
 
        for(i=0; i<n; i++)  scanf("%d", &a[i]);
 
        mid = (n+1) >> 1;
 
        generate(0, mid, 0, Left);
        generate(mid, n, 0, Right);
 
        sort(Right.begin(), Right.end());
 
        int sz = Left.size();
 
        for(i=0; i<sz; i++)
        {
            int t = k - Left[i];
 
            if(binary_search(Right.begin(), Right.end(), t))
            {
                flag = 1;
                break;
            }
 
        }
 
        printf("Case %d: ", cs++);
 
        puts(flag?"Yes":"No");
 
    }
 
    return 0;
}
 
 