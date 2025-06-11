t = II()
outs = []

for _ in range(t):
    n, m = MII()
    s = []
    cntr = []
    for _ in range(n):
        s.append(I())
        cntr.append(s[-1].count('A'))
    
    x = sum(cntr)
    if x == n * m:
        outs.append(0)
        continue

    cntl = []
    for j in range(m):
        cntl.append(sum(s[i][j] == 'A' for i in range(n)))
    
    if cntr[0] == m or cntr[-1] == m or cntl[0] == n or cntl[-1] == n:
        outs.append(1)
    else:
        
        tmp = int(s[0][0] == 'A') + int(s[0][-1] == 'A') + int(s[-1][0] == 'A') + int(s[-1][-1] == 'A')
        if tmp:
            outs.append(2)
        else:
            flg = False
            for i in range(1, n - 1):
                if cntr[i] == m:
                    flg = True
            for j in range(1, m - 1):
                if cntl[j] == n:
                    flg = True
            if flg:
                outs.append(2)
            else:
                if cntr[0] or cntr[-1] or cntl[0] or cntl[-1]:
                    outs.append(3)
                else:
                    if x:
                        outs.append(4)
                    else:
                        outs.append("MORTAL")

print('\n'.join(map(str, outs)))
