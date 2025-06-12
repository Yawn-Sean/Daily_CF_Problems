int n, m, x, y, a, b;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m >> x >> y >> a >> b;
    int g = __gcd(a, b);
    a /= g; b /= g;
    int k = min(n / a, m / b);
    a *= k; b *= k;
    int rx = x - (a + 1) / 2, ry = y - (b + 1) / 2;
    chkmax(rx, 0); chkmin(rx, n - a);
    chkmax(ry, 0); chkmin(ry, m - b);
    cout << rx << " " << ry << " " << rx + a << " " << ry + b << endl;
    return 0;
}
