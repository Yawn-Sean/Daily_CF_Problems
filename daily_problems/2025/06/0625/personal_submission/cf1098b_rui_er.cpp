const string ch = "AGCT";
inline int id(char c) {return find(ch.begin(), ch.end(), c) - ch.begin();}

int n, m;
vector<vector<int>> vec, ans;

inline int diff(const vector<vector<int>>& a, const vector<vector<int>>& b) {
    int cnt = 0;
    rep(i, 0, n - 1) rep(j, 0, m - 1) if(a[i][j] != b[i][j]) ++cnt;
    return cnt;
}

inline int diffr(const vector<vector<int>>& a, const vector<vector<int>>& b, int r) {
    int cnt = 0;
    rep(j, 0, m - 1) if(a[r][j] != b[r][j]) ++cnt;
    return cnt;
}

inline int diffc(const vector<vector<int>>& a, const vector<vector<int>>& b, int c) {
    int cnt = 0;
    rep(i, 0, n - 1) if(a[i][c] != b[i][c]) ++cnt;
    return cnt;
}

inline void update(const vector<vector<int>>& now) {
    if(ans.empty() || diff(vec, now) < diff(vec, ans)) ans = now;
}

inline void getr(int a, int b) {
    vector<vector<int>> tmp{{a, b}, {}};
    rep(i, 0, 3) if(i != a && i != b) tmp[1].push_back(i);
    vector<vector<int>> now(n, vector<int>(m));
    rep(i, 0, n - 1) {
        vector<int> val(2);
        rep(k, 0, 1) {
            rep(j, 0, m - 1) {
                now[i][j] = tmp[i & 1][(j + k) & 1];
            }
            val[k] = diffr(vec, now, i);
        }
        int k = val[0] < val[1] ? 0 : 1;
        rep(j, 0, m - 1) now[i][j] = tmp[i & 1][(j + k) & 1]; 
    }
    update(now);
}

inline void getc(int a, int b) {
    vector<vector<int>> tmp{{a, b}, {}};
    rep(i, 0, 3) if(i != a && i != b) tmp[1].push_back(i);
    swap(tmp[0][1], tmp[1][0]);
    vector<vector<int>> now(n, vector<int>(m));
    rep(j, 0, m - 1) {
        vector<int> val(2);
        rep(k, 0, 1) {
            rep(i, 0, n - 1) {
                now[i][j] = tmp[(i + k) & 1][j & 1];
            }
            val[k] = diffc(vec, now, j);
        }
        int k = val[0] < val[1] ? 0 : 1;
        rep(i, 0, n - 1) now[i][j] = tmp[(i + k) & 1][j & 1]; 
    }
    update(now);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    vec.resize(n, vector<int>(m));
    rep(i, 0, n - 1) {
        string s;
        cin >> s;
        rep(j, 0, m - 1) vec[i][j] = id(s[j]);
    }
    rep(a, 0, 3) {
        rep(b, a + 1, 3) {
            getr(a, b);
            getc(a, b);
        }
    }
    rep(i, 0, n - 1) {
        rep(j, 0, m - 1) cout << ch[ans[i][j]];
        cout << endl;
    }
    return 0;
}
