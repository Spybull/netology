#ifndef GREETER_H_
#define GREETER_H_

#include <iostream>
#include <string>

class Greeter {
    public:
        const std::string greet(const std::string &name) const;
};

#endif