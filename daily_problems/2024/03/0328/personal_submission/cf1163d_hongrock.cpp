#include<bits/stdc++.h>
using namespace std;

constexpr int inf = 0x3f3f3f3f;

void upd(int &x, int y){
  if(x < y) x = y;
}

void getfail(string &s, vector<int> &f, int &len, vector<vector<int>> &nxt){
  len = s.length();
  f.resize(len + 1);
  f[0] = f[1] = 0;
  for(int i=1; i<len; ++i){
    int j = f[i];
    while(j && s[j] != s[i])  j = f[j];
    f[i+1] = s[i] == s[j] ? j + 1 : 0;
  }
  nxt.resize(len + 1, vector<int>(26, 0));
  for(int i=0; i<=len; ++i){
    for(int v=0; v<26; ++v){
      int j = i;
      while(j && s[j] != (v + 'a')) j = f[j];
      if(s[j] == v + 'a') ++j;
      nxt[i][v] = j;
    }
  }
}

void _main(){
  string c, s, t;
  cin >> c >> s >> t;
  int len1, len2;
  vector<int> f1, f2;
  vector<vector<int>> nxt1, nxt2;
  getfail(s, f1, len1, nxt1);
  getfail(t, f2, len2, nxt2);

  int n = c.length();
  vector<vector<int>> dp1(len1 + 1, vector<int>(len2 + 1, -inf));
  vector<vector<int>> dp2(len1 + 1, vector<int>(len2 + 1, -inf));
  dp1[0][0] = 0;
  for(char ch : c){
    int st, ed;
    if(ch == '*'){
      st = 0;
      ed = 26;
    } else {
      st = ch - 'a';
      ed = st + 1;
    }
    for(int i=0; i<=len1; ++i){
      for(int j=0; j<=len2; ++j)  dp2[i][j] = -inf;
    }
    for(int i=0; i<=len1; ++i){
      for(int j=0; j<=len2; ++j){
        for(int v=st; v<ed; ++v){
          int i1 = nxt1[i][v];
          int j1 = nxt2[j][v];
          upd(dp2[i1][j1], dp1[i][j] + (i1 == len1) - (j1 == len2));
        }
      }
    }
    swap(dp1, dp2);
  }
  int ans = -inf;
  for(int i=0; i<=len1; ++i){
    for(int j=0; j<=len2; ++j)  upd(ans, dp1[i][j]);
  }
  cout << ans << '\n';
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  _main();
  return 0;
}
