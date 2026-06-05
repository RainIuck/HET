from setuptools import find_packages
from setuptools import setup

setup(
    name='alicia_d_sts_gripper',
    version='0.1.0',
    packages=find_packages(
        include=('alicia_d_sts_gripper', 'alicia_d_sts_gripper.*')),
)
