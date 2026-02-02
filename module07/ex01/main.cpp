#include"iter.hpp"

int main()
{
     const std::string array[] = {"imane","iqor"};
     int nums[] = {1,2,3,4,5};
    size_t lenghArr = sizeof(array) / sizeof(array[0]);
    size_t lenghNums = sizeof(nums) / sizeof(int);
    
    iter(array,lenghArr,print);
    
    iter(nums,lenghNums,increment);
    iter(nums,lenghNums,print);


    // std::cout<<lengh<<std::endl;
}