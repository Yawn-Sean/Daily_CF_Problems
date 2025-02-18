void solve() {
    vector<int> prime(eratosthenesSieve(100001));
    vector<pii> step;
    int n;
    cin >> n;
    vector<int> num(n), pos(n + 1), ord(n);
    for (int i = 0; i < n; i++) {
        cin >> num[i];
        ord[i] = num[i];
        pos[num[i]] = i;
    }
    sort(all(ord));
    for (int i = n - 1; i >= 0; i--) {
        if (ord[i] == num[i]) continue;
        int j = pos[ord[i]];
        while (j != i) {
            auto it = upper_bound(all(prime), i - j + 1); it--;
            int next = j + (*it) - 1;
            swap(num[j], num[next]);
            pos[num[j]] = j;
            pos[num[next]] = next;
            step.emplace_back(j + 1, next + 1);
            j = next;
        }
    }
    cout << sz(step) << "\n";
    for (auto& [i, j] : step) {
        cout << i << " " << j << "\n";
    }
}
