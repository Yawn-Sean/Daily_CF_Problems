"""
question: https://codeforces.com/problemset/problem/819/B
submission: https://codeforces.com/contest/819/submission/266261122

"""

def main(ac=FastIO()):
    n = ac.read_int()
    a = ac.read_list_ints()
    b = [x - i for i, x in enumerate(a, 1)]
    ans = res = sum(map(abs, b))
    fin = 0
    c = 0 
    heap = []
    for x in b: 
        if x < c: heap.append(-x)
    heapify(heap)
    for i in range(n - 1):
        res += abs(a[(i + n) % n] - n) - abs(a[i] - 1) + n - 1 - 2 * len(heap)
        if res <= ans: 
            fin = n - i - 1 
            ans = res 
        c -= 1 
        while heap and -heap[0] >= c: heappop(heap)
        if a[(i + n) % n] - n < 0: 
            heappush(heap, - (a[(i + n) % n] - n + c))
    ac.st(f"{ans} {fin}")
main()
