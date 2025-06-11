package main

import (
	"bufio"
	"fmt"
	"io"
)

func cf1068C(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()

	/*

	 */
	var n, m int
	fmt.Fscan(in, &n, &m)
	ans := make([][][]int, n+1)
	for i := 1; i <= n; i++ {
		ans[i] = append(ans[i], []int{i, i})
	}

	for i := 0; i < m; i++ {
		var u, v int
		fmt.Fscan(in, &u, &v)
		ans[u] = append(ans[u], []int{n + 1 + i, u})
		ans[v] = append(ans[v], []int{n + 1 + i, v})
	}
	// Print ans.size
	for i := 1; i <= n; i++ {
		fmt.Fprintln(out, len(ans[i]))
		for _, v := range ans[i] {
			for _, x := range v {
				fmt.Fprintf(out, "%d ", x)
			}
			fmt.Fprintln(out, "")
		}
	}
}

//func main() {
//	cf1068C(bufio.NewReader(os.Stdin), os.Stdout)
//}
