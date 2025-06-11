int T;
int n;
string s, t;

void solve1() {
    cin >> n >> s >> t;
    bool ok = true;
    vector<PII> res;
    for (int i = 0; i < n; i++) {
        if (s[i] != t[i]) {
            bool equal = false;
            for (int j = i + 1; j < n; j++) {
                if (s[i] == s[j]) {
                    swap(s[j], t[i]);
                    res.pb({j + 1, i + 1});
                    equal = true;
                    break;
                }
            }
            if (!equal) {
                for (int j = i + 1; j < n; j++) {
                    if (s[i] == t[j]) {
                        swap(s[n - 1], t[j]);
                        swap(s[n - 1], t[i]);
                        res.pb({n, j + 1});
                        res.pb({n, i + 1});
                        equal = true;
                        break;
                    }
                }
            }
            if (!equal) {
                ok = false;
                break;
            }
        }
    }
    if (ok) {
        assert(s == t);
        cout << "Yes\n";
        cout << res.size() << "\n";
        for (auto &pii : res) {
            cout << pii.x << " " << pii.y << "\n";
        }
    } else {
        cout << "No\n";
    }
}        