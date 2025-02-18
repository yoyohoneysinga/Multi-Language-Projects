#include <iostream>
#include <vector>

void primeFactors(int n, std::vector<int> &factors) {
    while (n % 2 == 0) {
        factors.push_back(2);
        n = n / 2;
    }

    for (int i = 3; i * i <= n; i = i + 2) {
        while (n % i == 0) {
            factors.push_back(i);
            n = n / i;
        }
    }

    if (n > 2) {
        factors.push_back(n);
    }
}

int main() {
    int n;
    std::cout << "Type a number and press enter: " << std::endl;
    std::cin >> n;

    std::vector<int> factors;

    primeFactors(n, factors);

    std::cout << n << " = ";
    for (size_t i = 0; i < factors.size(); i++) {
        if (i != 0) {
            std::cout << " * ";
        }
        std::cout << factors[i];
    }
    std::cout << std::endl;

    return 0;
}