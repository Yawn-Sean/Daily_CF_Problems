s = input()
t = input()
nums1 = []
nums2 = []
n = len(s)
orda = ord('a')
for i in range(n):
    nums1.append(ord(s[i]) - orda)
    nums2.append(ord(t[i]) - orda)
val1, val2 = 0, 0
for i in range(n):
    val1 = 26 * val1 + nums1[i]
    val2 = 26 * val2 + nums2[i]
if val2 - val1 == 1:
    print("No such string")
else:
    val1 += 1
    res = []
    for i in range(n):
        ch = val1 % 26
        val1 //= 26
        res.append(chr(ch + orda))
    for i in range(n - 1, -1, -1):
        print(res[i], end='')
