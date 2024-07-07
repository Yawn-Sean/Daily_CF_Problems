# Submission Link: https://codeforces.com/contest/1023/submission/268996915
def main():
    def query(r1, c1, r2, c2):
        print('?', r1, c1, r2, c2, flush=True)
        return I() == "YES"

    def answer(s):
        print('!', s, flush=True)

    n = II()

    x, y = 1, 1
    tmp1 = []

    for _ in range(n - 1):
        if query(x, y + 1, n, n):
            y += 1
            tmp1.append('R')
        else:
            x += 1
            tmp1.append('D')

    x, y = n, n
    tmp2 = []

    for _ in range(n - 1):
        if query(1, 1, x - 1, y):
            x -= 1
            tmp2.append('D')
        else:
            y -= 1
            tmp2.append('R')

    answer(''.join(tmp1) + ''.join(reversed(tmp2)))