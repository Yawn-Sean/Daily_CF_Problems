import sys

MI = lambda : int(sys.stdin.readline().strip())
MII = lambda : map(int, sys.stdin.readline().split())

out = []
def solve() :
    global out
    s = sys.stdin.readline().strip().split(',')
    L = [[] for _ in range(10**6 + 10)]
    i = 0
    cnt = 0
    f = [0]
    f = [0] * 10 ** 6
    while i < len(s) :
        t = f[-1]
        if t > cnt : cnt = t
        f.pop()
        L[t].append(s[i])
        c1 = int(s[i + 1])
        i += 2
        for j in range(c1) :
            f.append(t + 1)
    
    out.append(f'{cnt + 1}\n') 
    for i in range(cnt + 1) :
        for j in range(len(L[i])) :
            out.append(L[i][j] + (' ' if j != len(L[i]) - 1 else '\n')) 
    pass


if __name__ == '__main__' :
    
    solve()
    sys.stdout.write(''.join(out))
