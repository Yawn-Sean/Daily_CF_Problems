# Submission link: https://codeforces.com/contest/405/submission/286624127
def main():
    n = II()
    ans = 0

    for i in range(n):
        ans ^= LII()[i]

    outs = []

    q = II()
    for _ in range(q):
        if I()[0] == '3': outs.append(ans)
        else: ans ^= 1

    print(''.join(map(str, outs)))