/*
最后保留的是一个排列的中间一段连续区间
假如保留第一个串中的 [l, r] 这部分可以通过删除前缀和后缀做到
那么保留 [l, r] 的子串也一定能做到
枚举 r，求最小的 l，统计方案数即可
如何判断 [l, r] 是否可以被保留下来？
使用哈希，把这 10 个排列都当成字符串，并维护每个数字出现的位置
这样可以快速找到哪一段是待匹配字符串，然后哈希直接匹配即可
总复杂度 O(nmlogn)
双哈希常熟太大，过不去
*/

MyHash h1[M], h2[M];
int pos[M][N], n, m, a[M][N];

bool check(int l, int r) {
    int len = r - l + 1;
    LL hash_val1 = h1[1].get(l, r);
    for (int i = 2; i <= m; i++) {
        int p = pos[i][a[1][r]];
        int left = p - len + 1;
        if (left < 0) {
            return false;
        }
        if (h1[i].get(left, p) == hash_val1) {
            continue;
        } else {
            return false;
        }
    }
    return true;
}

void meibao() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        string s;
        for (int j = 0; j < n; j++) {
            int val;
            cin >> a[i][j];
            val = a[i][j];
            pos[i][val] = j;
            h1[i].origin_val[j] = val;
            // h2[i].origin_val[j] = val;
        }
        h1[i].init(n, n + 1, MOD1);
        // h2[i].init(n, n + 1, MOD2);
    }
    LL res = 0;
    for (int right = 0; right < n; right++) {
        int l = 0, r = right, mid;
        while (l + 1 < r) {
            mid = l + (r - l) / 2;
            if (check(mid, right)) {
                r = mid;
            } else {
                l = mid;
            }
        }
        if (check(l, right)) {
            res += right - l + 1;
        } else if (check(r, right)) {
            res += right - r + 1;
        }
    }
    cout << res << "\n";
}
