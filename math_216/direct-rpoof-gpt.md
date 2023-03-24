Suppose there exist natural numbers $a$ and $n$ ($n \ge 2$) such that $a^2 + 1 = 2^n$. We can rewrite this as $a^2 = 2^n - 1$. Since $n \ge 2$, $2^n$ is even and $2^n-1$ is odd. Thus, we can write $2^n-1$ as the product of an odd number and a power of 2, i.e., $2^n-1 = 2^k \cdot m + 1$ for some natural number $k$ and odd number $m$.

Substituting this expression for $2^n-1$ into the equation $a^2 = 2^n-1$, we get:

$$a^2 = 2^k \cdot m + 1$$

Since $a^2$ is odd if and only if $a$ is odd, we know that $a$ must be odd. Let $a = 2b+1$ for some natural number $b$. Substituting this expression for $a$ into the equation $a^2 = 2^k \cdot m + 1$, we get:

$$(2b+1)^2 = 2^k \cdot m + 1$$

Expanding the left-hand side, we get:

$$4b^2 + 4b + 1 = 2^k \cdot m + 1$$

Subtracting 1 from both sides and factoring, we get:

$$(2b+1)(2b) = 2^k \cdot m$$

Since $2b+1$ and $2b$ are consecutive odd and even numbers, one of them must be divisible by an odd prime. However, the right-hand side of the equation is divisible by 2 but not by any odd prime, since $m$ is odd and $2^k$ is a power of 2. This is a contradiction, so our assumption that there exist natural numbers $a$ and $n$ ($n \ge 2$) such that $a^2 + 1 = 2^n$ must be false.

Therefore, there are no natural numbers $a$ and $n$ ($n \ge 2$) such that $a^2 + 1 = 2^n$.