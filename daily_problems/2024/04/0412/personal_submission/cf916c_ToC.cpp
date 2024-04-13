// https://codeforces.com/contest/916/submission/256251176
using PII = pair<int, int>;
int n, t, m, p = 1e5 + 3;
void sol()
{
    cin >> n >> m;
    m -= (n - 1);
    int sp = p;
    int me = 1e9;
    cout << sp << " " << sp << '\n';

    for (int i = 1; i < n - 1; i++) {
        cout << i << " " << i + 1 << " " << 1 << '\n';
    }
    cout << n - 1 << " " << n <<  " " << p - (n - 2) << '\n';

    bool done = (m == 0);
    for (int i = 1; i < n - 1; i++) {
        for (int j = i + 2; j <= n; j++) {
            if (m-- > 0){
                cout << i << " " << j <<   " " << me << '\n';
            } else {
                done = true;
                break;
            }
        }
        if (done) break;
    }

}
