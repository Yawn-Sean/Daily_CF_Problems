/*
b 的长度至多为 n - 1
已经被加入到 b 中的数/没有出现在 b 中的数，在 a 中可以删除
每次往 b 中加入的数是确定的，只不过删除的数需要选择一下是左边还是右边
考虑 a[i], a[i + 1], a[i + 2]，要往 b 中加入 a[i + 1]，且 b 中后续无需加入 a[i] 和 a[i + 2]
如果删除 a[i]，则变成 a[i + 1], a[i + 2]，而 a[i + 1] 后面也可以删除了
如果删除 a[i + 2]，则变成 a[i], a[i + 1]，而 a[i + 1] 后面也可以删除了
所以不管删除左右的哪个，后面这三个数中剩下的两个都是后面可以删除的，不会导致构造不出答案
遇到两边都可以删除的情况时，我们选择随便删除一个，但是方案要乘 2
维护 b 中还需要加入的数字集合
维护 a 的链表，额外维护每个数在 a 中的位置
从左到右枚举 b[i]，找到 a 中 b[i] 的位置，判断左右能否删除，然后删除，统计方案 
*/

struct Node {
    int pre, ne, val;
};

int T;
int b[N], pos[N], n, k;
Node a[N];
set<int> left_b; 

void del(int p) {
    int pre_p = a[p].pre, ne_p = a[p].ne;
    if (pre_p > 0) {
        a[pre_p].ne = ne_p;
    }
    if (ne_p > 0) {
        a[ne_p].pre = pre_p;
    }
}

void solve1() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].val;
        a[i].pre = i - 1;
        a[i].ne = i + 1;
        pos[a[i].val] = i;
    }
    a[1].pre = -1;
    a[n].ne = -1;
    left_b.clear();
    for (int i = 1; i <= k; i++) {
        cin >> b[i];
        left_b.insert(b[i]);
    }
    LL res = 1;
    for (int i = 1; i <= k; i++) {
        int p = pos[b[i]];
        int pre_p = a[p].pre, ne_p = a[p].ne;
        int cnt = 0;
        if (pre_p > 0 && !left_b.count(a[pre_p].val)) {
            del(pre_p);
            cnt++;
        }
        if (ne_p > 0 && !left_b.count(a[ne_p].val)) {
            if (cnt == 0) {
                del(ne_p);
            }
            cnt++;
        }
        if (cnt == 0) {
            res = 0;
            break;
        }
        res *= cnt;
        res %= MOD2;
        left_b.erase(b[i]);
    }
    cout << res << "\n";
}   