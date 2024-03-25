#include<bits/stdc++.h>
using namespace std;

#define pb emplace_back
#define mp make_pair
 
using ll = long long;
using pii = pair<int,int>;
 
constexpr int mod = 998244353;
constexpr int inf = 0x3f3f3f3f;
constexpr int N = 1e6 + 10;

int n, a[N], s[N];

int lowbit(int x){
  return x & (-x);
}

void add(int x, int v){
  for(; x<=n; x+=lowbit(x)) s[x] += v;
}
int sum(int x){
  int ret = 0;
  for(; x>0; x-=lowbit(x))  ret += s[x];
  return ret;
}

void _main(){
  cin >> n;
  int v = 0;
  for(int i=1; i<=n; ++i){
    cin >> a[i];
    v ^= (i - 1 - sum(a[i]));
    add(a[i], 1);
  }
  if((v & 1) == (n * 3 & 1)){
    cout << "Petr\n";
  } else {
    cout << "Um_nik\n";
  }
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  _main();
  return 0;
}
