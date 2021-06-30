#include <stdio.h>
#include <stdlib.h>
#define lint long long int
#define ldouble long double

#define rep2(i, n) for (lint i = 0; i < (lint)n; i++)
#define rep3(i, a, n) for (lint i = a; i < (lint)n; i++)
#define rep4(i, a, n, d) for (lint i = a; i < (lint)n; i += d)

lint modpow(lint n, lint p, lint mod)
{
  if (p == 0)
    return 1;
  if (p % 2 == 1)
    return (n * modpow(n, p - 1, mod)) % mod;

  lint t = modpow(n, p / 2, mod);
  return t * t % mod;
}

ldouble frac(ldouble x)
{
  return x - (lint)x;
}

ldouble s(int j, lint d)
{
  ldouble ret = 0.;
  rep2(n, d + 1)
  {
    ret += (ldouble)modpow(16, d - n, 8 * n + j) / (8 * n + j);
  }
  return ret;
}

ldouble fs(int j, lint d)
{
  return frac(s(j, d));
}

// Digits   Time
// 0-1e4    1m21s138
// 1e4-2e4  4m37s972
// 2e4-3e4  8m07s255
// 0-1e5    37m(*8)

// ./argv[0] [DIGITS] [FROM]
int main(int argc, char **argv)
{
  lint FROM = 0;
  lint DIGITS = 1000;
  if (argc > 1)
  {
    DIGITS = atoi(argv[1]);
  }
  if (argc > 2)
  {
    FROM = atoi(argv[2]);
  }

  rep3(d, FROM, DIGITS)
  {
    ldouble dpid = frac(4 * fs(1, d) - 2 * fs(4, d) - fs(5, d) - fs(6, d) + 4);

    int pid = ((lint)(dpid * 16)) % 16;

    printf("%X", pid);
    // if (0 <= pid && pid <= 9)
    // {
    //   putchar('0' + pid);
    // }
    // else if (10 <= pid && pid <= 15)
    // {
    //   putchar('A' + (pid - 10));
    // }
  }
  return 0;
}
