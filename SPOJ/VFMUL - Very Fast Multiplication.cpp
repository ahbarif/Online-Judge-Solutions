
#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include <complex>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define MX 100005
#define LL long long

typedef complex<double> base;
const double PI = acos(-1.0);
vector<int>v1,v2,v3,v4,ans;
int a[MX],b[MX],c[MX];

inline void FFT(vector<base>&v_a, bool invert)
{
    int n = v_a.size();
    for(int i=1,j=0; i<n; ++i)
    {
        int bit = n >> 1;
        for( ; j>=bit; bit>>=1) j -= bit;
        j += bit;
        if(i<j) swap(v_a[i],v_a[j]);
    }

    for(int len=2; len<=n; len<<=1)
    {
        double angle = (2.0*PI)/len * (invert ? -1.0 : 1.0);
        base wlen (cos(angle), sin(angle));

        for(int i=0; i<n; i+=len)
        {
            base w (1);
            for(int j=0; j<(len/2); ++j)
            {
                base u = v_a[i+j], v = v_a[i+j+len/2]*w;
                v_a[i+j] = u+v;
                v_a[i+j+len/2] = u-v;
                w *= wlen;
            }
        }
    }

    if(invert)
    {
        for(int i=0; i<n; ++i)  v_a[i] /= n;
    }
    return;
}

inline vector<int> multiply(const vector<int>&v_a, const vector<int>&v_b)
{
    vector<int>res;
    vector<base> tmp_a(v_a.begin(),v_a.end()), tmp_b(v_b.begin(),v_b.end());

    size_t n = 1;
    while(n<max(v_a.size(),v_b.size())) n <<= 1;
    n <<= 1;

    tmp_a.resize(n);
    tmp_b.resize(n);
    FFT(tmp_a,false);
    FFT(tmp_b,false);

    for(size_t i=0; i<n; ++i)   tmp_a[i] *= tmp_b[i];

    FFT(tmp_a,true);

    res.resize(n);
    for(size_t i=0; i<n; ++i)
    {
        int x = int(tmp_a[i].real());
        double y = abs(double(tmp_a[i].real()));
        y = floor(y + 0.5);
        res[i] = (x<0) ? (-1 * y) : y;
        //res[i] = int(tmp_a[i].real() + 0.5);
    }

    while((int)res.size() && res.back()==0) res.pop_back();
    if(!(int)res.size())    res.push_back(0);

    return  res;
}

char str1[300005], str2[300005];
vector<int> va, vb;
string mul = "";

int main()
{
	#ifdef local
		freopen("in.txt", "r", stdin);
	#endif

  	int test;

    scanf("%d",&test);
    
    while(test--){
     	scanf("%s %s", str1, str2);
     	va.clear();
     	vb.clear();
    	for(int i = 0; str1[i]; i++){
    		va.push_back(str1[i]-'0');
    	}
    	for(int i = 0; str2[i]; i++){
    		vb.push_back(str2[i]-'0');
    	}

    	reverse(va.begin(), va.end());
    	reverse(vb.begin(), vb.end());

    	vector<int> ret = multiply(va, vb);

    	mul.clear();

    	int carry = 0;

    	for(int i = 0; i<ret.size(); i++){
    		int fuck = ret[i] + carry;
    		int p = fuck%10;
    		carry = fuck/10;
    		mul.push_back('0'+p);
    	}
    	if(carry) mul.push_back('0'+carry);

    	reverse(mul.begin(), mul.end());

    	for(char c:mul) printf("%c", c);
    	printf("\n");
    }
    return  0;
}
