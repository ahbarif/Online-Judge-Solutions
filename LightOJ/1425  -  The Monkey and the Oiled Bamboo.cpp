#include<bits/stdc++.h>
using namespace std;

int a[100005], n;

bool can(int mid)
{
	int i = 0;
	a[0] = 0;

	for(i=0; i<n; i++)
	{
		int next = a[i+1]-a[i];
		if(next>mid)	return false;
		else if(next==mid)	mid--;
	}

	return true;
}


int main()
{

		int test, cs = 1;

		 scanf("%d", &test);

		 while(test--)
		 {
			int lo = 0, hi = 1000000000, mid, ans, i;

			scanf("%d", &n);

			for(i=1; i<=n; i++)	scanf("%d", &a[i]);

			while(lo<hi)
			{
				mid = (lo+hi)>>1;

				if(can(mid))
				{
					ans = mid;
					hi = mid;
				}
				else lo = mid+1;
			}

			printf("Case %d: %d\n", cs++, ans);

		}


	return 0;

}
