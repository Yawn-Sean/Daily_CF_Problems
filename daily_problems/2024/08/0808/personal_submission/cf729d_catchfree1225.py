import sys
input = lambda: sys.stdin.readline().strip()
MII = lambda: map(int, input().split())

def solve():
    # key: 至少打中一個目標=排除剩下全部
    # 枚舉所有船下標，移除(a-1)個，至少能打中一個(鴿籠)
    boats = []
    cur = 0 # 避免邊界條件，討論累積量
    for i, x in enumerate(s, 1):
        if x == '0':
            cur += 1
            if cur == b:
                boats.append(i)
                cur = 0
        else:
            cur = 0
    
    cnt = len(boats) - (a - 1)
    print(cnt)
    print(*boats[:cnt])
               
for _ in range(1):
    n, a, b, k = MII()
    s = input()
    solve()