#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
 
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;

 
int main()
{
    cin.tie(0)->sync_with_stdio(0);
	  cin.exceptions(cin.failbit);
    
    int n;
    cin >> n;
    vector<int> num(n);
    int ans = 0, cnt = 0, d;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
        if (i == 0) {
            d = num[i];
        } else {
            d = __gcd(d, num[i]);
        }
        num[i] %= 2;
        if (num[i] == 1) {
            cnt++;
        } else {
            ans += cnt / 2 + 2 * (cnt % 2);
            cnt = 0;
        }
    }
    ans += cnt / 2 + 2 * (cnt % 2);
    cnt = 0;
    if (d != 1) {
        cout << "YES\n0\n";
    } else {
        cout << "YES\n" << ans << "\n";
    }
}
