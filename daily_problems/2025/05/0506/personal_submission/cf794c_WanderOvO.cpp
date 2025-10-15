/*
第一个人：xyz
第二个人：abc
第一个人：abc
第二个人：xyz
为了让字典序最小/大，第一个人一定是用最小的 (n + 1) / 2 个字符，第二个人一定用最大的 n / 2 个字符
第一个人拿当前最小字符：
- 假如第二个人的最小字符比自己大，则自己毋庸置疑要填到当前最靠前的空位置
- 假如第二个人的最小字符比自己小
  - 如果第二个人的最大字符也比自己的最小字符小，则自己不会往前填，那会填到哪里呢？
    其实就是填到最后面，因为现在第二个人的所有字符都小于第一个人的最小字符了
    第一个人为了让字典序最小，只能把自己的字符填最后
    第二个人为了让字典序最大，也是只能把自己的字符填最后
    按照何种顺序？第一个人应该优先把最大的往最后填，第二个人应该优先把最小的往最后填
  - 如果第二个人的最大字符比自己的最小字符大，则自己不填到最前面就会被对方填，所以自己还是会填到最前面
*/

int n;
string s, t;
char res[N];

void meibao() {
    cin >> s >> t;
    n = s.size();
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    reverse(t.begin(), t.end());
    int f1 = 0, t1 = (n + 1) / 2 - 1, f2 = 0, t2 = n / 2 - 1;
    int idx1 = 0, idx2 = n - 1;
    int cnt = 0;
    for (cnt = 0; cnt < n; cnt++) {
        if (cnt % 2 == 0) {
            if (s[f1] < t[f2]) {
                res[idx1++] = s[f1++];
            } else {
                break;
            }
        } else {
            if (t[f2] > s[f1]) {
                res[idx1++] = t[f2++];
            } else {
                break;
            }
        }
    }

    for ( ; cnt < n; cnt++) {
        if (cnt % 2 == 0) {
            res[idx2--] = s[t1--];
        } else {
            res[idx2--] = t[t2--];
        }
    }
    assert(cnt == n);
    assert(idx1 > idx2);
    for (int i = 0; i < n; i++) {
        cout << res[i];
    }
}   
