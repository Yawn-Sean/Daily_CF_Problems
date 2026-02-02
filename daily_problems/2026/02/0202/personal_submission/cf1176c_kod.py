n = ix()
a = il()
t = [n] + [0] * 6
d = {
    4: 1,
    8: 2,
    15: 3,
    16: 4,
    23: 5,
    42: 6
}
a = [d[x] for x in a ]
for x in a:
    if t[x - 1]:
        t[x - 1] -= 1
        t[x] += 1
print(n - 6 * t[6])
