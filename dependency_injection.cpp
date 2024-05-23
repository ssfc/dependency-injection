//
// Created by take_ on 24-5-23.
//
#include <iostream>
#include <random>
#include <memory>

class InnerClass {
public:
    InnerClass(std::mt19937& gen) : randGen(gen) {}

    void doSomething() {
        std::uniform_int_distribution<int> dist(1, 100);
        std::cout << "InnerClass random number: " << dist(randGen) << std::endl;
    }

private:
    std::mt19937& randGen;
};

class OuterClass {
public:
    OuterClass(std::mt19937& gen) : randGen(gen), inner(gen) {}

    void doSomething() {
        std::uniform_int_distribution<int> dist(1, 100);
        std::cout << "OuterClass random number: " << dist(randGen) << std::endl;
        inner.doSomething();
    }

private:
    std::mt19937& randGen;
    InnerClass inner;
};

int main() {
    std::mt19937 gen(42);  // 使用固定种子42初始化随机数生成器

    OuterClass outer_class(gen);
    outer_class.doSomething();

    return 0;
}
