// https://codeforces.com/contest/1196/submission/268271579
string s;
void sol()
{
    cin >> n >> k;
    cin >> s;
    string s1 {"RGB"}, s2 {"GBR"}, s3 {"BRG"};
    // c1是s1循环的修改数量，c2是s2循环的修改数量，c3是s3循环的修改数量，
    int c1 = 0, c2 = 0, c3 = 0;
    for (int i = 0; i < k; i++) {
        if (s[i] != s1[i % 3]) {
            c1++;
        }
        if (s[i] != s2[i % 3]) {
            c2++;
        }
        if (s[i] != s3[i % 3]) {
            c3++;
        }
    }
    int res = min({c1, c2, c3});
    int b1, b2, b3;
    for (int i = 1; i <= n - k; i++) {
        b1 = c1, b2 = c2, b3 = c3;
        c2 = b1 - (s[i - 1] != s1[0]) + (s[i + k - 1] != s2[((k % 3) + 2) % 3]);
        c3 = b2 - (s[i - 1] != s2[0]) + (s[i + k - 1] != s3[((k % 3) + 2) % 3]);
        c1 = b3 - (s[i - 1] != s3[0]) + (s[i + k - 1] != s1[((k % 3) + 2) % 3]);
        res = min(res, min({c1, c2, c3}));
    }
    cout << res << '\n';
}
