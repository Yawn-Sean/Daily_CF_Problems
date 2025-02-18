n, m, k = MII()
a = LII()
b = LII()

if len(a) > len(b):
    print("YES")
else:
    cnt = Counter(a)
    for x in b:
        cnt[x] -= 1

    cnt = sorted(cnt.items(), key=lambda x: x[0], reverse=True)
    tmp = 0
    for _, v in cnt:
        tmp += v
        if tmp > 0:
            print("YES")
            exit()
    print("NO")
