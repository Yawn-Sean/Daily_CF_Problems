先引入题目中的变量，上底 $b_1$，下底 $b_2$，高 $h$

则总面积为 $S:=\dfrac{(b_1+b_2)h}{2}$

设上面的三角形的高度为 $h_1:=x$，则下面的三角形的高度为 $h_2:=h-x$

上面的三角形的面积，$S_1:=\dfrac{b_1h_1}{2}=\dfrac{b_1}{2}x$

下面的三角形的面积，$S_2:=\dfrac{b_2h_2}{2}=-\dfrac{b_2}{2}x+\dfrac{b_2h}{2}$

侧面的单个三角形的面积，

$$
\begin{eqnarray}
S_3:&=&\frac{S-S_1-S_2}{2} \\
&=&\frac{(b_1+b_2)h-b_1x+b_2x-b_2h}{4} \\
&=&\frac{b_1h+(b_2-b_1)x}{4} \\
&=&\frac{b_2-b_1}{4}x+\frac{b_1h}{4}
\end{eqnarray}
$$

$S_1,S_2,S_3$ 每一个函数都是一次函数，因为 $\vert S_i(x)-S_j(x)\vert$ 很难分析，所以不妨取平方

令 $f_{ij}(x):=\left(S_i(x)-S_j(x)\right)^2\,(i\ne j)$

取平方之后，我们会得到形如 $ax^2+bx+c\,(a>0)$ 的二次函数

#### $\mathbf{a>0}$ 的二次函数是凸函数

[Wiki](https://zh.wikipedia.org/wiki/%E5%87%B8%E5%87%BD%E6%95%B0#%E4%B8%80%E5%85%83%E6%83%85%E6%B3%81)

设 $f(x)=ax^2+bx+c\,(a>0)$，则有 $f''(x)=2a>0$，因此 $f$ 为严格凸函数

#### 凸函数取 $\mathbf{max}$ 是凸函数

设 $f, g: \mathbb{R}^n\rightarrow\mathbb{R}$ 为凸函数，定义 $h(x) = \max(f(x), g(x))$

$\forall\,x, y \in \mathbb{R}^n$ 和 $\lambda \in [0,1]$，令 $z = \lambda x + (1-\lambda) y$，不妨设 $h(z) = f(z)$（若 $h(z) = g(z)$，证明类似）

由 $f$ 的凸性有：

$$
f(z) \le \lambda f(x) + (1-\lambda) f(y)
$$

又因为 $f(x) \le h(x)$ 和 $f(y) \le h(y)$，所以

$$
\lambda f(x) + (1-\lambda) f(y) \le \lambda h(x) + (1-\lambda) h(y)
$$

于是 $h(z) \le \lambda h(x) + (1-\lambda) h(y)$，满足凸函数定义，故 $h$ 为凸函数。

因此 $\max\{f_{12}(x),f_{13}(x),f_{23}(x)\}=\max\{f_{12}(x),\max\{f_{13}(x),f_{23}(x)\}\}$ 是凸函数，可以**三分求解**

<!--

作差：

$$
\begin{eqnarray}
S_1-S_2&=&\frac{b_1}{2}x-\left(-\frac{b_2}{2}x+\frac{b_2h}{2}\right) \\
&=&\frac{b_1+b_2}{2}x-\frac{b_2h}{2}
\end{eqnarray}
$$

$$
\begin{eqnarray}
S_1-S_3&=&\frac{b_1}{2}x-\left(\frac{b_2-b_1}{4}x+\frac{b_1h}{4}\right) \\
&=&\frac{3b_1-b_2}{4}x-\frac{b_1h}{4}
\end{eqnarray}
$$

$$
\begin{eqnarray}
S_2-S_3&=&\left(-\frac{b_2}{2}x+\frac{b_2h}{2}\right)-\left(\frac{b_2-b_1}{4}x+\frac{b_1h}{4}\right) \\
&=&\frac{b_1-3b_2}{4}x+\frac{(2b_2-b_1)h}{4}
\end{eqnarray}
$$

--!>
