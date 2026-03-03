void solve() {
    int mx = 30000;

    auto query = [&](auto& a) -> int {
        cout << "? " << a.size();
        for (int x: a) {
            cout << " " << x;
        }
        cout << endl;
        int x;
        cin >> x;
        return x;
    };

    vector<int> primes = {2, 3, 5, 7, 11};
    int m = primes.size();
    vector<int> ans(m);
    for (int i = 0; i < m; i++) {
        vector<int> a = {1};
        while (a.back() * primes[i] <= mx) {
            a.push_back(a.back() * primes[i]);
        }
        ans[i] = query(a);
    }
    vector<int> possible;
    for (int x = 1; x <= mx; x++) {
        bool ok = true;
        for (int i = 0; i < m; i++) {
            int t = x, y = 0;
            while (t) {
                y += t % primes[i];
                t /= primes[i];
            }
            if (y != ans[i]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            possible.push_back(x);
        }
    }

    int left = -1, right = possible.size();
    while (left + 1 < right) {
        int mid = (left + right) / 2;
        vector<int> a = {1};
        while (a.back() * 2 <= possible[mid]) {
            a.push_back(a.back() * 2);
        }
        for (int i = mid; i < right; i++) {
            if (__popcount(possible[i]) != 1) {
                a.push_back(possible[i]);
            }
        }
        if (query(a) == 1) {
            left = mid;
        } else {
            right = mid;
        }
    }
    cout << "! " << possible[left];
}
