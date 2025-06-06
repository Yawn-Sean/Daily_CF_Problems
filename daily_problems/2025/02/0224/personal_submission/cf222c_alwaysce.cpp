#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    /*
        1. 预处理整除最小的因子
    */
    int mx = 1e7;
    vector<int> prime_factor(mx + 1);
    iota(prime_factor.begin(), prime_factor.end(), 0);
    for (int i = 2; i <= mx; i++) {
        if (prime_factor[i] == i) {
            for (int j = i; j <= mx; j += i) {
                prime_factor[j] = i;
            }
        }
    }
    
    int n, m;
    cin >> n >> m;
    vector<i64> a(n), b(m);
    for (auto&x: a) { cin >> x; }
    for (auto&y: b) { cin >> y; }

    vector<int> cnt1(mx + 1), cnt2(mx + 1);
    for (int i = 0; i < n; i++) {
        int x = a[i];
        while (x > 1) {
            cnt1[prime_factor[x]]++;
            x /= prime_factor[x];
        }
    }
    for (int i = 0; i < m; i++) {
        int y = b[i];
        while (y > 1) {
            cnt2[prime_factor[y]]++;
            y /= prime_factor[y];
        }   
    }

    // 约分部分
    for (int i = 1; i <= mx; i++) {
        cnt1[i] = min(cnt1[i], cnt2[i]);
        cnt2[i] = cnt1[i];
    }

    for (int i = 0; i < n; i++) {
        int x = a[i];
        while (x > 1) {
            if (cnt1[prime_factor[x]]) {
                cnt1[prime_factor[x]]--;
                a[i] /= prime_factor[x]; // 根据次数约分
            }
            x /= prime_factor[x];
        }
    }
    for (int i = 0; i < m; i++) {
        int y = b[i];
        while (y > 1) {
            if (cnt2[prime_factor[y]]) {
                cnt2[prime_factor[y]]--;
                b[i] /= prime_factor[y];
            }
            y /= prime_factor[y];
        }
    }

    cout << n << ' ' << m << '\n';
    for (auto&v: a) { cout << v << ' '; }
    cout << '\n';
    for (auto&v: b) { cout << v << ' '; }
    return 0;
}
