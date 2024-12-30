# Submission link: https://codeforces.com/contest/610/submission/292110898
def main():
    n = II()
    print('\n'.join(''.join('+' if (i | j).bit_count() % 2 else '*' for j in range(1 << n)) for i in range(1 << n)))