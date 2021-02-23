#ifndef SINGLE_DESIGNPATTERN
#define SINGLE_DESIGNPATTERN
//
//#include "../common.h"
#include <thread>
#include <mutex>
#include <iostream>

class single
{
    public: 
        static single* getInstance()
        {
            if(master == NULL)
            {
                master = new single();
                return master;
            }
            else
            {
                 return master;
            }
           
        }

    private:
        static single* master;
        int temp;
        single(){
            std::cout<<" invoke constructor"<<" "<<std::endl;
            temp = 1;
        }
};



#endif

