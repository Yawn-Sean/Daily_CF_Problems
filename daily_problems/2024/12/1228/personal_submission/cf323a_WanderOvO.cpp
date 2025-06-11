/*
奇数的情况似乎构造不出来
羊神提示：都拆分成 2 * 2 * 2 的块
*/

int layer[110][110];
char s[2] = {'w', 'b'};

void meibao() {
    int n;
    cin >> n;
    if (n % 2) {
        cout << "-1\n";
    } else {
        memset(layer, 0, sizeof layer);
        for (int i = 1; i <= n; i += 2) {
            int cur = 1;
            for (int j = 1; j <= n; j += 2) {
                layer[i][j] = cur % 2;
                layer[i][j + 1] = cur % 2;
                layer[i + 1][j] = ((cur % 2) ^ 1);
                layer[i + 1][j + 1] = ((cur % 2) ^ 1);
                cur++;
            }
        }
        for (int i = 0; i < n; i++) {
            int t = (i / 2) % 2;
            for (int j = 1; j <= n; j++) {
                for (int k = 1; k <= n; k++) {
                    cout << s[layer[j][k] ^ t];
                }
                cout << "\n";
            }
            cout << "\n";
        }
    }
}
