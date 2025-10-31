t = ix()
for i in range(t):
    n = ix()
    m = d = 0
    for j in range(n):
        s = input()
        if 'xxx' in s:
            d ^= 1
        elif 'xx' in s:
            m ^= 1
    if d == m == 0:
        print('Polycarp')
    else:
        print('Monocarp')
