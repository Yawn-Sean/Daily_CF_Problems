'''
https://codeforces.com/problemset/submission/815/322932780
'''
# brute-force
def solve(n: int, m: int, grid: list[list[int]]) -> list[int]:
    sm = 0
    za = [True] * (n + m) # False when any of the cell in the row/column is 0

    for i, r in enumerate(grid):
        sm += sum(r)
        for j, x in enumerate(r):
            if x == 0:
                za[i] = za[n + j] = False

    ans = []
    seq = [] 
    if n > m:
        seq = list(range(n, n + m)) + list(range(n))
    else:
        seq = list(range(n + m))
    move = True
    while move:
        move = False
        for ind in seq:
            if za[ind]:
                move = True
                if ind < n:
                    i = ind
                    ans.append(i)
                    for j in range(m):
                        grid[i][j] -= 1
                        if grid[i][j] == 0:
                            za[i] = za[n + j] = False
                    sm -= m
                else:
                    j = ind - n
                    ans.append(~j)
                    for i in range(n):
                        grid[i][j] -= 1
                        if grid[i][j] == 0:
                            za[i] = za[n + j] = False
                    sm -= n
                break 
        if sm == 0: 
            return ans
    return [101] 

def print_ans(ans: list[int]):
    if ans and ans[0] == 101:
        print(-1)
    else:
        print(len(ans))
        for x in ans:
            if x >= 0:
                print("row", x + 1)
            else:
                print("col", ~x + 1)