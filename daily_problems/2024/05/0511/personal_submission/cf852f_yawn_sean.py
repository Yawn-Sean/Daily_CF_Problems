# Submission link: https://codeforces.com/contest/852/submission/260469762
def main():
    n, m, a, q = MII()

    powers = [1]
    for i in range(10 ** 6 + 123):
        powers.append(powers[-1] * a % q)
        if powers[-1] == 1:
            powers.pop()
            break

    phi = len(powers)

    fact = Factorial(m, phi)

    ans = [1] * n
    for i in range(n - 2, -1, -1):
        ans[i] = (ans[i + 1] + fact.combi(m, n - 1 - i)) % phi

    print(' '.join(str(powers[x]) for x in ans))