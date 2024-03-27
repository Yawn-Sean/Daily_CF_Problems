#include<bits/stdc++.h>
using namespace std;

#define pb emplace_back
#define mp make_pair

using ll = long long;
using pii = pair<int,int>;

constexpr int mod = 998244353;
constexpr int inf = 0x3f3f3f3f;
constexpr int N = 2e5 + 10;

int n, val[N];
string op[N];

void _main(){
  cin >> n;
  stack<int> st;
  for(int i=1; i<=n*2; ++i){
    cin >> op[i];
    if(op[i] == "+"){
      st.push(i);
    } else {
      if(st.empty()){
        cout << "NO\n";
        return;
      }
      cin >> val[i];
      val[st.top()] = val[i];
      st.pop();
    }
  }
  vector<int> ans;
  set<int> g;
  for(int i=1; i<=n*2; ++i){
    if(op[i] == "+"){
      g.insert(val[i]);
      ans.pb(val[i]);
    } else {
      if(*g.begin() != val[i]){
        cout << "NO\n";
        return;
      }
      g.erase(g.begin());
    }
  }
  cout << "YES\n";
  for(int i=0; i<n; ++i)  cout << ans[i] << " \n"[i == n - 1];
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  _main();
  return 0;
}