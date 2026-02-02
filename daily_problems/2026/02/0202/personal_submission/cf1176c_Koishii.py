tar = [4,8,15,16,23,42]

def soviet():
    n = int(input())
    a = list(map(int, input().split()))

    cnt = [0] * 6
    for i in range(n):
        a[i] = tar.index(a[i])
        if a[i] == 0:
            cnt[a[i]] += 1
        elif cnt[a[i] - 1]:
            cnt[a[i]] += 1
            cnt[a[i] - 1] -= 1 
    print(n - cnt[5] * 6)


soviet()
