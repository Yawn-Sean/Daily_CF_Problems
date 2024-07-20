'''
https://codeforces.com/contest/1243/submission/271415099
1243B2
2024/7/19 Y1
1600
array, set
'''

def init():
    n = int(input())
    s = input()
    t = input()
    return n, s, t

def solve(n: int, s: str, t: str):
    a = [ord(c) - 97 for c in s]
    b = [ord(c) - 97 for c in t]
    cs = [set() for _ in range(26)]
    ans = []
    for i, (x, y) in enumerate(zip(a, b)):
        if x != y:
            cs[x].add(i)
            cs[y].add(i)
    for i in range(len(a)):
        x, y = a[i], b[i]
        if x != y:
            cs[x].remove(i)
            cs[y].remove(i)
            if not cs[y]:
                return []
            j = next(j for j in cs[y])
            if a[j] == y: # y == a[j], first swap (a[j], b[j]), then swap (a[i], b[j])
                ans.append((j + 1, j + 1))
                a[j], b[j] = b[j], a[j]
            # swap a[i] and b[j]
            ans.append((i + 1, j + 1))
            cs[y].remove(j)
            if a[j] == x:
                cs[x].remove(j)
            else:
                cs[x].add(j)
            a[i], b[j] = b[j], a[i]
    return ans

if __name__ == '__main__':
    for _ in range(int(input())):
        args = init()
        ans = solve(*args)
        if ans:
            print("Yes")
            print(len(ans))
            for r in ans:
                print(*r)
        else:
            print("No")
