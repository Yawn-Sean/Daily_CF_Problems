#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int k, a;
        cin >> k >> a;
        ans = max(ans, k + 1);
        // 2^k+1能放4个2^k的盒子
        while (a > 1) {
            // ceil(a/4)
            a = (a + 3) / 4;
            k++;
        }
        ans = max(ans, k);
    }
    cout << ans << '\n';
    return 0;
}
