
def f1():
    global p 
    for i in range(n):
        newp[q[i]] = p[i]
    p = newp[::]

def f2():
    global p 
    for i in range(n):
        newp[i] = p[q[i]]
    p = newp[::]

n, k = MII()
q, s = LGMI(), LGMI()
p = [i for i in range(n)]

if p == s:
    print("NO")
else:
    flg = False
    newp = [0] * n
    for i in range(k):
        f1()
        if p == s:
            if i and (k - i - 1) % 2 == 0:
                flg = True
                break
            if i == 0:
                if k == 1:
                    flg = True
                    break
                f2()
                f2()
                if p != s:
                    if k % 2:
                        flg = True
                break

    newp = [0] * n
    p = [i for i in range(n)]
    for i in range(k):
        f2()
        if p == s:
            if i and (k - i - 1) % 2 == 0:
                flg = True
                break
            if i == 0:
                if k == 1:
                    flg = True
                    break
                f1()
                f1()
                if p != s:
                    if k % 2:
                        flg = True
                break

    if flg:
        print("YES")
    else:
        print("NO")
