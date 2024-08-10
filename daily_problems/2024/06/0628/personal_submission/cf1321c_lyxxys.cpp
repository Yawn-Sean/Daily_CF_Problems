#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1500, inf = 1e9;
 
void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = " " + s + " ";
    vector <int> lik(n+2), rik(n+2), del(n+1), ids[26];
    for (int i = 1; i <= n; ++ i){
        ids[s[i]-'a'].push_back(i);
        lik[i] = i-1, rik[i] = i+1;
    }
    //O(n^2)
    int cnt = 0;
    for (int i = 25; i >= 1; -- i){
        int j = ids[i].size();
        while (j--){
            for (auto &x: ids[i]){
                if (del[x]) continue;
                if (s[lik[x]]+1 == s[x] || s[rik[x]]+1 == s[x]){      
                    del[x] = true;
                    ++ cnt;
                    rik[lik[x]] = rik[x];
                    lik[rik[x]] = lik[x];
                }
            }
        }
    }
    cout << cnt << "\n";
}
 
int main(){
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#else
    freopen("in.txt", "rt", stdin), freopen("out.txt", "wt", stdout);
#endif
    int _ = 1;
    while (_--) solve();
    return 0;
}
