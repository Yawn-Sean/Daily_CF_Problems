int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);

    int n, a, b, k; cin >> n >> a >> b >> k;
    string s; cin >> s;
    int cand = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') continue;
        int j = i, cnt = 0;
        while (j < n && s[j] == '0') {
            ++j;
            ++cnt;
        }
        cand += cnt / b;
        i = j;
    }

    vector<int> ans;
    int cur = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            cur = 0;
            continue;
        }
        if (++cur == b) {
            cur = 0;
            ans.emplace_back(i + 1);
            cand -= 1;
            if (cand < a) break;
        }
    }

    cout << sz(ans) << '\n';
    for (int a : ans) cout << a << ' ';
    cout << '\n';

    return 0;
}
