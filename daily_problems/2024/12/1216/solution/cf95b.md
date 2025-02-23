**提示 1：** 有两种更大的可能：位数更多 / 位数一样但字典序更大。

**提示 2：** 先识别是哪种可能，再贪心地填。

数字更大有两种可能：位数更多 / 位数一样且字典序更大。

因为 $4,7$ 出现的频率要求是相等的，因此总位数总是偶数。于是如果初始数字长度是奇数，直接返回多一位的最小的满足条件的数，即 $44\dots 477\dots 7$。

否则，我们可以将当前的数和 $77\dots 744\dots 4$ 比较，因为这是对应位数的最大的数。如果这个数比我们原数小，则当前位数无法找到答案，我们选择将位数 $+2$ 再输出最小的数。

接下来总能在当前位数找到答案。因为我们要数字尽可能小，因此应该从头到尾遍历。而一旦有一个字符严格更大了，后面就没有任何限制了。因此遍历过程中，我们维护剩余 $4$ 的数量， $7$ 的数量，数字是否已经严格更大。

具体而言模拟过程如下——

- 如果已经严格更大了，直接贪心取剩下的字符中最小的。

- 否则，如果能填 $4$ ，且我们还有 $4$ ，我们就先填 $4$ 。如果能填 $7$ ，则填 $7$ 。注意这步可能需要更新数字是否已经严格更大。

- 如果填不了了怎么办呢？**这就意味着之前的一个 $4$ 得改成 $7$** ，我们不断回退，直到找到一个可以改成 $7$ 的 $4$ （保证回退到这个位置时是有 $7$ 的），再从这个位置开始重新模拟。

时间复杂度为 $\mathcal{O}(|s|)$ 。

### 具体代码如下——

Python 做法如下——

```Python []
def main():
    s = I()
    n = len(s)

    if n % 2:
        x = (n + 1) // 2
        print('4' * x + '7' * x)

    else:
        x = n // 2
        tmp = '7' * x + '4' * x
        if tmp < s: print('4' * (x + 1) + '7' * (x + 1))
        else:
            ans = [''] * n
            c4 = x
            c7 = x
            flg = False
            for i in range(n):
                if flg:
                    if c4:
                        ans[i] = '4'
                        c4 -= 1
                    else:
                        ans[i] = '7'
                        c7 -= 1
                else:
                    if s[i] == '4':
                        if c4:
                            ans[i] = '4'
                            c4 -= 1
                        else:
                            flg = True
                            ans[i] = '7'
                            c7 -= 1
                    elif s[i] > '4' and s[i] <= '7' and c7:
                        if s[i] != '7':
                            flg = True
                        ans[i] = '7'
                        c7 -= 1
                    elif s[i] > '4':
                        for j in range(i - 1, -1, -1):
                            if ans[j] == '4':
                                if c7:
                                    c4 += 1
                                    ans[j] = '7'
                                    c7 -= 1
                                    for k in range(j + 1, n):
                                        if c4: 
                                            ans[k] = '4'
                                            c4 -= 1
                                        else:
                                            ans[k] = '7'
                                            c7 -= 1
                                    break
                                else:
                                    c4 += 1
                            else:
                                c7 += 1
                        break
                    else:
                        flg = True
                        if c4:
                            ans[i] = '4'
                            c4 -= 1
                        else:
                            ans[i] = '7'
                            c7 -= 1
            print(''.join(ans))
```

C++ 做法如下——

```cpp []
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;
    int n = s.size();

    if (n & 1) {
        int x = (n + 1) / 2;
        cout << string(x, '4') << string(x, '7');
    }
    else {
        int x = n / 2;
        if (string(x, '7') + string(x, '4') < s)
            cout << string(x + 1, '4') << string(x + 1, '7');
        else {
            string ans = s;
            int c4 = x, c7 = x;
            bool flg = false;

            for (int i = 0; i < n; i ++) {
                if (flg) {
                    if (c4) ans[i] = '4', c4 --;
                    else ans[i] = '7', c7 --;
                }
                else {
                    if (s[i] == '4') {
                        if (c4) ans[i] = '4', c4 --;
                        else ans[i] = '7', c7 --, flg = true;
                    }
                    else if (s[i] > '4' && s[i] <= '7' && c7) {
                        if (s[i] != '7') flg = true;
                        ans[i] = '7', c7 --;
                    }
                    else if (s[i] > '4') {
                        flg = true;
                        for (int j = i - 1; j >= 0; j --) {
                            if (ans[j] == '4') {
                                if (c7) {
                                    c4 ++, c7 --, ans[j] = '7';
                                    i = j;
                                    break;
                                }
                                else c4 ++;
                            }
                            else c7 ++;
                        }
                    }
                    else {
                        flg = true;
                        if (c4) ans[i] = '4', c4 --;
                        else ans[i] = '7', c7 --;
                    }
                }
            }
            cout << ans;
        }
    }

    return 0;
}
```
