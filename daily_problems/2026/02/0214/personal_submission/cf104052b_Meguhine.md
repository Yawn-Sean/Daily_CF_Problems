设有：

- $x$ 个 $(2,1,1,0)$
- $y$ 个 $(2,0,2,0)$
- $z$ 个 $(1,1,2,1)$
- $S:=x+y+z$

显然可以二分 $S$ 这个答案，那么得到方程组：

$$
\left\{
\begin{array}{l}
x+y+z = S \\
2x+2y+z \le a \\
x+z \le b \\
x+2y+2z \le c \\
z \le d
\end{array}
\right.
$$

把 $x+z$ 替换成 $S-y$

$$
\left\{
\begin{array}{l}
S+y+x \le a \\
S-y \le b \\
S+y+z \le c \\
z \le d
\end{array}
\right.
$$

进一步整理，并加上 $x,y,z \ge 0$ 的限制

$$
\left\{
\begin{array}{l}
0 \le x \le a-(S+y) \\
\max(0,S-b) \le y \\
0 \le z \le \min(c-(S+y),d) \\
\end{array}
\right.
$$

对于 $x,z$ 而言，$y$ 越小，他们的限制越宽松

因此取 $y=\max(0,S-b)$，然后判断 $x,z$ 是否满足限制以及 $x+y+z\ge S$ 即可
