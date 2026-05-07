def solve():
    n=II()
    s=I()
    cnt = Counter(s)
    if len(cnt)==1:
        return print('NO')
    elif len(cnt)==2:
        return print('YES')
    else:
        return print('YES' if n>=4 else 'NO')

T = 1
T = II()
result=[]
for _ in range(T):
    solve()
