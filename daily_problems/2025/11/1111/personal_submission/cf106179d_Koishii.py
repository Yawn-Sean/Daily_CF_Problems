def soviet():
    n = int(input())
    a = list(map(int, input().split()))
    v1, v2 = [], []
    for i in range(n):
        if (i < n // 2) ^ (a[i] <= n // 2) :
            v1.append(a[i])
        else :
            v2.append(a[i])

    if len(v1) and len(v2) :
        print(2)
    else :
        print(1)

    if len(v1) :
        print(len(v1), *v1)

    if len(v2) :
        print(len(v2), *v2)


T = int(input())
for _ in range(T):
    soviet()
