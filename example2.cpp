extern "C"{
void(*C_Callback)(int); //c callback pointer
}

#include <iostream>
#include<functional>
using namespace std;

class A{
    int exampleVar=333;
    A(){

    }
public:
    static A& getinst(){
        static A obj;
        return obj;
    }

    void callbackCpp(int m){
        std::cout<<"localVariable = "<<m<<" c++ class private filed = "<<exampleVar<<std::endl;
    }
};

int main()
{
    C_Callback=[](int n){ A::getinst().callbackCpp(n);};
    C_Callback(3);
}
