package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
)

func solve(in *bufio.Reader, out *bufio.Writer) {
	var n int
	fmt.Fscan(in, &n)
	x := make([]int, n)
	y := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &x[i], &y[i])
	}
	pos := make(map[int][]int)
	val := make([][]int, n)
	for i := 0; i < n; i++ {
		for j := 1; j*j <= x[i]; j++ {
			if x[i]%j != 0 {
				continue
			}
			val[i] = append(val[i], j)
			pos[j] = append(pos[j], i)
			if j*j != x[i] {
				val[i] = append(val[i], x[i]/j)
				pos[x[i]/j] = append(pos[x[i]/j], i)
			}
		}
	}
	for i := 0; i < n; i++ {
		cnt := 0
		for _, v := range val[i] {
			// 从pos[v]找到离i左边最近的点
			if len(pos[v]) == 0 {
				continue
			}
			t := sort.Search(len(pos[v]), func(j int) bool {
				return pos[v][j] >= i
			})
			t--
			if t < 0 || pos[v][t]+y[i] < i {
				cnt++
			}
		}
		fmt.Fprintln(out, cnt)
	}
}

func main() {
	in := bufio.NewReader(os.Stdin)
	out := bufio.NewWriter(os.Stdout)
	defer out.Flush()
	T := 1
	for t := 0; t < T; t++ {
		solve(in, out)
	}
}
