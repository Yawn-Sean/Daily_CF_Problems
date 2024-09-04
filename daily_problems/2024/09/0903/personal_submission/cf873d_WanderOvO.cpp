/*
首先可以计算出归并排序所有涉及到的区间，最多的调用次数就是区间个数
假如某个区间的函数被调用了，那么包含它的更大区间的函数一定也被调用了
所以其实就是先找一个“线段树”上包含根的大小为 k 的连通块，然后再构造
构造时，考虑不会继续往下调用的那些区间，这些区间的数据应该是升序的了
但可能两个有序的区间组成的新区间本身也是有序的

羊的做法：
假如一个子数组不是升序，则需要调用两次 mergesort，所以调用次数一定是奇数次
如何保证构造时 [l, r) 不是升序，但是 [l, mid), [mid, r) 是升序？
考虑从 1 2 ... n 开始调整
我们交换 a[mid - 1] 和 a[mid]，则这两个区间本身还是升序的，但是整体不是
*/

int T;
int n, k;
int a[N];

void dfs(int l, int r) {
    if (l + 1 >= r) {
        return;
    }
    if (k > 0) {
        int mid = (l + r) / 2;
        if (mid - 1 < l) {
            return;
        }
        swap(a[mid - 1], a[mid]);
        k -= 2;
        dfs(l, mid);
        dfs(mid, r);
    }
}

void solve1() {
    cin >> n >> k;
    if (k % 2 == 0) {
        cout << "-1\n";
        return;
    }

    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
    }
    k--;
    dfs(0, n);
    if (k != 0) {
        cout << "-1\n";
    } else {
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
    }
}        
