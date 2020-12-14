#include <string>
#include "GrayscaleConvert.h"

int main(int argc, char * argv[]) {

    std::string path = argv[1];
    std::string savePath = argv[2];

    GrayscaleConvert gc(path,savePath);

    return 0;
}
