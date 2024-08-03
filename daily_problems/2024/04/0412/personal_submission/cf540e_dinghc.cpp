// Submission link: https://codeforces.com/contest/540/submission/256389937

int main() {
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 0, a, b; i < n; i++) {
        cin >> a >> b;
        auto it1 = mp.find(a);
        auto it2 = mp.find(b);
        int v1 = it1 == mp.end() ? a : it1->second;
        int v2 = it2 == mp.end() ? b : it2->second;
        if (it2 != mp.end()) {
            it2->second = v1;
        } else {
            mp.insert({b, v1});
        }
        if (it1 != mp.end()) {
            it1->second = v2;
        } else {
            mp.insert({a, v2});
        }
    }

    vector<pair<int, int>> a;
    for (auto it = mp.begin(); it != mp.end(); it++) {
        auto& [pos1, val1] = *it;
        a.emplace_back(val1, 1);
        auto it_nxt = it;
        if (++it_nxt != mp.end()) {
            auto& [pos2, val2] = *it_nxt;
            if (pos2 - pos1 > 1) {
                a.emplace_back((pos1 + pos2) / 2, pos2 - pos1 - 1);
            }
        }
    }
    
    vector<pair<int, int>> b = a;
    ranges::sort(b);

    fenwick_tree fw(b.size());
    long long ans = 0LL;
    for (auto& [x, k] : a) {
        int idx = ranges::lower_bound(b, pair<int, int> {x, 0}) - b.begin();
        ans += fw.gt(idx) * k;
        fw.add(idx, k);
    }
    
    cout << ans << "\n";

    return 0;
}

