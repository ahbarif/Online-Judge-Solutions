#include<bits/stdc++.h>
using namespace std;
void rvrs(int arr[], int start, int end)
{
	int temp;
	while (start < end)
	{
		temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;
		start++;
		end--;
	}
}
int main(){       

    int t, n, m, i, j, q, a[110], d, y, z, k;

    char op;

    cin>>t;
    for(i=1; i<=t; i++){

        cin>>n>>m;
        for(j=0; j<n; j++)  cin>>a[j];

        while(m--){

            cin>>op;
            if(op=='S'){
                cin>>d;
                for(q=0; q<n; q++)  a[q]+=d;
            }
            else if(op=='M'){
                cin>>d;
                for(q=0; q<n; q++)  a[q]*=d;
            }
            else if(op=='D'){
                cin>>d;
                for(q=0; q<n; q++)  a[q]/=d;
            }
            else if(op=='R'){
                    rvrs(a, 0, n-1);
                }

            else{
                cin>>y>>d;
                swap(a[y], a[d]);
            }
            }
        printf("Case %d:\n", i);
        for(j=0; j<n; j++){
           if(j!=n-1) cout<<a[j]<<" ";
           else cout<<a[j]<<endl;
        }  
        

        }
return 0;

}
