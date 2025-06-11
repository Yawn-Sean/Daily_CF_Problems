from math import inf
def main():
    a,b,c = map(int,input().split())
    ans = inf
    if a % 2 == b % 2: ans = min(ans, max(a, b))
    if a % 2 == c % 2: ans = min(ans, max(a, c))
    if b % 2 == c % 2: ans = min(ans, max(b, c))
    print(ans)

main()