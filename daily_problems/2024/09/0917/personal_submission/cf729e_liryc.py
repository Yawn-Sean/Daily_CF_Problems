'''
https://codeforces.com/contest/729/submission/281554389
729E
2024/9/17 Y2
1900
Tree, constructive
'''

import sys
input = lambda: sys.stdin.readline().strip()

def init():
    n, s = map(int, input().split())
    a = list(map(int, input().split()))
    return n, s, a

def solve(n: int, s: int, a: list[int]):
    skip, m, lv = 0, 0, 0

    # 起点与报了0的节点要特殊处理
    ## 报了0的虽然明显是错，但仍然可以作为马甲使用，所以不是放到skip，而是手动将报数改成无穷大
    skip = 1
    for i in range(n):
        if i != s - 1 and a[i] == 0:
            a[i] = 999999
    # if a[s - 1] == 0:
    #     skip = a.count(0)
    # else:
    #     skip = a.count(0) + 1

    for i, v in enumerate(sorted(a[j] for j in range(n) if j != s - 1 and a[j] != 0)):
        if i + m == n - skip:
            break
        if v > lv + 1:
            r = n - m - i - skip - 1
            if r >= v - lv - 1:
                m += v - lv - 1
                lv = v
            else:
                m += r + 1
                break
        else:
            if v == lv + 1:
                lv = v

    if a[s - 1] == 0:
        return m + skip - 1
    else:
        return m + skip

if __name__ == '__main__':
    args = init()
    ans = solve(*args)
    print(ans)
