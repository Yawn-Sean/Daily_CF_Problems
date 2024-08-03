from collections import defaultdict,deque
def main():
    n = int(input())
    a = list(map(int, input().split()))
    c = defaultdict(deque)
    for i in range(n):
        while c[a[i]]:
            a[c[a[i]].popleft()] = -1
            a[i] += a[i]
        c[a[i]].append(i)
    a = list(filter(lambda x: x != -1, a))
    print(len(a))
    print(*a)
main()