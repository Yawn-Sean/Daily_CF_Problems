// https://codeforces.com/contest/1615/submission/265822758
int a[MAXN], b[MAXN];
string s1, s2;
void sol()
{
    cin >> n >> s1 >> s2;
    int cnta, cntb;
    cnta = 0, cntb = 0;
    for (int i = 1; i <= n; i++) {
        a[i] = s1[i - 1] - '0';
        if (a[i] == 1) 
            cnta++;
    }
    bool down = true;
    vector<int> one, zero, sone, szero;
    for (int i = 1; i <= n; i++) {
        b[i] = s2[i - 1] - '0';
        if (b[i] == 1) cntb++;
        if (b[i] != a[i]) {
            down = false;
            if (a[i] == 1) one.push_back(i);
            else zero.push_back(i);
        } else {
            if (a[i] == 1) sone.push_back(i);
            else szero.push_back(i);
        }
    }
    if (down) {
        cout << 0 << '\n';
        return ;
    }
    if (cnta == 0) {
        cout << -1 << '\n';
    } else if (cnta == n) {
        if (cntb == 1) {
            cout << 1 << '\n';
        } else {
            cout << -1 << '\n';
        }
    } else {
        int cnte = INF, cnto = INF;
        if (cntb == cnta) {
            cnte = 2 * one.size();
        } 
        if (cntb == n - cnta + 1) {
            cnto = 1;
            int idx1 = 1, idx0 = 0;
            int siz1 = sone.size(), siz0 = szero.size();
            while (idx1 < siz1 && idx0 < siz0) {
                cnto += 2;
                idx1++, idx0++;
            }
            if (idx1 < siz1) {
                cnto += 2 * (siz1 - idx1);
            }
            if (idx0 < siz0) {
                cnto += 2 * (siz0 - idx0);
            }
        }
        int res = min(cnte, cnto);
        cout << (res == INF ? -1 : res) <<'\n';
    }
}
