# Submission link: https://codeforces.com/contest/117/submission/279265029
def main():
    a, b, mod = MII()

    c = 10 ** 9 % mod
    v = 0
    for i in range(min(a + 1, mod)):
        if v > b:
            print(f'1 {i:0{9}}')
            exit()
        v -= c
        v %= mod

    print(2)