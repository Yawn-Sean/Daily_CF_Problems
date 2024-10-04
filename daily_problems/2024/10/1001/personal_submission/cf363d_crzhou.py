from bisect import bisect_left
import sys
input = lambda: sys.stdin.readline().strip()

def I():
    return input()

def II():
    return int(input())

def MII():
    return map(int, input().split())

def LI():
    return list(input().split())

def LII():
    return list(map(int, input().split()))

def LFI():
    return list(map(float, input().split()))

def GMI():
    return map(lambda x: int(x) - 1, input().split())

def LGMI():
    return list(map(lambda x: int(x) - 1, input().split()))

fmax = lambda x, y: x if x > y else y
fmin = lambda x, y: x if x < y else y

def check(x: int) -> bool:
    tmpa = all
    for i in range(x):
        if stus[x - 1 - i] < bics[i]:
            tmpa -= bics[i] - stus[x - 1 - i]
            if tmpa < 0:
                return True     # 不能租到 x 辆车
    return False                # 能租到 x 辆车

n, m, all = MII()
stus = LII()
bics = LII()
stus.sort(reverse=True)
bics.sort()

ans0 = bisect_left(range(fmin(n, m) + 1), True, key=check) - 1
ans1 = sum(bics[:ans0]) - all
if ans1 < 0:
    ans1 = 0
print(ans0, ans1)
