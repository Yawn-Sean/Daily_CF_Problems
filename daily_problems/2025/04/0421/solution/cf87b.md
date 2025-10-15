**提示：** 欸，好像没啥要提示的，读懂题，想想怎么实现就好啦！

首先，有两个基础类 `void` 和 `errtype` 。

前者是可以变为 `void**...` 的类，后者无论如何操作都是 `errtype` 。

然后你做的操作叫做定义类，在一个类的基础上，如果多了一个 `&` ，那么少一个 `*` ，如果多了一个 `*` ，那么多一个 `*` （形式上）。

于是，我们可以根据原类，进行上述运算得到新的类有多少个 `*` 。如果新的类的 `*` 变为小于 0 的话，那么新的类就是 `errtype` 了。

因此，为了方便实现，我们对 `void` 记录数值为 $0$ ，对 `errtype` 记录数值为负的足够大的数，分别表示对应的 `*` 的个数。这样，我们只需通过加法减法，即可得到新类型的 `*` 的个数。

这样，从 `errtype` 起步一定得到非法类。否则，新类型的 `*` 的个数可以从其原本元素的 `*` 的个数推导出来（数 `*` 和 `&` 的个数）。如果个数是负数，则又得到了 `errtype` ，重置为负无穷就行。

注意没被定义的类都是 `errtype` ，可以直接赋值负无穷。同时，输出的一行是可以包含 `*` 和 `&` 的，你需要进行类似上面的判断。

时间复杂度为 $\mathcal{O}(n^2)$ ，因为可能不断加入 `*` 后输出 $\mathcal{O}(n)$ 轮。

### 具体代码如下——

Python 做法如下——

```Python []
def main():
    n = II()
    cnt = Counter()

    cnt['void'] = 0
    cnt['errtype'] = -100000
    outs = []

    for _ in range(n):
        op = LI()
        if op[0] == 'typedef':
            v1 = op[1]
            v2 = op[2]
            
            l = 0
            r = len(v1) - 1
            cur = 0
            
            while v1[l] == '&':
                l += 1
                cur -= 1
            
            while v1[r] == '*':
                r -= 1
                cur += 1
            
            orig = v1[l:r + 1]
            
            if orig not in cnt:
                cnt[orig] = -100000
            
            nval = cnt[orig] + cur
            cnt[v2] = nval if nval >= 0 else -100000
        else:
            v = op[1]
            
            l = 0
            r = len(v) - 1
            cur = 0
            
            while v[l] == '&':
                l += 1
                cur -= 1
            
            while v[r] == '*':
                r -= 1
                cur += 1
            
            orig = v[l:r + 1]
            
            outs.append('errtype' if orig not in cnt or cnt[orig] + cur < 0 else "void" + '*' * (cnt[orig] + cur))

    print('\n'.join(outs))
```

C++ 做法如下——

```cpp []
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    map<string, int> mp;
    mp["void"] = 0;
    mp["errtype"] = -100000;

    while (n --) {
        string op;
        cin >> op;
        if (op[4] == 'd') {
            string v1, v2;
            cin >> v1 >> v2;

            int l = 0, r = v1.size() - 1, cur = 0;

            while (v1[l] == '&')
                l ++, cur --;
            
            while (v1[r] == '*')
                r --, cur ++;
            
            string orig = v1.substr(l, r - l + 1);

            if (mp.find(orig) == mp.end())
                mp[orig] = -100000;
            
            int nval = mp[orig] + cur;
            mp[v2] = (nval >= 0 ? nval : -100000);
        }
        else {
            string v;
            cin >> v;

            int l = 0, r = v.size() - 1, cur = 0;

            while (v[l] == '&')
                l ++, cur --;
            
            while (v[r] == '*')
                r --, cur ++;
            
            string orig = v.substr(l, r - l + 1);

            if (mp.find(orig) == mp.end() || mp[orig] + cur < 0) cout << "errtype";
            else cout << "void" << string(mp[orig] + cur, '*');
            cout << '\n';
        }
    }

    return 0;
}
```
