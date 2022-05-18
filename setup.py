from pybind11.setup_helpers import Pybind11Extension, build_ext
from setuptools import setup
import pybind11

#cpp_args = ['-std=c++11', '-stdlib=libc++', '-mmacosx-version-min=10.7']

bo_module = Pybind11Extension(
    'er_build_optimizer_module',
    sources=['module.cpp', "ERBuildOptimizer.cpp", "SubsetSum.cpp"],
    include_dirs=[pybind11.get_include()],
    language='c++',
    #extra_compile_args=cpp_args,
    )

setup(
    name='er_build_optimizer_module',
    version='0.6',
    author="Richard Scales",
    author_email="richardscales118@gmail.com",
    description='Build optimization backend functionality.',
    ext_modules=[bo_module],
    zip_safe=False,
    python_requires=">=3.6",
)