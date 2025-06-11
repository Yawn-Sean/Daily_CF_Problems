/*
假设有 k 个颜色，至多能配出多少个满足条件的对？
k 个颜色的有序对有 k * (k - 1) 个（除去相等的）
枚举 i, 然后从 j = i + 1 枚举，输出 (i, j) 和 (j, i)
*/

LL n, k;

void meibao() {
    cin >> n >> k;
    if (n > k * (k - 1)) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        for (int i = 1; i <= k && n > 0; i++) {
            for (int j = i + 1; j <= k && n > 0; j++) {
                n--;
                cout << i << " " << j << "\n";
                if (n > 0) {
                    n--;
                    cout << j << " " << i << "\n";
                }
            }
        }
    }
}    
