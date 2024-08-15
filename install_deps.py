import subprocess
import sys
import os

def install_package(package_name):
    subprocess.check_call([sys.executable, "-m", "pip", "install", package_name])

def check_and_install_pybind11():
    try:
        import pybind11
        print("pybind11 is already installed.")
    except ImportError:
        print("Installing pybind11...")
        install_package('pybind11')

def check_and_install_torch():
    try:
        import torch
        print("torch is already installed.")
    except ImportError:
        print("Installing torch...")
        install_package(torch)

def install_openmp():
    platform = sys.platform
    if platform == "darwin":
        # macOS - check and install via brew
        if subprocess.call(["brew", "list", "libomp"], stdout=subprocess.DEVNULL, stderr=subprocess.STDOUT) != 0:
            print("Installing OpenMP on macOS...")
            subprocess.check_call(["brew", "install", "libomp"])
        else:
            print("OpenMP is already installed on macOS.")
    elif platform.startswith("linux"):
        # Linux - check and install via apt or yum
        distro = subprocess.check_output(["lsb_release", "-is"]).decode().strip()
        if distro.lower() == "centos":
            subprocess.check_call(["sudo", "yum", "install", "-y", "libomp-dev"])
        else:
            subprocess.check_call(["sudo", "apt-get", "install", "-y", "libomp-dev"])
    elif platform == "win32":
        print("For Windows, OpenMP comes with MSVC by default.")
    else:
        raise RuntimeError("Unsupported platform")

def install_eigen():
    platform = sys.platform
    if platform == "darwin":
        if subprocess.call(["brew", "list", "eigen"], stdout=subprocess.DEVNULL, stderr=subprocess.STDOUT) != 0:
            print("Installing Eigen on macOS...")
            subprocess.check_call(["brew", "install", "eigen"])
        else:
            print("Eigen is already installed on macOS.")
    elif platform.startswith("linux"):
        # Linux - check and install via apt or yum
        distro = subprocess.check_output(["lsb_release", "-is"]).decode().strip()
        if distro.lower() == "centos":
            subprocess.check_call(["sudo", "yum", "install", "-y", "eigen3-devel"])
        else:
            subprocess.check_call(["sudo", "apt-get", "install", "-y", "libeigen3-dev"])
    elif platform == "win32":
        print("For Windows, Eigen is not a package; it needs to be downloaded manually.")
    else:
        raise RuntimeError("Unsupported platform")

def main():
    check_and_install_pybind11()
    install_openmp()
    install_eigen()
    check_and_install_torch()

if __name__ == "__main__":
    main()
