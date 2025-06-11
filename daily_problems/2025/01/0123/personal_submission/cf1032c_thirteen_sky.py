n = int(input())
a = list(map(int, input().split()))
if n == 1:
    print(1)
else:
    b, res = [], True
    if a[0] > a[1]:
        b.append(5)
    elif a[0] < a[1]:
        b.append(1)
    else:
        b.append(2)
    n = len(a)
    for i in range(1, n - 1):
        if a[i] > a[i - 1]:
            if a[i] <= a[i + 1]:
                b.append(b[-1] + 1)
            elif a[i] > a[i + 1]:
                b.append(5)
        elif a[i] < a[i - 1]:
            if a[i] >= a[i + 1]:
                b.append(b[-1] - 1)
            elif a[i] < a[i + 1]:
                b.append(1)
        else:
            if a[i] > a[i + 1]:
                b.append(5 if b[-1] != 5 else 4)
            elif a[i] < a[i + 1]:
                b.append(1 if b[-1] != 1 else 2)
            else:
                b.append(2 if b[-1] != 2 else 4)
        if not 1 <= b[-1] <= 5 or b[-1] == b[-2]:
            res = False
            break
    
    if a[-2] > a[-1]:
        b.append(b[-1] - 1)
    elif a[-2] < a[-1]:
        b.append(b[-1] + 1)
    else:
        b.append(2 if b[-1] != 2 else 4)
    if not 1 <= b[-1] <= 5 or b[-1] == b[-2]:
        res = False
    print(*b if res else [-1])
