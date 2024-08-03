n = int(input())
pairs_up = []
pairs_dn = []
for i in range(1, n+1):
    a, b = map(int, input().split())
    if a > b:
        pairs_dn.append((a, b, i))
    else:
        pairs_up.append((a, b, i))
if len(pairs_up) > len(pairs_dn):
    pairs_up.sort(reverse = True)
    ans = [i[2] for i in pairs_up]
    print(len(pairs_up))
    print(*ans)
else:
    pairs_dn.sort()
    ans = [i[2] for i in pairs_dn]
    print(len(pairs_dn))
    print(*ans)
