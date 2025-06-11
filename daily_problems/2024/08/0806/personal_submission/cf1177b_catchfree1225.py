import sys
input = lambda: sys.stdin.readline().strip()

def solve():
    k = int(input()) - 1 # 一律計算offset
    i = 0
    while True:
        cnt = 9 * 10**i # 當層數字數
        bit_cnt = cnt * (i + 1) # # 當層總位數
        if k < bit_cnt: 
            break
        k -= bit_cnt
        i += 1
    
    p, q = divmod(k, i + 1)
    num = str(10**i + p)
    print(num[q])
               
for _ in range(1):
    solve()