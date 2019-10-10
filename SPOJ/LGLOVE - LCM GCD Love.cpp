#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mx = 300005;
ll mod = 1000000007LL;
int arr[mx];

namespace NT{
	ll primes[mx], dp[mx], mark[mx];
	int idx = 0;

	void sieve(int N){
	    for(int i = 3; i*i <= N; i += 2){
	        if(mark[i] == false){
	            for(int j = i*i; j <= N; j += i*2){
	                mark[j] = true;
	            }
	        }
	    }
	    primes[idx++] = 2;
	    for(int i=3; i<=N; i+=2){
	        if(!mark[i]){
	            primes[idx++] = i;
	        }
	    }
	    dp[0] = 2LL;

	    for(int i = 1; i<idx; i++){
	    	 dp[i] = dp[i-1] * primes[i];
	    	 dp[i] %= mod;
	    }
	}

	ll __LCM(int n){
	    ll lcm = 1;
	    for (int i=0; primes[i]*primes[i]<=n; i++){
	        ll pp = n/primes[i];
	        while (pp>=primes[i]){
	            pp /= primes[i];
	            lcm *= primes[i];
	            lcm %= mod;
	        }
	    }
	    return lcm;
	}

	ll LCM_from_1(int n){
		if(n == 1) return 1LL;
		ll lcm = __LCM(n);
		int pos = upper_bound(primes, primes+idx, n) - primes;
		lcm *= dp[pos-1];
		lcm %= mod;
		return lcm;
	}
}

namespace SegTree{
    ll tree_1[mx*4], tree_2[mx*4], Lazy[mx*4];   // tree2 te min

    void construct(int node, int st, int en){ 
        if (st == en) { 
            tree_1[node] = arr[st]; 
            tree_2[node] = arr[st]; 
            return; 
        }  
        int mid = (st + en) / 2; 
        construct(node*2, st, mid); 
        construct(node*2+1, mid+1, en); 
        tree_1[node] = max(tree_1[node*2], tree_1[node*2+1]); 
        tree_2[node] = min(tree_2[node*2], tree_2[node*2+1]); 
    } 

    void rangeUpdate(int si, int ss, int se, int us, int ue, int diff){
        if(Lazy[si] != 0){
            tree_1[si] += Lazy[si];
            tree_2[si] += Lazy[si];

            if(ss != se){
                Lazy[si * 2] += Lazy[si]; 
                Lazy[si * 2 + 1] += Lazy[si]; 
            }

            Lazy[si] = 0;
        }

        if (ss > se || ss > ue || se < us) return;

        if (ss >= us && se <= ue) { 
            tree_1[si] += diff; 
            tree_2[si] += diff; 

            if (ss != se) { 
                Lazy[si * 2] += diff; 
                Lazy[si * 2 + 1] += diff; 
            } 
            return; 
        } 

        int mid = (ss + se)/2;
        rangeUpdate(si * 2, ss, mid, us, ue, diff); 
        rangeUpdate(si * 2 + 1, mid + 1, se, us, ue, diff);

        tree_1[si] = max(tree_1[si*2], tree_1[si*2+1]); 
        tree_2[si] = min(tree_2[si*2], tree_2[si*2+1]);  
    }

    int query(int node, int st, int en, int i, int j, int isMax){
        if(Lazy[node] != 0){
            tree_1[node] += Lazy[node];
            tree_2[node] += Lazy[node];

            if(st != en){
                Lazy[node * 2] += Lazy[node]; 
                Lazy[node * 2 + 1] += Lazy[node]; 
            }
            Lazy[node] = 0;
        }

        if (st > en || st > j || en < i){
            return (isMax?0:300000);
        } 

        if (st >= i && en <= j){
            return isMax?tree_1[node]:tree_2[node];
        }

        int mid = (st+en)/2;

        int x = query(node*2, st, mid, i, j, isMax); 
        int y = query(node*2+1, mid+1, en, i, j, isMax);

        return (isMax?max(x, y):min(x, y));
    }
}



int main()
{

	// freopen("in.txt", "r", stdin);
	
	NT::sieve(300000);

	int n, q;
	scanf("%d %d", &n, &q);
	for(int i = 0; i<n; i++) scanf("%d", &arr[i]);

	SegTree::construct(1, 0, n-1);

	while(q--){
		int t, u, v, x;
		scanf("%d %d %d", &t, &u, &v);
		if(t == 1){
			int max_val = SegTree::query(1, 0, n-1, u, v, true);
			// cout<<"max = "<<max_val<<endl;
			printf("%lld\n", NT::LCM_from_1(max_val));
		}
		else if(t == 2){

			int min_val = SegTree::query(1, 0, n-1, u, v, false);
			// cout<<"min = "<<min_val<<endl;
			
			printf("%lld\n", NT::LCM_from_1(min_val));
		}
		else{
			scanf("%d", &x);
			SegTree::rangeUpdate(1, 0, n-1, u, v, x);
		}

	}

	return 0;

}

