#include<bits/stdc++.h>
using namespace std;

void solve(int cs)
{
    printf("Case %d:\n", cs);

    int r, x1, x2, x3, x4, y1, y2, y3, y4;

    cin>>r;

    x1 = -1 * (45 * 5 * r) / 100;
    x2 = x1;
    x3 = x1 + (5*r);
    x4 = x1 + 5*r;

    y1 = (3 * r) / 2;
    y2 = -y1;
    y3 = y2;
    y4 = y1;

    cout<<x1<<" "<<y1<<endl;
    cout<<x4<<" "<<y4<<endl;
    cout<<x3<<" "<<y3<<endl;
    cout<<x2<<" "<<y2<<endl;

}

int main()
{

  //  freopen("in.txt", "r", stdin);

    int t;

    scanf("%d", &t);

    for(int i = 1; i<=t; i++) solve(i);


    return 0;
}
