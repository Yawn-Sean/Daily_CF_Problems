input = sys.stdin.read().split()
ptr = 0
T = int(input[ptr])
ptr += 1
for _ in range(T):
    n = int(input[ptr])
    ptr += 1
    a = [[0]*(n+2) for _ in range(n+2)]
    ans = [0]*10
    for i in range(1, n+1):
        s = input[ptr]
        ptr += 1
        for j in range(1, n+1):
            a[i][j] = int(s[j-1])
    
    U = [n+1]*10
    D = [0]*10
    for i in range(1, n+1):
        for j in range(1, n+1):
            digit = a[i][j]
            U[digit] = min(U[digit], i)
            D[digit] = max(D[digit], i)
    
    for i in range(1, n+1):
        L = [n+1]*10
        R = [0]*10
        for j in range(1, n+1):
            digit = a[i][j]
            L[digit] = min(L[digit], j)
            R[digit] = max(R[digit], j)
        for j in range(10):
            if R[j] == 0:
                continue
            ans[j] = max(ans[j], (R[j] - L[j]) * max(i-1, n-i))
            H = max(i - U[j], D[j] - i)
            W = max(R[j] - 1, n - L[j])
            if H < 0: H = 0
            if W < 0: W = 0
            ans[j] = max(ans[j], W * H)
    
    L = [n+1]*10
    R = [0]*10
    for i in range(1, n+1):
        for j in range(1, n+1):
            digit = a[i][j]
            L[digit] = min(L[digit], j)
            R[digit] = max(R[digit], j)
    
    for j in range(1, n+1):
        U = [n+1]*10
        D = [0]*10
        for i in range(1, n+1):
            digit = a[i][j]
            U[digit] = min(U[digit], i)
            D[digit] = max(D[digit], i)
        for i in range(10):
            if D[i] == 0:
                continue
            ans[i] = max(ans[i], (D[i] - U[i]) * max(j-1, n-j))
            W = max(j - L[i], R[i] - j)
            H = max(D[i] - 1, n - U[i])
            if H < 0: H = 0
            if W < 0: W = 0
            ans[i] = max(ans[i], H * W)
    
    print(' '.join(map(str, ans)))
