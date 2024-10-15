const int N = 50000 + 7;
int X[N], Y[N], Z[N];

void solve() {
    int n;
    cin >> n;
    map<int, vector<int>> sortByZ;
    for (int i = 1; i <= n; i++) {
        cin >> X[i] >> Y[i] >> Z[i];
        sortByZ[Z[i]].emplace_back(i);
    }
    int remLastRound = -1;
    for (auto& [z, points] : sortByZ) {
        map<int, vector<int>> sortByX;
        for (int id : points) {
            sortByX[X[id]].emplace_back(id);
        }
        int rem = -1;
        for (auto& [x, pt] : sortByX) {
            sort(all(pt), [&](int a, int b) -> bool {
                return Y[a] < Y[b];
            });
            while (sz(pt) > 1) {
                int u = pt.back(); pt.pop_back();
                int v = pt.back(); pt.pop_back();
                cout << u << " " << v << "\n";
            }
            if (sz(pt) == 1) {
                if (rem != -1) {
                    cout << pt.back() << " " << rem << "\n";
                    rem = -1;
                } else {
                    rem = pt.back();
                }
            }
        }
        if (rem != -1) {
            if (remLastRound == -1) remLastRound = rem;
            else {
                cout << remLastRound << " " << rem << "\n";
                remLastRound = -1;
            }
        }
    }
}
