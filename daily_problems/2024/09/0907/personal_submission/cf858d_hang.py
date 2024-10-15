from collections import Counter
def main():
    n = int(input())
    g = []
    vis = Counter()
    for _ in range(n):
        x = input()
        g.append(x)
        t = set()
        for i in range(9):
            cur = 0
            for j in range(i, 9):
                cur = cur * 10 + int(x[j])
                t.add(cur * 10 + (j - i)) # 这里最后一位表示长度-1
        for v in t:
            vis[v] += 1
    for x in g:
        mn_len = 10
        pos = 0
        for i in range(9):
            cur = 0
            for j in range(i, 9):
                cur = cur * 10 + int(x[j])
                if vis[cur * 10 + (j - i)] == 1 and j - i < mn_len:
                    mn_len = j - i
                    pos = i
        
        print(x[pos:pos + mn_len + 1])

main()