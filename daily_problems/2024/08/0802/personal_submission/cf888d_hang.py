from math import comb
def main():
    n, k = map(int, input().split())
    ans = 1
    if k >= 2:
        ans += comb(n, 2)
    if k >= 3:
        ans += comb(n, 3) * 2
    if k >= 4:
        ans += comb(n, 4) * 9
    print(ans)

main()