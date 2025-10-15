n, m, p = il()
a = [1 if x == '(' else -1 for x in input()]
b = []
while len(a) > p:
    b.append(a.pop())
for x in input():
    if x == 'R':
        a.append(b.pop())
    elif x == 'L':
        b.append(a.pop())
    else:
        v = a.pop()
        if v > 0:
            while v:
                v += b.pop()
        else:
            while v:
                v += a.pop()
        if b:
            a += b.pop(),
res = ['(' if x == 1 else ')' for x in (a + b[::-1])]
print(''.join(res))
