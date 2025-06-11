/*
我们每次选还没排序的最小的数的下标，找到它该去的下标
假如 j - i + 1本来就是素数，直接换即可
假如 j - i + 1 不是素数，拆分成较少的交换步骤做到这一点
从 j 交换到 i，先从 j 交换到 k，然后从 k 交换到 i，总和是 j - k + 1 + k - i + 1 = j - i + 2
选 cnt 个中间点，则交换次数就是 cnt + 1，要看的数就是 j - i + 1 + cnt
假如 j - i + 1 为奇数，则 j - i + 2 为偶数，一定能找到一个 k，使得可以通过换 2 次满足题意
假如 j - i + 1 为偶数，先把其和旁边一个交换，就变成了奇数的情况，可以通过换 3 次满足题意
维护一下双向的映射，pos[i] 表示 i 值的当前位置，val[i] 表示 i 位置的值
考虑所有 >= 4 的偶数，预处理出来其可以拆分成哪两个素数的和
1e5 以内有不到 1e4 个素数，直接平方枚举，就可以得到每个偶数的拆分
*/

int T;
int n, pos[N], val[N];
int prime[N], m, cnt;
bool is_prime[N];
int divide[N];
vector<PII> res;

void swp(int pos1, int pos2) {
    swap(val[pos1], val[pos2]);
    swap(pos[val[pos1]], pos[val[pos2]]);
    res.pb({pos1, pos2});
}

void my_swap(int pos1, int pos2) {
    if (is_prime[pos2 - pos1 + 1]) {
        swp(pos1, pos2);
    } else {
        if ((pos2 - pos1) % 2 == 0) {
            int d = pos2 - pos1 + 2;
            swp(pos1 + divide[d] - 1, pos2);
            swp(pos1, pos1 + divide[d] - 1);
        } else {
            pos1++;
            int d = pos2 - pos1 + 2;
            swp(pos1 + divide[d] - 1, pos2);
            swp(pos1, pos1 + divide[d] - 1);
            swp(pos1 - 1, pos1);
        }
    }
}

void solve1() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> val[i];
        pos[val[i]] = i;
    }
    get_prime();
    for (int i = 0; i < cnt; i++) {
        for (int j = i; j < cnt; j++) {
            int p1 = prime[i], p2 = prime[j];
            if (p1 + p2 >= N) continue;
            divide[p1 + p2] = p1;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (pos[i] != i) {
            my_swap(i, pos[i]);
        }
    }
    cout << res.size() << "\n";
    for (auto p : res) {
        cout << p.x << " " << p.y << "\n";
    }
}                                                                                                                  
