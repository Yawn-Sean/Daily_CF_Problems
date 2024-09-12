'''
https://codeforces.com/contest/1267/submission/280800227
1267 E
2024/9/12 Y1
1700
sorting, enumeration
'''

import sys
input = lambda: sys.stdin.readline().strip()

def init():
    n, m = map(int, input().split())
    a = []
    for _ in range(m):
        l = list(map(int, input().split()))
        a.append(l)
    return n, m, a

def solve(n: int, m: int, a: list[list[int]]) -> list[int]:
    ans = list(range(m))
    for i in range(n - 1):
        ca = list(sorted((a[r][-1] - a[r][i], r) for r in range(m)))
        k, sm = 0, 0
        while k < m and sm - ca[k][0] >= 0:
            sm -= ca[k][0]
            k += 1
        ca = list(r for _, r in ca[k:])
        if len(ca) < len(ans):
            ans = ca

        # 如果只需要输出结果可以如下一行搞定
        # max(j for j, sm in enumerate(accumulate(sorted((a[r][i] - a[r][-1] for r in range(m)), reverse=True))) if sm >= 0)

    return [x + 1 for x in ans]

if __name__ == '__main__':
    args = init()
    ans = solve(*args)
    print(len(ans))
    if ans:
        print(*ans)
