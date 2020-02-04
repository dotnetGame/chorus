#include <iostream>

#include <chorus/client.h>

int main(void)
{
    chorus::Client client("127.0.0.1", 7000);
    // auto result = client.call("add", 2, 3).as<int>();
    // std::cout << "The result is: " << result << std::endl;
    return 0;
}