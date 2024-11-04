int n, q;

void solve() {
    cin >> n;
    int sum = 0;
    // 对角线上的值才对答案有影响
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            int x;
            cin >> x;
            if (i == j) {
                sum ^= x;
            }
        }
    }
    
    cin >> q;
    string res;
    
    while (q --) {
        int op;
        cin >> op;
        if (op == 3) {
            res += '0' + sum;
        }
        else {
            int x;
            cin >> x;
            sum ^= 1;
        }
    }
    
    cout << res << endl;
}