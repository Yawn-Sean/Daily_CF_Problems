n = ix()
a = il()
ans = []
while a:
    n = len(a)
    for i in range(n - 1, -1, -1):
        if a[i] == i + 1:
            ans.append(i + 1)
            del a[i]
            break
    else:
        exit(print("NO"))
print("YES")
print(*ans[::-1])
