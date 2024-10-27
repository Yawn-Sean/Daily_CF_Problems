
def xor(a, b): return a ^ b
def main():
    n = int(input())
    p = list(map(int, input().split()))
    def pref_xor(x):
        if x % 4 == 0: return x
        if x % 4 == 1: return 1
        if x % 4 == 2: return x + 1
        return 0

    ans = 0
    for i in range(n):
        ans ^= p[i]

    for i in range(1, n + 1):
        x = n % (2 * i)
        if x >= i: ans ^= pref_xor(i - 1) ^ pref_xor(x - i)
        else: ans ^= pref_xor(x)

    print(ans)
main()