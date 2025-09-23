/*
倘若 b[1] 确定了，b[i + 1] = a[i] ^ b[i]，也确定了
如果 b[1] = 0，则假如 a[1] >= n，就废了，这样会导致 b[2] >= n
所以 b[1] 至少是个能让 a[1] ^ b[1] <= n - 1 的数
通过样例 2 可以发现，构造出的 b 可能不止 1 种
b[2] = a[1] ^ b[1]
b[3] = a[2] ^ b[2] = a[1] ^ a[2] ^ b[1]
b[4] = a[3] ^ b[3] = a[1] ^ a[2] ^ a[3] ^ b[1]
如果 a[i] 的前缀异或和互不相同，则有希望构造出 b，否则一定构造不出，会有相同的数
题目应该保证了前缀异或和不会有相同的数
由于前缀异或和已经互不相同了，所以其实是让最大值为 n - 1 就好了
所以相当于找一个 0 到 n - 1 之内的数，使得和这些 a[i] 异或起来最大值为 n - 1 即可
相当于需要一个快速求最大异或对的办法
*/

int n, a[N];
int trie[M][2], idx;

void insert(int val) {
    int p = 1;
    for (int i = 28; i >= 0; i--) {
        int ch = ((val >> i) & 1);
        if (!trie[p][ch]) {
            trie[p][ch] = ++idx;
        }
        p = trie[p][ch];
    }
}

int query(int val) {
    int p = 1;
    int res = 0;
    for (int i = 28; i >= 0; i--) {
        int ch = ((val >> i) & 1);
        if (trie[p][ch ^ 1]) {
            res = 2 * res + 1;
            p = trie[p][ch ^ 1];
        } else {
            res = 2 * res;
            p = trie[p][ch];
        }
    }
    return res;
}

void meibao() {
    cin >> n;
    idx = 1;
    for (int i = 1; i < n; i++) {
        cin >> a[i];
        a[i] ^= a[i - 1];
        insert(a[i]);
    }

    for (int i = 0; i < n; i++) {
        if (query(i) <= n - 1) {
            cout << i << " ";
            for (int j = 1; j < n; j++) {
                cout << (i ^ a[j]) << " ";
            }
            return;
        }
    }
}   
