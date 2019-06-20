#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll N = 46657LL;

vector<ll> prime;

void seive()
{
	prime.push_back(2);

	bool mark[N];

	memset(mark, 0, sizeof(mark));

	for(ll i=3; i*i<=N; i+=2)
	{
		for(ll j=i*i; j<=N; j+=i*2)
		{
			mark[j]=true;
		}
	}

	for(ll i=3; i<=N; i+=2) if(!mark[i]) prime.push_back(i);
}

ll segmented_sieve(ll a, ll b)
{
	bool mark[b-a+10];

	memset(mark, 0, sizeof(mark));

	ll i, j;

	for(i = 0; i<prime.size(); i++)
	{
		ll st = prime[i] * ((a + prime[i]-1) / prime[i]);

		for(j=st; j<=b; j+=prime[i])	if(j!=prime[i]) mark[j-a] = true;
	}

	ll res = 0;

	for(i=a; i<=b; i++)
	{
		if(mark[i-a]==false && i!=1)	++res;
	}

	return res;
}

int main()
{
	seive();

	int t, cs = 1;

	scanf("%d", &t);

	while(t--)
	{
		ll a, b, c;

		scanf("%lld %lld", &a, &b);

		c = segmented_sieve(a, b);

		printf("Case %d: %lld\n", cs++, c);
	}

	return 0;

}
