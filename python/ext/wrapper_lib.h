#ifndef WRAPPER_LIB_HPP
#define WRAPPER_LIB_HPP

#include <vector>

class WrapperLib {
public:
    WrapperLib();
    void capturePhoto();
    std::pair<int, std::vector<float>> processImage();
};

#endif // WRAPPER_LIB_HPP