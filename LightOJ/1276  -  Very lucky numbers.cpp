#include <bits/stdc++.h>
using namespace std;
 
typedef long long Long;
const Long MAX = 1000000000000LL;
 
vector<Long> lucky, super;
set<Long> st;
 
void generate_lucky(Long sum)
{
    if(sum > 0 && sum < MAX)
    {
        lucky.push_back(sum);
    }
 
    if(sum > MAX) return;
 
    generate_lucky(sum * 10 + 4);
 
    generate_lucky(sum * 10 + 7);
}
 
void generate_super(int i, Long sum)
{
    if(sum>MAX) return;
 
    if(sum<=MAX && sum>3)   st.insert(sum);
 
    if(i>=lucky.size())
    {
        if(sum<=MAX && sum>3)   st.insert(sum);
 
        return;
    }
 
    if( sum <= MAX / lucky[i] ) generate_super(i , sum * lucky[i]);  
 
    if( sum <= MAX / lucky[i] ) generate_super(i + 1, sum);
   
    if( sum <= MAX / lucky[i] ) generate_super(i + 1, sum * lucky[i]);
 
}
 
int main()
{
 
        generate_lucky(0LL);
 
        sort(lucky.begin(), lucky.end());
 
        generate_super(0, 1LL);
 
        set<Long> ::iterator it;
 
        for(it = st.begin(); it!=st.end(); it++)    super.push_back(*it);
 
        int test, cs = 1;
 
        scanf("%d", &test);
 
        while(test--)
        {
            Long A, B, x = 0, y = 0;
 
            scanf("%lld %lld", &A, &B);
 
            x = upper_bound(super.begin(), super.end(), B) - super.begin();
 
            y = upper_bound(super.begin(), super.end(), A-1) - super.begin();
 
            printf("Case %d: %lld\n", cs++, x-y);
 
        }
 
       
    return 0;
 
}
 