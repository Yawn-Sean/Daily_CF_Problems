package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

func CF1044B(_r io.Reader, _w io.Writer) {
	in := bufio.NewReader(_r)
	out := bufio.NewWriter(_w)
	defer out.Flush()

	var t int
	fmt.Fscan(in, &t)
	for t > 0 {
		t--
		var n int
		fmt.Fscan(in, &n)
		path := make([][]int, n)
		for i := 0; i < n-1; i++ {
			var u, v int
			fmt.Fscan(in, &u, &v)
			u--
			v--
			path[u] = append(path[u], v)
			path[v] = append(path[v], u)
		}

		var k1 int
		fmt.Fscan(in, &k1)
		nodes1 := make([]int, k1)
		for i := range nodes1 {
			fmt.Fscan(in, &nodes1[i])
			nodes1[i]--
		}

		var k2 int
		fmt.Fscan(in, &k2)
		nodes2 := make([]int, k2)
		for i := range nodes2 {
			fmt.Fscan(in, &nodes2[i])
			nodes2[i]--
		}

		vis1 := make([]bool, n)
		vis2 := make([]bool, n)
		for _, v := range nodes1 {
			vis1[v] = true
		}
		for _, v := range nodes2 {
			vis2[v] = true
		}

		var node int
		fmt.Fprintf(out, "B %d\n", nodes2[0]+1)
		out.Flush()
		fmt.Fscan(in, &node)
		node--
		if vis1[node] {
			fmt.Fprintf(out, "C %d\n", node+1)
			out.Flush()
		} else {
			vis := make([]bool, n)
			vis[node] = true
			q := []int{node}
			for len(q) > 0 {
				u := q[0]
				q = q[1:]
				if vis1[u] {
					fmt.Fprintf(out, "A %d\n", u+1)
					out.Flush()
					fmt.Fscan(in, &node)
					node--
					if vis2[node] {
						fmt.Fprintf(out, "C %d\n", u+1)
					} else {
						fmt.Fprintln(out, "C -1")
					}
					out.Flush()
					break
				}
				for _, v := range path[u] {
					if !vis[v] {
						vis[v] = true
						q = append(q, v)
					}
				}
			}
		}
	}
}

func main() {
	CF1044B(bufio.NewReader(os.Stdin), os.Stdout)
}
