int n;

int ask(const string& s) {
    cout << "? " << s << endl;
    cout.flush();
    int x;
    cin >> x;
    return x;
}
void solve() {
    cin >> n;
    string s(n, '0');
    int one = ask(s);
    int l = 0, r = n - 1;
    vector<int> res(2, -1);
    
    while (res[0] == -1 or res[1] == -1) {
        auto mid = (l + r) >> 1;
        // 检查[l, mid] 有多少的0, 1
        for (int i = 0; i < n; i ++) {
            s[i] = '0' + (i >= l and i <= mid);
        }
        int diff = ask(s);
        // 区域内0比1多diff-one个 0+1 = mid-l+1 0-1 = diff-one
        int in_zero = (diff - one + mid - l + 1) / 2;
        int in_one = mid - l + 1 - in_zero;
        if (in_zero == 0) {
            res[1] = l;
            l = mid + 1;
        }
        else if (in_one == 0) {
            res[0] = l;
            l = mid + 1;
        }
        else {
            r = mid;
        }
    }
    cout << "! " << res[0] + 1 << " " << res[1] + 1 << endl;
    cout.flush();
}