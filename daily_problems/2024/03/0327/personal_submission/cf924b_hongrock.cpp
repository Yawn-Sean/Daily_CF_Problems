#include<bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int N = 1e5 + 10;

int n, U, e[N];

void _main(){
  cin >> n >> U;
  for(int i=1; i<=n; ++i) cin >> e[i];
  ll up = -1, down = 1;
  for(int i=1, j=1; i<=n; ++i){
    j = max(j, i);
    while(j < n && e[j+1] - e[i] <= U)  ++j;
    if(j - i >= 2 && up * (e[j] - e[i]) < down * (e[j] - e[i+1])){
      up = e[j] - e[i+1];
      down = e[j] - e[i];
    }
  }
  if(up == -1){
    cout << "-1\n";
  } else {
    cout << fixed << setprecision(10) << 1.0 * up / down << '\n';
  }
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr); cout.tie(nullptr);
  _main();
  return 0;
}