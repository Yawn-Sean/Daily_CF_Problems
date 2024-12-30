vector<int> getK(vector<int>& a) {
    BIT<int> bit(n);
    for (int i = 0; i < n; i ++) {
        bit.add(i + 1, 1);
    }
    vector<int> ka(n);
    for (int i = 0; i < n; i ++) {
        ka[i] = bit.sum(1, a[i]);
        bit.add(a[i] + 1, -1);
    }
    return ka;
}

void solve() {
    cin >> n;
    vector<int> a(n), b(n);
    cin >> a >> b;
    vector<int> ka = getK(a), kb = getK(b);
    
    // add
    vector<int> order(n, 0);
    int carry = 0;
    for (int i = n - 1; i >= 0; i --) {
        auto t = ka[i] + kb[i] + carry;
        order[i] = t % (n - i);
        carry = t / (n - i);
    }
    
    vector<int> res(n, 0);
    BIT<int> bit(n);
    for (int i = 0; i < n; i ++) {
        bit.add(i + 1, 1);
    }
    
    for (int i = 0; i < n; i ++) {
        res[i] = bit.select(order[i] + 1);
        bit.add(res[i] + 1, -1);
        res[i] -= 1;
    }
    cout << res << endl;
}