# brent method

in Quantlib, they are using `brent` method to solve the option implied volatility. I hereby have a try of this method, and found out that it actually slower than bisection method. However, some math knowledge I picked up is quite interesting.

- Lagrange Polynomial

for a data set with k points $\{x_i,y_j\}$, we can design a lagrange polynomial to make an assumption of any input $x$.
$$
l_j(x)=\prod_{i\ne j, 0\le i \le k}\frac{(x-x_i)}{(x_j-x_i)}
$$
The basic meaning of $l_j(x)$  is that, for any input $x$, $l_j(x)=0$ if $x\ne x_j$, and $l_j(x)=1$ if $x=x_j$

Therefore, the lagrange polynomial is
$$
L(x) = \sum_{0\le j\le k}l_j(x)
$$

- Brent method

In brent method, it use lagrange polynomial to estimate the root, by assigning $x=0$

Suppose, we want to find the root of $f(x)=0$, and we have three points from the previous three iterations: $(a, f(a)), (b, f(a)), (c, f(c))$

The lagrange polynomial is 
$$
x=\frac{(x-b)(x-c)}{(f(a)-f(b))(f(a)-f(c))}a+\frac{(x-a)(x-c)}{(f(b)-f(a))(f(b)-f(c))}b+\frac{(x-a)(x-b)}{(f(c)-f(a))(f(c)-f(b))}c
$$
letting $x=0$, we have the **inverse quadratic interpolation** from these three points.

brent method estimate the root by adopting the effective inverse quadratic interpolation by some rules. If the interpolation is invalid, the bisection method is used instead.