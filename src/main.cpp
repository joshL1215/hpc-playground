#include <iostream>
#include <vector>

inline int get_idx(int i, int j, int width) {
    return i * width + j;
}

int main() {
    int WIDTH = 25;
    int HEIGHT = 25;
    int ITERATIONS = 100;

    std::vector<int> input(WIDTH * HEIGHT, 0);

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            int center = get_idx(i, j, WIDTH);
            input[center] = i;
        }
    }

    std::vector<int> output(WIDTH * HEIGHT, 0);

    for (int it = 0; it < ITERATIONS; it++) {
        for (int i = 0; i < HEIGHT; i++) {
            for (int j = 0; j < WIDTH; j++) {
                int center = get_idx(i, j, WIDTH);
                int d_up = 0, d_right = 0, d_down = 0, d_left = 0;

                if (j > 0)
                    d_left = input[center - 1];
                if (j < WIDTH - 1)
                    d_right = input[center + 1];
                if (i > 0)
                    d_up = input[center - WIDTH];
                if (i < HEIGHT - 1)
                    d_down = input[center + WIDTH];

                output[center] = input[center] + d_up + d_right + d_down + d_left;
            }
        }
        std::swap(input, output);
    }

    for (int val : output) {
        std::cout << val << ' ';
    }

    std::cout << '\n' << "-------------------------------" << '\n';

    for (int val : input) {
        std::cout << val << ' ';
    }

    return 0;
}