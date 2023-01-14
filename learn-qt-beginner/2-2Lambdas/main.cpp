#include <iostream>

using namespace std;

int main()
{

    /*
        * [capture list] (parameter list)-> return_value_type {function body}
    */

    /*
     * // Give lambda function a name and call it
    auto func = [](){
        cout << "Hello World!" << endl;
    };

    func();
    */

    /*
     * // Call lambda function directly after definition
    [](){
            cout << "Hello World!" << endl;
        }();
    */

    /*
    // Define a lambda function that takes parameters
    [](int a, int b){
      cout << "a + b = " << a + b << endl;
    }(7, 3);

    */

    /*
    // Define a lambda that returns something
    int sum = [](int a, int b)->int{
      return a + b;
    }(7, 3);

    cout << "The sum is: " << sum << endl;
    */

    /*
    // Capture Lists
    int a = 7;
    int b = 3;

    [a, b]() {
       cout << "a is : " << a << endl;
       cout << "b is : " << b << endl;
       cout << "a + b is : " << a + b << endl;
    }();
    */

    /*
    // Caputreing by value
    int c = 42;

    auto func = [c](){
        cout << "The value of c is : " << c << endl;
    };

    for (int i = 1; i < 5; i++) {
        cout << "The outter value of c is: " << c << endl;
        func();
        c = c + 1;
    }
    */

    /*
    // Capturing by Reference
    int c = 42;

    auto func = [&c](){
        cout << "The inner value of c is : " << c << endl;
    };

    for (int i = 1; i < 5; i++) {
        cout << "The outter value of c is: " << c << endl;
        func();
        c = c + 1;
    }
    */

    /*
    // Capture everything by value
    int c = 42;
    int d = 6;

    auto func = [=](){
        cout << "The inner value of c is : " << c << endl;
        cout << "The inner value of d is : " << d << endl;
    };

    for (int i = 1; i < 5; i++) {
        cout << "The outter value of c is: " << c << endl;
        func();
        c = c + 1;
    }
    */

    // Capture everything by reference
    int c = 42;
    int d = 6;

    auto func = [&](){
        cout << "The inner value of c is : " << c << endl;
        cout << "The inner value of d is : " << d << endl;
    };

    for (int i = 1; i < 5; i++) {
        cout << "The outter value of c is: " << c << endl;
        func();
        c = c + 1;
    }

    return 0;
}
