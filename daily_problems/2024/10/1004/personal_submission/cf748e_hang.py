def main():
    n,k = map(int,input().split())
    a = list(map(int,input().split()))
    if sum(a) < k:
        print(-1)
        return
    MAX = 10 ** 7 + 1
    cnt = [0] * MAX
    for x in a:
        cnt[x] += 1
    
    tot = 0
    for i in range(MAX - 1, 0, -1):
        tot += cnt[i]
        if 2 * i + 1 <= MAX - 1:
            tot += cnt[2 * i + 1]
            cnt[i] += cnt[2 * i + 1]
            cnt[i + 1] += cnt[2 * i + 1]
        
        if 2 * i <= MAX - 1:
            tot += cnt[2 * i]
            cnt[i] += cnt[2 * i] + cnt[2 * i]
        if tot >= k:
            print(i)
            return
main()