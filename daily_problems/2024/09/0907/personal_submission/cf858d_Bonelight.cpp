#include <bits/stdc++.h>
using namespace std;
#define int long long
#define uint unsigned long long
#define endl '\n'
#define pii pair<int, int>

void solve()
{
    int n; cin >> n;
    vector<string> ss(n);
    for(auto &i:ss) cin >> i;

    unordered_map<string,int> mp;
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < 9; j ++){
            int num = 0;
            for(int k = j; k < 9; k ++){
                string s = ss[i].substr(j,k - j + 1);
                if(mp.find(s) == mp.end()) mp[s] = i;
                else if(mp[s] != i) mp[s] = -1;
            }
        }
    }
    
    for(int i = 0; i < n; i ++){
        string ans = string(10,'0');
        for(int j = 0; j < 9; j ++){
            for(int k = j; k < 9; k ++){
                string s = ss[i].substr(j, k - j + 1);
                if(s.size() < ans.size() && mp[s] == i){
                    ans = s;
                }
            }
        }
        cout << ans << endl;
    }
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "rt", stdin), freopen("out.txt", "wt", stdout);
#endif
    int T = 1;
    while (T--)
        solve();
}
