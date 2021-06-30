import math
import sys


h = input()
d = int(h, 16) * 5**(4 * len(h))

limit = int(len(h) * math.log10(16)) - 2  # ~=len(h)*1.20

print(str(d)[:limit], end='')

