#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Fenwick {
    int n;
    vector<ll> bit;

    Fenwick(int n) : n(n), bit(n + 1, 0) {}

    void add(int idx, ll val) {
        for (++idx; idx <= n; idx += idx & -idx)
            bit[idx] += val;
    }

    ll sum(int idx) const { // sum [0, idx]
        ll s = 0;
        for (++idx; idx > 0; idx -= idx & -idx)
            s += bit[idx];
        return s;
    }

    ll rsum(int l, int r) const { // sum [l, r]
        if (l > r) return 0;
        return sum(r) - (l ? sum(l - 1) : 0);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<ll> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    vector<ll> acc(n + 1, 0);
    for (int i = 0; i < n; i++)
        acc[i + 1] = acc[i] + nums[i];

    Fenwick fen_k(n + 1), fen_b(n + 1);

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i < n; i++) {
        if (acc[i] <= nums[i])
            pq.push(i);
    }

    vector<ll> outs;
    outs.reserve(q);

    while (q--) {
        int l, r;
        ll x;
        cin >> l >> r >> x;
        l--;  

        fen_k.add(l, x);
        fen_b.add(l, -(ll)(l - 1) * x);

        fen_k.add(r, -x);
        fen_b.add(r, (ll)(r - 1) * x);

        if (l > 0)
            pq.push(l);

        while (!pq.empty()) {
            int u = pq.top();

            ll left_val =
                acc[u]
                + fen_k.rsum(0, u - 1) * (u - 1)
                + fen_b.rsum(0, u - 1);

            ll right_val =
                nums[u]
                + fen_k.rsum(0, u);

            if (left_val <= right_val)
                break;

            pq.pop();
        }

        outs.push_back(pq.empty() ? -1 : pq.top() + 1);
    }

    for (ll x : outs)
        cout << x << '\n';

    return 0;
}
