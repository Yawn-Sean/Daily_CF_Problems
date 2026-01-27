int costs[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

void solve() {
    int n;
    cin >> n;

    int maxl = (n + 6) / 7;
    string res = "";

    for (int i = 0; i < maxl; ++i) {
        for (int d = 0; d <= 9; ++d) {
            if (i == 0 && d == 0 && maxl > 1) continue;

            int left = n - costs[d];
            int len = maxl - 1 - i;

            if (left >= 2 * len && left <= 7 * len) {
                res += (char)('0' + d);
                n = left;
                break;
            }
        }
    }
    cout << res << endl;
}
