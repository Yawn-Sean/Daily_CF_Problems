'''
961E
2024/8/5 Y2
1900
Fenwick Tree
例如(7,2)，必须在(1,y), (2,y) 更新后进行check，看有多少个y大于等于7
'''

class Fenwick:
    def __init__(self, n: int):
        self.n = n + 1
        self.a = [0] * self.n
    def update(self, i: int, inc: int = 1) -> None:
        i += 1
        while i < self.n:
            self.a[i] += inc
            i += i & -i
    def getsum(self, i: int) -> int:
        s = 0
        i += 1
        while i > 0:
            s += self.a[i]
            i -= i & -i
        return s
    def getone(self, i: int) -> int:
        i += 1
        s = self.a[i]
        next, end = i - 1, i - (i & -i)
        while next > end:
            s -= self.a[next]
            next -= next & -next
        return s
    
if __name__ == '__main__':
    n = int(input())
    a = list(map(int, input().split()))
    ft = Fenwick(n)
    b = []
    for i, y in enumerate(a):
        x = i + 1
        y = min(y, n)
        b.append((min(x, y), x, y))
    b.sort()
    ans, cnt = 0, 0
    for _, x, y in b:
        ans += cnt - ft.getsum(x - 1)
        ft.update(y)
        cnt += 1
    print(ans)