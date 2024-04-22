ll a, b;

void solve() {
    cin >> a >> b;
    int mx = (sqrt(1.0 + 8.0 * (a + b)) - 1) / 2;
    
    vector<int> A, B;
    for (ll i = 1, sum = 0; sum + i <= a; i ++) {
        A.pbk(i);
        sum += i;
    }
    int sum = a - accumulate(all(A), 0);
    for (int i = sz(A) - 1, tar = mx; i >= 0 and sum > 0; i --, tar --) {
        int t = min(tar - A[i], sum);
        A[i] += t;
        sum -= t;
    }

    for (int i = 1, j = 0; i <= mx; i ++) {
        if (j < sz(A) and i == A[j]) {
            j ++;
            continue;
        }
        B.pbk(i);
    }
    cout << sz(A) << endl;
    cout << A << endl;
    cout << sz(B) << endl;
    cout << B << endl;
}