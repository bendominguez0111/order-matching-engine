#include <iostream>
#include <random>
#include <vector>
#include <ctime>
#include <chrono>

enum Side {
    BUY,
    SELL
};

struct Order {
    int id;
    std::chrono::time_point<std::chrono::system_clock> time_submitted;
    float price;
    int quantity;
    Side side;
};

float generate_next_random_price(float start, std::mt19937& rng) {

    float dt = 0.0001;

    std::normal_distribution<float> normal_dist(0.0, std::sqrt(dt));

    float random_step = normal_dist(rng);
    float next_price = ceil((start += random_step) * 100) / 100;

    return next_price;
}

std::vector<float> generate_random_time_series_data(float price, int num_steps=100) {

    std::mt19937 rng(static_cast<unsigned>(std::time(nullptr)));

    std::vector<float> data;
    data.push_back(price);

    for (int i=0; i < num_steps; i++) {
        price = generate_next_random_price(price, rng);
        data.push_back(price);
    }

    return data;
}

int main() {

    int num_steps = 10000;
    float price = 10.11;

    Order my_order;
    my_order.id = 1;
    my_order.price = 10;
    my_order.quantity = 100;
    my_order.side = Side::BUY;

    std::vector data = generate_random_time_series_data(price, num_steps);
}