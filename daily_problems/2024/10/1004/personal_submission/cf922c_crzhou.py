n, k = MII()
s = set()
for i in range(1, k + 1):
    tmp = n % i
    if tmp not in s:
        s.add(n % i)
    else:
        exit(print("No"))
print("Yes")
