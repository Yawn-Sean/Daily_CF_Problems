#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int P = 1e9+7;
int chart[1050], f[1050][1050], k;
string s;

void init(){
    memset(f, -1, sizeof f);
    for (int i = 2; i <= 1000; ++ i){
        int sum = 0;
        for (int j = 0; j < 10; ++ j)
            sum += i>>j & 1;
        chart[i] = chart[sum]+1;
    }
}
//cout << cnt << " " << chart[cnt] << "\n";
int dfs(int len, int cnt, bool limit, bool lead){
    if (len < 0) {return chart[cnt]+1 == k;}
    if (~f[len][cnt] && lead && !limit) return f[len][cnt];
    int up = limit ? s[len]-'0' : 1;
    int res = 0;
    for (int i = 0; i <= up; ++ i)
        res = (res + dfs(len-1, cnt+i, limit&&i==up, i|lead)) % P; //有无上限，搜索有无开始
    if (lead && !limit) f[len][cnt] = res;
    return res;
}   
void solve(){
    cin >> s >> k;
    chart[0] = -1, init();
    int len = s.size()-1;
    reverse(s.begin(), s.end());
    int res = dfs(len, 0, 1, 0);
    if (k == 1) -- res;
    cout << res << "\n";
}
