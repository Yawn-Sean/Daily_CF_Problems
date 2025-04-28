#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    /*
        给定x2
        首先可以判断哪些x1是可能的
        x1 = [x2-maxp(x2)+1, ...x2]
        然后对于每个x1，找x0最小
    */
    int x2;
    cin >> x2;

    int mx = 1e6;
    vector<int> prime_factor(mx + 1);
    iota(prime_factor.begin(), prime_factor.end(), 0);
    for (int i = 2; i <= mx; i++) {
        if (prime_factor[i] == i) {
            for (int j = i; j <= mx; j += i) {
                prime_factor[j] = i;
            }
        }
    }
    int ans = x2;
    for (int x1 = x2 - prime_factor[x2] + 1; x1 <= x2; x1++) {
        if (prime_factor[x1] != x1) {
            ans = min(ans, x1 - prime_factor[x1] + 1);
        }
    }
    cout << ans;
    return 0;
}
