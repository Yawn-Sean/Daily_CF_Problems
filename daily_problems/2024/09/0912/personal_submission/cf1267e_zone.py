# submission url: https://codeforces.com/contest/1267/submission/280795168

n, m = map(int, input().split()) 
a = [list(map(int, input().split())) for _ in range(m)]

ans = list(range(m))

for i in range(n - 1):
    b = [a[j][i] - a[j][-1] for j in range(m)]
    s = sum(b)
    if s >= 0: 
        print(0)
        exit() 
    c = sorted(range(m), key=lambda x: -b[x])
    res = []
    while s < 0: 
        s -= b[c[-1]]
        res.append(c[-1])
        c.pop() 
    if len(res) < len(ans): 
        ans = res 

print(len(ans))
print(' '.join(str(x + 1) for x in ans))
