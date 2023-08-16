#ifndef BINDER_LIB_HPP
#define BINDER_LIB_HPP

#include <vector>

class BinderLib {
public:
    BinderLib();
    void capturePhoto();
    std::pair<int, std::vector<float>> processImage();
};

#endif // BINDER_LIB_HPP