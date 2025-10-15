const ll N = 2e5 + 5;

ll n, a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    rep(i, 1, n) cin >> a[i];
    vector<ll> A, B;
    rep(i, 1, n) {
        ll s = sqrtl(a[i]);
        if(s * s == a[i]) {
            if(a[i] == 0) A.push_back(2);
            else A.push_back(1);
        }
        else B.push_back(min(a[i] - s * s, (s + 1) * (s + 1) - a[i]));
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    if(A.size() == B.size()) cout << 0 << endl;
    else if(A.size() > B.size()) cout << accumulate(A.begin(), A.begin() + (A.size() - B.size()) / 2, 0LL) << endl;
    else cout << accumulate(B.begin(), B.begin() + (B.size() - A.size()) / 2, 0LL) << endl;
    return 0;
}
