#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;
std::map<i64, int> S;
void solve() {
    int n;
    std::cin >> n;
    std::vector<i64> a(n + 1);
    for(int i = 1; i <= n; i++) std::cin >> a[i];
    for(int i = 1; i <= n; i++) {
        S[a[i]]++;
    }
    

    i64 ans = count(a.begin() + 1, a.end(), 0);
    if(ans < 2) ans = 2;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(j == i || a[i] == 0 && a[j] == 0) continue;
            i64 x1 = a[i], x2 = a[j], x3;
            // S.erase(S.find(x1)), S.erase(S.find(x2));
            S[x1]--, S[x2]--;
            std::vector<i64> tmp;
            tmp.reserve(100);
            tmp.push_back(x1);
            tmp.push_back(x2);
            for(int k = 3; k <= 1000; k++) {
                x3 = x1 + x2;
                if(S[x3] != 0) {
                    S[x3]--;
                    tmp.push_back(x3);
                    x1 = x2, x2 = x3;
                    if(ans < k) ans = k;
                    continue;
                } else {
                    break;
                }
            }
            for(auto x : tmp) {
                S[x]++;
            }
        }
    }

    std::cout << ans << "\n";
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t = 1;  
    while (t--)
        solve();
    return 0;
}
