class Solution:
    def solve(self, n: int, arr: int) -> int:
        operations = list()
        indices = {val: i + 1 for i, val in enumerate(arr)}
        def swap(i, j):
            arr[i - 1], arr[j - 1] = arr[j - 1], arr[i - 1]
            indices[arr[i - 1]], indices[arr[j - 1]] = indices[arr[j - 1]], indices[arr[i - 1]]
            operations.append([i, j])
        for i in range(1, n + 1):
            if arr[i - 1] == i: continue
            index = indices[i]
            if abs(index - i) >= n // 2:
                swap(i, index)
            else:
                if index <= n // 2 and i <= n // 2:
                    swap(index, n)
                    swap(i, n)
                elif index > n // 2 and i > n // 2:
                    swap(index, 1)
                    swap(i, 1)
                elif index <= n // 2 and i > n // 2:
                    swap(index, n)
                    swap(1, n)
                    swap(1, i)
                elif index > n // 2 and i <= n // 2:
                    swap(index, 1)
                    swap(1, n)
                    swap(i, n)
        print(len(operations))
        for op in operations:
            print(*op)

TC = 1

def main():
    obj = Solution()
    for _ in range(TC):
        n = int(input())
        arr = list(map(int, input().split()))
        obj.solve(n, arr)

main()
