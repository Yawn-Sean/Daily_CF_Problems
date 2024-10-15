"""
思路：对每个数进行判断，看是否能排在现有答案的后边，可以的话直接加入， 否则开一个新数组来存储。

数组的值比较大， 对数的判断用二分。

"""
#python 代码：
n = int(input())
a = list(map(int, input().split()))

ans = []
for num in a:
	l = 0
	r = len(ans)
	while l < r:
		mid = l + r >> 1
		if ans[mid][-1] < num:
			r = mid
		else:
			l = mid + 1
	if l == len(ans):
		ans.append([num])
	else:
		ans[l].append(num)

for x in ans:
	print(*x)
