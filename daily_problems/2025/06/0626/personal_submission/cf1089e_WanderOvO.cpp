/*
对于 n <= 56 的情况，可以先按照右上左上的方法走 n - 2 步，最后两步直接往上 + 往右搞定
对于 n > 56 的情况，先从 a1 一步一步走到 h1，然后从 h1 走到 h7，蛇形最后走到 a2，然后跳到 a8，这样才能够
*/

int n;

void meibao() {
    cin >> n;
    cout << "a1 ";
    if (n <= 56) {
        int i = 0, j = 0;
        while (n > 2) {
            n--;
            if (i % 2 == 0) {
                if (j + 1 < 8) {
                    j++;
                } else {
                    i++;
                }
            } else {
                if (j - 1 >= 0) {
                    j--;
                } else {
                    i++;
                }
            }
            char col = 'a' + j;
            cout << col << i + 1 << " ";
        }

        if (j == 7) {
            if (i < 6) {
                char col = 'a' + j;
                cout << col << i + 2 << " ";
            }
        } else {
            char col = 'a' + j;
            cout << col << "8" << " ";
        }

        cout << "h8";
    } else {
        int i = 0, j = 0;
        n -= 7;
        for (int k = 1; k < 8; k++) {
            char col = k + 'a';
            cout << col << "1 ";
        }
        n--;
        cout << "h2 ";
        i = 1;
        j = 7;
        while (!(i == 1 && j == 0)) {
            n--;
            if (j % 2) {
                if (i + 1 < 7) {
                    i++;
                } else {
                    j--;
                }
            } else {
                if (i - 1 > 0) {
                    i--;
                } else {
                    j--;
                }
            }
            char col = 'a' + j;
            cout << col << i + 1 << " ";
        }
        i = 7;
        j = 0;
        cout << "a8 ";
        n--;
        while (n > 1) {
            n--;
            j++;
            char col = 'a' + j;
            cout << col << i + 1 << " ";
        }
        cout << "h8";
    }
    cout << "\n";
}
