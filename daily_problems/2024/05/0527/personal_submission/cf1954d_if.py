import sys
input = sys.stdin.buffer.readline
n = int(input())
a = list(map(int,input().split()))
sm = sum(a)
nb_sb = [[0] * (sm+1) for _ in range(n+1)]
nb_sb[0][0] = 1
for i, ai in enumerate(a, 1):
    for j in range(sm+1):
        nb_sb[i][j] = nb_sb[i-1][j]
        if j-ai >= 0:
            nb_sb[i][j] += nb_sb[i-1][j-ai]
        nb_sb[i][j] %= 998244353
ans = 0
for j in range(sm+1):
    ans += nb_sb[n][j] * ((j+1)//2)
    ans %= 998244353
for ai in a:
    for j in range(ai):
        ans += nb_sb[n][j] * (ai - ((ai+j+1)//2))
        ans %= 998244353
print(ans)
