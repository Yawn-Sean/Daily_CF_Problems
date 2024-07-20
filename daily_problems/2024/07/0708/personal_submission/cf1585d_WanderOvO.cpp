/*
a[i], a[j], a[k] 变成 a[k], a[i], a[j]
相当于先交换 i 和 j 位置的数，再交换 i 和 k 位置的数
i, j, k 的相对大小没有要求
考虑每次把最小的换到最前面
只要还未确定位置的数字 >= 3 个，就一定能确定 1 个数字的位置
假如所有数两两不同，则逆序对的奇偶性始终不会变，倘若最开始是奇数则肯定不行了
假如存在相同的数，则相当于可以第一次交换不改变奇偶性，第二次改变，这样就反过来了
*/

int T;
LL n, a[N], res, tmp[N];
 
void merge(int l, int mid, int r) {
    int i = l, j = mid + 1, k = l;
    while (i <= mid && j <= r) {
        if (a[i] <= a[j]) {
            tmp[k++] = a[i++];
        } else {
            res += (mid - i + 1);
            tmp[k++] = a[j++];
        }
    }
    while (i <= mid) {
        tmp[k++] = a[i++];
    }
    while (j <= r) {
        tmp[k++] = a[j++];
    }
    for (k = l; k <= r; k++) {
        a[k] = tmp[k];
    }
}
 
void merge_sort(int l, int r) {
    if (l < r) {
        int mid = (l + r) / 2;
        merge_sort(l, mid);
        merge_sort(mid + 1, r);
        merge(l, mid, r);
    }
}

void solve1() {
    cin >> n;
    set<int> vals;
    bool same = false;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (vals.count(a[i])) {
            same = true;
        }
        vals.insert(a[i]);
    }
    res = 0;
    merge_sort(1, n);
    if (res % 2 == 0 || same) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}        