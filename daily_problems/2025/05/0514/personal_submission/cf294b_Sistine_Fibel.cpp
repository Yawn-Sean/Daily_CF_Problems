#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve();
#define endl '\n'

const long long INF = 0x3f3f3f3f3f3f3f3f;
const long long MOD = 1e9; //模数

struct node{
    int w, v;
};

signed main (){ 
	std::cin.tie(NULL)->sync_with_stdio(false);
	int t = 1;
	// cin >> t;  //atc默认关闭，cf按需开启
	while(t --)
		solve();
}

void solve(){
    int n;
   cin >> n;
  int totLen = 0;
  node b[100010];
  int dp[100010];
  for (int i = 1; i <= n; i++) {
    cin >> b[i].w >> b[i].v;
    totLen += b[i].w;
  }
  for (int i = 1; i <= totLen; i++) {
    dp[i] = INF;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = totLen; j >= b[i].w; j--) {
      dp[j] = min(dp[j], dp[j - b[i].w] + b[i].v);
    }
  }
  for (int i = totLen; i >= 0; i--) {
    if (totLen - i >= dp[i]) {
      cout << totLen - i;
      return;
    }
  }
  return;
}

