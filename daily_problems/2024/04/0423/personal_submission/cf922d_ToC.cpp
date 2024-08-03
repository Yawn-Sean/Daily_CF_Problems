// https://codeforces.com/contest/922/submission/257851852
string seq[MAXN];
// 优化：避免除法，避免浮点数
struct SC {
    int sc; 
    int hc;
    int id;
} shcount[MAXN];
bool cmp(SC &s1, SC &s2) {
    return (LL)s2.sc * s1.hc < (LL)s1.sc * s2.hc;
}
void sol()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> seq[i];
        int t = 0;
        for (auto &c : seq[i])
            if (c == 's') 
                t++;
        shcount[i].sc = t;
        shcount[i].hc = seq[i].size() - t;
        shcount[i].id = i;
    }
    sort(shcount + 1, shcount + n + 1, cmp);

    LL res = 0, sc = 0;
    for (int i = 1; i <= n; i++) {
        for (auto &c : seq[shcount[i].id])
            if (c == 's') sc++;
            else res += sc;
    }
    cout << res << '\n';
}
