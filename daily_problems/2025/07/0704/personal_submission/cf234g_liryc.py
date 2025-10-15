'''
https://codeforces.com/problemset/submission/234/327322396
'''
# 分治
fin = open('input.txt', 'r')
fout = open('output.txt', 'w')
input = lambda: fin.readline().strip()
print = lambda s: fout.write(s + '\n')

def solve(n: int) -> list[list[int]]:
    f = 1
    while f < n:
        f <<= 1
    h = f >> 1
    ans = []
    while f > 1:
        r = []
        for i in range(n):
            if i % f < h:
                r.append(i + 1)
        ans.append(r)
        f, h = h, h + 1 >> 1
    return ans

if __name__ == '__main__':
    n = int(input())
    ans = solve(n)
    print(str(len(ans)))
    for r in ans:
        print(str(len(r)) + " " + " ".join(map(str, r)))
