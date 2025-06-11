'''
https://codeforces.com/contest/748/submission/284251957
CF748E
2024/10/4 Y2
2100
Counter, math
'''

# from collections import Counter
import sys
input = lambda: sys.stdin.readline().strip()

def init():
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    return n, k, a

def solve(n: int, k: int, a: list[int]) -> int:
    if sum(a) < k:
        return -1
    
    # cn = Counter(a) # 不知道为什么用Counter很慢
    ca = [0] * 10000001
    for x in a:
        ca[x] += 1
    
    m = 0
    for s in range(10000000, -1, -1):
        m += ca[s]
        if s <= 5000000 and ca[s << 1] > 0:
            m += ca[s << 1]
            ca[s] += ca[s << 1] << 1
        if 2 <= s <= 5000000 and ca[s + s - 1] > 0:
            ca[s] += ca[s + s - 1]
            ca[s - 1] += ca[s + s - 1]
        if m >= k:
            return s
    # print(cn)
    # print('k=', k, 'm=', m)

if __name__ == '__main__':
    args = init()
    ans = solve(*args)
    print(ans)
