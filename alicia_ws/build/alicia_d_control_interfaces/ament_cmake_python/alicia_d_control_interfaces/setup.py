from setuptools import find_packages
from setuptools import setup

setup(
    name='alicia_d_control_interfaces',
    version='0.1.0',
    packages=find_packages(
        include=('alicia_d_control_interfaces', 'alicia_d_control_interfaces.*')),
)
