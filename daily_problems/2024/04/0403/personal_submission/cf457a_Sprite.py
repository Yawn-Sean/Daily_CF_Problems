a, b = list(map(int, list(input())))[::-1], list(map(int, list(input())))[::-1]
if len(a) < 2:
    a += [0, 0]
if len(a) < len(b):
    a += [0] * (len(b) - len(a))
else:
    b += [0] * (len(a) - len(b))

while len(a) > 2:
    now_a = a.pop()
    now_b = b.pop()
    a[-1] += now_a - now_b
    a[-2] += now_a - now_b

if a == b:
    print('=')
elif a[::-1] > b[::-1]:
    print('>')
else:
    print('<')
