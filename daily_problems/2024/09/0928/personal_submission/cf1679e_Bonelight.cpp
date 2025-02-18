/*
    Bonelight * v *
    20240930：放假的前一天，欧耶
    No Coding , No Bug
*/
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define INF 2e14
#define pii pair<int,int>

void solve(){
    int n; cin >> n; 
    string s; cin >> s;
    s = " " + s;

    const int mo = 998244353;
    auto M = [&](int x){return (x % mo + mo) % mo;};

    vector<vector<int>> pows(18,vector<int>(n + 1, 1));
    for(int i = 1; i <= 17; i ++){
        for(int j = 1; j <= n; j ++){
            pows[i][j] = pows[i][j - 1] * i;
            pows[i][j] %= mo;
        }
    }

    vector<vector<int>> cnt(n + 1, vector<int>(n + 1));
    vector<int> pre(n + 1);
    for(int i = 1; i <= n; i ++){
        int now = (s[i] == '?');
        cnt[i][i] = now;
        pre[i] = pre[i - 1] + now;
    }

    vector<vector<int>> dp(n + 1, vector<int>(n + 1)); //正确匹配串
    for(int l = n; l >= 1; l --){
        for(int r = l + 1; r <= n; r ++){
            if(dp[l + 1][r - 1] == -1 
                || (s[l] != '?' && s[r] != '?' && s[l] != s[r])){
                
                dp[l][r] = -1;
            } else {
                dp[l][r] = dp[l + 1][r - 1];
                cnt[l][r] = cnt[l + 1][r - 1];

                if(s[l] == '?' && s[r] != '?'){
                    dp[l][r] |= 1 << (s[r] - 'a');
                } else if(s[l] != '?' && s[r] == '?'){
                    dp[l][r] |= 1 << (s[l] - 'a');
                } else if(s[l] == '?' && s[r] == '?'){
                    cnt[l][r] ++;
                }
            }
        }
    }

    vector<vector<int>> ans(18, vector<int> (1 << 17));
    for(int l = 1; l <= n; l ++){
        for(int r = l; r <= n; r ++){
            if(dp[l][r] != -1){
                for(int i = 1; i <= 17; i ++){
                    ans[i][dp[l][r]] += 
                        pows[i][cnt[l][r] + pre[n] - (pre[r] - pre[l - 1])];
                    ans[i][dp[l][r]] % mo;
                }
            }
        }
    }

    for(int i = 1; i <= 17; i ++){
        for(int j = 0; j < 17; j ++){
            for(int msk = 0; msk <= (1 << 17); msk ++){
                if((msk >> j) & 1){
                    ans[i][msk] += ans[i][msk ^ (1 << j)];
                    ans[i][msk] %= mo;
                }
            }
        }
    }
    int q; cin >> q;
    while(q --){
        string qs; cin >> qs;
        int msk = 0;
        for(auto i:qs) msk |= 1 << (i - 'a');
        cout << ans[qs.size()][msk] << endl;
    }
    // cout << "end" << endl;
}

signed main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin);
    freopen("out.txt", "wt", stdout);
#endif
    int T = 1;
    while(T --){
        solve();
    }
}
