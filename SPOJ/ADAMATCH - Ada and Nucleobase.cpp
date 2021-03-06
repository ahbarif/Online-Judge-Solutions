#include <bits/stdc++.h>
using namespace std;

typedef complex<double> base;
const double PI = acos(-1.0);
typedef long long ll;
 
inline void FFT(vector<base>&v_a, bool invert){
   
    int n = v_a.size();
    
    for(int i=1,j=0; i<n; ++i){
        int bit = n >> 1;
        for( ; j>=bit; bit>>=1) j -= bit;
        j += bit;
        if(i<j) swap(v_a[i],v_a[j]);
    }
 
    for(int len=2; len<=n; len<<=1){
        double angle = (2.0*PI)/len * (invert ? -1.0 : 1.0);
        base wlen (cos(angle), sin(angle));
        for(int i=0; i<n; i+=len){
            base w (1);
            for(int j=0; j<(len/2); ++j){
                base u = v_a[i+j], v = v_a[i+j+len/2]*w;
                v_a[i+j] = u+v;
                v_a[i+j+len/2] = u-v;
                w *= wlen;
            }
        }
    }
 
    if(invert){
        for(int i=0; i<n; ++i)  v_a[i] /= n;
    }
    return;
}
 
inline vector<int> multiply(const vector<int>&v_a, const vector<int>&v_b){
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
    for(size_t i=0; i<n; ++i){
        int x = int(tmp_a[i].real());
        double y = abs(double(tmp_a[i].real()));
        y = floor(y + 0.5);
        res[i] = (x<0) ? (-1 * y) : y;
    }
 
    if(!(int)res.size())    res.push_back(0);
    while((int)res.size() && res.back()==0) res.pop_back();
 
    return  res;
}

char text[500005], pattern[500005];
int hamming[1000005], val;

vector<int> va, vb;


void process(char c){
	va.clear();
	vb.clear();
	
	for(int i = 0; text[i]; i++){
		if(text[i] == c) va.push_back(1);
		else va.push_back(0);
	}
 
	for(int i = strlen(pattern)-1; i>=0; i--){
		if(pattern[i] == c) vb.push_back(1);
		else vb.push_back(0);
	}
  
	vector<int> ret = multiply(va, vb);
	//cout<<ret.size()<<endl;

	int len = strlen(pattern);

	int cc = 0;
	for(int i = len-1; i<ret.size(); i++){
		 hamming[cc] += ret[i];
		 cc++;
		 if(cc == val) break;
	}



}


int main()
{
	#ifdef local
		freopen("in.txt", "r", stdin);
	#endif

	scanf("%s", text);
	scanf("%s", pattern);
	val = strlen(text) - strlen(pattern) + 1;
	process('A');
	process('C');
	process('T');
	process('G');

	int len = strlen(pattern);

	int mn = len;

	for(int i = 0; i<val; i++) mn = min(mn, len-hamming[i]);

	cout<<mn<<endl;
	




     return 0;
}
