# Submission link: https://codeforces.com/contest/234/submission/316896239
def main():
    input_file = open("input.txt", 'r')
    input = lambda: input_file.readline().strip()

    output_file = open("output.txt", 'w')
    def print(s):
        output_file.write(s)
        output_file.write('\n')

    n1 = II()
    nums1 = LII()
    n2 = II()
    nums2 = LII()

    nums1.append(0)
    nums2.append(0)

    c1 = 0
    for i in range(n1):
        if nums1[i] != nums1[i + 1]:
            c1 += 1

    c2 = 0
    for i in range(n2):
        if nums2[i] != nums2[i + 1]:
            c2 += 1

    if c1 < c2:
        order = []
        vals = []
        
        p = 0
        for i in range(n2):
            while p < n1 and nums1[p] == nums2[i]:
                order.append(p)
                vals.append(nums1[p])
                p += 1
            order.append(n1 + i)
            vals.append(nums2[i])
        
        for i in range(p, n1):
            order.append(i)
            vals.append(nums1[i])

    else:
        order = []
        vals = []
        
        p = 0
        for i in range(n1):
            while p < n2 and nums2[p] == nums1[i]:
                order.append(n1 + p)
                vals.append(nums2[p])
                p += 1
            order.append(i)
            vals.append(nums1[i])
        
        for i in range(p, n2):
            order.append(n1 + i)
            vals.append(nums2[i])

    print(' '.join(str(x + 1) for x in order))

    vals.append(0)
    idxs = [i for i in range(1, n1 + n2 + 1) if vals[i] != vals[i - 1]]
    print(str(len(idxs)))
    print(' '.join(map(str, idxs)))