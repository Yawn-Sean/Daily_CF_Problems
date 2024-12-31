def main():
    t = II()
    outs = []

    for _ in range(t):
        n = II()
        x, y = 1, 1
        for _ in range(n):
            x, y = x + y, x
            if x > 10 ** 18:
                break
        if x <= 10 ** 18:
            outs.append(f'{x} {y}')
        else:
            outs.append('-1')

    print('\n'.join(outs))