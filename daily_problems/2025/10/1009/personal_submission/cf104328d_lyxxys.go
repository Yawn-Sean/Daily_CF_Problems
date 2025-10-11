package main

import (
	"bufio"
	. "fmt"
	"io"
	"os"
)

const tot = 10000000

var mip [tot + 1]int

func init() {
	for i := range mip {
		mip[i] = i
	}
	for i := 2; i*i <= tot; i++ {
		if mip[i] == i {
			for j := i * i; j <= tot; j += i {
				if mip[j] == j {
					mip[j] = i
				}
			}
		}
	}
}

func cf104328D(in io.Reader, out io.Writer) {
	var n int
	Fscan(in, &n)
	
	st := make([]int, n)
	f := make([]map[int]int, n)
	g := make([][]int, n)

	for i := 0; i < n; i++ {
		f[i] = make(map[int]int, 5) 
		g[i] = make([]int, 0, 3)   
	}
	for i := 0; i < n; i++ {
		var x int
		Fscan(in, &x)
		for x > 1 {
			p := mip[x]
			f[i][p] = 1
			for x%p == 0 {
				x /= p
			}
		}
	}

	for i := 0; i < n-1; i++ {
		var u, v int
		Fscan(in, &u, &v)
		u, v = u-1, v-1
		g[u] = append(g[u], v)
		g[v] = append(g[v], u)
	}

	diameter := 1

	stack := make([]int, 0, n)
	parent := make([]int, n)
	for i := range parent {
		parent[i] = -1
	}

	order := make([]int, 0, n)
	stack = append(stack, 0)
	st[0] = 1

	for len(stack) > 0 {
		u := stack[len(stack)-1]
		stack = stack[:len(stack)-1]
		order = append(order, u)

		for _, v := range g[u] {
			if v != parent[u] {
				parent[v] = u
				st[v] = 1
				stack = append(stack, v)
			}
		}
	}

	for i := len(order) - 1; i >= 0; i-- {
		u := order[i]
		for _, v := range g[u] {
			if v == parent[u] {
				continue
			}
			for p, d1 := range f[u] {
				if d2, exists := f[v][p]; exists {
					if d1+d2 > diameter {
						diameter = d1 + d2
					}
					if d2+1 > d1 {
						f[u][p] = d2 + 1
					}
				}
			}
		}
	}

	if diameter > n/2 {
		Fprintln(out, "YES")
	} else {
		Fprintln(out, "NO")
	}
}

func main() {
	cf104328D(bufio.NewReader(os.Stdin), os.Stdout)
}
