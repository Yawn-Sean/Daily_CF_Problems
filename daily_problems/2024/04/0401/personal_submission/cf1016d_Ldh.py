def solve(testcase):
    n, m = MI()
    A = LII()
    B = LII()
    check = 0
    for a in A:
        check ^= a
    for b in B:
        check ^= b
    if (check):
        print("NO")
        return
    
    print("YES")
    res = [[0 for _ in range(m)] for _ in range(n)]
    t = 0
    for j in range(m - 1):
        res[0][j] = B[j]
        t ^= B[j]
    res[0][-1]= A[0] ^ t
    t = res[0][-1]
    for i in range(1, n - 1):
        res[i][-1] = A[i]
        t ^= A[i]
    res[-1][-1] = t ^ B[-1]

    for i in range(n):
        print(*res[i])

for testcase in range(1):
    solve(testcase)
