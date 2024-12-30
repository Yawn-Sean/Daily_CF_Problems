package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
)

var offset = []int{1, 0, -1, 0, 1}

func main() { CF1105D(os.Stdin, os.Stdout) }

func CF1105D(_r io.Reader, out io.Writer) {
	in := bufio.NewReader(_r)
	var n, m, p int
	fmt.Fscan(in, &n, &m, &p)
	s := make([]int, p)
	for i := 0; i < p; i++ {
		fmt.Fscan(in, &s[i])
	}
	q := make([][][]int, p)
	var tmp string
	vis := make([][]bool, n)
	for i := 0; i < n; i++ {
		vis[i] = make([]bool, m)
	}
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &tmp)
		for j := 0; j < m; j++ {
			if tmp[j] == '#' {
				vis[i][j] = true
			} else if tmp[j] != '.' {
				vis[i][j] = true
				c := tmp[j] - '1'
				q[c] = append(q[c], []int{i, j})
			}
		}
	}
	ans := make([]int, p)
	cnt := 0
	for i := 0; i < p; i++ {
		if len(q[i]) == 0 {
			cnt++
		}
	}
	for cnt < p {
		for i := 0; i < p; i++ {
			if len(q[i]) == 0 {
				continue
			}
			for k := 0; k < s[i]; k++ {
				ans[i] += len(q[i])
				size := len(q[i])
				for j := 0; j < size; j++ {
					cur := q[i][0]
					q[i] = q[i][1:]
					for a := 0; a < 4; a++ {
						x, y := offset[a], offset[a+1]
						nx, ny := cur[0]+x, cur[1]+y
						if 0 <= nx && nx < n && 0 <= ny && ny < m && !vis[nx][ny] {
							vis[nx][ny] = true
							q[i] = append(q[i], []int{nx, ny})
						}
					}
				}
				if len(q[i]) == 0 {
					break
				}
			}
			if len(q[i]) == 0 {
				cnt++
			}
		}
	}
	for i := 0; i < p; i++ {
		fmt.Fprintf(out, "%d ", ans[i])
	}
}
