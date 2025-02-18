import sys
input = lambda: sys.stdin.readline().strip()
MII = lambda: map(int, input().split())
    
def solve():
    # 題目給遞迴關係式: 看1.初始值2.遞迴關係
    # key1: a1=b1, a,b為嚴格遞增
    # key2: bit操作是同步的，可以分開討論
    #       觀察最高bit，被抵銷一定變小!
    # 問題轉換成討論最高bit是否等於1，ai,bi最高bit相同
    # 放k個項，可選可不選，range(ai) = [2^k, min(2^(k+1) - 1, d)]
    ans = 1
    for p in range(d.bit_length()):
        seg_ai = min((1 << (p + 1)) - 1, d) - (1 << p) + 1
        ans = ans * (seg_ai + 1) % MOD
    
    ans = (ans - 1) % MOD # 不可空
    print(ans)
     
for _ in range(int(input())):
    d, MOD = MII()
    solve()