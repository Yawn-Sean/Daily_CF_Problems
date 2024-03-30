/*
  https://codeforces.com/contest/1045/submission/253879501
*/
int n, t;
int sa[26];
int all[N];

void sol()
{
    cin >> n;
    string s;
    unordered_map<int, int> m2c;
    for (int i = 0; i < n; i++) {
        cin >> s;
        memset(sa, 0, sizeof(sa));
        for (auto &e : s)
            sa[e - 'a'] ^= 1;
        int mask = 0;
        for (int j = 0; j < 26; j++)
            if (sa[j])
                mask |= (1 << j);
        all[i] = mask;
        m2c[mask]++;
    }
    LL res = 0;
    for (int i = 0; i < n; i++) {
        int mask = all[i];
        for (int j = 0; j < 26; j++) {
            res += m2c[mask ^ (1 << j)];
        }
        res += m2c[mask] - 1;
    }
    cout << res / 2 << '\n';
}
