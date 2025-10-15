import sys
out = []

def solve() :
    global out
    n, m, k = list(map(int, sys.stdin.readline().strip().split()))

    s = [[0] * m for i in range(n)]
    for i in range(n) :
        tmp = sys.stdin.readline().strip()
        for j in range(m) :
            s[i][j] = ord(tmp[j]) - ord('a')
    
    col = [0] * m
    ans = 0
    for i in range(n) :
        for j in range(m) :
            col[j] = 0
        
        for j in range(i, n) :
            for _ in range(m) :
                if s[j][_] == 0 :
                    col[_] += 1
            
            if i == j : 
                continue

            row = [0] * m
            sum = col[0]
            l = 0
            cl = [0] * 26

            if s[i][0] == s[j][0] : 
                cl[s[i][0]] += 1
            
            for r in range(1, m) :
                sum += col[r]
                if s[i][r] == s[j][r] :
                    cl[s[i][r]] += 1
                    if sum <= k:
                        ans += cl[s[i][r]] - 1
                    else :
                        while l < r and sum > k:
                            sum -= col[l]
                            if s[i][l] == s[j][l] :
                                cl[s[i][l]] -= 1
                            l += 1
                        if sum <= k :
                            ans += cl[s[i][r]] - 1
        


    out.append(f'{ans}')
    pass

if __name__ == '__main__' :
    sys.stdin = open('input.txt', 'r')
    sys.stdout = open('output.txt', 'w')
    solve()
    sys.stdout.write('\n'.join(out) + '\n')
