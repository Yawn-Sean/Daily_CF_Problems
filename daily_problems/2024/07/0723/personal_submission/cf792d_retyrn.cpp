int q;
ll n, x;
int layer;
using pli = pair<ll, int>;

void solve() {
    cin >> x;
    string s;
    cin >> s;
    
    vector<pli> stk = {mpr((n >> 1) + 1, 1)};
    while (stk.back().fi != x) {
        if (x < stk.back().fi) {
            // left
            ll nx = stk.back().fi - (1ll << (layer - stk.back().se - 1));
            stk.emplace_back(nx, stk.back().se + 1);
        }
        else {
            // right
            ll nx = stk.back().fi + (1ll << (layer - stk.back().se - 1));
            stk.emplace_back(nx, stk.back().se + 1);
        }
    }
    
    for (auto c : s) {
        if (c == 'U') {
            if (sz(stk) <= 1) continue;
            stk.pop_back();
        }
        else if (c == 'L') {
            if (stk.back().se == layer) continue;
            ll nx = stk.back().fi - (1ll << (layer - stk.back().se - 1));
            stk.emplace_back(nx, stk.back().se + 1);
        }
        else {
            if (stk.back().se == layer) continue;
            ll nx = stk.back().fi + (1ll << (layer - stk.back().se - 1));
            stk.emplace_back(nx, stk.back().se + 1);
        }
    }
    cout << stk.back().fi << endl;
}
int main() {
    FAST;
    int T;
    cin >> n >> T;
    layer = __builtin_popcountll(n);
    
    while (T --)
        solve();

    return 0;
}
