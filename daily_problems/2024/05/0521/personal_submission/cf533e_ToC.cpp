// https://codeforces.com/contest/533/submission/262114609
void sol()
{
    cin >> n;
    cin >> s1 >> s2;

    // 计算最长公共子序列|lcs| = n - 1，O(n ^ 2)， tle
    // 计算最长相同 前后缀
    int head = -1, tail = -1;
    for (int i = 0; i < n; i++) {
        if (s1[i] != s2[i]) {
            if (head == -1)
                head = i;
            tail = i;
        }
    } 
    int ok1 = true, ok2 = true;
    for (int i = head; i < tail; i++) {
        if (s1[i] != s2[i + 1]) ok1 = false;
        if (s1[i + 1] != s2[i]) ok2 = false;
    }
    cout << (int)ok1 + ok2 << '\n';
    

}
