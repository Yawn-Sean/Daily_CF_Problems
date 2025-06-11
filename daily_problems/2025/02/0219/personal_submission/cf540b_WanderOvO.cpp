/*
已经有 k 个 [1, 1000] 之间的数，希望再构造 n - k 个这个范围内的数，使得总和 <= x，且中位数 >= y
首先容易算出剩下的 n - k 个数的总和
如果目前中位数已经 >= y，则可以先插 1，直到中位数恰好还能 >= y
之后就是轮番插入 1 和 y，事实上我们确实只会插入 1 和 y 这两种数，这样既能保证增加中位数，也能保证和最小
我们可以枚举插入多少个 1 和多少个 y，然后检验是否可以，从全插入 1 开始检验
*/

int n, k, p, x, y;
int a[N];

void meibao() {
    cin >> n >> k >> p >> x >> y;
    for (int i = 1; i <= k; i++) {
        cin >> a[i];
    }
    
    bool ok = false;
    for (int cnt1 = n - k; cnt1 >= 0; cnt1--) {
        int cnty = n - k - cnt1;
        vector<int> b;
        for (int i = 1; i <= k; i++) {
            b.push_back(a[i]);
        }
        for (int i = 1; i <= cnt1; i++) {
            b.push_back(1);
        }
        for (int i = 1; i <= cnty; i++) {
            b.push_back(y);
        }
        sort(b.begin(), b.end());
        int sum = 0;
        for (auto v : b) {
            sum += v;
        }
        if (sum <= x && b[b.size() / 2] >= y) {
            for (int i = 1; i <= cnt1; i++) {
                cout << "1 ";
            }
            for (int i = 1; i <= cnty; i++) {
                cout << y << " ";
            }
            cout << "\n";
            ok = true;
            break;
        } 
    }
    if (!ok) {
        cout << "-1\n";
    }
}
