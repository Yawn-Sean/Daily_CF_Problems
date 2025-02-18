n, k = MII()

if n > k * (k - 1):
    print("NO")
else:
    print("YES")
    outs = []
    for i in range(3, k + k):
        for j in range(1, i):
            if j != i - j and j <= k and i - j <= k:
                outs.append((j, i - j))
                if len(outs) == n:
                    print("\n".join(map(lambda x: str(x[0]) + " " + str(x[1]), outs)))
                    exit()
