void solve() {
    string s;
    cin >> s;
    int n = s.length(), ans = 0;
    int delay = 0, cntM = 0;
    vector<int> cost(n);
    for (int i = 0; i < n; i++) {
        if (s[i] == 'M') {
            cntM++;
            delay = max(0, delay - 1);
        } else {
            if (cntM == 0) cost[i] = 0;
            else {
                cost[i] = delay + cntM;
                delay++;
            }
        }
    }
    cout << *max_element(all(cost)) << "\n";
}
