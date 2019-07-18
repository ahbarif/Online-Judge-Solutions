#include<bits/stdc++.h>
using namespace std;

int grid[1005][1005];
int a[1005][1005];

vector<int> vec; // after extract
vector<int> tmp;

int ru, rd, cl, cr, dim;

bool extract(){

    vec.clear();
    tmp.clear();

    for(int j = cl; j<cr; j++) tmp.push_back(a[ru][j]), vec.push_back(grid[ru][j]);
    for(int j = ru; j<rd; j++) tmp.push_back(a[j][cr]), vec.push_back(grid[j][cr]);
    for(int j = cr; j>cl; j--) tmp.push_back(a[rd][j]), vec.push_back(grid[rd][j]);
    for(int j = rd; j>ru; j--) tmp.push_back(a[j][cl]), vec.push_back(grid[j][cl]);

    int pos = -1, ff = vec[0];

    for(int i = 0; i<tmp.size(); i++){
        if(tmp[i] == ff){
            pos = i;
            break;
        }
    }

//    for(auto it:vec) cout<<it<<" ";
//    cout<<endl;
//
//    for(auto it:tmp) cout<<it<<" ";
//    cout<<endl;

    if(pos == -1) return false;

  //  cout<<"pos = "<<pos<<endl;

    for(int i = 0; i<vec.size(); i++){
        int x = vec[i];
        int y = tmp[pos];

        if(x != y) return false;
        pos++;
        if(pos>=tmp.size()) pos = 0;
    }

    return true;




}

int main()
{
    int n, cs = 0;

    while(scanf("%d", &n) && n){
        int cid = 1;
      //  scanf("%d", &n);
        ru = 1;
        rd = n;
        cl = 1;
        cr = n;

        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=n; j++){
                scanf("%d", &a[i][j]);
                grid[i][j] = cid++;
            }
        }


        int rng = n/2;
        bool flag = true;
        for(int i = 1; i<=rng; i++){
            if(extract() == false){
                flag = false;
                break;
            }
            ru++;
            rd--;
            cl++;
            cr--;
        }

        if(n&1){
            int x = grid[(n+1)/2][(n+1)/2];
            int y = a[(n+1)/2][(n+1)/2];

            if(x != y) flag = false;
        }

        printf("%d. ", ++cs);

        if(flag) printf("YES\n");
        else printf("NO\n");

    }

}



