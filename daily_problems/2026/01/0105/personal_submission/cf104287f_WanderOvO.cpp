
void solve() {
    LL a, b, c;
    cin >> a >> b >> c;
    LL g = __gcd(a, b);
    LL l = a / g * b;
    g = __gcd(l, c);
    cout << (c - 1) / g * g << "\n";
}
