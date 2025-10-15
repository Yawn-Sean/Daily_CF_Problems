#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define debug(x) cerr << #x << ": " << x << '\n';
#define endl '\n'
typedef long long ll;
typedef unsigned long long ull;

inline void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n+1);
    for(int i=1; i<=n; i++) {
        cin >> a[i];
    }
    vector<int> fa(256, -1);
    for(int i=1; i<=n; i++) {
        if(fa[a[i]] != -1) {
            continue;
        }
        int t = max(0, a[i]-k+1);
        int p = -1;
        for(int j=t; j<=a[i]; j++) {
            if(fa[j] != -1) {
                if(fa[j]+k-1 >= a[i]) {
                    p = fa[j];       
                }
                continue;
            }
            if(fa[j] == -1 && p == -1) {
                p = j;
            } 
            fa[j] = p;
        }
    }
    for(int i=1; i<=n; i++)
        cout << fa[a[i]] << " ";
}
int main()
{
    cout << fixed << setprecision(10);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;
    t = 1;
    while(t --)
        solve();
    return 0;
}
