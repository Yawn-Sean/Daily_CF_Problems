'''
https://codeforces.com/problemset/submission/1252/276732331
1252 C
2024/8/16 Y1
1600
矩阵 前缀和
'''
def solve():
    n, q = map(int, input().split())
    ra = list(map(int, input().split()))
    ca = list(map(int, input().split()))
    psR, psC = [1] * n, [1] * n
    for i in range(1, n):
        if (ra[i] & 1) == (ra[i - 1] & 1):
            psR[i] += psR[i - 1]
        if (ca[i] & 1) == (ca[i - 1] & 1):
            psC[i] += psC[i - 1]
    for _ in range(q):
        r1, c1, r2, c2 = map(int, input().split())
        r1, c1, r2, c2 = min(r1, r2) - 1, min(c1, c2) - 1, max(r1, r2) - 1, max(c1, c2) - 1
        yield psR[r2] > r2 - r1 and psC[c2] > c2 - c1

if __name__ == '__main__':
    for ans in solve():
        if ans:
            print("YES")
        else:
            print("NO")
