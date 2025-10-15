# Submission link: https://codeforces.com/contest/1523/submission/295323562
def main():
    t = II()
    outs = []

    for _ in range(t):
        n = II()
        stk = []
        for _ in range(n):
            x = II()
            if x == 1:
                stk.append(1)
            else:
                while stk[-1] != x - 1:
                    stk.pop()
                stk[-1] = x
            outs.append('.'.join(map(str, stk)))

    print('\n'.join(outs))