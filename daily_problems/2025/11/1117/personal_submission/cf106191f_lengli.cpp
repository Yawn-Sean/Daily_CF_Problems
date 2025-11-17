#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Fenwick {
    int n;
    vector<ll> bit; // 1-indexed internally
    Fenwick() : n(0) {}
    Fenwick(int n_): n(n_), bit(n_+1, 0) {}
    void add(int idx, ll val){ // idx: 0-based position
        int i = idx + 1;
        while(i <= n){ bit[i] += val; i += i & -i; }
    }
    // sum of first k elements (i.e. indices [0, k-1])
    ll sum_prefix(int k){
        ll res = 0;
        int i = k;
        while(i > 0){ res += bit[i]; i -= i & -i; }
        return res;
    }
    // sum on [l, r) 0-based
    ll range_sum(int l, int r){
        return sum_prefix(r) - sum_prefix(l);
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if(!(cin >> n)) return 0;
    vector<ll> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];

    // map from prefix-sum value -> vector of all neg values that appear at that prefix
    unordered_map<ll, vector<int>> d;
    d.reserve(n * 2);

    // choose a random 30-bit origin to avoid collisions with zero-only problems
    random_device rd;
    mt19937_64 rng(rd());
    ll orig = (ll)(rng() & ((1ULL<<30) - 1));

    ll cur = orig;
    int neg = 0;
    d[cur].push_back(0);

    for (int i = 0; i < n; ++i){
        cur += nums[i];
        if (nums[i] < 0) ++neg;
        else --neg;
        d[cur].push_back(neg);
    }

    // sort each bucket
    for (auto &p : d){
        auto &vec = p.second;
        sort(vec.begin(), vec.end());
    }

    // create Fenwick trees of the right sizes
    unordered_map<ll, Fenwick> fens;
    fens.reserve(d.size()*2);
    for (auto &p : d){
        int sz = (int)p.second.size();
        fens.emplace(p.first, Fenwick(sz));
    }

    ll ans = 0;
    cur = orig;
    neg = 0;

    // initial occurrence
    {
        auto &vec = d[cur];
        int pos = int(lower_bound(vec.begin(), vec.end(), neg) - vec.begin());
        fens[cur].add(pos, 1);
    }

    for (int i = 0; i < n; ++i){
        cur += nums[i];
        if (nums[i] < 0) ++neg;
        else --neg;

        auto &vec = d[cur];
        int addPos = int(lower_bound(vec.begin(), vec.end(), neg) - vec.begin());
        int countLE = int(upper_bound(vec.begin(), vec.end(), neg) - vec.begin());
        // count how many previous occurrences have value <= neg
        ans += fens[cur].sum_prefix(countLE);
        // insert current occurrence at the lower_bound position
        fens[cur].add(addPos, 1);
    }

    cout << ans << '\n';
    return 0;
}
