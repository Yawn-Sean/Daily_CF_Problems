
import sys
read = lambda : map(int, sys.stdin.readline().split())
out = []

def solve() :
    global out
    n, m = read()
    s = [[0] * m for _ in range(n)]

    xmi = [n] * 26
    xmx = [-1] * 26
    ymi = [m] * 26
    ymx = [-1] * 26

    ans = []
    for i in range(n) :
        s1 = sys.stdin.readline().strip()
        for j in range(m) :
            if s1[j] != '.' :
                s[i][j] = ord(s1[j]) - ord('a')
                if xmi[s[i][j]] > i :
                    xmi[s[i][j]] = i
                if xmx[s[i][j]] < i :
                    xmx[s[i][j]] = i
                if ymi[s[i][j]] > j :
                    ymi[s[i][j]] = j
                if ymx[s[i][j]] < j :
                    ymx[s[i][j]] = j
                
            else : s[i][j] = -1



    for i in range(25, -1, -1) :
        if xmx[i] == -1 :
            if len(ans) > 0 :
                ans.append(ans[-1])
            continue

        if xmi[i] == xmx[i] or ymi[i] == ymx[i] :
            if xmi[i] == xmx[i] :
                for j in range(ymi[i], ymx[i] + 1) :
                    if s[xmi[i]][j] != -1 and s[xmi[i]][j] >= i :
                        continue
                    else :
                        out.append('NO')
                        return
                ans.append((xmi[i] + 1, ymi[i] + 1, xmi[i] + 1, ymx[i] + 1))
            else :
                for j in range(xmi[i], xmx[i] + 1) :
                    if s[j][ymi[i]] != -1 and s[j][ymi[i]] >= i :
                        continue
                    else :
                        out.append('NO')
                        return
                ans.append((xmi[i] + 1, ymi[i] + 1, xmx[i] + 1, ymx[i] + 1))
        else : 
            out.append('NO')
            return 


    out.append('YES') 
    out.append(f'{len(ans)}') 
    ans = reversed(ans)
    for x1, y1, x2, y2 in ans :
        out.append(f'{x1} {y1} {x2} {y2}') 

    pass


if __name__ == '__main__' :
    t = int(sys.stdin.readline().strip())
    while t > 0 :
        t -= 1
        solve()
    sys.stdout.write('\n'.join(out) + '\n')
