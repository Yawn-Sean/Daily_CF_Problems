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
    vector<int> a(n+1), pre(n+1);
    for(int i=1; i<=n; i++) {
        cin >> a[i];
        pre[i] = pre[i-1] + a[i];
    }
    auto check = [&](int x) {
        for(int i=1; i+x-1<=n; i++) {
            int s = pre[i+x-1] - pre[i-1];
            if(s + k >= x) return true;
        }
        return false;
    };
    int l = 0, r = n;
    while(l < r) {
        int mid = l + r + 1 >> 1;
        if(check(mid)) l = mid;
        else r = mid - 1;
    }
    cout << l << endl;
    for(int i=1; i+l-1<=n; i++) {
        int s = pre[i+l-1] - pre[i-1];
        if(s + k >= l) {
            for(int j=i; j<=i+l-1; j++)
                a[j] = 1;
            break;
        }
    }
    for(int i=1; i<=n; i++)
        cout << a[i] << " ";
}
