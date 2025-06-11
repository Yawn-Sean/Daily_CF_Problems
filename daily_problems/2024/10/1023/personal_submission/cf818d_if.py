from collections import Counter
n, a = map(int, input().split())
c = list(map(int, input().split()))
cnt = Counter()

tar = 0
for i in c:
    if i == a:
        tar += 1
        s = set()
        for l in cnt:
            if cnt[l] < tar:
                s.add(l)
        while s:
            del cnt[s.pop()]
    if cnt[i] >= tar:
        cnt[i] += 1
    if not cnt:
        print(-1)
        exit()

for i in cnt:
    print(i)
    exit()
