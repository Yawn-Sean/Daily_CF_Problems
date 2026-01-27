import sys

input = lambda: sys.stdin.readline().rstrip()

def solve():
    t = int(input())
    mod = 10**9 + 7
    
    for _ in range(t):
        k, x = map(int, input().split())
        
        if x == 0:
            print(0)
            continue
            
        v = x.bit_count()
        
        ans = (x % mod * pow(k + 1, v - 1, mod)) % mod
        print(ans)

solve()
