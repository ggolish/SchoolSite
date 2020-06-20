
import sys

if len(sys.argv) != 2:
    sys.stderr.write("Usage: {} <filename>\n".format(sys.argv[0]))
    sys.exit(1)

with open(sys.argv[1], "r") as fd:
    n = len(fd.readlines())

print(n)
