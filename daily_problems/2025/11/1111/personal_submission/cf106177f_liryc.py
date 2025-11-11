'''
https://codeforces.com/gym/106177/submission/348439840
'''
# t0和t1分别表示子数组中偶数和奇数的个数，那么
# 要么t0=2k, t1=2k+1，要么t0=2k+1, t1=2k
# pd: t0-t1的前缀和
# pp: t0奇偶性的前缀和

class SeqCounter:
    def __init__(self, lo, hi):
        self.arr = [0] * (hi - lo + 1)
        self.inc = -lo

    def __getitem__(self, index):
        return self.arr[index + self.inc]

    def __setitem__(self, index, value):
        self.arr[index + self.inc] = value

def solve(n: int, a: list[int]) -> int:
    cn = [SeqCounter(-n - 1, n + 1), SeqCounter(-n - 1, n + 1)]
    ans, d, t0, t1 = 0, 0, 0, 0
    cn[0][0] = 1
    for x in a:
        if x & 1:
            t1 += 1
            d -= 1
        else:
            t0 += 1
            d += 1
        ans += cn[t0 & 1][d + 1]
        ans += cn[t0 & 1 ^ 1][d - 1]
        cn[t0 & 1][d] += 1
    return ans
