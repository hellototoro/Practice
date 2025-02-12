#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class MultiPly {
public:
    MultiPly(int factor) : m_factor(factor) {}

    int operator()(int n) const {
        return n * m_factor;
    }

private:
    int m_factor;
};

int test() {
    std::vector<int> numbers = { 1, 2, 3, 4, 5 };
    std::vector<int> numbers2(numbers.size());
    int factor = 3;
    std::transform(numbers.begin(), numbers.end(), numbers2.begin(), MultiPly(factor));
    for (int num : numbers2) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}