extern "C"{
    void(*C_Callback)(int); //c callback pointer 
}

#include <iostream>
#include<functional>
using namespace std;

class A{
    int exampleVar=333;
    static inline std::function<void(int)> func; //static object to bind class member
public:
    A(){
        using namespace std::placeholders;
        func=bind(&A::callbackCpp,this,_1);  //bind class member to static object
        //set C_Callback to lambda function. Lambda has acces to func static object
        C_Callback=[](int m){
                if (func)func(m);
        };
    }
    void callbackCpp(int m){
          std::cout<<"localVariable = "<<m<<" c++ class private filed = "<<exampleVar<<std::endl;
    }
};

int main()
{
   A a; //set C_Callback in class constructor
   C_Callback(3); //call C_Callback for test 
}
