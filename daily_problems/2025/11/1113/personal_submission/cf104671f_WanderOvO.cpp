/*
每次给一个区间，问这个区间的一个子集是否按位与可以是 k
我们其实只关心 k 二进制的超集那些数，只可能从这里面选
要选的话，必然是全选最可能成功
其他的那些数，我们希望它不会影响我们的结果
我们不妨设那些不被考虑的数为 2^31 - 1，注意不能是 2^30 - 1，因为 k 可以是这个，取这个值会影响结果
然后被考虑的数，就是本身的二进制表示
这样就变成了求区间 and，区间 and = k 就是可以，因为不被考虑的数肯定不是 k 且全 1，选了等于没选
不等于 k，则就是不可以
*/

LL n, k, q, a[N];
LL st[M][N], lg[N];

void solve() {
    cin >> n >> k >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if ((a[i] & k) != k) {
            a[i] = (1LL << 30);
            a[i] *= 2;
            a[i] -= 1;
        }
    }
    
    for (int i = 2; i <= n; i++) {
        lg[i] = lg[i / 2] + 1;
    }
    
    for (int i = 1; i <= n; i++) {
        st[0][i] = a[i];
    }
    for (int j = 1; j < M; j++) {
        for (int i = 1; i + (1 << j) - 1 <= n; i++) {
            st[j][i] = (st[j - 1][i] & st[j - 1][i + (1 << (j - 1))]);
        }
    }
    
    auto query = [&] (int l, int r) -> LL {
        int k = lg[r - l + 1];
        return (st[k][l] & st[k][r - (1 << k) + 1]);  
    };
    
    for (int i = 1; i <= q; i++) {
        int l, r;
        cin >> l >> r;
        if (query(l, r) == k) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}
