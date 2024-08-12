/*
标记每个数 x 的左边第一个不等于 x 的位置
假设询问 [l, r]，如果 a[r] != x，则问题已经解决
如果 a[r] = x，则 r = pos[r]，看是否 >= l
*/

int T;
int n, m, a[N], pos[N];

void solve1() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (i >= 2) {
            pos[i] = (a[i] == a[i - 1]) ? pos[i - 1] : (i - 1);
        }
    }
    while (m--) {
        int l, r, x;
        cin >> l >> r >> x;
        if (a[r] != x) {
            cout << r << "\n";
        } else {
            r = pos[r];
            if (r >= l) {
                cout << r << "\n";
            } else {
                cout << "-1\n";
            }
        }
    }
}    