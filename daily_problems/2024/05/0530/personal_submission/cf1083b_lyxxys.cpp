#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve(){
    int n, k;
    cin >> n >> k;
    string s, t;
    cin >> s >> t;
    // 分别计算每一个长度不同的前缀分别有多少个字符串
    // 长度为m的前缀对结果的贡献为前缀满足的字符串数量cnt和k的最小值
    ll res = 0;
    for (int i = 0, sum = 1; i < n; ++ i){
        sum = sum*2 - (s[i] == 'b') - (t[i] == 'a');
        sum = min(sum, k+1);
        res += min(sum, k);
    }
    cout << res << "\n";
}
