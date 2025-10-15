"""
如果第一行和最后一行，第一列和最后一列是A， 答案是1

如果中间某一行或者某一列是A， 答案是2， 如果四个角是A， 答案也是2
还有一种情况，是某一行和另外一行拼接出来一行， 那么这种情况下也是2，但是这种情况必须在四个角其中一个有A， 归为第一类

如果是四个边有一个A， 那么答案是3

如果A是在中间，那么答案是4
    
如果全都是P， 那么答案是 MORTAL，  如果全是A， 那么答案是 0
"""
#python 代码：
for _ in range(int(input())):
    r, c = map(int,input().split())
    g = []
    for _ in range(r):
        l = list(input())
        f = [0] * c
        for j in range(c):
            if l[j] == 'A':
                f[j] = 1
        g.append(f)
    if all(g[i][j] for i in range(r) for j in range(c)):
        print(0)
    elif all(g[i][j] == 0 for i in range(r) for j in range(c)):
        print("MORTAL")
    elif all(g[0][j] for j in range(c)) or all(g[r - 1][j] for j in range(c)):
        print(1)
    elif all(g[i][0] for i in range(r)) or all(g[i][c - 1] for i in range(r)):
        print(1)
    elif g[0][0] or g[0][c - 1] or g[r - 1][c - 1] or g[r - 1][0]:
        print(2)
    elif any(all(g[i][j] for j in range(c)) for i in range(1, r - 1)):
        print(2)
    elif any(all(g[i][j] for i in range(r)) for j in range(1, c - 1)):
        print(2)
    elif any(g[0][j] for j in range(c)) or any(g[r - 1][j] for j in range(c)):
        print(3)
    elif any(g[i][0] for i in range(r)) or any(g[i][c - 1] for i in range(r)):
        print(3)
    else:
        print(4)
            
