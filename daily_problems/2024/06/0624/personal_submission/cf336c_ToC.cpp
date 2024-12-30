// https://codeforces.com/contest/336/submission/267250636
int a[MAXN];
void sol()
{
    cin >> n;
    for (int i = 1; i <= n; i++) 
        cin >> a[i];
    sort(a + 1, a + n + 1);
    int res = -1, start = -1;
    for (int i = 30; i >= 0; i--) {
        int head = 1, tail = n, minv = pow(2, i);
        while (head < tail) {
            int mid = head + tail >> 1;
            if (a[mid] >= minv) tail = mid;
            else head = mid + 1;
        }
        if (a[head] >= minv) {
            int tmp = (1U << 31) - 1;
            vector<int> vec;
            for (int j = head; j <= n; j++) {
                if ((a[j] >> i) & 1) {
                    tmp &= a[j];
                    vec.push_back(a[j]);
                }
            }
            if ((tmp & -tmp) == (1 << i)) {
                cout << vec.size() << '\n';
                for (auto &e : vec) cout << e << " ";
                cout << '\n';
                return ;
            }
        }
    }
    cout << -1 << '\n';
}
