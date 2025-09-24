n = ix()
a = il()
t = ZeroOneTrie(32)
for i in range(1, n - 1):
    a[i] ^= a[i - 1]
t.insert(0)
for x in a:
    t.insert(x)
for i in range(n):
    if t.get_max_xor(i) == n - 1:
        ans = [i] + [i ^ x for x in a]
        print(*ans)
        break
