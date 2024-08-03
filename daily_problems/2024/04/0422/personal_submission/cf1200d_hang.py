# 好像写了一坨答辩 
# https://codeforces.com/contest/1200/submission/257678882
def main():
    n,k = map(int,input().split())
    g = []
    g.append([])
    for _ in range(n):
        s = input()
        z = [0] + [0 if x == 'B' else 1 for x in s]
        g.append(z)
    row = [0]*(n+1)
    col = [0]*(n+1)
    for i in range(1,n+1):
        if all(x == 1 for x in g[i][1:]):
            row[i] = 1
        row[i] += row[i-1]
    for j in range(1,n+1):
        for i in range(1, n+1):
            
            col[j] += g[i][j]
        if col[j] == n:
            col[j] = 1
        else:
            col[j] = 0
        col[j] += col[j-1]
    

    row_b = []
    
    row_b.append([0,0])
    for i in range(1,n+1):
        r = []
        row_b.append(r)
        for j in range(1,n+1):
            if g[i][j] == 0:
                if len(r) < 2:
                    r.append(j)
                else:
                    r[-1] = j
    ans = [[0] * (n+1) for _ in range(n+1)]
    
    for j in range(k, n+1):
        pre = 0
        for i in range(1, n+1):

            if len(row_b[i]) == 0:
                pre += 1
            elif row_b[i][-1] <= j and row_b[i][0] >= j-k+1:
                pre += 1
            if i >= k:
                if len(row_b[i-k]) == 0 or (row_b[i-k][-1] <= j and row_b[i-k][0] >= j-k+1):
                    pre -= 1
                row_lines = row[i-k] + row[-1] - row[i]
                ans[i][j] += pre + row_lines
    
    col_b = []
    col_b.append([0,0])    
    for j in range(1,n+1):
        r = []
        col_b.append(r)
        for i in range(1,n+1):
            if g[i][j] == 0:
                if len(r) < 2:
                    r.append(i)
                else:
                    r[-1] = i

    
    for i in range(k, n+1):
        pre = 0
        for j in range(1, n+1):

            if len(col_b[j]) == 0:
                pre += 1
            elif col_b[j][-1] <= i and col_b[j][0] >= i-k+1:
                pre += 1
            if j >= k:
                if len(col_b[j-k]) == 0 or (col_b[j-k][-1] <= i and col_b[j-k][0] >= i-k+1):
                    pre -= 1
                col_lines = col[j-k] + col[-1] - col[j]
                ans[i][j] += pre + col_lines
    print(max(max(x) for x in ans))
main()