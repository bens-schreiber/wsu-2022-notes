from pickle import TRUE
import sys
import os
from pathlib import Path

if (len(sys.argv) < 2):
    print("file arg needed")
    exit()

c_files = " ".join([str(path.absolute()) for path in Path(sys.argv[1]).rglob("*.c")])
print(f"gcc {c_files}");
os.system(
    f"gcc {c_files} && ./a.out"
)