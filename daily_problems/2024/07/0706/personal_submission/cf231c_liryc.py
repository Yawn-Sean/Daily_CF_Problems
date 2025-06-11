'''
https://codeforces.com/contest/231/submission/269003570
231C
2024/7/6 Y1
1600
滑动窗口
'''

def init():
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    return n, k, a

def solve(n: int, k: int, a: list[int]):
    ma, mi = 0, 0
    a.sort()
    i, m, c = 0, a[0], 0
    for j, x in enumerate(a):
        c += (x - m) * (j - i)
        while c > k:
            c -= x - a[i]
            i += 1
        if j - i + 1 > ma:
            ma = j - i + 1
            mi = x
        m = x
    return ma, mi

if __name__ == '__main__':
    args = init()
    ma, mi = solve(*args)
    print(ma, mi)
