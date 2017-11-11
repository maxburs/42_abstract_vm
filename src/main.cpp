#include <iostream>
#include <abstract_vm.h>
#include <iostream> //cin, ofstream
#include <istream> //ifstream
#include <fstream>

int main(int argc, char** argv)
{
    if (argc > 1) {
        std::ifstream file;

        file.open(argv[1]);

        AbstractVM vm(file);

        vm.run();

        file.close();
    }
    else {
        AbstractVM vm(std::cin);

        vm.run();
    }

    return 0;
}
