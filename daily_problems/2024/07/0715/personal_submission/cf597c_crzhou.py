
# 超时
# def f():
#     n, k = map(int, input().split())
#     nums = [int(input()) - 1 for _ in range(n)]
#     dp = [1] * n
#     for _ in range(k):
#         new_dp = [0] * n
#         for i in range(n - 1, -1, -1):
#             for j in range(i - 1, -1, -1):
#                 if nums[i] > nums[j]:
#                     new_dp[i] += dp[j]
#         dp = new_dp
#     print(sum(dp))
# f()


# 树状数组：单点修改，区间查询
# 本题是增加dp[i]，查询前缀和
class FenwickTree:
    def __init__(self, size):
        self.size = size
        self.tree = [0] * (size + 1)
    
    def init(self):
        self.tree = [0] * (self.size + 1)
    
    def add(self, index, value):
        index += 1
        while index <= self.size:
            self.tree[index] += value
            index += index & -index
    
    def sum(self, index):
        index += 1
        total = 0
        while index > 0:
            total += self.tree[index]
            index -= index & -index
        return total

def main():
    
    n, k = map(int, input().split())
    nums = [int(input()) - 1 for _ in range(n)]
    
    dp = [1] * n
    fen = FenwickTree(n)
    
    for _ in range(k):
        fen.init()
        for i in range(n):
            fen.add(nums[i], dp[i])
            dp[i] = fen.sum(nums[i] - 1)
        
    print(sum(dp))

if __name__ == "__main__":
    main()
  
