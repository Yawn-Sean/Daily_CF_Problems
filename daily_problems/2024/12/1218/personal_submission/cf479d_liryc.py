'''
https://codeforces.com/problemset/submission/479/297111384
479D
2024/12/18 Y1
1700
sliding window
'''
# 滑动窗口
import sys
input = lambda: sys.stdin.readline().strip()

def init():
    n, l, x, y = map(int, input().split())
    a = list(map(int, input().split()))
    return n, l, x, y, a

def solve(n, l, x, y, a):
    def search1(d):
        nonlocal a
        i = 0
        for j in range(1, len(a)):
            while a[j] - a[i] > d:
                i += 1
            if a[j] - a[i] == d:
                return a[j]
        return 0
    
    def search2(d):
        nonlocal a, y, l
        i = 0
        for j in range(1, len(a)):
            while a[j] - a[i] > d:
                i += 1
            if a[j] - a[i] == d:
                if a[j] >= y:
                    return a[j] - y
                elif a[i] + y <= l:
                    return a[i] + y
        return 0
    
    fx, fy = search1(x), search1(y)
    if fx and fy:
        return []
    elif fx or fy:
        return [x] if fy else [y]
    else:
        f = search2(y - x)
        if f:
            return [f]
        else:
            f = search1(x + y)
            if f:
                return [f - y]
    return [x, y]

if __name__ == '__main__':
    args = init()
    ans = solve(*args)
    if ans:
        print(len(ans))
        print(*ans)
    else:
        print(0)
