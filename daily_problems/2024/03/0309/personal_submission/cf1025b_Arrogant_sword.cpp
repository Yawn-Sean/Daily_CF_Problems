
#include<bits/stdc++.h>
#define int long long 
#define all(a) a.begin(), a.end()
#define endl '\n'
#define pb push_back
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

    vector<array<int, 2>> po(n);
    for (int i = 0; i < n; i ++ ) {
        cin >> po[i][0] >> po[i][1];
    }

    vector<int> primes;
    int x = po[0][0];
    for (int i = 2; i <= x/i; i ++ ) {
        if(x % i == 0) {
            primes.pb(i);
            while (x % i == 0) {
                x /= i;
            }
        }
    }
    if (x) primes.pb(x);

    x = po[0][1];
    for (int i = 2; i <= x/i; i ++ ) {
        if(x % i == 0) {
            primes.pb(i);
            while (x % i == 0) {
                x /= i;
            }
        }
    }
    if (x) primes.pb(x);

    for (int t: primes) {
        if (t  <= 1) continue;
        bool ok = true;
        for (int i = 1; i < n; i ++ ) {
            if (po[i][0] % t && po[i][1] % t) {
                ok = false;
                break;
            }
        }
        if (ok) {
            cout << t << endl;
            return;
        }
    }

    cout << -1 << endl;

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