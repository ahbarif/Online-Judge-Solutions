#include <bits/stdc++.h>
using namespace std;

int a[1000005];

void sieve(){
	int n = 1000000;

	for(int i = 1; i<=n; i++){
		for(int j = i; j<=n; j+=i){
			a[j]++;
		}
	}
}
int main()
{
	#ifdef local
    	freopen("in.txt","r",stdin);
	#endif

    sieve();
    // cout<<a[12]<<endl;
    // cout<<a[36]<<endl;

    int test;

    scanf("%d", &test);

    while(test--){
    	int ax, b;
    	scanf("%d %d", &ax, &b);
    	printf("%d\n", a[__gcd(ax, b)]);
    	
    }
    return 0;
}
