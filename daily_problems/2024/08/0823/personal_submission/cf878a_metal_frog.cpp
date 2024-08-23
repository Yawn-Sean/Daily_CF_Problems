void solve() {
    int n;
    cin >> n;
    int res1 = 1023, res0 = 0;
    for (int t = 0; t < n; t++) {
        string op;
        int num;
        cin >> op >> num;
        if (op == "|") {
            res1 |= num;
            res0 |= num;
        } else if (op == "^") {
            res1 ^= num;
            res0 ^= num;
        } else {
            res1 &= num;
            res0 &= num;
        }
    }
    int andNum = 0, orNum = 0, xorNum = 0;
    for (int i = 0; i < 10; i++) {
        int r1 = (res1 & (1 << i));
        int r0 = (res0 & (1 << i));
        if (r1 && r0) {
            orNum += (1 << i);
        } else if (r1 && !r0) {
            andNum += (1 << i);
        } else if (!r1 && r0) {
            andNum += (1 << i);
            xorNum += (1 << i);
        }
    }
    cout << "3\n";
    cout << "& " << andNum << "\n";
    cout << "^ " << xorNum << "\n";
    cout << "| " << orNum << "\n";
}
