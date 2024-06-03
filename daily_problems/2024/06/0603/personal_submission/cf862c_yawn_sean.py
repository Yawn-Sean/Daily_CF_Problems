# Submission link: https://codeforces.com/contest/862/submission/263831521
def main():
    n, x = MII()
    if n == 1:
        print('YES')
        print(x)
    elif n == 2:
        if x:
            print('YES')
            print(0, x)
        else:
            print('NO')
    else:
        while True:
            rnd = random.sample(range(1 << 17), k=n - 2)
            v = reduce(xor, rnd) ^ x
            if v: break
        rnd.extend([1 << 17, (1 << 17) ^ v])
        print('YES')
        print(' '.join(map(str, rnd)))