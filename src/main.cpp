#include <iostream>
#include <vector>

int main() {
    int width = 25;
    int height = 25;

    std::vector<int> v = {};

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            v.push_back((i * width + j));
        }
    }

    for (int val : v) {
        std::cout << val << ' ';
    }

    return 0;
}