#include <bits/stdc++.h>
using namespace std;

#define dbg(x) cout << #x << " = " << x << endl

typedef long long ll ;
typedef complex<double> complx;

vector <complx> FFT(vector <complx> ar, int inv){
    int i, j, l, len, n = ar.size();
    const double p = 4.0 * inv * acos(0.0);

    for (i = 1, j = 0; i < n; i++){
        for (l = n >> 1; j >= l; l >>= 1) j -= l;
        j += l;
        if (i < j) swap(ar[i], ar[j]);
    }

    for (l = 1, len = 2; len <= n; l <<= 1, len <<= 1){
        double theta = p / len;
        complx mul(cos(theta), sin(theta));

        for (i = 0; i < n; i += len){
            complx w(1.0, 0.0);
            for (j = 0; j < l; j++){
                complx u = ar[i + j], v = ar[i + j + l] * w;
                ar[i + j] = u + v, ar[i + j + l] = u - v;
                w *= mul;
            }
        }
    }

    if (inv == -1){
        for (i = 0; i < n; i++) ar[i] /= n;
    }
    return ar;
}

vector <complx> multiply(vector <complx> A, vector <complx> B){
    int n, m, i;
    vector <complx> C;
    n = A.size() + B.size() - 1;
    m = 1 << (32 - __builtin_clz(n) - (__builtin_popcount(n) == 1));
    A.resize(m, 0), B.resize(m, 0), C.resize(m, 0);

    A = FFT(A, 1), B = FFT(B, 1);
    for (i = 0; i < m; i++) C[i] = A[i] * B[i];
    return FFT(C, -1);
}
vector <complx> A;
vector <complx> B;

void solve(){
	A.clear();
	B.clear();

	int n;

	scanf("%d", &n);

	for(int i = 0; i<=n; i++){
		long long x;
		scanf("%lld", &x);
		A.push_back(x);
	}
	for(int i = 0; i<=n; i++){
		long long x;
		scanf("%lld", &x);
		B.push_back(x);
	}
	vector<complx> C = multiply(A, B);

	int len = n + n + 1;

	for(int i = 0; i<len; i++){
		if(i) printf(" ");
		long long x = C[i].real()+0.5;

		printf("%lld", x);
	}
	printf("\n");

}

int main()
{
	#ifdef local
		freopen("in.txt", "r", stdin);
	#endif

	int t;
	cin>>t;

	while(t--){
		solve();
	}
    return 0;
}
