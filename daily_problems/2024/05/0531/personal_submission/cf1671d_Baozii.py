from itertools import pairwise
 
class Solution:
    def solve(self, n: int, x: int, arr: list[int]) -> None:
        ans = sum(abs(a - b) for a, b in pairwise(arr))
        _ma, _mi = max(arr), min(arr)
        inc = min(abs(arr[0] - x), abs(arr[-1] - x), max(0, (x - _ma) * 2))
        dec = min(abs(arr[0] - 1), abs(arr[-1] - 1), (_mi - 1) * 2)
        print(ans + inc + dec)
 
TC = int(input())
 
def main():
    obj = Solution()
    for _ in range(TC):
        n, x = map(int, input().split())
        arr = list(map(int, input().split()))
        obj.solve(n, x, arr)
 
main()
