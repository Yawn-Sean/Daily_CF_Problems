k = II()

if k % 2 == 0:
    print("NO")
else:
    print("YES")
    
    root = 1
    ans = []

    for i in range(2, k + 1):
        ans.append((root, i))

    cur = k + 1

    for i in range(k // 2):
        a, b = 2 * i + 2, 2 * i + 3
        tmp = [a, b]
        for j in range(k - 1):
            for x in tmp:
                ans.append((cur, x))               
            tmp.append(cur)
            cur += 1

    n = len(ans)
    cha = cur - 1
    for i in range(n):
        ans.append((ans[i][0] + cha, ans[i][1] + cha))
    ans.append((1, cur))

    print(cur * 2 - 2, cur * k - k)
    print("\n".join(map(lambda x: str(x[0]) + " " + str(x[1]), ans)))
