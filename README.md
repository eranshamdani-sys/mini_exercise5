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
