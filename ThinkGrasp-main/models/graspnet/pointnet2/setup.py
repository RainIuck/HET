from setuptools import setup
from torch.utils.cpp_extension import BuildExtension, CUDAExtension
import glob
from setuptools import find_packages
import os
import os.path as osp
import torch

ROOT = os.path.dirname(os.path.abspath(__file__))

_ext_src_root = "_ops"
_ext_sources = glob.glob("{}/src/*.cpp".format(_ext_src_root)) + glob.glob(
    "{}/src/*.cu".format(_ext_src_root)
)
_ext_headers = glob.glob("{}/include/*".format(_ext_src_root))

# Load the version from the _version.py file
exec(open(osp.join(ROOT, "_version.py")).read())

# Specify requirements
requirements = ["torch>=1.4"]

def configure_cuda_arch_list():
    if os.environ.get("TORCH_CUDA_ARCH_LIST"):
        return
    if torch.cuda.is_available():
        major, minor = torch.cuda.get_device_capability(0)
        os.environ["TORCH_CUDA_ARCH_LIST"] = f"{major}.{minor}+PTX"
    else:
        os.environ["TORCH_CUDA_ARCH_LIST"] = "12.0+PTX"


configure_cuda_arch_list()

setup(
    name='pointnet22',
    ext_modules=[
        CUDAExtension(
            name='pointnet22._ext',
            sources=_ext_sources,
            extra_compile_args={
                "cxx": ["-O2", "-std=c++17", "-I{}".format("{}/{}/include".format(ROOT, _ext_src_root))],
                "nvcc": [
                    "-O2",
                    "-std=c++17",
                    "-I{}".format("{}/{}/include".format(ROOT, _ext_src_root)),
                ],
            },
            include_dirs=[osp.join(ROOT, _ext_src_root, "include")],
        )
    ],
    cmdclass={
        'build_ext': BuildExtension
    },
    install_requires=requirements,  # Include your requirements here
    packages=find_packages()  # Automatically find all packages
)
