#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, b, ans = 1e18;
    cin >> n >> b;
    long long MXN = sqrt(b);
    vector<int> primes, isp(MXN+1, 1), cnt;
    vector<long long> nums;
    for (int i = 2; i <= MXN; i++) {
        if (isp[i]) primes.push_back(i);
        for (int x : primes) {
            if (1LL * i * x > MXN) break;
            isp[i*x] = 0;
            if (i % x == 0) break;
        }
    }
    for (int x : primes) {
        if (b % x == 0) {
            int c = 0;
            while (b % x == 0) {
                b /= x;
                c++;
            }
            nums.push_back(x);
            cnt.push_back(c);
        }
    }
    if (b > 1) {
        nums.push_back(b);
        cnt.push_back(1);
    }
    int m = nums.size();
    vector<long long> cnt2(m, 0);
    for (int i = 0; i < m; i++) {
        long long x = n;
        while (x) {
            cnt2[i] += x / nums[i];
            x /= nums[i];
        }
    }
    for (int i = 0; i < m; i++) {
        ans = min(ans, cnt2[i] / cnt[i]);
    }
    cout << ans << endl;

    return 0;
}
