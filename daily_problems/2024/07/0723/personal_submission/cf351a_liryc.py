'''
https://codeforces.com/contest/351/submission/272010993
351A
2024/7/23 Y1
1800
一开始想错了，留意是和的绝对值差，不是绝对值差的和
'''

if __name__ == '__main__':
    n = int(input())
    a = [int(t.split('.')[1]) for t in input().split()]
    c1 = sum(1 for x in a if x)
    sm = sum(a)
    lo, hi = 0 if c1 <= n else c1 - n, min(c1, n)
    ans = min(abs(sm - c * 1000) for c in range(lo, hi + 1))
    print(f"{(ans / 1000):.3f}")