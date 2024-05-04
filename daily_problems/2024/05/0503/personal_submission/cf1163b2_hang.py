from collections import Counter
def main():
    n = int(input())
    u = map(int, input().split())
    c = [0] * (10 ** 5 + 1)
    z = [0] * (n + 1)
    z[0] = n

    ans = 0
    mx_z = 0

    for i, v in enumerate(u):
        z[c[v]] -= 1
        c[v] += 1
        z[c[v]] += 1

        mx_z = max(mx_z, c[v])
        
        if mx_z == 1 or mx_z * z[mx_z] == i or (mx_z - 1) * (z[mx_z - 1] + 1) == i:
            ans = i

    print(ans + 1)
main()