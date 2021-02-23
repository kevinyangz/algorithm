#ifndef SPINLOCK_H
#define SPINLOCK_H

#include <thread>
#include <mutex>
class spinLock
{
    private:
        std::atomic_flag flag = ATOMIC_FLAG_INIT;
    public:
        spinLock(){}
        void lock()
        {
            while(flag.test_and_set());
        }

        void unlock()
        {
            flag.clear();
        }

};



#endif