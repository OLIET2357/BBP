import math
import sys


h = input()
d = int(h, 16) * 5**(4 * len(h))

limit = int(len(h) * math.log10(16)) - 2  # ~=len(h)*1.20

print(str(d)[:limit], end='')
exit()


def ketakugiri(s, keta):
  if keta == 0:
    return s
  ret = ''
  for i, c in enumerate(s):
    ret += c
    if (i + 1) % keta == 0:
      ret += ' '
  return ret


print(limit)

KETA = 10
if len(sys.argv) > 1:
  KETA = int(sys.argv[1])

print(ketakugiri(str(d)[:limit], KETA))
print()

padding = ''
if KETA != 0:
  padding = ' ' * (limit % KETA)

print('[%s]' % ketakugiri(padding + str(d)[limit:], KETA))
