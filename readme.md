# Project1
by Kenny Sexton

## Psudo Code


#### Application
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
   
   close file
}
```
##### Functions

`randomChar()`  - generates a random number,  convert that number to ASCII equivilet and returns that char

`randomLine()`  - picks a random number 0-9 which will then detrmine what line to read

`timeStamp()`  - Prints the current time in microseconds



#### Timer 1
```
for (i=0 : 100+){
  open up files for writing
  record timestamp
  fork()
  if (in child){
    exec(./application)
  }
  else { // on parent
    waitpid()
  }
  read start and end time files
  subtract(end - start) and write to seperate file
}
```
`timeStamp()`  - Prints the current time in microseconds

#### Timer 2
```
for (i=0 : 100+){
  open up files for writing
  record timestamp
  fork()
  if (in child){
    exec(./application)
  }
  else { // on parent
    waitpid()
  }
  
  fork2()
  if (in child){
    exec(./application)
  }
  else { // on parent
    waitpid()
  }
  read start and end time files
  subtract(end - start) and write to seperate file
}
```
`timeStamp()`  - Prints the current time in microseconds

## Testing

- [X] create a file
- [X] write a single line
- [X] put ten sequences in the file
- [X] check that application will generate new random sequences on every run
- [X] read from file succesfully
- [X] run strcmp & print both arrays to the screen
- [X] confirm that reading matches the file line

- [ ] create timer 1
- [ ] check outputs in excel
- [ ] check that outputs make sense
- [ ] create timer 2

## Questions

1.) What are the mean and standard deviation values for your observations?
> The mean is ___

2.) What is the 95% confidence level interval?

3.) Why shouldn't it always take exactly the same amount of time to perform this simple action of
program startup?
> The CPU has different tasks that are waiting on the execution queue.
