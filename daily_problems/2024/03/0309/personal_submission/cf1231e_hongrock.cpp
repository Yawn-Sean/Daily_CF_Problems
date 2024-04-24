#include<bits/stdc++.h>
using namespace std;

#define pb emplace_back
#define mp make_pair
 
using ll = long long;
using pii = pair<int,int>;
 
constexpr int mod = 998244353;
constexpr int inf = 0x3f3f3f3f;
constexpr int N = 110;

int T, n, cnt[26], nxt[N][26];
string s, t;

int solve(){
  fill(cnt, cnt + 26, 0);
  for(int i=0; i<n; ++i){
    ++cnt[s[i] - 'a'];
    --cnt[t[i] - 'a'];
  }
  for(int i=0; i<26; ++i){
    if(cnt[i] != 0) return -1;
    nxt[n][i] = n;
  }
  for(int i=n-1; i>=0; --i){
    for(int j=0; j<26; ++j) nxt[i][j] = nxt[i+1][j];
    nxt[i][s[i] - 'a'] = i;
  }
  int ans = 1;
  for(int i=0; i<n; ++i){
    int x = -1;
    for(int j=i; j<n; ++j){
      int y = t[j] - 'a';
      if(nxt[x+1][y] < n){
        x = nxt[x+1][y];
        ans = max(ans, j - i + 1);
      } else {
        break;
      }
    }
  }
  return n - ans;
}

void _main(){
  cin >> T;
  while(T--){
    cin >> n >> s >> t;
    cout << solve() << '\n';
  }
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  _main();
  return 0;
}
