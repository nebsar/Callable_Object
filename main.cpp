/* 
 * File:   main.cpp
 * Author: Eagleye
 *
 * Created on September 11, 2018, 1:25 AM
 */

#include <thread>
#include <future>
#include <functional>
#include <mutex>

using namespace std;

class A {
public:

    void f(int x, char c) {
    }

    long g(double x) {
        return 0;
    }

    int operator()(int N) {
        return 0;
    }
};

void foo(int i){}

int main(int argc, char** argv) {
    A a;
    //// BELOW LINES OF CODE CALLS CALLABLE OBJECT IN A STANDART WAY ///////////
    thread t1(a, 6); // a copy of a() in a different thread.
    thread t2(ref(a),6); //same a() as a functor inside a different thread.
    thread t3(move(a),6); //a is moved to thread and a is not usable in main thread anymore
    thread t4 (A(),6); // temp A().
    thread t5 ([](int x){ return x*x;},6);// a lambda function can also be used
    thread t6 (foo,7); // function to a thread with arguments
    
    thread t7 (&A::f,a,8,'w');//copy of a and invoke a's f function in a different thread
    thread t8 (&A::f,&a,8,'w');// same a and invoke a's f function in a different thread    
    
   /* async(launch::async, a, 6);
    bind(a, 6);
    std::once_flag flag1;
    call_once(flag1, a, 6);*/
    ///////////////////////////////////////////////////////////////
    
    
    
    return 0;
}

