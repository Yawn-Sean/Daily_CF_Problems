"""
url: 
    question:   https://codeforces.com/problemset/problem/962/D
    submission: https://codeforces.com/contest/962/submission/262464188
time: 1249 ms
"""

def solve():
    n = int(input())
    a = list(map(int, input().split()))
    indexs = dd(SortedList)
    for i, x in enumerate(a):
        indexs[x].add(i)
    st = set(a)
    def op(cur_val, cur_idx):
        index = indexs[cur_val]
        while len(index) == 1 and cur_val not in st: 
            del indexs[cur_val]
            cur_val *= 2 
            cur_idx = max(cur_idx, index[-1])
            index   = indexs[cur_val]
        indexs[cur_val].add(cur_idx)
    
    for x in sorted(st):
        index = indexs[x]
        m = len(index)
        if m == 0: continue
        for i in range(1, m, 2):
            op(2 * x, index[i])
        del indexs[x]
        if m & 1: indexs[x].add(index[-1])

    ans = [[i, x] for x, item in indexs.items()
                  for i in item]
    ans.sort(key=lambda x: x[0])
    print(len(ans))
    print(' '.join(str(x[1]) for x in ans))

solve()
