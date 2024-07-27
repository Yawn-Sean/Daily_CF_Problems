import sys
input = lambda: sys.stdin.readline().strip()

def solve():
    pos = [[0] * n for _ in range(26)]
    for i, c in enumerate(a):
        c = ord(c) - 97
        pos[c][i] = 1
    
    sum_pos = [[0] * (n + 1) for _ in range(26)]
    for ps, p in zip(sum_pos, pos):
        for i in range(n):
            ps[i + 1] = ps[i] + p[i]
    
    saved = [[0] * (n + 1) for _ in range(26)]
    for c in range(26): # containing pieces of only colour c
        cnt = n
        for x in range(n, -1, -1):
            ps = sum_pos[c]
            
            def check(k: int) -> bool:
                for i in range(n - k + 1):
                    if k - (ps[i + k] - ps[i]) <= x:
                        return True
                return False
            
            while not check(cnt):
                cnt -= 1                   
            saved[c][x] = cnt
    
       
    for _ in range(int(input())):
        q = input().split()
        x, c = int(q[0]), ord(q[1]) - 97
        print(saved[c][x])
        
for _ in range(1):
    n = int(input())
    a = input()
    solve()