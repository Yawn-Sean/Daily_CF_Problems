#include<bits/stdc++.h>
using namespace std;

#define pb emplace_back
#define mp make_pair
 
using ll = long long;
using pii = pair<int,int>;
 
constexpr int mod = 998244353;
constexpr int inf = 0x3f3f3f3f;
constexpr int N = 2e6 + 10;

int n, m;
char s[N];
vector<string> g;
vector<int> p[N];

void _main(){
  set<int> st;
  m = 0;
  cin >> n;
  g.resize(n);
  for(int i=0; i<n; ++i){
    cin >> g[i];
    int x, y;
    cin >> x;
    while(x--){
      cin >> y;
      --y;
      p[i].pb(y);
      m = max(m, y + (int)g[i].length());
    }
  }
  for(int i=0; i<m; ++i)  st.insert(i);
  for(int i=0; i<n; ++i){
    int len = g[i].length();
    for(int v : p[i]){
      int w = v;
      for(;w<v+len;){
        auto it = st.lower_bound(w);
        if(it == st.end())  break;
        if(*it >= v + len)  break;
        s[*it] = g[i][*it - v];
        w = *it + 1;
        st.erase(it);
      }
    }
  }
  for(int v : st) s[v] = 'a';
  s[m] = '\0';
  cout << s << '\n';
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  _main();
  return 0;
}
