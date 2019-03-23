# SimCorpDevChallenge
SimCorp DEV Challenge

Build:
* `make`  - build executable
* `make doc` - generate Doxygen Docs
* `make clean` - cleanup directory

Usage:
```
solver.exe [OPTION] -i INPUT_FILE
OPTIONS:
-i        input filename
-h        show this message and exit
```

Sample Input:
```
cat data/input.txt 
1,23,3,,,,44,5,76,767,65,5,-7,-77,-86,55,-67,54,-1,0,1,2,-1,-4
```

Sample Output:
 ```
./solver.exe -i data/input.txt 
-77,1,76,
-77,23,54,
-67,2,65,
-67,23,44,
-7,2,5,
-4,-1,5,
-4,1,3,
-1,-1,2,
-1,0,1,
```
enjoy)
