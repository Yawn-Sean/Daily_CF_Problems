// LUOGU_RID: 150626115

#include<bits/stdc++.h>
#define int long long 
#define all(a) a.begin(), a.end()
#define endl '\n'
#define pb push_back
#define PII pair<int,int>
#define x first
#define y second
using namespace std;
void print(vector<int> vi)
{
    for (auto t : vi) cout << t << ' ';
    cout << endl;
}
//////////////////////////////////////////////////

void solve() 
{
    int n;
    cin >> n;

    string s[n+1];
    int len = 0;
    vector<array<int, 3>> q;
    for (int i = 1; i <= n; i ++ ) {
        cin >> s[i];
        int k;
        cin >> k;
        int lens = s[i].size();
        while(k -- ) {
            int pos;
            cin >> pos;
            q.push_back({pos, pos + lens - 1, i});
            len = max(len, lens + pos - 1);
        }
    }

    sort(all(q));
    vector<bool> used(len + 1);
    vector<char> ans(len + 1);
    int now = 1;
    for (auto [l, r, id] : q) {
        for (now = max(now, l); now <= r; now ++ ) {
            ans[now] = s[id][now-l];
            used[now] = 1;
        }
    }

    for (int i = 1; i <= len; i ++ ) {
        if (!used[i]) ans[i] = 'a';
        cout << ans[i];    
    }

} 

signed main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    
    int T = 1;
    //cin >> T;
    while (T --) {
        solve();
    }
    
}