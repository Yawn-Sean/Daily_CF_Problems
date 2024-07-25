int main() {
    int n;
    cin >> n;
    vector<int> ne(26, -1), fr(26, -1), st(26, 0);
    for (int i = 1; i <= n; i ++) {
        string s;
        cin >> s;
        vector<int> cnt(26, 0);
        for (int j = 0; j < s.size(); j ++) {
            st[s[j] - 'a'] = true;
            if (cnt[s[j] - 'a']) {
                cout << "NO" << endl;
                return 0;
            }
            cnt[s[j] - 'a'] ++;
        }
        for (int j = 0; j < s.size(); j ++) {
            int now = s[j] - 'a';
            if (j - 1 >= 0 && ((fr[now] != -1 && (fr[now] != s[j - 1] - 'a')) || (ne[s[j - 1] - 'a'] != -1 && ne[s[j - 1] - 'a'] != now))) {
                cout << "NO" << endl;
                return 0;
            }
            if (j + 1 < s.size() && ((ne[now] != -1 && (ne[now] != s[j + 1] - 'a')) || (fr[s[j + 1] - 'a'] != -1 && fr[s[j + 1] - 'a'] != now))) {
                cout << "NO" << endl;
                return 0;
            }
            if (j + 1 < s.size()) {
                fr[s[j + 1] - 'a'] = now;
                ne[now] = s[j + 1] - 'a';
            }
            if (j - 1 >= 0) {
                fr[now] = s[j - 1] - 'a';
                ne[s[j - 1] - 'a'] = now;
            }
        }
    }
    string ans;
    for (int i = 0; i < 26; i ++) {
        if (st[i] && fr[i] == -1) {
            int now = i;
            while (now != -1) {
                ans.push_back(now + 'a');
                now = ne[now];
            }
        }
    }
    for (int i = 0; i < 26; i ++) {
        if (st[i] && ans.find(i + 'a') == -1) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << ans << endl;
    return 0;
}
