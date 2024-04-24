int n;  
string s;
map<int, int> c;

void solve1() {
    cin >> n;
    LL res = 0;
    for (int i = 1; i <= n; i++) {
        cin >> s;
        int cnt = 0;
        for (int j = 0; j < s.size(); j++) {
            int val = s[j] - 'a';
            cnt ^= (1 << val);
        }
        res += c[cnt];
        for (int j = 0; j < 26; j++) {
            if ((cnt >> j) & 1) {
                res += c[cnt & (~(1 << j))];
            } else {
                res += c[cnt | (1 << j)];
            }
        }
        c[cnt]++;
    }
    cout << res << "\n";
}         