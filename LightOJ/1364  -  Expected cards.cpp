#include<bits/stdc++.h>
using namespace std;

int req[5];

double dp[14][14][14][14][5][5];
bool vis[14][14][14][14][5][5];

bool done(int s, int h, int c, int d){
  return (s >= req[0] && h >= req[1] && c >= req[2] && d>=req[3]);
}

int cnt;

double fun(int s, int h, int c, int d, int j1, int j2){

    int cs = 13 - s + (j1 == 1) + (j2 == 1);  // collected  spade
    int ch = 13 - h + (j1 == 2) + (j2 == 2);  // collected hearts
    int cc = 13 - c + (j1 == 3) + (j2 == 3);
    int cd = 13 - d + (j1 == 4) + (j2 == 4);

    if(done(cs, ch, cc, cd)) return dp[s][h][c][d][j1][j2] = 0.0;

    int lagbe = max(0, req[0]-cs) + max(0, req[1] - ch) + max(0, req[2] - cc) + max(req[3] - cd, 0);
    int availabe = s + h + c + d + (j1 == 0) + (j2 == 0);
    if(availabe < lagbe) return dp[s][h][c][d][j1][j2]= 10000.0;

    if(vis[s][h][c][d][j1][j2]) return dp[s][h][c][d][j1][j2];
    vis[s][h][c][d][j1][j2] = 1;


    double joker = 0;
    if(j1 == 0) joker += 1.0;
    if(j2 == 0) joker += 1.0;

    double tot = availabe * 1.0;

    double ret = 0.0;

    if( s > 0) ret += (s/tot)*(1+fun(s-1, h, c, d, j1, j2));
    if( h > 0) ret += (h/tot)*(1+fun(s, h-1, c, d, j1, j2));
    if( c > 0) ret += (c/tot)*(1+fun(s, h, c-1, d, j1, j2));
    if( d > 0) ret += (d/tot)*(1+fun(s, h, c, d-1, j1, j2));

    if(j1 == 0){
        double p = (joker*1.0/tot);

        double tmp = p*(1+fun(s, h, c, d, 1, j2));
        double x2  = p*(1+fun(s, h, c, d, 2, j2));
        double x3  = p*(1+fun(s, h, c, d, 3, j2));
        double x4  = p*(1+fun(s, h, c, d, 4, j2));

        tmp = min(tmp, x2);
        tmp = min(tmp, x3);
        tmp = min(tmp, x4);

        ret += tmp;
    }

    else if(j2 == 0){
        double p = (joker*1.0/tot);
        double tmp2 = p*(1+fun(s, h, c, d, j1, 1));
        double x22  = p*(1+fun(s, h, c, d, j1, 2));
        double x33  = p*(1+fun(s, h, c, d, j1, 3));
        double x44  = p*(1+fun(s, h, c, d, j1, 4));

        tmp2 = min(tmp2, x22);
        tmp2 = min(tmp2, x33);
        tmp2 = min(tmp2, x44);

        ret += tmp2;
    }

    return dp[s][h][c][d][j1][j2] = ret;
}

void solve(int cs){

  printf("Case %d: ", cs);
  int ex = 0;

  for(int i = 0; i<4; i++){
    cin>>req[i];
    if(req[i]>13) ex += (req[i]-13);
  }
  if(ex>2) cout<<-1<<endl;
  else{
    memset(vis, 0, sizeof(vis));
    double ret = fun(13, 13, 13, 13, 0, 0);
    printf("%.10f\n", ret);
  }

}

int main()
{
    #ifdef local
      freopen("in.txt", "r", stdin);
    #endif

    int t, cs = 0;

    scanf("%d", &t);

    while(t--){
        solve(++cs);
    }

    return 0;

}
