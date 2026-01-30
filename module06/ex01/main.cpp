#include"Serializer.hpp"

int main()
{
    Data data = {42};
    Data* original = &data;
    uintptr_t ptr = Serializer::serialize(&data);
    std::cout<<ptr<<std::endl;
    std::cout<<&data<<std::endl;
    std::cout<<original<<std::endl;
    Data* des = Serializer::deserialize(ptr);
    std::cout<<des<<std::endl;

    if(des == &data)
        std::cout<<"same"<<std::endl;
    else
        std::cout<<"not the same"<<std::endl;




}