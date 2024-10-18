int n, a, b, k;
string s;

void solve() {
    cin >> n >> a >> b >> k;
    cin >> s;
    vector<int> pos;
    int cnt = 0;
    for (int i = 0; i < n; i ++) {
        if (s[i] == '1') {
            cnt = 0;
            continue;
        }
        cnt ++;
        if (cnt == b) {
            pos.push_back(i + 1);
            cnt = 0;
        }
    }
    cout << (sz(pos) - a + 1) << endl;
    for (int i = a - 1; i < sz(pos); i ++) {
        cout << pos[i] << ' ';
    }
    cout << endl;
}