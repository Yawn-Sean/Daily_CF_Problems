int main(void)
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, a1 = 2, a2 = 1;
    ll ans = 0;
    cin >> n;
    while(a1 <= n) {
        swap(a1, a2);
        a1 += a2;
        ans++;
    }
    cout << ans << "\n";
}
