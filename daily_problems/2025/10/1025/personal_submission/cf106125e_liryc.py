'''
https://codeforces.com/gym/106125/submission/345739115
'''
# 最长子数组和问题

def query(l: int, r: int):
    print(l + 1, r + 1, flush=True)
    a = list(map(int, input().split()))
    p = int(input())
    return p, a

def solve(n: int):
    a = [0] * n
    p = 0
    while p < 70:
        max_l, max_r, max_s, l, s = 0, 0, 0, 0, 0
        for r, x in enumerate(a):
            if s < 0:
                l, s = r, 0
            s += -1 if x else 1
            if s > max_s or s == max_s and r - l > max_r - max_l:
                max_l, max_r, max_s = l, r, s
        p, a = query(max_l, max_r)
