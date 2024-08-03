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
void solve(int _) 
{
    int n, b;
    cin >> n >> b;
    vector<PII> primes;

    for (int i = 2; i <= b/i; i ++ ) {
        if (b % i == 0) {
            int cnt = 0;
            while (b % i == 0 ) {
                cnt ++;
                b /= i;
            }
            primes.emplace_back(i, cnt);
        }
    }
    if (b > 1) primes.emplace_back(b, 1);

    int ans = LLONG_MAX;
    for (auto [p, c]: primes) {
        int cur = n;
        int now = 0;
        while (cur) {
            cur /= p;
            now += cur;
        }
        ans = min(ans, now / c);
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
