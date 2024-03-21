
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
    int n, m;
    cin >> n >> m;
    vector<int> a(34);
    for (int i = 0; i < n; i ++ ) cin >> a[i];

    int ans = 0, last = 0;
    vector<int> res;
    for (int i = 32; i >= 0; i --) {
        if ((m >> i) & 1) {
            last ++;
        } 
        
        if (a[i] != 0) {
                int mn = 1e18, p = 2;
                for (int j = n-1; j >= 0; j -- ) {
                    if (j >= i) {
                        mn = min(mn, a[j]);
                    } else {
                        mn = min(mn, a[j] * p);
                        p *= 2;
                    }
                }
                ans += mn * last;
                last = 0;
            }
        
        
        if (a[i]) {
            res.pb(a[i] + ans);
        }
        last *= 2;
    }
    
    cout << min(ans, *min_element(all(res))) << endl;
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