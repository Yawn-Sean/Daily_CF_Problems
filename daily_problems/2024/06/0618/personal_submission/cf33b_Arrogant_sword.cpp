#include<bits/stdc++.h>
#define int long long 
#define all(a) a.begin(), a.end()
#define endl '\n'
#define pb push_back
#define PII pair<int,int>
#define SZ(a) ((int)a.size())
using namespace std;
void print(vector<int> vi)
{
    for (auto t : vi) cout << t << ' ';
    cout << endl;
}
//////////////////////////////////////////////////
const int N = 2e5 + 10;
vector cost(26, vector<int>(26, INT_MAX));
void floyd()
{
    int n = 26;
    for (int i = 0; i < n; i ++ ) cost[i][i] = 0;
    for (int k = 0; k < n; k ++ )
        for (int i = 0; i < n; i ++ )
            for (int j = 0; j < n; j ++ )
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
}

void solve(int _) 
{
    string a, b;
    cin >> a >> b;
    if (SZ(a) != SZ(b)) {
        cout << -1 << endl;
        return;
    }

    int n;
    cin >> n;
    for (int i = 0; i < n; i ++ ) {
        char u, v; int w; cin >> u >> v >> w;
        cost[u-'a'][v-'a'] = min(cost[u-'a'][v-'a'], w);
    }

    floyd();

    int ans = 0;
    string res;
    int sn = SZ(a);
    for (int i = 0; i < sn; i ++ ) {   
        int tmp = INT_MAX;
        char ch;
        for (int j = 0; j < 26; j ++ ) {
            if (tmp > cost[a[i]-'a'][j] + cost[b[i]-'a'][j]) {
                tmp = cost[a[i]-'a'][j] + cost[b[i]-'a'][j];
                ch = char(j+'a');
            }
        }
        ans += tmp;
        res += ch;
        if (ans > 1e9) {
            cout << -1 << endl;
            return;
        }
    }

    cout << ans << endl;
    cout << res << endl;
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