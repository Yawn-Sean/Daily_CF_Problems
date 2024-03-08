#include<bits/stdc++.h>

#define int long long 
#define all(a) a.begin(), a.end()
#define endl '\n'
#define pb push_back
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;

void print(vector<int> vi)
{
    for (auto t : vi) cout << t << ' ';
    cout << endl;
}


//////////////////////////////////////////////////


void solve() 
{
    double m, n;
    cin >> m >> n;
    double ans = 0;
    for (double i = 1; i <= m; i ++ ) {
        ans += i * (pow(i/m, n) - pow((i-1)/m, n));
    }

    cout << fixed << setprecision(12) << ans <<  endl;

} 


signed main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    
    int T = 1;
   // cin >> T;
    while (T --) {
        solve();
    }
    
}