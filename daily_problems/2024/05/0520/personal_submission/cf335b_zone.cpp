/*
url: 
    question:   https://codeforces.com/problemset/problem/335/B
    submission: https://codeforces.com/contest/335/submission/261769725
time: 124 ms
*/

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    unordered_map<char, int> cnt;
    for (auto x: s) cnt[x] ++;
    for (char i = 'a'; i <= 'z'; i ++ ) {
        if (cnt[i] >= 100) {
            for (int j = 0; j < 100; j ++ ) cout << i;
            cout << endl;
            return;
        }
    }
    // O(n ^ 2)
    vector<vector<int>> st(n, vector<int>(n));
    for (int i = 0; i < n; i ++ ) st[i][i] = 1;
    for (int i = n - 1; i >= 0; i --) {
        for (int j = i + 1; j < n; j ++ ) {
            if (s[i] == s[j]) st[i][j] = st[i + 1][j - 1] + 2;
            else st[i][j] = max(st[i + 1][j], st[i][j - 1]);
        }
    }
    string pre = "", rear = "";
    auto dfs = [&](auto &&self, int i, int j) -> void {
        if (i >= j) {
            if (i == j) pre += s[i];
            return;
        }
        int res = st[i][j];
        if (s[i] == s[j] && st[i + 1][j - 1] + 2 == res) {
            pre += s[i];
            self(self, i + 1, j - 1);
            rear += s[j];
        } else if (st[i + 1][j] == res) {
            self(self, i + 1, j);
        } else if (st[i][j - 1] == res) {
            self(self, i, j - 1);
        }
    };
    dfs(dfs, 0, n - 1);
    string ans = pre + rear;
    if (ans.size() > 100) ans = ans.substr(0, 50) + ans.substr(ans.size() - 50, 50);
    cout << ans << endl;
}

int main() {   
    std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
    solve();
    return 0;
}
