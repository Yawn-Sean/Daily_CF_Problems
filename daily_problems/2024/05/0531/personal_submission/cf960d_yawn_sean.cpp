#include <bits/stdc++.h>
using namespace std;

struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int q;
    cin >> q;

    vector<long long> shift(60);

    while (q --) {
        int op;
        cin >> op;

        if (op == 1) {
            long long x, k;
            cin >> x >> k;
            int idx = 63 -  __builtin_clzll(x);
            shift[idx] += k;
            if (shift[idx] < 0) shift[idx] += 1ll << idx;
            shift[idx] &= (1ll << idx) - 1;
        }
        else if (op == 2) {
            long long x, k;
            cin >> x >> k;
            int idx = 63 -  __builtin_clzll(x);
            for (int i = idx; i < 60; i ++) {
                shift[i] += k;
                if (shift[i] < 0) shift[i] += 1ll << i;
                shift[i] &= (1ll << i) - 1;
                k &= (1ll << i) - 1;
                k *= 2;
            }
        }
        else {
            long long x;
            cin >> x;
            int idx = 63 - __builtin_clzll(x);
            long long pos = (1ll << idx) + ((x - (1ll << idx) + shift[idx]) & ((1ll << idx) - 1));
            for (int i = idx; i >= 0; i --) {
                cout << (1ll << i) + ((pos + (1ll << i) - shift[i]) & ((1ll << i) - 1)) << ' ';
                pos >>= 1;
            }
            cout << '\n';
        }
    }

    return 0;
}