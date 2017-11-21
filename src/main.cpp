#include <iostream>
#include <abstract_vm.h>
#include <fstream> //ifstream
#include <string> //string, getline
#include <sstream> //stringstream

int main(int argc, char** argv)
{
    int err;

    if (argc > 1) {
        std::ifstream file;

        // todo: handle bad filename error
        file.open(argv[1]);

        AbstractVM vm(file);

        err = vm.run();

        file.close();
    } else {
        std::stringstream instructions;
        std::string line;

        while (
            std::getline(std::cin, line)
            && line != ";;"
        ) {
            instructions << line + "\n";
        }

        if (
            std::cin.eof() == false
            && line != ";;"
        ) {
            std::cerr << "Error reading instructions\n";
            return 1;
        }

        AbstractVM vm(instructions);

        err = vm.run();
    }

    return err;
}
