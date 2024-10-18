/*
所有原本编号奇偶性相同的男生，操作之后奇偶性也是一样的
原本奇偶性相同的男生，比方说 2，4，6 这种，操作完之后，一定也是顺时针 2 4 6... 相对位置不变
所以似乎我们只需要考虑 1 和 2 最后在哪里即可
为了好算循环，我们把所有下标都 -1 之后算
*/

int T;
int n, q;

void solve1() {
    cin >> n >> q;
    vector<int> res(n + 1);
    int pos0 = 0, pos1 = 1;
    for (int i = 1; i <= q; i++) {
        int op;
        cin >> op;
        if (op == 1) {
            int x;
            cin >> x;
            pos0 += x;
            pos1 += x;
            pos0 = (pos0 % n + n) % n;
            pos1 = (pos1 % n + n) % n;
        } else {
            if (pos0 % 2 == 0) {
                pos0++;
            } else {
                pos0--;
            }
            if (pos1 % 2 == 0) {
                pos1++;
            } else {
                pos1--;
            }
            pos0 = (pos0 % n + n) % n;
            pos1 = (pos1 % n + n) % n;
        }
    }
    res[1] = pos0 + 1;
    res[2] = pos1 + 1;
    for (int i = 3; i <= n; i++) {
        res[i] = res[i - 2] + 2;
        if (res[i] > n) {
            res[i] -= n;
        }
    }
    map<int, int> ans;
    for (int i = 1; i <= n; i++) {
        ans[res[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
}       
