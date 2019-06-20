# include<bits/stdc++.h>
using namespace std;

int main(){

	int div[1010];
	int k, i, n, j, tc=0, last;
    	int test;
   	cin>>test;


	while (test--){

        		cin>>n;
		
		memset(div, 0, sizeof(div));

		for (i = 2; i <= n; i++){
			k = i;
			while (k % 2 == 0){
				k /= 2; div[2]++;
			}
			for (j=3; j*j<=k; j++){
	                while(k%j==0)   {
                	    k/=j; div[j]++;
                	}
			}
	        if(k>2) div[k]++;
    	}
        	cout<<"Case "<<++tc<<": "<<n<<" = "<<2<<" ("<<div[2]<<")";

	        for(i=3; i<1010; i++){
            		if(div[i])    cout<<" * "<<i<<" ("<<div[i]<<")";
        	}
        		cout<<endl;

	}

    return 0;
}