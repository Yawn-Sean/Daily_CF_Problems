#include<bits/stdc++.h>
using namespace std;

#define pb emplace_back
#define mp make_pair
 
using ll = long long;
using pii = pair<int,int>;
 
constexpr int mod = 998244353;
constexpr int inf = 0x3f3f3f3f;
constexpr int N = 2e5 + 10;

int r[7], arr[4] = {1, 6, 8, 9};

void _main(){
  memset(r, -1, sizeof(r));
  do{
    int x = 0;
    for(int i=0; i<4; ++i){
      x = x * 10 + arr[i];
    }
    int y = x % 7;
    if(r[y] == -1){
      r[y] = x;
    }
  }while(next_permutation(arr, arr+4));
  string s;
  vector<int> cnt(10, 0);
  cin >> s;
  for(char c : s){
    ++cnt[c - '0'];
  }
  for(int i=0; i<4; ++i)  --cnt[arr[i]];
  int v = 0;
  string ans = "";
  for(int i=9; i>=1; --i){
    for(int j=0; j<cnt[i]; ++j){
      v = (v * 10 + i) % 7;
      ans += (char)(i + '0');
    }
  }
  v = v * 10000 % 7;
  ans += to_string(r[(7 - v)%7]) + string(cnt[0], '0');
  cout << ans << '\n';
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  _main();
  return 0;
}
