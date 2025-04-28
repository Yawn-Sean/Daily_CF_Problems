# Submission link: https://codeforces.com/problemset/submission/1089/312129684#
def main():
    n = II()

    for i in range(2, 40000):
        if i == n: break
        if n % i == 0 and math.gcd(i, n // i) == 1:
            a, b = i, n // i
            
            for j in range(1, a):
                if (n - 1 - j * b) % a == 0:
                    nj = (n - 1 - j * b) // a
                    print('YES')
                    print(2)
                    print(nj, b)
                    print(j, a)
                    exit()

    print('NO')