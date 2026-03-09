for _ in range(ix()):
    n, m, k = il()
    if k == 1:
        if m * n % 2: print('Munir')
        else:print('Matthew')
    elif n % 2 or m % 2 or k >= 4: print('Munir')
    else: print('Matthew')
