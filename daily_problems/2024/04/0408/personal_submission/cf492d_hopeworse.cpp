// link : https://codeforces.com/contest/492/submission/255558916
void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> ans(x + y + 10);
    int cnt1 = 0, cnt2 = 0;
    for (int i = 1; i <= x + y; i++) {
        int t1 = (cnt1 + 1) * y;
        int t2 = (cnt2 + 1) * x;

        if (t1 < t2) {
            cnt1++;
            ans[i] = 1;
        } else if (t1 > t2) {
            cnt2++;
            ans[i] = 2;
        } else {
            i++;
            cnt1++;
            cnt2++;
        }
    }
    debug(ans);
    for (int i = 1; i <= n; i++) {
        int xx;
        cin >> xx;
        xx %= (x + y);
        debug(xx);
        if (ans[xx] == 1) {
            cout << "Vanya" << endl;
        } else if (ans[xx] == 2) {
            cout << "Vova" << endl;
        } else {
            cout << "Both" << endl;
        }
    }
}
