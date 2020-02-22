#include "remove_file.h"
#include <iostream>
#include <unistd.h>
#include <cstdio>

void remove_file(std::string path) {

    if (remove(path.c_str()) != 0) {
        std::cout << "remove file[" << path << "] faild." << std::endl;
        return;
    }
        std::cout << "remove file[" << path << "] success." << std::endl;
    return;
}