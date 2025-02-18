/*
假如翻转了 (i, j) 位置的数，对和有什么影响？
作为行贡献时，(i, j) 位置的会和 (j, i) 作用
作为列贡献时，(i, j) 位置也是和 (j, i) 作用
所以本质上要求的那个和就是枚举所有的 (i, j)，然后累加 a[i][j] & a[j][i]
答案只关心最后有奇数还是偶数个 1
最后相当于做异或，所以非对角线元素完全不影响答案
每次对行或者列操作，都只影响一个对角线元素，所以答案一定变
*/

int n, a[M][M];

void meibao() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    int res = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            res ^= (a[i][j] & a[j][i]);
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int op;
        cin >> op;
        if (op == 3) {
            cout << res;
        } else {
            int x;
            cin >> x;
            res ^= 1;
        }
    }
} 
