import io, sys
input = lambda : sys.stdin.readline().strip()

def main():
    n = int(input())
    ans = []

    for x in map(int, input().split()):
        l, r = 0, len(ans)-1
        while l < r:
            mid = (l+r) // 2
            if x > ans[mid][-1]: r = mid
            else: l = mid + 1
        if len(ans) == 0 or ans[l][-1] >= x: ans.append([x])
        else: ans[l].append(x)

    for res in ans:
        for x in res:
            print(x, end=' ')
        print()
