from math import gcd

def main():
    n = int(input())
    dic = {}
    ans = 0
    for _ in range(n):
        x, y, u, v = map(int, input().split())
        k = gcd(u - x, v - y)
        direc = ((u - x) // k, (v - y) // k)
        if (-direc[0], -direc[1]) in dic:
            ans += dic[(-direc[0], -direc[1])]
        if direc not in dic:
            dic[direc] = 0
        dic[direc] += 1

    return ans

for _ in range(int(input())):
    print(main())
