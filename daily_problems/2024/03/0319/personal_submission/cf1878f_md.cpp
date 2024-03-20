#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

std::vector<int> minp, primes; 
constexpr int V = 1E6;

void sieve(int n) {
    minp.assign(n + 1, 0);
    primes.clear();
    
    for (int i = 2; i <= n; i++) {
        if (minp[i] == 0) {
            minp[i] = i;
            primes.push_back(i);
        }
        
        for (auto p : primes) {
            if (i * p > n) {
                break;
            }
            minp[i * p] = p;
            if (p == minp[i]) {
                break;
            }
        }
    }
}

void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> cnt(V + 1);

    int d = 1;
    auto add = [&](int num) {
        while (num > 1) {
            int p = minp[num];
            num /= p;
            d /= (cnt[p] + 1);
            cnt[p]++;
            d *= (cnt[p] + 1);
        }
    };

    auto remove = [&](int num) {
        while (num > 1) {
            int p = minp[num];
            num /= p;
            d /= (cnt[p] + 1);
            cnt[p]--;
            d *= (cnt[p] + 1);
        }
    };

    add(n);
    vector<int> nums{n};

    while (q--) {
        int k;
        cin >> k;
        if (k == 1) {
            int num;
            cin >> num;
            nums.push_back(num);
            add(num);

            long long val = 1;
            for (auto num : nums) {
                val = val * num % d;
            }
            cout << ((val == 0) ? "YES\n" : "NO\n");
        } else {
            while (size(nums) > 1) {
                remove(nums.back());
                nums.pop_back();
            }
        }
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve(V);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}