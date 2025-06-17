#include "include/PmergeMe.hpp"


std::vector<size_t> generateJacobsthalIndices(size_t n) {
    std::vector<size_t> result;
    if (n == 0) return result;
    if (n == 1) {
        result.push_back(1);
        return (result);
    }

    // Generate Jacobsthal numbers: 1, 1, 3, 5, 11, 21, 43...
    std::vector<size_t> jacobsthal;
    if (n >= 1) jacobsthal.push_back(1);
    if (n >= 1) jacobsthal.push_back(1);
    
    size_t a = 1;
    size_t b = 1;
    while (true) {
        size_t next = b + 2 * a;
        if (next > n) break;
        jacobsthal.push_back(next);
        a = b;
        b = next;
    }

    size_t prev_jacob = 1;
    for (size_t i = 1; i < jacobsthal.size(); ++i) {
        size_t current_jacob = jacobsthal[i];
        // Clamp to available range
        size_t end_pos = std::min(current_jacob, n);
        
        // Insert from end_pos down to prev_jacob + 1 (in descending order)
        for (size_t pos = end_pos; pos > prev_jacob; --pos) {
            result.push_back(pos - 1); // Convert to 0-based index
        }
        
        prev_jacob = current_jacob;
    }
    
    // Handle remaining elements if any
    for (size_t pos = n; pos > prev_jacob; --pos) {
        result.push_back(pos - 1); // Convert to 0-based index
    }

    return result;
}

int main(int argc, char **argv) {
    (void)argc;
    std::vector<size_t> indices = generateJacobsthalIndices(atoi(argv[1]));
    printContainer(indices);
    return (0);
}