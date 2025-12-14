#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

vector<long long> inv(1000010);
vector<long long> res(1000010);

void solve() {
    int n;
    cin >> n;

    cout << res[n] << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T = 1;
    cin >> T;

    inv[1] = 1;
    for (int i = 2; i < 1000010; ++i) {
        inv[i] = (long long)(MOD - MOD / i) * inv[MOD % i] % MOD;
    }
    
    long long ans = 1;
    res[1] = 1;
    res[2] = 1;
    for (int i = 2; i < 1000010; ++i) {
        if (i == 2) continue;

        long long num = i - 2;
        long long term = num * inv[i] % MOD * inv[i - 1] % MOD;

        ans = (ans + term) % MOD;
        res[i] = ans;
    }

    while (T--)
        solve();

    return 0;
}
