# Copyright (c) Facebook, Inc. and its affiliates.
# 
# This source code is licensed under the MIT license found in the
# LICENSE file in the root directory of this source tree.

from setuptools import setup
from torch.utils.cpp_extension import BuildExtension, CUDAExtension
import glob
import os
import torch
ROOT = os.path.dirname(os.path.abspath(__file__))

_ext_src_root = "_ext_src"
_ext_sources = glob.glob("{}/src/*.cpp".format(_ext_src_root)) + glob.glob(
    "{}/src/*.cu".format(_ext_src_root)
)
_ext_headers = glob.glob("{}/include/*".format(_ext_src_root))

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
    name='pointnet2',
    ext_modules=[
        CUDAExtension(
            name='pointnet2._ext',
            sources=_ext_sources,
            extra_compile_args={
                "cxx": ["-O2", "-std=c++17", "-I{}".format("{}/{}/include".format(ROOT, _ext_src_root))],
                "nvcc": [
                    "-O2",
                    "-std=c++17",
                    "-I{}".format("{}/{}/include".format(ROOT, _ext_src_root)),
                ],
            },
        )
    ],
    cmdclass={
        'build_ext': BuildExtension
    }
)
