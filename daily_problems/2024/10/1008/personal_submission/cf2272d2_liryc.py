'''
https://codeforces.com/contest/1227/submission/284866147
2272D2
2024/10/8 Y1
1800
Greedy, Fenwick Tree
'''

import sys
input = lambda: sys.stdin.readline().strip()

class FenwickTree:
    def __init__(self, n):
        self.n = n
        self.bit = [0] * n
        length = (self.n + 1).bit_length() - 1
        self.powers = [1 << i for i in range(length, -1, -1)]
        self.total = 0

    def sum(self, r):
        res = 0
        while r >= 0:
            res += self.bit[r]
            r = (r & r + 1) - 1
        return res

    def rangesum(self, l, r):
        return self.sum(r) - self.sum(l - 1)

    def add(self, idx, delta):
        while idx < self.n:
            self.bit[idx] += delta
            idx |= idx + 1
        self.total += delta

    def lower_bound(self, num):
        if num <= 0: return -1
        note, tmp = -1, 0
        for power in self.powers:
            if note + power >= self.n or tmp + self.bit[note + power] >= num: continue
            note += power
            tmp += self.bit[note]
        return note + 1

    def upper_bound(self, num):
        if num > self.total: return self.n
        note = -1
        tmp = 0
        for power in self.powers:
            if note + power >= self.n or tmp + self.bit[note + power] >= num: continue
            note += power
            tmp += self.bit[note]
        return note
    
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
