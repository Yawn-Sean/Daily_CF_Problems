"""
思路：每个号码只有9位， 比较短，反而 n 相比来说大多了。

遍历每个号码里的子串， 用字典统计子串出现的次数， 看是否在其他子串中也出现。

统计完后，再次遍历号码串，如果子串出现次数为 1 且小于暂存变量里的字串长度， 就更新。

"""
#python代码：
n = int(input())
dict = {}
a = []
for i in range(n):
    string = input()
    s = set()
    for i in range(9):
        for j in range(i, 9):
            k = string[i:j + 1]
            if k in s:
                continue
            else:
                s.add(k)
            if k in dict:
                dict[k] += 1
            else:
                dict[k] = 1
    a.append(string)

for string in a:
    tmp = string
    for i in range(9):
        for j in range(i, 9):
            k = string[i:j + 1]
            if dict[k] == 1 and len(k) < len(tmp):
                tmp = k
    print(tmp)
