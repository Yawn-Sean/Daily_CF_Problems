'''
https://codeforces.com/problemset/submission/1482/301317983
1482C
2025/1/17 Y1
1600
constructive
'''
# 2 candidates enough
from collections import Counter, defaultdict, deque
import sys
input = lambda: sys.stdin.readline().strip()

def init():
    n, m = map(int, input().split())
    a = []
    for _ in range(m):
        a.append(list(map(int, input().split()))[1:])
    return n, m, a

def solve(n: int, m: int, a: list[list[int]]):
    di = defaultdict(deque)
    cnt = Counter()
    ans = [0] * m
    for i in range(m):
        r = a[i]
        x = r[0]
        replace = 0
        if cnt[x] == m + 1 >> 1:
            if len(r) > 1:
                x = r[1]
                if len(r) > 2:
                    replace = r[2]
            elif di[x]:
                j, y = di[x].pop()
                cnt[x] -= 1
                cnt[y] += 1
                ans[j] = y
            else:
                return []
        elif len(r) > 1:
            replace = r[1]
        ans[i] = x
        cnt[x] += 1
        if replace:
            di[x].append((i, replace))
    return ans

if __name__ == '__main__':
    for _ in range(int(input())):
        args = init()
        ans = solve(*args)
        if ans:
            print("YES")
            print(*ans)
        else:
            print("NO")
