'''
https://codeforces.com/contest/1227/submission/284866147
2272D2
2024/10/8 Y1
1800
Greedy, Fenwick Tree
'''

import sys
input = lambda: sys.stdin.readline().strip()

# class FenwickTree:
    
def solve():
    n = int(input())
    nums = list(map(int, input().split()))
    st_range = sorted(range(n), key=lambda x: -nums[x])

    xs = []
    queries = [[] for _ in range(n)]

    q = int(input())
    for i in range(q):
        k, x = map(int, input().split())
        queries[k - 1].append(i)
        xs.append(x)

    ans = [-1] * q
    fen = FenwickTree(n)

    for i in range(n):
        fen.add(st_range[i], 1)
        
        for q_id in queries[i]:
            ans[q_id] = nums[fen.lower_bound(xs[q_id])]

    return ans

if __name__ == '__main__':
    ans = solve()
    print(*ans, sep='\n')
