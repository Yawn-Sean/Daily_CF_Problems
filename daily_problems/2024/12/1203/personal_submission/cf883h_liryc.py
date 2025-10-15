'''
https://codeforces.com/problemset/submission/883/294615306
883H
2024/12/3 Y1
1800
string, BF, implementation
'''
# 直接枚举子字符串的长度
import sys
from collections import Counter
input = lambda: sys.stdin.readline().strip()

def init():
    _ = input()
    s = input()
    return s

def solve(s: str) -> list[str]:
    n = len(s)
    cn = Counter(s)
    a1 = [x for x, c in cn.items() if c & 1]
    if not a1:
        a = [''] * n
        i = 0
        for x, c in cn.items():
            for _ in range(c >> 1):
                a[i] = x
                i += 1
        a[n >> 1:] = a[(n >> 1) - 1::-1]
        return [''.join(a)]
    else:
        y, ans = ' ', []
        for x in a1:
            cn[x] -= 1
        for m in range(n - (n & 1 ^ 1), 2, -2):
            k, mod = divmod(n, m)
            if mod == 0 and k >= len(a1): # 可证此时k - len(a1)必定是偶数，不用if判断
                h = m >> 1
                b = []
                for x, c in cn.items():
                    r = c
                    while r:
                        if not b:
                            if not a1:
                                a1.append(x)
                                a1.append(x)
                                y = x
                                r -= 2
                                continue
                            else:
                                y = a1.pop()
                        t = min(h - len(b), r >> 1)
                        b += [x] * t
                        r -= t * 2
                        if len(b) == h:
                            ans.append(''.join(b + [y] + b[::-1]))
                            b = []
                return ans
    return [c for c in s] # when m == 1

if __name__ == '__main__':
    s = init()
    ans = solve(s)
    print(len(ans))
    print(*ans)
