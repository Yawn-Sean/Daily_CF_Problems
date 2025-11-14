'''
https://codeforces.com/gym/104671/submission/348765898
'''
# 分析数组每个元素x的每一位：若bit(k)==1,则bit(x)也必须是1，若bit(k)==0，则至少要有一个bit(x)==0
# 于是维护每一位的前缀和，维护该位0的数量
from sys import stdin
input = lambda: stdin.readline().strip()

def init():
    n, k, q = map(int, input().split())
    a = list(map(int, input().split()))
    kb = [k >> i & 1 for i in range(30)]
    ps = [[] if b else [0] * n for b in kb]
    for i, x in enumerate(a):
        if (k & x) == k: 
            for j in range(30):
                if not kb[j]:
                    ps[j][i] = 1 - (x >> j & 1)
        if i:
            for j in range(30):
                if not kb[j]:
                    ps[j][i] += ps[j][i - 1]
    return n, k, q, a, ps

# 当k==2^30-1时ps为空，会导致原本判断失效
def init2(a):
    ps = [0] * len(a)
    for i, x in enumerate(a):
        ps[i] = x == 1073741823
        if i:
            ps[i] += ps[i - 1]
    return ps

# each k=0 bit must have at least one 0
# easily calc using prefix sum
def solve(ps, l, r):
    for i in range(30):
        if ps[i]:
            c = ps[i][r]
            if l:
                c -= ps[i][l - 1]
            if c == 0:
                return False
    return True

# special solve for init2()
def solve2(ps, l, r):
    c = ps[r]
    if l:
        c -= ps[l - 1] 
    return c

if __name__ == '__main__':
    n, k, q, a, ps = init()
    if k == 1073741823:
        ps_k = init2(a)
    for _ in range(q):
        l, r = map(int, input().split())
        l, r = l - 1, r - 1
        if k == 1073741823:
            ans = solve2(ps_k, l, r)
        else: 
            ans = solve(ps, l, r)
        print("YES" if ans else "NO")
