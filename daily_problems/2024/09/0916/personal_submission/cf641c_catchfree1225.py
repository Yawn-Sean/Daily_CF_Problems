import sys
input = lambda: sys.stdin.readline().strip()
MII = lambda: map(int, input().split())

def solve():
    # Key: 1.不考慮相對運動，只考慮原本位置位移(線性)
    #      2.交換奇偶位->分開維護奇數與偶數移動
    # !注意: swap不能直接swap(even, odd)，要維護原本的位置
    # (只能透過flg判斷位移)
    
    even = odd = flg = 0
    for _ in range(q):
        x = tuple(MII())
        if x[0] == 1:
            odd += x[1]
            even += x[1]
            flg ^= x[1] % 2
        else:
            if not flg:
                odd += 1
                even -= 1
            else:
                odd -= 1
                even += 1
            flg ^= 1

    ans = [-1] * n
    for i in range(n):
        x = i + 1
        diff = odd if x % 2 else even
        ans[(i + diff) % n] = x
    print(*ans)
               
for _ in range(1):
    n, q = MII()
    solve()