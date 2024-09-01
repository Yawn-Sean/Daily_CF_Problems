'''
https://codeforces.com/contest/768/submission/278721744
768 B
2024/8/30 Y1
1600
Binary Tree
问题可以转化成一棵满二叉树，先定位到l,然后中序遍历到r即可
'''
ans = 0

def midorder(n: int, i: int, lv: int, skip: int, end: int) -> int:
    global ans

    # skip when not in [l, r]
    cnt = (1 << n.bit_length() - lv) - 1 # stupid BUG: cnt = (1 << n.bit_length() - 1) - 1
    if i > end or i + cnt <= skip:
        return i + cnt
    
    # left child
    if lv < n.bit_length() - 1:
        i = midorder(n, i, lv + 1, skip, end)
    
    # current node
    if skip <= i <= end:
        ans += n >> lv & 1
        # print('i ans =', i, ans)
    i += 1

    
    # right child
    if lv < n.bit_length() - 1:
        i = midorder(n, i, lv + 1, skip, end)
    return i        

if __name__ == '__main__':
    n, l, r = map(int, input().split())
    midorder(n, 0, 0, l - 1, r  - 1)
    print(ans)
