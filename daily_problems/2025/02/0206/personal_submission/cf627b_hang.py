class FenwickTree:
    def __init__(self, n):
        self.size = n
        self.tree = [0] * (n + 1)
    
    def update(self, i, delta):
        while i <= self.size:
            self.tree[i] += delta
            i += i & -i
    
    def query(self, i):
        res = 0
        while i > 0:
            res += self.tree[i]
            i -= i & -i
        return res
    def query_range(self, left, right):
        return self.query(right) - self.query(left - 1)

def main():
    n,k,a,b,q = map(int, input().split())   
    f1 = FenwickTree(n)
    f2 = FenwickTree(n)
    nums1 = [0] * (n + 1) # 保存未修理状态
    nums2 = [0] * (n + 1) # 保存已修理状态
    ans = []
    for  _ in range(q):
        v = list(map(int, input().split()))
        if v[0] == 1:
            t = min(nums1[v[1]] + v[2],b) - nums1[v[1]]
            nums1[v[1]] += t
            f1.update(v[1], t)

            t = min(nums2[v[1]] + v[2],a) - nums2[v[1]]
            nums2[v[1]] += t
            f2.update(v[1], t)
        else:
            ans.append(f1.query_range(1, v[1] - 1) + f2.query_range(v[1] + k, n))
    print('\n'.join(map(str, ans)))

main()