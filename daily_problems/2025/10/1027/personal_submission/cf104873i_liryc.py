'''
https://codeforces.com/gym/104873/submission/345958107
'''
# query each array twice

def query(qa: list[int]):
    print('?', len(qa), *qa, flush=True)
    _, *a = map(int, input().split())
    return list(a)

def solve(n: int):
    if n == 1:
        a = query([1])
        return [len(a)] + a
    m = 1 if n == 3 else n // 3 + 1 
    i = 0
    ans = []
    while i < n:
        j = min(i + m, n)
        qa = []
        for idx in range(i, j):
            qa.append(idx + 1)
            qa.append(idx + 1)
        a = query(qa)
        i = 0
        while i < len(a):
            ans.append([a[i]])
            i += 1
            while a[i] != ans[-1][0]:
                ans[-1].append(a[i])
                i += 1
            i += len(ans[-1])
        i = j
    rs = []
    for r in ans:
        rs.append(len(r))
        rs.extend(r)
    return rs

if __name__ == '__main__':
    n = int(input())
    ans = solve(n)
    print('!', *ans)
