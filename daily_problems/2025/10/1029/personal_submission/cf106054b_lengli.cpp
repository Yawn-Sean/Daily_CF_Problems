#include <bits/stdc++.h>
using namespace std;

int fastPow(int base, int exp, int mod) {
    int result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) {
            result = 1LL * result * base % mod;
        }
        base = 1LL * base * base % mod;
        exp >>= 1;
    }
    return result;
}
int combination(int n, int k, int mod) {
    int numerator = 1;  
    int denominator = 1; 
    
    for (int i = 0; i < k; i++) {
        numerator = 1LL * numerator * (n - i) % mod;
        denominator = 1LL * denominator * (i + 1) % mod;
    }
    
    return 1LL * numerator * fastPow(denominator, mod - 2, mod) % mod;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    const int MOD = 998244353;
    int n, k;
    cin >> n >> k;
    
    vector<int> blocks(n - k + 1);
    for (auto &x : blocks) {
        cin >> x;
    }

    vector<int> differences(n, 0);
    for (int i = k; i < n; i++) {
        differences[i] = differences[i - k] + blocks[i - k + 1] - blocks[i - k];
    }

    long long addition = 0;
    for (int i = 0; i < k; i++) {
        int minValue = 0;
        for (int j = i; j < n; j += k) {
            minValue = min(minValue, differences[j]);
        }
        addition -= minValue;
    }
    
    if (addition > blocks[0]) {
        cout << 0;
    } else {
        int total = blocks[0] - addition;
        cout << combination(total + k - 1, k - 1, MOD);
    }
    
    return 0;
}
