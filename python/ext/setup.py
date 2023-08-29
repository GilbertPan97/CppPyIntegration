from setuptools import setup, Extension
from Cython.Build import cythonize

setup(
    ext_modules=[
        Extension(
            "WrapperLib",
            sources=["python/ext/wrapper_lib.pyx", "cpp/src/wrapper_lib.cpp"],
            language="c++",
            extra_compile_args=["/std:c++14"],  # Use C++14 standard
        )
    ]
)

# Run the following command in the terminal to build the Cython extension module:
# python python/ext/setup.py build_ext --build-lib examples/utils/