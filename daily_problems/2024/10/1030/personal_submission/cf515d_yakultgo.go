package main

import (
	"bufio"
	"fmt"
	"os"
)

func solve(in *bufio.Reader, out *bufio.Writer) {
	var n, m int
	fmt.Fscan(in, &n, &m)
	str := make([][]byte, n)
	deg := make([][]int, n)
	for i := range str {
		str[i] = make([]byte, m)
		deg[i] = make([]int, m)
		fmt.Fscan(in, &str[i])
	}
	dirs := [4][2]int{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}
	check := func(x, y int) bool {
		return x >= 0 && x < n && y >= 0 && y < m
	}
	cnt := 0
	type pair struct{ f, s int }
	qu := make([]pair, 0, n*m)
	for i := 0; i < n; i++ {
		for j := range str[i] {
			if str[i][j] == '.' {
				cnt++
				for _, dir := range dirs {
					nx, ny := i+dir[0], j+dir[1]
					if check(nx, ny) && str[nx][ny] == '.' {
						deg[i][j]++
					}
				}
				if deg[i][j] == 1 {
					qu = append(qu, pair{i, j})
				}
			}
		}
	}
	for len(qu) > 0 {
		t := qu[0]
		qu = qu[1:]
		if str[t.f][t.s] == '*' || deg[t.f][t.s] != 1 {
			continue
		}
		for i := 0; i < 4; i++ {
			nx, ny := t.f+dirs[i][0], t.s+dirs[i][1]
			if check(nx, ny) && str[nx][ny] == '.' {
				if i == 0 {
					str[t.f][t.s] = 'v'
					str[nx][ny] = '^'
				} else if i == 1 {
					str[t.f][t.s] = '^'
					str[nx][ny] = 'v'
				} else if i == 2 {
					str[t.f][t.s] = '>'
					str[nx][ny] = '<'
				} else {
					str[t.f][t.s] = '<'
					str[nx][ny] = '>'
				}
				deg[nx][ny] = 0
				deg[t.f][t.s] = 0
				cnt -= 2
				for _, dir := range dirs {
					nnx, nny := nx+dir[0], ny+dir[1]
					if check(nnx, nny) && str[nnx][nny] == '.' {
						deg[nnx][nny]--
						if deg[nnx][nny] == 1 {
							qu = append(qu, pair{nnx, nny})
						}
					}
				}
			}
		}
	}
	if cnt == 0 {
		for i := range str {
			fmt.Fprintln(out, string(str[i]))
		}
	} else {
		fmt.Fprintln(out, "Not unique")
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
