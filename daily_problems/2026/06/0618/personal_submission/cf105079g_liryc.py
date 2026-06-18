'''
https://codeforces.com/gym/105079/submission/379314592
priority queue
'''
def solve(n: int, A: list[int], B: list[int]) -> int:
    hp = [~a for a in A]
    heapify(hp)
    bs = 0
    for b in B:
        bs += b
        a = ~heappop(hp)
        a -= a + bs >> 1
        heappush(hp, ~a)
    return sum(~a + bs for a in hp)
