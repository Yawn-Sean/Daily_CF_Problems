#include<bits/stdc++.h>
#define int long long 
#define all(a) a.begin(), a.end()
#define endl '\n'
#define pb push_back
#define PII pair<int,int>
#define x first
#define y second
#define SZ(a) ((int)a.size())
using namespace std;
void print(vector<int> vi)
{
    for (auto t : vi) cout << t << ' ';
    cout << endl;
}
//////////////////////////////////////////////////
const int N = 2e5 + 10;
const int inf = 1e14;

void solve(int _) 
{
    string s;
    cin >> s;
    int n = s.size();

    function<int(int)> work = [&](int k) -> int {
        int res = 0, cur = 0;
        vector<int> cnt(26);
        for (int l = 0, r = 0; r < n; r ++ ) {
            int c = s[r] - 'a';
            if (cnt[c] == 0) cur ++;
            cnt[c] ++;
            while (l <= r && cur > k) {
                if (--cnt[s[l]-'a'] == 0) {
                    cur --;
                }
                l ++;
            }
            res += r - l + 1;
        }
        return res;
    };

    vector<int> ans;
    for (int i = 1; i <= 26; i ++ ) {
        int x = work(i) - work(i - 1);
        if (!x) break;
        ans.push_back(x);
    }

    cout << SZ(ans) << endl;
    for (int &x: ans) cout << x << endl;
} 

signed main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    
    int T = 1;
    //cin >> T;
    for (int _ = 1; _ <= T; _ ++ ) {
        solve(_);
    }
    return 0;
}