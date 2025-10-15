h = ix()
a = il()
oa = a[:]
n = sum(a)
for x in range(h):
    if a[x] > 1 and a[x + 1] > 1:
        print("ambiguous")
        nums = [0] * n
        p = v = 0
        for i in range(n):
            while a[p] == 0:
                p += 1
                v = i
            nums[i] = v
            a[p] -= 1
        print(*nums)
        id = sum(oa[:x + 1])
        nums[id] -= 1
        print(*nums)
        break
else:
    print("perfect")
