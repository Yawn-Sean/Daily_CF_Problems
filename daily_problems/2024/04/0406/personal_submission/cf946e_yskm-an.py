t = int(input())
for _ in range(t):
    s = input().strip()
    n = len(s)
    num = 0
    for x in s:
        p = int(x)
        num ^= (1 << p)
    ans = ''
    flag = False
    k = 0
    nu = num
    for i in range(n - 1, -1, -1):
        if flag:
            break
        nu ^= (1 << int(s[i]))
        mi = 0 if i != 0 else 1
        for j in range(int(s[i]) - 1, mi - 1, -1):
            nu ^= (1 << j)
            p = bin(nu).count('1')
            if p <= k:
                t = []
                # print(bin(nu))
                for q in range(10):
                    if nu & 1 == 1:
                        t.append(q)
                    nu >>= 1
                ans = s[:i] + str(j) + '9' * (k - p)
                t.sort(reverse=True)
                for x in t:
                    ans += str(x)
                flag = True
                break
            nu ^= (1 << j)
        k += 1
    if len(ans) > 0:
        print(ans)
    else:
        print('9' * (n - 2))
