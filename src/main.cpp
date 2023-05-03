#include <iostream>
#include <random>
#include <vector>
#include <ctime>

float generate_next_random_price(float start, std::mt19937& rng) {

    float dt = 0.01;

    std::normal_distribution<float> normal_dist(0.0, std::sqrt(dt));

    float random_step = normal_dist(rng);
    float next_price = start += random_step;

    return next_price;
}

int main() {

    int num_steps = 50;
    float price = 10.11;

    std::mt19937 rng(static_cast<unsigned>(std::time(nullptr)));

    std::vector<float> brownian_motion;
    brownian_motion.push_back(price);

    for (int i=0; i < num_steps; i++) {
        price = generate_next_random_price(price, rng);
        brownian_motion.push_back(price);
        std::cout << price << std::endl;
    }
}