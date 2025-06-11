void Solve() {
    string s;getline(cin, s);
    int add = 1, sub = 0;
    for (auto i : s) {
        if (i == '+') {
            add++;
        }
        else if (i == '-') {
            sub++;
        }
    }
    auto it = find(s.begin(), s.end(), '=') - s.begin();
    int n = stoi(s.substr(it + 1));
    vector<int> a, b;
    int sum = 0;
    for (int i = 1;i <= add;i++) a.push_back(1), sum += 1;
    for (int i = 1;i <= sub;i++) b.push_back(n), sum -= n;
    if (sum <= n and n <= sum + (n - 1) * (add + sub)) {
        cout << "Possible\n";
        int pa = 0, pb = 0;
        while (sum < n) {
            if (pa < add) {
                int mn = min(n - 1, n - sum);
                a[pa++] += mn;
                sum += mn;
            }
            else {
                int mn = min(n - 1, n - sum);
                b[pb++] -= mn;
                sum += mn;
            }
        }
        char lst = '+';
        for (auto i : s) {
            if (i == '?') {
                if (lst == '+') {
                    cout << a.back();
                    a.pop_back();
                }
                else {
                    cout << b.back();
                    b.pop_back();
                }
            }
            else {
                cout << i;
                if (i == '+') lst = '+';
                else if (i == '-') lst = '-';
            }
        }
    }
    else {
        cout << "Impossible\n";
    }
}
