# Direct Proof

Prove that there are no natural numbers $a$ and $n$ ($n \ge 2$) such that $a^2 + 1 = 2^n$

We will prove this by contradiction. That is, suppose if there exists natural numbers $a$ and $n$ then $a^2 + 1 = 2^n$.

Using algebra we can rewrite the equation
$$
\begin{align*}
a^2 + 1 &= 2^n
\\ a^2 &= 2^n - 1
\end{align*}
$$

[Prove $RHS$ of above equation is odd]\
On the above equation, $2^n$ on given interval $n \ge 2$, using algebra we can writie this as:
$$
2(2^{n-1})
$$
By letting $k = 2^{n-1}$, we can write the above as $2k$.
Thus, by definition of even numbers, on the given interval, $2^n$ is even.

Subsituting $2k$ into the given equation $a^2 = 2^n - 1$, we get
$$
a^2 = 2k-1
$$
Thus, the $RHS$ of the above equation must be odd, because using algebra it can be written as $2(k-1) + 1$ which satisifies the definition of odd numbers.

[$LHS$ must be odd] \
Since the $RHS$ of $a^2 = 2^n - 1$  is proven to be odd, then the $LHS$ must also be an odd number

Thus, we can define $a$ as $2j + 1$ by the definition of odd. Substituting this into the equation, we get
$$
(2j+1)^2 = 2(k-1) + 1
$$

Using algebra on the above equation, it simplifies to

$$
\begin{align*}
(2j+1)^2 &= 2(k-1) + 1
\\ 4j^2+4j+1&=2k−1
\\ 2j^2+2j+2&=k+1
\\ 2j^2+2j+1&=2^{n-1}
\\ 2(j^2+j)+1&=2^{n-1}
\end{align*}
$$
On the $LHS$ of this equation, $2(j^2+j)+1$ satisfies the definition of odd numbers. However, on the $RHS$, $2^{n-1}$ has been proven to be even. Therefore, we have proven that there are no natural numbers $a$ and $n$ that satisfy $a^2 + 1 = 2^n$


