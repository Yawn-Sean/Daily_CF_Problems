// core part
void solve() {
    read(int, n);
    readvec(ll, a, n);
    int sz = INF;
    vector<ll> res;
    for (int i = 0; i < 61; ++i) {
        ll pw = 1LL << i;
        vector<ll> curr;
        for (auto&& x : a) if (!(x % pw == 0 && ((x / pw) % 2))) curr.push_back(x);
        if (curr.size() < sz) {
            sz = curr.size();
            res = curr;
        }
    }
    cout << sz << '\n';
    putvec(res);
}

