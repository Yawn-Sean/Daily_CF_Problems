
void solve() {
    int n;
    cin >> n;
    // 必选a的第一个不同，再必选b的第一个不同，看其他部分能不能一致
    auto check = [n](string& a, string& b) {
        int i = 0, j = 0;
        int fa = 0, fb = 0;
        while (i < n and j < n) {
            if (a[i] == b[j]) {
                ++i, ++j;
                continue;
            } else if (!fa) {
                fa = 1;
                i += 1;
            } else if (!fb) {
                fb = 1;
                j += 1;
            } else break;
        }
        if (i < n and j < n) return false;
        return true;
    };
    string s1, s2;
    cin >> s1 >> s2;
    cout << (int)check(s1, s2) + (int)check(s2, s1);
}
