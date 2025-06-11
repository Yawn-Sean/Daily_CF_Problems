n = II()
s1 = I()
s2 = I()
ct = s2.count("1")

d = [[] for _ in range(3)]
for i in range(n):
    t = int(s1[i]) + int(s2[i])
    d[t].append(i + 1)

for a in range(n):
    b = ct - 2 * a
    c = n // 2 - a - b
    if 0 <= a <= len(d[2]) and 0 <= b <= len(d[1]) and 0 <= c <= len(d[0]):
        z = d[2][:a] + d[1][:b] + d[0][:c]
        print(*z)
        exit(0)


print(-1)
