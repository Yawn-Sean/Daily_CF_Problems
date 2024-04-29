from collections import Counter


def main():
    for _ in range(int(input())):
        n = int(input())
        nums = list(map(int, input().split(" ")))
        cnt = Counter(nums)
        m = min(cnt.values())
        for k in range(m, 0, -1):
            ans = 0
            for c in cnt.values():
                q, r = divmod(c, k)
                if q < r:
                    break
                ans += (c + k) // (k + 1)
            else:
                print(ans)
                break

main()

