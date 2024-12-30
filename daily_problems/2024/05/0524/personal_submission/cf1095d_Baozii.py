n = int(input())
arr = [[-1, -1]]
for _ in range(n):
    arr.append(list(map(int, input().split())))
ans = [1]
i = 1
while len(ans) < n:
    a, b = arr[i]
    if a == 1:
        ans.append(b)
        i = b
    elif b == 1:
        ans.append(a)
        i = a
    else:
        if b in arr[a]:
            ans.append(a)
            i = a
        else:
            ans.append(b)
            i = b
print(*ans)
