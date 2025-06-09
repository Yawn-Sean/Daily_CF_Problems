#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n, x;
    cin >> n >> x;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    /*
        其实求的是 最多能凑出多少对和不低于x
    */
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int ans = 0, pt = 0;
    for (int j = n - 1; j >= 0; j--) {
        while (pt < n && a[j] + b[pt] < x) {
            pt++;
        }
        if (pt < n && a[j] + b[pt] >= x) {
            ans += 1; // 找到一个
        }
        pt += 1;
    }
    cout << 1 << " " << ans << endl;
    return 0;
}
