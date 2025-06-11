package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() { CF1286B(os.Stdin, os.Stdout) }

func CF1286B(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var n int
	fmt.Fscan(in, &n)
	parent := make([]int, n) // 父节点
	counts := make([]int, n) // 括号中的整数
	tree := make([][]int, n) // 子节点
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &parent[i], &counts[i])
		parent[i] -= 1 // 下标改成从0开始
		if parent[i] >= 0 {
			tree[parent[i]] = append(tree[parent[i]], i)
		}
	}

	rt := -1
	for i, p := range parent {
		if p == -1 {
			rt = i
			break
		}
	}

	var dfsOrder []int // 将dfs改成循环而非函数调用的形式
	stack := []int{rt}

	for len(stack) > 0 { // 获取dfs的顺序
		u := stack[len(stack)-1]
		stack = stack[:len(stack)-1]
		for _, v := range tree[u] {
			stack = append(stack, v)
		}
		dfsOrder = append(dfsOrder, u)
	}

	ans := make([]int, n)
	nodes := make([][]int, n) // 用于根据已有答案将当前节点的所有子树根据编号结合起来，然后按顺序放到tmp中

	for i := len(dfsOrder) - 1; i > -1; i -= 1 { // 根据dfs顺序进行倒序遍历
		node := dfsOrder[i]
		stack = []int{node} // 初始化栈，用于遍历当前节点的子树
		for len(stack) > 0 {
			u := stack[len(stack)-1]
			stack = stack[:len(stack)-1]
			for _, v := range tree[u] {
				stack = append(stack, v)
				nodes[ans[v]] = append(nodes[ans[v]], v) // 将子节点加入到相应的编号列表中
			}
		}
		// 合并当前节点及其子节点
		var tmp []int
		for j := 1; j < n; j++ {
			if len(nodes[j]) == 0 {
				break
			}
			tmp = append(tmp, nodes[j]...) // 合并节点
			nodes[j] = nil
		}
		if len(tmp) < counts[node] { // 如果子树中元素不足k，直接返回 'NO'
			fmt.Fprintf(out, "NO")
			return
		}

		tmp = append(tmp[:counts[node]], append([]int{node}, tmp[counts[node]:]...)...) // 插入当前节点到 tmp 的指定位置
		for j, v := range tmp {                                                         // 更新节点在结果数组中的位置
			ans[v] = j + 1
		}
	}

	fmt.Fprintf(out, "YES\n")
	for _, v := range ans {
		fmt.Fprintf(out, "%d ", v)
	}
}
