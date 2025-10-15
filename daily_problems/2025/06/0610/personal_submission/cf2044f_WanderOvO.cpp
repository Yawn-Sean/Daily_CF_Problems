/*
总和是多少？(a[1] + ... + a[n]) * (b[1] + ... + b[m]) = sum
选择 r 行 c 列进行处理，和变成了多少？
target = sum - a[r] * (b[1] + ... + b[m]) - b[c] * (a[1] + ... + a[n]) + a[r] * b[c]
则 a[r] * (b[1] + ... + b[m]) + b[c] * (a[1] + ... + a[n]) - a[r] * b[c] = sum - target
事实上就是判断是否有一行一列的和加起来 = sum - target
sa * sb - target = a[r] * sb + b[c] * sa - a[r] * b[c]
sa * sb - a[r] * sb - b[c] * sa - a[r] * b[c] = target
(sa - a[r]) * (sb - b[c]) = target
 
*/
 
LL a[N], b[N], n, m, q;
 
void meibao() {
    cin >> n >> m >> q;
    LL sa = 0, sb = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sa += a[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
        sb += b[i];
    }
    set<LL> s1, s2;
    for (int i = 1; i <= n; i++) {
        s1.insert(sa - a[i]);
    }
    for (int i = 1; i <= m; i++) {
        s2.insert(sb - b[i]);
    }
 
    while (q--) {
        LL val;
        cin >> val;
        LL flag = (val >= 0 ? 1 : -1);
        val *= flag;
        int root = sqrt(val);
        bool ok = false;
        for (int i = 1; i <= root && !ok; i++) {
            if (val % i == 0) {
                int j = val / i;
                if (flag == 1) {
                    if ( (s1.count(i) && s2.count(j)) || (s1.count(-i) && s2.count(-j)) || (s1.count(j) && s2.count(i)) || (s1.count(-j) && s2.count(-i)) ) {
                        cout << "YES\n";
                        ok = true;
                    } 
                } else {
                    if ( (s1.count(-i) && s2.count(j)) || (s1.count(i) && s2.count(-j)) || (s1.count(-j) && s2.count(i)) || (s1.count(j) && s2.count(-i)) ) {
                        cout << "YES\n";
                        ok = true;
                    } 
                }
            }
        }
        if (!ok) {
            cout << "NO\n";
        }
    }
}
