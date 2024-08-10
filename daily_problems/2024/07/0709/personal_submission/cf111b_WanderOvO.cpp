int T;  
int n;
map<int, int> last_factor_pos;

vector<int> get_factors(int val) {
    vector<int> res;
    int root = sqrt(val);
    for (int i = 1; i <= root; i++) {
        if (val % i == 0) {
            res.pb(i);
            if (val / i != i) {
                res.pb(val / i);
            }
        }
    }
    return res;
}

void solve1() {
    cin >> n;
    for (int rd = 1; rd <= n; rd++) {
        int x, y;
        cin >> x >> y;
        vector<int> factors = get_factors(x);
        int res = 0;
        for (auto factor : factors) {
            if (!last_factor_pos.count(factor)) {
                res++;
            } else if (last_factor_pos[factor] < rd - y) {
                res++;
            }
            last_factor_pos[factor] = rd;
        }
        cout << res << "\n";
    }
}