#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 100010;
int n, fa[N], s[N];
 
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    cin >> n;
    for (int i = 2; i <= n; i++)
        cin >> fa[i];
    for (int i = 1; i <= n; i++)
        cin >> s[i];

    for (int i = 2; i <= n; i++) {
        if (s[i] >= 0 && (s[fa[i]] == -1 || s[fa[i]] >= s[i]))
            s[fa[i]] = s[i];
    }

    ll ans = 0;
    for (int i = n; i >= 1; i--) {
        if (s[i] != -1) {
            if (s[fa[i]] > s[i]) {
                cout << "-1\n";
                return 0;
            }
            ans += s[i] - s[fa[i]];
        }
    }
    cout << ans + s[0] << "\n";
    return 0;
}
