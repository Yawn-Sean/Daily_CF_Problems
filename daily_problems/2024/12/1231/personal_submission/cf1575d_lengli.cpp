#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)(x).size()
typedef long long LL;
LL expo(LL a, LL b){
  // a %= MOD; // USE THIS WHEN N IS REALLY BIG!
  LL ret = 1;
  while(b > 0){
    if(b&1) ret = (ret*a);
    a = (a*a); b >>= 1;
  }
  return ret;
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string s; cin >> s;
  int low = expo(10, sz(s) - 1);
  int high = expo(10, sz(s)) - 1;
  if(low == 1) low--;
  while(low%25) low++;
  int ans = 0;
  for(;low <= high;low += 25){
    string current = to_string(low);
    char xval = '-';
    bool can = 1;
    for(int i = 0;i < sz(s);i++){
      if(s[i] == '_') continue;
      if(s[i] == 'X'){
        if(xval != '-' && xval != current[i]){
          can = 0;
          break;
        }
        xval = current[i];
      }else if(s[i] != current[i]){
        can = 0;
        break;
      }
    }
    ans += can;
  }
  cout << ans << endl;
}
