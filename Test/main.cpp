#include <iostream>

extern int ref_test();
extern int test();

struct VectorCallBack {
    void operator()(int i) {
        std::cout << i << std::endl;
    };
};

int main()
{
    std::cout << "Start Test!" << std::endl;
    //ref_test();
    test();
    return 0;
}