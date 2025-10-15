import copy

def printf(extra):
    print("YES")
    for x in extra:
        print(x)

n = int(input())
a = [int(input()) for i in range(n)]
for a1 in range(1, min(a) + 1 if a else 2):
    extra = []
    if a1 not in a and a1 not in extra:
        extra.append(a1)
    if a1 * 3 not in a and a1 * 3 not in extra:
        extra.append(3 * a1)
    if len(a + extra) > 4 or max(a + extra) != 3 * a1:
        continue
    if len(a + extra) == 4:
        if sum(a + extra) == a1 * 8:
            printf(extra)
            exit()
    if len(a + extra) == 3:
        printf(extra + [a1 * 8 - sum(a + extra)])
        exit()
    if len(a + extra) == 2:
        printf(extra + [a1, a1 * 3])
        exit()
print("NO")