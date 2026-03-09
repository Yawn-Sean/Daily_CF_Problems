#define first "Munir"
#define second "Matthew"

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    if (k == 1) {
        cout << (n * m % 2 ? first : second);
    } else if (n % 2 and m % 2 or n % 2 != m % 2) {
        cout << first;
    } else {
        cout << (k >= 4 ? first : second);
    }
    cout << '\n';
}
