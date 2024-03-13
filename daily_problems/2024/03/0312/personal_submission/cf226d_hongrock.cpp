#include<bits/stdc++.h>
using namespace std;

#define pb emplace_back
#define mp make_pair
 
using ll = long long;
using pii = pair<int,int>;
 
constexpr int mod = 998244353;
constexpr int inf = 0x3f3f3f3f;
constexpr int N = 110;

int n, m, a[N][N], row[N], col[N];
bool vis_row[N], vis_col[N];

void change(int x, int y){
  row[x] -= a[x][y];
  col[y] -= a[x][y];
  a[x][y] = -a[x][y];
  row[x] += a[x][y];
  col[y] += a[x][y];
}

void _main(){
  cin >> n >> m;
  for(int i=1; i<=n; ++i){
    for(int j=1; j<=m; ++j){
      cin >> a[i][j];
      row[i] += a[i][j];
      col[j] += a[i][j];
    }
  }
  for(;;){
    bool flag = 0;
    for(int i=1; i<=n && !flag; ++i){
      if(row[i] < 0){
        vis_row[i] ^= 1;
        for(int j=1; j<=m; ++j) change(i, j);
        flag = 1;
      }
    }
    for(int i=1; i<=m && !flag; ++i){
      if(col[i] < 0){
        vis_col[i] ^= 1;
        for(int j=1; j<=n; ++j) change(j, i);
        flag = 1;
      }
    }
    if(!flag) break;
  }
  vector<int> x, y;
  for(int i=1; i<=n; ++i) if(vis_row[i])  x.pb(i);
  for(int i=1; i<=m; ++i) if(vis_col[i])  y.pb(i);
  cout << x.size();
  for(int v : x)  cout << ' ' << v;
  cout << '\n';
  cout << y.size();
  for(int v : y)  cout << ' ' << v;
  cout << '\n';
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  _main();
  return 0;
}
