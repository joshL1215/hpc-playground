#include <iostream>
#include <vector>

int main() {
    int WIDTH = 25;
    int HEIGHT = 25;

    std::vector<int> input(WIDTH * HEIGHT, 0);

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            input[i * WIDTH + j] = i;
        }
    }

    std::vector<int> output(WIDTH * HEIGHT, 0);

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            int d_up = 0, d_right = 0, d_down = 0, d_left = 0;
            if (j > 0 && j < WIDTH - 1) {
                d_right = input[i * WIDTH + j + 1];
                d_left = input[i * WIDTH + j - 1];
            }
            if (i > 0 && i < HEIGHT - 1) {
                d_up = input[(i - 1) * WIDTH + j];
                d_down = input[(i + 1) * WIDTH + j];
            }
            output[i * WIDTH + j] = input[i * WIDTH + j] + d_up + d_right + d_down + d_left;
        }
    }

    for (int val : input) {
        std::cout << val << ' ';
    }

    std::cout << '\n' << "-------------------------------" << '\n';

    for (int val : output) {
        std::cout << val << ' ';
    }

    return 0;
}