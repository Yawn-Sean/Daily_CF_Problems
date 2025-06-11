#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define endl '\n'
typedef long long ll;
typedef unsigned long long ull;
inline void solve()
{
    int n, k;
    cin >> n >> k;
    auto check = [&](int x, int y) {
        cout << "1 " << x << " " << y << endl;
        cout.flush();
        string s;
        cin >> s;
        if(s == "TAK") return 1;
        else return 0;
    };
    auto search = [&](int l, int r) {
        while(l < r) {
            int mid = l+r >> 1;
            if(check(mid, mid+1)) r = mid;
            else l = mid + 1;
        }
        return l;
    };
    int a = search(1, n);
    int b;
    b = search(1, a-1);
    cout << "1 " << b << " " << a << endl;
    cout.flush();
    string s;
    cin >> s;
    if(s == "NIE" || a == b) {
        b = search(a+1, n);
    }
    
    cout << "2 " << a << " " << b << endl;
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
