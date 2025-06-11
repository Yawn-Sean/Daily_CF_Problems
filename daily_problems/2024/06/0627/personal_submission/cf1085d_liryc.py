'''
https://codeforces.com/contest/1085/submission/267636014

1085D 2024/6/27 
1700
iq question: count number of leaves
'''

from collections import Counter

def init():
    n, s = map(int, input().split())
    edges = []
    for _ in range(n - 1):
        a, b = map(int, input().split())
        edges.append((a, b))
    return n, s, edges

def solve(n, s, edges):
    cn = Counter()
    for a, b in edges:
        cn[a] += 1
        cn[b] += 1
    return s / sum(cn[t] == 1 for t in range(1, n + 1)) * 2.0

if __name__ == '__main__':
    args = init()
    ans = solve(*args)
    print(ans)
