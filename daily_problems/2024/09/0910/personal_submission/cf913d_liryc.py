'''
https://codeforces.com/contest/913/submission/280524927
913D
2024/9/10 Y1
1800
Binary Search 
'''

from bisect import bisect_right
import sys
input = lambda: sys.stdin.readline().strip()

def init():
    n, T = map(int, input().split())
    a, t = [], []
    for _ in range(n):
        x, y = map(int, input().split())
        a.append(x)
        t.append(y)
    return n, T, a, t

def solve(n: int, T: int, a: list[int], t: list[int]):
    si = list(sorted(range(n), key = lambda i: t[i]))
    def check(k):
        nonlocal si, T, a, t
        if k == 0:
            return False
        c, sm = 0, 0
        for i in si:
            if a[i] >= k:
                c += 1
                sm += t[i]
                if sm > T:
                    # print("check", k, i, sm, False)
                    return True
                if c == k:
                    # print("check", k, i, sm, True)
                    break # return False
        return c != k # False
    k = bisect_right(range(n + 1), False, key = check) - 1
    # print(si)
    # print('k=', k)
    return [i + 1 for i in si if a[i] >= k][:k]

if __name__ == '__main__':
    args = init()
    ans = solve(*args)
    print(len(ans))
    print(len(ans))
    if ans:
        print(*ans)
