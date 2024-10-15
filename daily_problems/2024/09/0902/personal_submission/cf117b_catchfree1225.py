import sys
input = lambda: sys.stdin.readline().strip()
MII = lambda: map(int, input().split())

def solve():
    # key: 取模等價可以移項!
    # s2 != -s1*10**9 (%mod)
    # (因為給定上限，判斷s2>b即可獲勝)
    
    mt = 10**9 % mod
    s2 = 0
    for i in range(min(a + 1, mod)):
        if s2 > b:
            print(1, str(i).zfill(9))
            return
        s2 = (s2 - mt) % mod
    print(2)    
           
for _ in range(1):
    a, b, mod = MII()
    solve()