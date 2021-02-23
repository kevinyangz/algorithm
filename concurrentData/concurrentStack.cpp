
#include "../common.h"
#include <condition_variable>
#include <thread>
#include "singleDesignPattern.hpp"
 class single;
single* single::master;

int main()
{
    single* a = single::getInstance();
    single* b = single::getInstance();
    //single* c = single::getInstance();
    return 0;
}