#include<bits/stdc++.h>
using namespace std;

#define pb emplace_back
#define mp make_pair
 
using ll = long long;
using pii = pair<int,int>;

constexpr int mod = 998244353;
constexpr int inf = 0x3f3f3f3f;
constexpr int N = 2e5 + 10;

struct Node{
  int x, y, id;
  void read(int p){
    id = p;
    cin >> x >> y;
  }
  bool operator < (const Node &A)const{
    if(x == A.x){
      return y < A.y || (y == A.y && id < A.id);
    }
    return x < A.x;
  }
}a[N];

int n, m, c, h, ans[N];
int len, b[N];

#define lson o<<1
#define rson o<<1|1
#define gmid (l[o]+r[o])>>1

int l[N<<2], r[N<<2], S[N<<2];
void build(int o, int L, int R){
  l[o] = L; r[o] = R;
  S[o] = -2e9;
  if(L < R){
    int mid = gmid;
    build(lson, L, mid);
    build(rson, mid+1, R);
  }
}

void update(int o, int p, int v){
  if(l[o] == r[o]){
    S[o] = max(S[o], v);
    return;
  }
  int mid = gmid;
  if(p <= mid)  update(lson, p, v);
  else  update(rson, p, v);
  S[o] = max(S[lson], S[rson]);
}

int query(int o, int L, int R){
  if(l[o] == L && r[o] == R){
    return S[o];
  }
  
  int mid = gmid;
  if(R <= mid)  return query(lson, L, R);
  if(L > mid) return query(rson, L, R);
  return max(query(lson, L, mid), query(rson, mid+1, R));
}

void upd(int &x, int y){
  if(x < y) x = y;
}

void solve(){
  len = 0;
  for(int i=1; i<=h+c; ++i){
    b[len++] = a[i].y;
  }
  sort(b, b + len);
  len = unique(b, b + len) - b;
  build(1, 0, len - 1);
  for(int i=1; i<=h+c; ++i){
    int j = lower_bound(b, b+len, a[i].y) - b;
    if(a[i].id == 0){
      update(1, j, -a[i].x - a[i].y);
    } else {
      upd(ans[a[i].id], a[i].x + a[i].y + query(1, 0, j));
    }
  }
}

void _main(){
  cin >> n >> m;
  cin >> c;
  for(int i=1; i<=c; ++i){
    a[i].read(0);
  }
  cin >> h;
  for(int i=1; i<=h; ++i){
    a[i+c].read(i);
  }
  solve();
  for(int i=1; i<=h+c; ++i){
    a[i].y = m + 1 - a[i].y;
  }
  solve();
  for(int i=1; i<=h+c; ++i){
    a[i].x = n + 1 - a[i].x;
  }
  solve();
  for(int i=1; i<=h+c; ++i){
    a[i].y = m + 1 - a[i].y;
  }
  solve();
  int key = 1;
  for(int i=2; i<=h; ++i){
    if(ans[i] < ans[key]){
      key = i;
    }
  }
  cout << ans[key] << '\n' << key << '\n';
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  _main();
  return 0;
}
