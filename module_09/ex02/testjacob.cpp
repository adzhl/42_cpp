#include "include/PmergeMe.hpp"


std::vector<size_t> generateJacobsthalIndices(size_t n) {
    std::vector<size_t> result;
    if (n == 0) return result;
    if (n == 1) {
        result.push_back(1);
        return (result);
    }

    std::vector<size_t> jacobsthal;
    if (n >= 1) jacobsthal.push_back(1);
    if (n >= 2) jacobsthal.push_back(3);
    
    size_t a = 1;
    size_t b = 3;
    while (true) {
        size_t next = b + 2 * a;
        if (next > n) break;
        jacobsthal.push_back(next);
        a = b;
        b = next;
    }
    // js = [1, 3, 5]
    // size = 5
    // next = 11 > 5 ; break
    // a = 3
    // b = 5

    // js = [1, 3, 5]
    // n = 5
    // end_pos = 3
    size_t prev_jacob = 1;
    for (size_t i = 1; i < jacobsthal.size(); ++i) {
        size_t current_jacob = jacobsthal[i];
        size_t end_pos = std::min(current_jacob, n);
    
        for (size_t pos = end_pos; pos > prev_jacob; --pos) {
            result.push_back(pos);
        }

        prev_jacob = current_jacob;
    }

    for (size_t pos = n; pos > prev_jacob; --pos) {
        result.push_back(pos);
    }

    return (result);
}

int main(int argc, char **argv) {
    (void)argc;
    std::vector<size_t> indices = generateJacobsthalIndices(atoi(argv[1]));
    printContainer(indices);
    return (0);
}
