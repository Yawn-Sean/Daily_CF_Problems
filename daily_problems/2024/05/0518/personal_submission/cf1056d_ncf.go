package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func main() { CF1056D(os.Stdin, os.Stdout) }

func CF1056D(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var n, c int
	fmt.Fscan(in, &n)
	child := make([][]int, n+1)
	for i := 2; i <= n; i++ {
		fmt.Fscan(in, &c)
		child[c] = append(child[c], i)
	}
	m := map[int]int{}
	var dfs func(cur int) int
	dfs = func(cur int) int {
		if len(child[cur]) == 0 {
			m[1] += 1
			return 1
		}
		res := 0
		for _, e := range child[cur] {
			res += dfs(e)
		}
		m[res] += 1
		return res
	}
	dfs(1)
	val := 1
	count := 0
	for i := 1; i <= n; i++ {
		for count < i {
			if m[val] > 0 {
				count += m[val]
			}
			val += 1
		}
		fmt.Fprintf(out, "%d ", val-1)
	}
}
