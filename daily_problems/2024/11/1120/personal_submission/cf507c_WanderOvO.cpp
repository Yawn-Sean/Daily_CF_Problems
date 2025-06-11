/*
以 u 为根的完美二叉树，叶子结点包括 [l, r]，一共包含 2^h - 1 个结点，h 是深度，从 1 开始
mid = l + (r - l) / 2
往左走，则访问到 [l, mid]，往右走，则访问到 [mid + 1, r]
目前在第 1 层，往左走，则如果 [l, mid] 不包含 exit，则左边得全走完
左边的结点一共有 2^h - 1 个，访问完之后才能访问根的右儿子子树
访问根的右儿子子树时，仍然考虑其包含的叶子 [l, r]
看先访问哪边，假如先被访问的那边没有 exit，则又全都白走了，走完才能回来
需要知道当前在哪层，且这个结点包含哪些叶子，且接下来该往哪边走
*/

LL h, n, res;
bool finished;

void dfs(LL level, LL l, LL r, LL direction) {
    if (finished) return;
    res++;
    if (l == r) {
        if (n == l) {
            finished = true;
        } 
        return;
    }
    LL mid = (l + r) / 2;
    if (direction == 0) {
        if (n >= l && n <= mid) {
            dfs(level + 1, l, mid, direction ^ 1);
        } else {
            res += (1LL << (h - level + 1)) - 1;
            dfs(level + 1, mid + 1, r, direction);
        }
    } else {
        if (n > mid && n <= r) {
            dfs(level + 1, mid + 1, r, direction ^ 1);
        } else {
            res += (1LL << (h - level + 1)) - 1;
            dfs(level + 1, l, mid, direction);
        }
    }
}

void meibao() {
    cin >> h >> n;
    res = 0;
    finished = false;
    dfs(1, 1, (1LL << h), 0);
    cout << res - 1 << "\n";
}
