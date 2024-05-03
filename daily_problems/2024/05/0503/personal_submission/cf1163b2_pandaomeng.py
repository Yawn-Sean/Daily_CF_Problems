'''
submission: https://codeforces.com/problemset/submission/1163/259340829

遍历 i from 0 to n - 1
数字的种类记为 kinds
最大计数为 max_cnt, 最小计数为 min_cnt
满足的条件为
kinds == 1
或者
min_cnt == 1 and max_cnt * (kinds - 1) == i
或者
max_cnt - 1 == min_cnt and min_cnt * kinds == i
'''

def main():
    n = II()
    arr = LII()
    min_cnt = inf
    max_cnt = 0
    cnt = defaultdict(int)
    s = set()
    ans = 0
    h = []
    for i, x in enumerate(arr):
        s.add(x)
        kinds = len(s)
        cnt[x] += 1
        heappush(h, (cnt[x], x))
        while h and cnt[h[0][1]] != h[0][0]:
            heappop(h)
        max_cnt = max(max_cnt, cnt[x])
        min_cnt = h[0][0]
        # print(i, kinds, max_cnt, min_cnt)
        if kinds == 1:
            ans = max(ans, i + 1)
        elif min_cnt == 1 and max_cnt * (kinds - 1) == i:
            ans = max(ans, i + 1)
        elif max_cnt - 1 == min_cnt and min_cnt * kinds == i:
            ans = max(ans, i + 1)
    print(ans)

main()