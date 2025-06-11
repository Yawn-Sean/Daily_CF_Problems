'''
https://codeforces.com/problemset/submission/992/289083216
992C
2024/11/1 Y1
1600
'''
# ref
x, k = map(int, input().split())
MOD = 10 ** 9 + 7
print((pow(2, k, MOD) * (2 * x - 1) % MOD + 1) % MOD if x else 0)