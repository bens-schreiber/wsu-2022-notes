import sys
import os
from pathlib import Path

if (len(sys.argv) < 2):
    print("file arg needed")
    exit()

# lol
c_files = " ".join(str(path.absolute()) for path in Path(sys.argv[1]).rglob("*.c") if "tmeasitn..cc"[len(sys.argv)==3 and"-t"==sys.argv[2]::2] not in path.name)

print(f"gcc {c_files}");
os.system(
    f"gcc {c_files} -I . && ./a.out"
)