from setuptools import find_packages
from setuptools import setup

setup(
    name='alicia_d_arm_motion',
    version='0.1.0',
    packages=find_packages(
        include=('alicia_d_arm_motion', 'alicia_d_arm_motion.*')),
)
