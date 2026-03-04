a = list(map(int, input().split()))

def wash(a):
    b = []
    for i in range(0, 26):
        j = i + 26
        b.append(a[i])
        b.append(a[j])
    return b

def check(a):
    cnt = 0
    for i in range(26):
        if a[i] == 1:
            cnt += 1
    return cnt == 4

for _ in range(9):
    if check(a):
        print('YES')
        break
    a = wash(a)
else: print('NO')
