const int mod = int(1e9) + 7;
int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
 
    ll a, b; cin >> a >> b;
    ll ans = 0, sum = (a * b % mod + b + 2) * a % mod * po(2, mod - 2) % mod;
    for (int r = 0; r < b; r++) {
        ans = (ans + sum * r % mod) % mod;
    }
    cout << ans << '\n';

    return 0;
}
