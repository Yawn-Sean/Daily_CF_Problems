import bisect
def main():
    n = int(input())
    a = list(map(int, input().split()))
    ans = []
    last = []
    for x in a:
        x = -x
        pos = bisect.bisect_left(last, x)
        if pos == len(last):
            last.append(x)
            ans.append([x])
        else:
            ans[pos].append(x)
            last[pos] = x
    for x in ans:
        x = [-i for i in x]
        print(*x)
    

main()