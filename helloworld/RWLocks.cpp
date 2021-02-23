
/*
    Reader comeing 
        -> Block Reader if there is writer 
        -> Block reader if there are two many Readers (exceed your allowence)
        -> Let reader in 
            Increment reader count 
            process 
            Decrement Reader count 
            Leave (Release the lock and signal others ? )
    
    Writer Coming:
        -> blocker writer if there are any readers
        -> Block writer if there are already a writer in 
            release lock and sleep or spinlock/ Busy Wait
        -> 
            Let writer in 
            inc writer Count 
            process
            decWriter count
            leave  (Release the look and signal others)

*/

#include <mutex>
#include <thread>
#include <condition_variable>
#include <iostream>

using namespace std;
#define ReaderCount 3
#define writerCount 0 


//singleton design here, you do want to intialize two RW locks 
class rwLock
{
    public:
        //Function behavior: Blocking API  
        // Non-Blocking  -> you acquire the ReadLock
        // Blocking  -> you did not get the Readlock
        acquireReadLock(){
           

            while(readerCounter >= ReaderCount || writerCount > 0)
            {
                cv.wait(lk);
            }

            readerCounter++;
          
            lk.unlock();
            //process your task 
        };
        releaseReadLock(){
             unique_lock<std::mutex> lk(m);
             readerCounter--;
             cv.notify_all();
        }
        acquireWriteLock(){};
        releasWriteLock(){};
        rwLock()
        {
            writeCounter = 0;
            readerCounter = 0;
        }
    private:
        int writeCounter;
        int readerCounter;
        mutex m;
        condition_variable cv;
};