#include<bits/stdc++.h>
using namespace std;

struct trie
{

    struct node
    {

        int endmark;

        node* next[2];

        node()
        {
            endmark = 0;
            for (int i = 0; i < 2; i++)  next[i] = NULL;
        }

    } * root;

    trie() {}

    void init()
    {
        root = new node();
    }

    void insert(int mask)
    {
        node* curr = root;

        for (int i = 31; i >=0; i--)
        {
            int id = (mask >> i) & 1;

            if (curr->next[id] == NULL) curr->next[id] = new node();

            curr = curr->next[id];
        }
        curr->endmark++;
    }

    int foo(int mask)
    {

        int ans= 0;

        node* curr = root;

        for (int i = 31; i >=0; i--)
        {
            int id = (mask >> i) & 1;

            if(curr->next[id] == NULL)
            {
                ans<<=1;
                ++ans;
                curr = curr->next[id^1];
            }
            else
            {
                curr = curr->next[id];
                ans <<= 1;
            }

        }

        return ans;

    }

    int bar(int mask)
    {
        int ans= 0;

        node* curr = root;

        for (int i = 31; i >=0; i--)
        {
            int id = (mask >> i) & 1;
            id ^= 1;

            if(curr->next[id] == NULL)
            {
                ans<<=1;
                curr = curr->next[id^1];
            }
            else
            {
                curr = curr->next[id];
                ans <<= 1;
                ++ans;
            }

        }

        return ans;
    }

    void del(node* cur)
    {
        for (int i = 0; i < 2; i++)
            if (cur->next[i] != NULL) del(cur->next[i]);
        delete (cur);
    }

};
int main()
{
#ifdef local
    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
#endif


    trie T;

    int test, cs = 0;

    scanf("%d", &test);

    while(test--)
    {

        int n, mn = INT_MAX, mx = 0, prefix = 0;

        T.init();

        T.insert(prefix);

        scanf("%d", &n);

        while(n--)
        {
            int x;
            scanf("%d", &x);

            prefix ^= x;

            mn = min(mn, T.foo(prefix));
            mx = max(mx, T.bar(prefix));
            T.insert(prefix);

        }

        printf("Case %d: %d %d\n", ++cs, mx, mn);


        T.del(T.root);
    }


#ifdef local
    cerr<<"\n\n__time elapsed = "<<clock()*1000/CLOCKS_PER_SEC<<" ms__"<<endl;
#endif

}

