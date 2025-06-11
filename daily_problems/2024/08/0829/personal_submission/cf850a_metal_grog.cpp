const int N = 1e3 + 7;
int p[N][5];
 
void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> p[i][j];
        }
    }
    if (n > 34) {
        cout << "0\n";
        return;
    }
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        bool okay = true;
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < j; k++) {
                int val = 0;
                for (int d = 0; d < 5; d++) {
                    val += (p[j][d] - p[i][d]) * (p[k][d] - p[i][d]);
                }
                if (val > 0) {
                    okay = false;
                }
            }
        }
        if (okay) ans.emplace_back(i + 1);
    }
    cout << ans.size() << "\n";
    for (int x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}
