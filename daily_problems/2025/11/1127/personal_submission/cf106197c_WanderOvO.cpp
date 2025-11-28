/*
一个数 k，有恰好 n 个因数，包括 1 和它本身
现在你需要使用一些操作，去判断这 n 个因数里，哪些是素数
有 n 个因数，能不能推断出来其有多少种素因子？
假如一个数的素因数分解是 p1^cnt1 * p2^cnt2 * ... * pm^cntm
则因数个数是 (cnt1 + 1) * ... * (cntm + 1)
考虑把 n 拆成若干个 >= 2 的数的乘积，每种乘积其实对应一种素因数分解的可能性
数组中一定包含 1，两个素数的 gcd 是 1
对于样例 1，4 只能拆成 2 * 2，所以确定了只有 1 种素因子
n = 2 * 2 * 3 = 12，则 k 可以是 2 * 3 * 5 * 5 这种，也可以是 2 * 2 * 2 * 3 * 3 这种
根据样例 1，或许找到 1 是谁很关键？
假如我们找到了一个素数的位置了，则和这个素数互素的，肯定是不包含这个素数的
n <= 1e4，所以 k 有可能是某个数的 n - 1 次方，可能会是非常大的数，没有保证其上限
k 中至多包含的素因子种类，应该是 13 个，即把 k 拆成一堆 2 相乘...
1 和任何数查询，得到的结果都是 1 的位置
n 和任何数查询，得到的结果是任何数的位置
a[1] 和其他数做 gcd，可能得到的结果:
- 如果和 1 做 gcd，则返回 1 的位置
- 如果和 n 做 gcd，则返回自己的位置，即 1
- 如果和自己互素的数做 gcd，则返回 1 的位置
- 其他情况，则返回的结果会比较怪，但可以肯定的是，返回的是非 1 非 n 的位置

能有确定的算法找到 1 吗？
我有一个想法，gcd(a[1], a[2]) 求出来的下标是 k，则 a[k] 的素因子含量肯定低于 a[1] 和 a[2] 的
然后我们求 a[k] 和 a[3] 的...
gcd 相当于做交集，交到最后肯定是 1 的位置了
我们可以用 n - 1 次去做这个事情

现在知道 1 的位置了，后面如何去确定素数？
我们随便选一个别的数，则这个数至少包含素因子
我们找两个 gcd 起来是 1 的数，则这两个数的素因子无交集
两个数的 gcd 起来不是 1，则至少有一个是合数
假如两个数 a[i] 和 a[j]，gcd 起来得到的下标是 k，k 不是 1 的位置
则显然 k 比 a[i] 和 a[j] 更可能是素数，我们可以直接扔掉 i 和 j
这样感觉就类似于素数筛的意思
如果问 i 和 j，i 和 j 都不是 1 的位置，
- 返回的是 i 或者 j，则删掉没返回的那个
- 返回的是另一个 k，且 k 不是 1 的位置，则删除 i 和 j

根据上面的分析，我们不妨考虑除了 1 之外的其他的数的位置
我们取第一个数，然后和后边的数做 gcd
- 如果 gcd 的结果是 i 或 j，则删掉另一个，后边用保留下来的这个继续做
- 如果返回的是另一个 k，且 k 不是 1 的位置，则删除 i 和 j，后边用这个 k 继续做
这样一来，我们最后肯定能得到一个素数的位置
这波操作下来，我们干掉了至少一半的数，并且这个素数的所有倍数都被我们干掉了

我们再取一个别的数，做这个操作，则又能得到一个素数，并且再次筛掉一半的数
一直这样做下去，我们能得到所有素数的位置
但是，这样下去要做多少次操作呢？
n - 1 + n + n / 2 + n / 4 + ...后边是个等比数列求和，不超过 n，所以 3n 是充足的
*/

int n;
bool deleted[N];

void solve() {   
    cin >> n;
    for (int i = 1; i <= n; i++) {
        deleted[i] = false;
    }

    int one_pos = -1;
    int cur = 1;

    auto query = [&] (int i, int j) -> int {
        cout << "? " << i << " " << j << endl;
        int res;
        cin >> res;
        return res;
    };

    for (int i = 2; i <= n; i++) {
        cur = query(cur, i);
    }

    one_pos = cur;

    deleted[one_pos] = true;
    vector<int> cur_left, next_left;
    for (int i = 1; i <= n; i++) {
        if (!deleted[i]) {
            cur_left.push_back(i);
        }
    }

    vector<int> ans;

    while (cur_left.size() > 0) {
        cur = cur_left[0];
        for (int i = 1; i < cur_left.size(); i++) {
            int res = query(cur, cur_left[i]);
            if (res == one_pos) {
                continue;
            }

            if (res == cur) {
                deleted[cur_left[i]] = true;
            } else if (res == cur_left[i]) {
                deleted[cur] = true;
            } else {
                deleted[cur] = true;
                deleted[cur_left[i]] = true;
            }
            cur = res;
        }

        ans.push_back(cur);
        deleted[cur] = true;
        
        next_left.clear();
        for (auto id : cur_left) {
            if (!deleted[id]) {
                next_left.push_back(id);
            }
        }
        cur_left = next_left;
    }

    sort(ans.begin(), ans.end());
    cout << "! ";
    cout << ans.size() << " ";
    for (auto id : ans) {
        cout << id << " ";
    }
    cout << endl;
}
