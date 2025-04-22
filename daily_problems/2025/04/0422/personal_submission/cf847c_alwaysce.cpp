#include <iostream>
#include <vector>
#include <map>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    i64 n, k;
    cin >> n >> k;

    vector<i64> pw(n);
    pw[0] = 0;
    for (int i = 1; i < n; i++) {
        pw[i] = 1ll * i * (i + 1) / 2;
    }

    if (k > pw.back()) {
        cout << "Impossible\n";
    } else {
        int mx = 0;
        string ans;
        // n(n+1)/2 >= k
        // minus = n * (n + 1) / 2 - k
        // 1 .... n -> 1 ... n - 1 + ()
        for (int i = 0; i < n; i++) {
            if (pw[i] >= k) { 
                mx = i;
                break;
            }
        }

        // move n -> n - minus
        // cout << mx << '\n';
        i64 minus = pw[mx] - k;
        int left = n - 1 - mx;

        i64 remove_layer = mx - minus;
        // cout << minus << ' ' << remove_layer << '\n';

        ans.push_back('(');
        for (int j = 1; j <= mx; j++) {
            if (j == remove_layer) {
                ans.push_back('(');
                ans.push_back(')');
            } else {
                ans.push_back('(');
            }
        }
        for (int j = 1; j <= mx - 1; j++) {
            ans.push_back(')');
        }
        ans.push_back(')');
        for (int j = 0; j < left; j++) {
            ans.push_back('(');
            ans.push_back(')');
        }
        cout << ans << '\n';
    }
    return 0;
}
