#include <noise.h>
#include "httplib.h"
#include <iostream>

void srv() {
    std::cout << "# server is up and running..." << std::endl;
    // HTTP
    httplib::Server svr;
    svr.Get("/hi", [](const httplib::Request &, httplib::Response &res) {
        res.set_content("Hello World!", "text/plain");
    });

    svr.listen("0.0.0.0", 9999);
}

void client() {
    std::cout << "# client sending..." << std::endl;

    // HTTP
    httplib::Client cli("localhost:9999");
    auto res = cli.Get("/hi");
    std::cout << "Received status : " << res->status << std::endl;
    std::cout << "Received body   : " << res->body << std::endl;
}

int main(int argc, char *argv[]) {
    if (argc > 1) {
        std::string argvStr{argv[1]};
        std::string serverFlag{"-s"};

        const bool isServer = (argvStr.compare(serverFlag) == 0);
        std::cout << std::boolalpha << "server side: " << isServer << std::endl;
        if (isServer == true) {
            srv();
        } 
        else {
            client();
        }
    } 
    else {
        client();
    }

    return 0;
}