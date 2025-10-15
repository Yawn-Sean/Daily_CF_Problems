#include <bits/stdc++.h>

using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;

i64 t1 = 0;

void solve() {
    i64 n, m;
    std::cin >> n >> m;
    if(n > 823542 || m > 823542) {
        std::cout << 0 << "\n";
        return;
    }
    
    std::string s1, s2;
    --n, --m;
    if(n == 0) {
        s1 = "0";
    } else {
        int x = n;
        while(x) {
            s1 += '0';
            x /= 7;
        }
    }
    if(m == 0) {
        s2 = "0";
    } else {
        int x = m;
        while(x) {
            s2 += '0';
            x /= 7;
        }
    }
    if(s1.size() + s2.size() > 7) {
        std::cout << 0 << "\n";
        return;
    }
    i64 ans = 0;
    for(int i = 0; i <= n; i++) {
        for(int j= 0; j <= m; j++) {
            std::string s11 = s1, s22 = s2;
            i64 t1 = i;
            int k = 0;
            while(t1) {
                s11[k++] = t1 % 7 + '0';
                t1 /= 7; 
            }
            k = 0;
            t1 = j;
            while(t1) {
                s22[k++] = t1 % 7 + '0';
                t1 /= 7;
            }  
            bool ok = 1;
            for(int c = 0; c < 7; c++) {
                if(count(s11.begin(), s11.end(), c + '0') + count(s22.begin(), s22.end(), c + '0') >= 2 ) {
                    ok = 0;
                }
            }
            ans += ok;
        }
    }
    std::cout << ans << "\n";
}

void pre() {
    t1 = 6;
    for(int i = 1; i < 7; i++) {
        t1 = t1 * 7 + 6;
    }
    // std::cerr << t1 << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);

    pre();
    int t = 1;
    // std::cin >> t;
    while(t--)
        solve();
    return 0;
}
