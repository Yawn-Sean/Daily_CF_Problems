package main

import (
	"bufio"
	"fmt"
	"os"
)

func solve(in *bufio.Reader, out *bufio.Writer) {
	var k int
	fmt.Fscan(in, &k)
	if k%2 == 0 {
		fmt.Fprintln(out, "NO")
		return
	}
	fmt.Fprintln(out, "YES")
	fmt.Fprintln(out, 4*k-2, k*(2*k-1))
	type edge struct{ u, v int }
	edges := make([]edge, 0, k*(2*k-1))
	edges = append(edges, edge{1, 2 * k})
	add := func(base int) {
		for i := 1 + base; i < base+k; i++ {
			edges = append(edges, edge{base, i})
		}
		for i := 1 + base; i < base+k; i++ {
			for j := base + k; j < base+2*k-1; j++ {
				edges = append(edges, edge{i, j})
			}
		}
		for i := base + k; i < base+2*k-1; i += 2 {
			edges = append(edges, edge{i, i + 1})
		}
	}
	add(1)
	add(2 * k)
	for i := range edges {
		fmt.Fprintln(out, edges[i].u, edges[i].v)
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
