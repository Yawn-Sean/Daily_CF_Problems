**提示 1：** 线相交的条件是什么？

线相交，当且仅当第一个数组中，某两个颜色的先后顺序与第二个数组中的不同。

于是，我们考虑第一个数组中 $i$ 位置的元素在第二个数组中出现在 $p[i]$ 位置，那么我们要求的就是 $i\lt j$ 且 $p[i]\gt p[j]$ 。

我们要选取一个子序列，两两满足上述要求，其实求的就是最长递减子序列，这是个经典问题，可以用树状数组等方式解决。

时间复杂度为 $\mathcal{O}(n\log n)$ 。

### 具体代码如下——

Python 做法如下——

```Python []
def main():
    n = II()
    nums1 = LGMI()
    nums2 = LGMI()
    
    pos1 = [0] * n
    pos2 = [0] * n
    
    for i in range(n):
        pos1[nums1[i]] = i
        pos2[nums2[i]] = i
    
    ar = [0] * n
    
    for i in range(n):
        ar[pos1[i]] = -pos2[i]
    
    print(lengthOfLIS(ar))
```

C++ 做法如下——

```cpp []
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> pos1(n), pos2(n);

    for (int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        pos1[x - 1] = i;
    }
    
    for (int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        pos2[x - 1] = i;
    }

    vector<int> ar(n);
    for (int i = 0; i < n; i ++)
        ar[pos1[i]] = -pos2[i];
    
    vector<int> d;

    for (auto &x: ar) {
        int pos = lower_bound(d.begin(), d.end(), x) - d.begin();
        if (d.size() == pos) d.emplace_back(x);
        else d[pos] = x;
    }

    cout << d.size();

    return 0;
}
```