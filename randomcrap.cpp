#include <iostream>
int testvariable;
int testvariable1;
int main()
{
    testvariable = 0;
    testvariable1 = 0;
    std::cout << "Print test" << std::endl; // testing print here
    system("pause");
    std::cout << "Simple game incoming!" << std::endl; // testing another print here
    system("pause");
    if( testvariable == 0 ){
        std::cout << "test complete" << std::endl;
        system("pause");
    }

    while(testvariable1 <= 24){
        testvariable1 += 1;
        std::cout << "lmfao" << std::endl;

    }
}




