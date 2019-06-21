#include<bits/stdc++.h>
using namespace std;

int a[500009], n;

void query(int x)
{
        int left=-1, right=-1, k;


        right = upper_bound(a, a+n, x)-a;
        if(right>=0 && right<n) right=a[right];
        else right = -1;

        int lo=0, hi=n-1, mid;

        while(true)
        {
                mid=(lo+hi)>>1;
                if(a[mid]>=x)   hi=mid;
                else
                {
                    left=a[mid];
                    lo=mid;
                }

                if(lo+1==hi)
                {
                    if(a[hi]<x) left=a[hi];
                    else if(a[lo]<x)    left=a[lo];
                    break;
                }
        }


        if(left==-1)    cout<<"X ";
        else            cout<<left<<" ";

        if(right>0)     cout<<right<<endl;
        else            puts("X");


}

int main()
{

        int q, x;

        scanf("%d", &n);

        for(int i=0; i<n; i++)  scanf("%d", &a[i]);

        scanf("%d", &q);

        while(q--)
        {
            scanf("%d", &x);
            query(x);
        }

    return 0;
}
