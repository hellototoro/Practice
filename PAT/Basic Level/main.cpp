#include <iostream>
#include <vector>

extern int _1004(void);
extern int _1006(void);
extern int _1007(void);
extern int _1005(void);

void test()
{
    std::vector<int> v{ 1,2,3,4 };
    auto it = std::find(v.begin(), v.end(), 4);
    auto e = v.end();
    std::cout << *e;
}

int main()
{
    //_1004();
    //_1006();
    _1005();
    //test();
    return 0;
}