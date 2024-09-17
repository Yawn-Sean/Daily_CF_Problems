# submission url: https://codeforces.com/contest/641/submission/281427456

n, q = map(int, input().split())
x = cnt = 0

for _ in range(q): 
    op = list(map(int, input().split()))
    if op[0] == 2: 
        if ((x + cnt) % n) % 2: 
            cnt -= 1 
        else:
            cnt += 1
    else:
        x += op[1] 
ans = [-1] * n 
for i in range(n):
    pos = (x + cnt + i) % n
    ans[pos] = i + 1
    cnt *= -1 
print(' '.join(str(x) for x in ans))
