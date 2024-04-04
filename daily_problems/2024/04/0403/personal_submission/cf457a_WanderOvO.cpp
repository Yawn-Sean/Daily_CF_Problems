/*
先把前导 0 去掉
然后从低位到高位，每遇到两个相邻的 1，就把这两个消掉，进到下一位去
由于这个东西也不是二进制数，所以从高位到低位贪心比较可能是错的

羊：遇到高位，把它拆成两个低位，最后就化成了 kq + b 的形式了
如果不能贪心比大小，那就做差比大小
*/

string s, t;
int a[N], b[N], c[N];

void solve1() {
    cin >> s >> t;
    int n = s.size(), m = t.size();
    reverse(s.begin(), s.end());
    reverse(t.begin(), t.end());
    for (int i = 0; i < n; i++) {
        a[i] = s[i] - '0';
    }
    for (int i = 0; i < m; i++) {
        b[i] = t[i] - '0';
    }
    
    int mx = max(n, m);
    for (int i = 0; i < mx; i++) {
        c[i] = a[i] - b[i];
    }
    for (int i = mx - 1; i >= 0; i--) {
        if (i - 2 < 0) {
            continue;
        }
        if (c[i] >= 2) {
            cout << ">\n";
            return;
        } else if (c[i] <= -2) {
            cout << "<\n";
            return;
        }
        if (c[i] == 1) {
            c[i - 1]++;
            c[i - 2]++;
            c[i]--;
        } else if (c[i] == -1) {
            c[i - 1]--;
            c[i - 2]--;
            c[i]++;
        }
    }
    if (mx == 1) {
        if (c[0] > 0) {
            cout << ">\n";
        } else if (c[0] == 0) {
            cout << "=\n";
        } else {
            cout << "<\n";
        }
    } else {
        if (c[0] == 0 && c[1] == 0) {
            cout << "=\n";
            return;
        }
        double res = c[1] * pow((sqrt(5) + 1) / 2, 2) + c[0];
        if (res > 0) {
            cout << ">\n";
        } else {
            cout << "<\n";
        }
    }
}         