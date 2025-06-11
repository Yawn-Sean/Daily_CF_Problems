# Submission link: https://codeforces.com/contest/896/submission/297040304
def main():
    n, m, c = MII()
    bound = c // 2

    ans = [-1] * n
    not_used = n

    while not_used:
        v = II()
        if v <= bound:
            for i in range(n):
                if ans[i] == -1 or ans[i] > v:
                    print(i + 1, flush=True)
                    not_used -= (ans[i] == -1)
                    ans[i] = v
                    break
        else:
            for i in range(n - 1, -1, -1):
                if ans[i] == -1 or ans[i] < v:
                    print(i + 1, flush=True)
                    not_used -= (ans[i] == -1)
                    ans[i] = v
                    break