#include <iostream>

#include <chorus/server.h>

int main(void)
{
    // Creating a server that listens on port 7000
    chorus::Server srv(7000);

    // Binding a lambda function to the name "add".
    srv.bind("add", [](int a, int b) {
        return a + b;
    });

    // Run the server loop.
    srv.run();
    return 0;
}