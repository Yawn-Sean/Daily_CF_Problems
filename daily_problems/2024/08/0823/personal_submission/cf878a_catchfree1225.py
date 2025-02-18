import sys
input = lambda: sys.stdin.readline().strip()

def solve():
    # key: 計算技巧，位運算對每個bit是同步的
    # 沒給原本的數，怎麼累計操作? A:找全0(v0)與全1(v1)
    # 先對v1做and(移除掉v0的影響): and(v0^v1)
    # 再補上v0的結果: xor(v0)
    # '不可'使用: and(v1&~v0), or(v0)
    # (xor才會可逆，不會變不見v0)
    
    v0, v1 = 0, 1023
    for _ in range(n):
        op, x = input().split()
        x = int(x)
        if op == '&':
            v0 &= x
            v1 &= x
        elif op == '|':
            v0 |= x
            v1 |= x
        else:
            v0 ^= x
            v1 ^= x
    
    print(2)
    print('&', v1 ^ v0)
    print('^', v0)
               
for _ in range(1):
    n = int(input())
    solve()