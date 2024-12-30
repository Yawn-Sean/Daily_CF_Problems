# Submission link: https://codeforces.com/contest/1168/submission/262943884

def main():
    vis = [set() for _ in range(11)]

    for i in range(1, 11):
        for j in range(1 << i):
            x = bin(j)[2:].zfill(i)
            f = False
            for mid in range(i):
                for wing in range(1, i):
                    if mid - wing < 0 or mid + wing >= i: break
                    if x[mid - wing] == x[mid] == x[mid + wing]:
                        f = True
            if f: vis[i].add(j)

    s = I()
    n = len(s)
    ans = 0

    for i in range(n):
        cur = 0
        for j in range(i, n):
            cur = 2 * cur + int(s[j])
            if cur in vis[j - i + 1]:
                ans += n - j
                break

    print(ans)