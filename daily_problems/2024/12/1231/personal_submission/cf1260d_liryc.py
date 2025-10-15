'''
https://codeforces.com/problemset/submission/1260/299146354
1260D
2024/12/31 Y2
1900
binary search
'''
# 二分下界：可以在t秒内到达终点的最低agility
from bisect import bisect_left
from heapq import heappop, heappush
import sys
input = lambda: sys.stdin.readline().strip()

def init():
    m, n, k, t = map(int, input().split())
    a = list(map(int, input().split()))
    traps = []
    for _ in range(k):
        l, r, d = map(int, input().split())
        traps.append([l, r, d])
    return m, n, k, t, a, traps

def solve(m: int, n: int, k: int, t: int, a: list[int], traps: list[list[int]]) -> int:
    a.sort()
    
    # 基于优先队列构建难度数组，不需要在每次搜索中构建差分
    hp = []
    th = [0] * (n + 2) # threshold
    st = list(sorted(range(k), key = lambda i: traps[i][0]))
    j = 0
    for i in range(1, n + 1):
        while hp and hp[0][1] < i:
            heappop(hp)
        while j < k and traps[st[j]][0] <= i:
            heappush(hp, (-traps[st[j]][2], traps[st[j]][1]))
            j += 1
        if hp:
            th[i] = -hp[0][0]
    
    # 二分查找下界模板
    def check(mi):
        nonlocal n, t, a, th
        min_agility = a[mi]
        s = 0
        for i in range(1, n + 2):
            s += 1
            if th[i] > min_agility:
                s += 2
        return s <= t
    min_agility_index = bisect_left(range(m), True, key=check)
    return m - min_agility_index

if __name__ == '__main__':
    args = init()
    ans = solve(*args)
    print(ans)