#include <iostream>
#include <abstract_vm.h>
#include <fstream> //ifstream

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
        AbstractVM vm;

        err = vm.run();
    }

    return err;
}
