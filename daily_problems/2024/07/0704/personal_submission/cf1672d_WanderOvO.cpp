/*
a[l] a[l + 1] ... a[r], a[l] = a[r]
-> a[l + 1] ... a[r] a[l]，导致两个相同的数字相邻了
只出现一次的数字的相对位置似乎是变不了的
题目所谓操作本质上就是其他数字的相对顺序不变，把一些相同的数字聚在一起
5 2 3 4 5 7 8 9 5
5 2 3 4 7 8 9 5 5
2 3 4 5 7 8 9 5 5
2 2 4 4 1
1 2 2 4 4
直接考虑从左往右比较，a 和 b 中的数字不一样就存起来（往后移动）
*/

int T;
int cnt[N], n, a[N], b[N];

void solve1() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    int pt = 1;
    for (int i = 1; i <= n; i++) {
        if (a[i] == b[pt]) {
            pt++;
        } else {
            cnt[a[i]]++;
        }
        while (pt <= n && pt > 1 && b[pt] == b[pt - 1] && cnt[b[pt]]) {
            cnt[b[pt]]--;
            pt++;
        }
    }
    if (pt == n + 1) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}  