# mini_exercise5
https://github.com/eranshamdani-sys/mini_exercise5

Task 3:
This program printed 15381 instead of the expected 20000 because the ++ operation is not atomic.
This operation actually involves three steps:
1. Read the current value of bar from memory
2. Add 1 to that value
3. Write the result back to bar
When two threads execute bar++ at the same time, their operations can interleave, adding one instead of the expected 2.
This happens when one thread is stoped right before step 3, and then the OS starts the second thread.
So when the OS gives the CPU back to the first thread it puts in bar the old bar (even if the second thread added 1000 in that time)

Task 4:
The keyword synchronized makes it so only one thread can run the method at any given time.

Task 5:
synchronized(this) acts to help synchronization. When we use it on a block of code, that block can be run only from one thread in every specific instance of the class at any given time.

Task 6:
This code does the same as the first code but bigger, instead of 2 threads for 10,000 we use 10 threads for 100,000,000.
We also print the time it took, which is around 20-30 miliseconds.

Task 7:
Now we add to this code the synchronized(this) and we can see how much longer we have to wait.
We now get the right output of 10*10,000,000=100,000,000. But now it take around 4000 miliseconds (which even humans can notice as 4 seconds)
