/*
需要把尽可能多的 1 移动到主对角线上，假如有 cnt 个
然后要把 n - cnt 个主对角线的 0 变成 1，剩下位置的 1 都变成 0
*/

int T;
int n;

void solve1() {
    cin >> n;
    vector<int> cnt(n, 0);
    int tot_one = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) {
            if (s[j] == '1') {
                cnt[(i + n - j) % n]++;
                tot_one++;
            }
        }
    }
    int mx = 0;
    for (int i = 0; i < n; i++) {
        mx = max(mx, cnt[i]);
    }
    cout << tot_one + n - 2 * mx << "\n";
}                                                                                                                  
