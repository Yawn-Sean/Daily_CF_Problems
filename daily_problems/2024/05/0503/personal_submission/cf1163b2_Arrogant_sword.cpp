
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
    int n;
    cin >> n;
    vector<int> a(n+1);
    for (int i = 1; i <= n; i ++ ) {
        cin >> a[i];
    }
    int ans = 0, mx = 0;
    map<int, int> cnt, freq;
    for (int i = 1; i <= n; i ++ ) {
        freq[cnt[a[i]]] --;
        cnt[a[i]] ++;
        freq[cnt[a[i]]] ++;
        mx = max(mx, cnt[a[i]]);
        // 1 2 3 4
        if (mx == 1) {
            ans = i;
            continue;
        }
        // 1 2 2 3 3 4 4
        if (freq[mx] * mx == i - 1) {
            ans = i;
            continue;
        }
        // 1 1 2 2 3 3 3
        if ((freq[mx-1] + 1) * (mx - 1) == i - 1) {
            ans = i;
            continue;
        }
    }

    cout << ans << endl;
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