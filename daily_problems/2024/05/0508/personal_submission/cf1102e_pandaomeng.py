# submission: https://codeforces.com/problemset/submission/1102/260005929

def main():
    n = II()
    arr = LII()
    max_index =defaultdict(int)
    for i, x in enumerate(arr):
        max_index[x] = max(max_index[x], i)

    cnt = 0
    remote = 0
    for i, x in enumerate(arr):
        remote = max(remote, max_index[x])
        if remote == i:
            cnt += 1

    print(2 ** (cnt - 1) % 998244353)