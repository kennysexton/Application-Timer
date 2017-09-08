# Project1
by Kenny Sexton

## Psudo Code

### Application
```
repeat process many times {
  open up a file (w+ for read and write)
  generate a random character
  
    // Create a 10 line file each line with 120 rnd characters
  for (i=0 : 10){
    for(j=0 : 121){
      storage[i][j] = randomChar();
      fprintf // print randomChar to file
    }
   }
   
    // Pick a random line to read
	 randomLine();
   move filepointer to correct position
   fgets that line 
   
    // extract a smaller line array from the storage array
   for(i=0 : 121) {
      lineStorage[i] = storage[randomLine][i] 
   }
   
   use strcmp() to compare the read file to the stored line
   exit to program if (strcmp() != 0)
}
```
#### Functions

`randomChar()`  - generates a random number,  convert that number to ASCII equivilet and returns that char

`randomLine()`  - picks a random number 0-9 which will then detrmine what line to read

### Timer

