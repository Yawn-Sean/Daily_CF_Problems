int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    int n = s.size();
    rep(i, 0, n - 1) {
        string t = s.substr(i + 1, n - i - 1) + s.substr(0, i + 1);
        if (ispal(t) && s != t) {
            cout << 1 << "\n";
            return 0;
        }
    }
    rep(i, 0, n / 2 - 1) if (s[i] != s[i + 1]) {
        cout << 2 << "\n";
        return 0;
    }
    cout << "Impossible\n";
}
