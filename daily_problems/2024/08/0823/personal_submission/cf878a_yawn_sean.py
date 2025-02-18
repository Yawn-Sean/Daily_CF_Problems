# Submission link: https://codeforces.com/contest/878/submission/277716224
def main():
    v0, v1023 = 0, 1023

    for _ in range(n):
        op, x = LI()
        x = int(x)
        if op == '|':
            v0 |= x
            v1023 |= x
        elif op == '&':
            v0 &= x
            v1023 &= x
        else:
            v0 ^= x
            v1023 ^= x

    print(2)
    print('&', v0 ^ v1023)
    print('^', v0)