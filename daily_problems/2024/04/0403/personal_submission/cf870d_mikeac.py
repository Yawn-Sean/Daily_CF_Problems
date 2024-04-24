import sys

# region fastio
input = lambda: sys.stdin.readline().rstrip()
sint = lambda: int(input())
mint = lambda: map(int, input().split())
ints = lambda: list(map(int, input().split()))
# endregion fastio

# MOD = 998_244_353
# MOD = 10 ** 9 + 7
# DIR4 = ((-1, 0), (0, 1), (1, 0), (0, -1)) #URDL
# DIR8 = ((-1, 0), (-1, 1), (0, 1), (1, 1), (1, 0), (1, -1), (0, -1), (-1, -1))

def solve() -> None:
    n = sint()

    r1 = [0] * n
    r2 = [0] * n

    for i in range(n):
        print('?', i, 0, flush=True)
        r1[i] = sint()
    
    r2[0] = r1[0]
    for i in range(1, n):
        print('?', 0, i, flush=True)
        r2[i] = sint()
    
    ans = []
    cnt = 0
    for i in range(n):
        p = [-1] * n
        b = [-1] * n
        
        p[0] = i
        for j in range(n):
            b[j] = r2[j] ^ p[0]
        
        for j in range(n):
            p[j] = r1[j] ^ b[0]

        check = True
        for j in range(n):
            if b[j] >= n or p[b[j]] != j:
                check = False
                break
        if check:
            cnt += 1
            if not ans:
                ans = p
    
    print('!')
    print(cnt)
    print(*ans)


solve()
