# Submission link: https://codeforces.com/contest/922/submission/284240943
def main():
    n, k = MII()

    for i in range(1, k + 1):
        if n % i != i - 1:
            exit(print('No'))

    print('Yes')