int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    cout << k * (6 * n - 1) << "\n";
    for (int i = 0; i < n; ++i) {
        for (int j : {1, 2, 3, 5}) {
            cout << (6 * i + j) * k << " ";
        }
        cout << "\n";
    }
    
    return 0;
}
