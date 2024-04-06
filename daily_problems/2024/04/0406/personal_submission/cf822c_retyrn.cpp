const int inf = INT_MAX;
int n, m;
using ai3 = array<int, 3>;

void solve() {
    cin >> n >> m;
    map<int, vector<ai3>> mp;
    for (int i = 0; i < n; i ++) {
        int l, r, w;
        cin >> l >> r >> w;
        mp[r - l + 1].push_back({l, r, w});
    }
    for (auto& [k, v] : mp) {
        sort(all(v));
    }
    
    int res = inf;
    for (auto& [k, v] : mp) {
        if (!mp.count(m - k)) continue;
        auto& vec = mp[m - k];
        multiset<int> S;
        int left = 0, right = sz(vec) - 1;
        while (left < sz(vec) and vec[left][1] < v[0][0]) {
            S.insert(vec[left][2]);
            left ++;
        }
        while (right >= 0 and vec[right][0] > v[0][1]) {
            S.insert(vec[right][2]);
            right --;
        }
        right += 1;
        
        if (sz(S)) res = min(res, *S.begin() + v[0][2]);
        
        for (int i = 1; i < sz(v); i ++) {
            while (left < sz(vec) and vec[left][1] < v[i][0]) {
                S.insert(vec[left][2]);
                left ++;
            }
            while (right < sz(vec) and vec[right][0] <= v[i][1]) {
                S.erase(S.find(vec[right][2]));
                right ++;
            }
            if (sz(S)) res = min(res, *S.begin() + v[i][2]);
        }
    }
    
    cout << (res == inf ? -1 : res) << endl;
}