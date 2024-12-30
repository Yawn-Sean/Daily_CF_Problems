// https://codeforces.com/contest/989/submission/259758347
int n, m;
int cnt[4];
string str("ABCD");
void show(vector<vector<char>> &mat) {
    for (auto &row: mat) {
        for (auto &ele: row) cout << ele;
        cout << '\n';
    }
}
void paint(int border, int inner) {
    vector<vector<char>> tmp(10, vector<char>(50, str[border]));
    for (int i = 1; i < 10; i++) {
        int j = 1 + (i % 2 == 0);
        for (; j < 49; j += 2) {
            if (cnt[inner] > 1) {
                tmp[i][j] = str[inner];
                cnt[inner]--;
            }
            else break;
        }
        if (i == 2 || i == 5) i++;
    }
    show(tmp);
}
void sol()
{
    for (int i = 0; i < 4; i++)
        cin >> cnt[i];
    cout << 40 << " " << 50 << '\n';
    for (int i = 0; i < 4; i++) {
        paint(i, (i + 1) % 4);
    }
}
