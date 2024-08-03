ll a, b;
void solve() {
    cin >> a >> b;
    ll k = (ll)(cbrt(a * b) + eps);
    if (k * k * k == a * b and a % k == 0 and b % k == 0) {
        cout << "Yes" << endl;
        return;
    }
    cout << "No" << endl;
}