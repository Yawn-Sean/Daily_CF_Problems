#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define cute_prov0nce main
using namespace std;
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;

void solve()
{
    int n;
    cin >> n;
    int now = 1;
    vector<int> a(n+1);
    for (int i = 1; i <= n; i ++) {
        cout << "? " << i <<' ' << now << endl;
        char x;
        cin >> x;
        if (x == '=') {
            a[i] = now;
        }
        else if (x == '<') {
            while (x == '<') {
                now ++;
                cout << "? " << i <<' ' << now << endl;
                cin >> x;
            }
            a[i] = now;
        }
    }
    cout << "! ";
    for (int i =1 ; i<= n;i ++)cout << a[i] << ' ';
    cout << endl;
}

signed cute_prov0nce()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
