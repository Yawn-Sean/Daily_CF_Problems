a, b = I(), I()
a = list(map(ord, a))
i = len(a) - 1
while a[i] == 122:
    a[i] = 97
    i -= 1
a[i] += 1
a = str(''.join(map(chr, a)))
if a < b:
    print(a)
else:
    print('No such string')
