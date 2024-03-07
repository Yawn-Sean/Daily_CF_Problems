from sys import stdin
input = lambda: stdin.readline().rstrip()

# 预处理出最大位数
MAXD = [0, 0, 59, 37, 29, 25, 23, 21, 19, 18, 17]
memo = [[[-1] * (1<<base) for _ in range(MAXD[base])] for base in range(11)]

def cvt(x, base):
    res = []
    while x:
        res.append(x % base)
        x //= base
    return res

def solve():
    base, lo, hi = map(int, input().split())
    hidigits = cvt(hi, base)
    n = len(hidigits)
    lodigits = cvt(lo, base)
    lodigits += [0] * (n - len(lodigits))

    def f(i: int, mask: int, lolim: bool, hilim: bool, isnum: bool):
        if i == -1:
            return int(mask == 0)
        # 奇偶性不满足要求时提前返回0
        if i % 2 == 0 and not isnum:
            return f(i-1, 0, True, False, False) if lodigits[i] == 0 else 0
        if not lolim and not hilim and isnum and memo[base][i][mask] != -1:
            return memo[base][i][mask]
        lod = lodigits[i] if lolim else 0
        hid = hidigits[i] if hilim else base-1
        res = 0
        for d in range(lod, hid+1):
            res += f(i-1, mask^(1<<d) if (isnum or d != 0) else mask, lolim and d == lod, hilim and d == hid, isnum or d != 0)
        if not lolim and not hilim and isnum:
            memo[base][i][mask] = res
        return res

    return f(n-1, 0, True, True, False)

T = int(input())
# 用一个generator保存答案然后直接打印，避免频繁输出
ans = (solve() for _ in range(T))
print(*ans, sep='\n')