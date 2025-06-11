void solve() {
    string s, c;
    cin >> s >> c;
    int n = s.size(), m = c.size();
    int i = 0, j = 0;
    for (; i < n && j < m; ) {
        if (s[i] == c[j]) {
            for (int k = i + 1; k < n; k++) {
                if (s[k] < c[j]) {
                    swap(s[i], s[k]);
                    cout << s << endl;
                    return;
                }
            }
            i++, j++;
            continue;
        } else if (s[i] < c[j]) {
            cout << s << endl;
            return;
        } else {
            int k = i + 1, id = -1;
            while (k < n) {
                if (s[k] == c[j]) {
                    id = k;
                } else if (s[k] < c[j]) {
                    swap(s[k], s[i]);
                    cout << s << endl;
                    return;
                }
                k++;
            }
            if (id == -1) {
                cout << "---" << endl;
                return;
            }
            swap(s[i], s[id]);
            break;
        }
    }
    if (s < c) {
        cout << s << endl;
    } else {
        cout << "---" << endl;
    }
}