# Submission link: https://codeforces.com/contest/1148/submission/254643442
def main():
    n = II()
    a = []
    b = []
    cnt = 0
    for _ in range(n):
        x, y = MII()
        a.append(x)
        b.append(y)
        if x > y: cnt += 1

    if cnt * 2 >= n:
        chosen = [i for i in range(n) if a[i] > b[i]]
        chosen.sort(key=lambda x: a[x])
    else:
        chosen = [i for i in range(n) if a[i] < b[i]]
        chosen.sort(key=lambda x: -b[x])

    print(len(chosen))
    print(' '.join(str(x + 1) for x in chosen))