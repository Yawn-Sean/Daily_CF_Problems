def solve(testcase):
    n = II()
    A = []
    Aidx = []
    B = []
    Bidx = []
    
    for i in range(1, n + 1):
        a, b = MI()
        if a > b:
            A.append((a, b))
            Aidx.append(i)
        else:
            B.append((a, b))
            Bidx.append(i)
    
    if len(A) >= len(B):
        idxs = [i for i in range(len(A))]
        idxs.sort(key = lambda x : A[x][0])
        print(len(A))
        print(*[Aidx[i] for i in idxs])
    else:
        idxs = [i for i in range(len(B))]
        idxs.sort(key = lambda x : -B[x][1])
        print(len(B))
        print(*[Bidx[i] for i in idxs])

for testcase in range(1):
    solve(testcase)
