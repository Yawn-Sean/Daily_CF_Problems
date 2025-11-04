'''
https://codeforces.com/gym/105973/submission/347355856
'''
MAXM = 1000000
lut = []
def init():
    global MAXM, lut
    fac = Factorial(MAXM, 998244353)
    lut = [0] * (MAXM + 1)
    for i in range(1, MAXM + 1):
        lut[i] = lut[i - 1] ^ 1 ^ (0 if i & 1 else fac.combi(i, i >> 1))

if __name__ == '__main__':
    init()
    for _ in range(int(input())):
        n = int(input())
        print(lut[n])
