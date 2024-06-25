class SortedList:
    ...

class Solution:
    def solve(self, n: int, k: int, arr: list[int]) -> int:
        indices = defaultdict(deque)
        for i, num in enumerate(arr):
            indices[num].append(i)
        for num in indices:
            indices[num].append(n)
        capacity = SortedList()
        s = set()
        ans = 0
        for i, num in enumerate(arr):
            while capacity and capacity[-1][0] == n:
                _, book = capacity.pop()
                s.remove(book)
            if num not in s:
                if len(s) == k:
                    _, book = capacity.pop()
                    s.remove(book)
                s.add(num)
                indices[num].popleft()
                capacity.add((indices[num][0], num))
                ans += 1
            else:
                capacity.remove((indices[num].popleft(), num))
                capacity.add((indices[num][0], num))

        return ans

TC = 1

def main():
    obj = Solution()
    for _ in range(TC):
        n, k = map(int, input().split())
        arr = list(map(int, input().split()))
        if n == k:
            print(len(set(arr)))
            continue
        print(obj.solve(n, k, arr))

main()
