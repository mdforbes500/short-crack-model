# Short Crack Propagation Model

## Getting Started

To begin running the model of the short crack model distribution, there are package dependencies that you will need to install. After building these, you should be able to work with the files included in this repository. For a list of the package dependencies, please see _**Prerequisites**_. A complete set of build and install instructions is then given in _**Installing**_, following that. Afterwards, you should be able to run the excample _short-crack-propagation.c_ file listed in the _/examples_ directory.

### Prerequisites

Before installing or depolying any of the libraries mentioned, please make sure you have the [GCC](http://gcc.gnu.org/) compiler, [CMAKE](https://cmake.org/), [GNU Make](https://www.gnu.org/software/make/), [GNU Autoconf](https://www.gnu.org/software/autoconf/autoconf.html), the [GraphViz](https://www.graphviz.org/) package, and [GNUPlot](http://www.gnuplot.info/) all installed on your machine.

The short-crack-propagation model relies on four software packages:
1. [deal-ii](http://www.dealii.org/) - The finite element library used for modeling the problem
2. [Trilinos](https://trilinos.org/) - The "solver" for both linear and non-linear systems
3. [PetSc](https://www.mcs.anl.gov/petsc/) - Important for _deal-ii_'s parallel frameworks
4. [p4est](http://www.p4est.org/) - A scalable octree generator for adaptive meshing  

Additionally, the _deal-ii_ library is modified by two packages developed by the [PRISMS Center](http://www.prisms-center.org/#/home):
1. [Plasticity](https://github.com/prisms-center/plasticity) - For implementing the crystal plasticity model for grains
2. [Phase Field](https://github.com/prisms-center/phaseField) - For implementing a phase-field model for crack propagation

Additionally, the _deal-ii_ library need to find the _Trilinos_, _PetSc_, _p4est_, and _PRISMS_ packages to be able to reference them. A method for this is documented in the _**Installing**_ section below.

### Downloading
To begin the install process, download tarball-gzip archives (_i.e._, '.tar.gz') of each of the libraries from thier respective repositories. Do **NOT** download the pre-built package of _deal-ii_, as this is a standalone package and you need to build the dependencies from each of these.

You should have four gzip files titled as such,
```
deal-ii.X.Y.Z.tar.gz
petsc-X.Y.Z.tar.gz
p4est-X.Y.tar.gz
trilinos-X.Y.Z-Source.tar.gz
```
Since the _PRISMS_ libraries are built on-top of the _deal-ii_ libraries, the libraries will be downloaded after the initial install is finished.

*N.B.:* _X.Y_ or _X.Y.Z_ refer to version numbers in the gzip files listed above.

### Checking for Dependencies
As there are many dependencies for these libraries, it is important to check to see if your computer has all of the required libraries installed to complete a build of the tarballs installed previously.

#### GNU Make
To verify that your computer has the required dependencies, start by checking to see if GNU Make is installed. To do so, open the terminal window and input the following,

```
make --version
```
This should return a set of configuration options, a version number, and the install directories if it is installed. If not, download the latest stable release of [GNU Make](https://www.gnu.org/software/make/) from one of the correct mirror sites listed on the source website. Install procedures are listed in its README file within the tarball.

#### GCC Compiler
To verify that your computer has the required dependencies, start by checking to see if the GCC compiler is installed. To do so, open the terminal window and input the following,

```
gcc --version
```
This should return a set of configuration options, a version number, and the install directories if it is installed. If not, download the latest stable release of [GCC](http://gcc.gnu.org/) from one of the correct mirror sites listed on the source website. Install procedures are available at http://gcc.gnu.org/install/.

#### CMAKE
Check the version number and see if CMAKE is installed by entering the following command,

```
cmake --version
```
This should return a version number. If it returns an error, download the latest stable release of [CMAKE](https://cmake.org/) and install it from the directory on thier website. If it buils an application, be sure to install the command line tools by following the instructions within the app.

#### GNU Autoconf
Similarly to the above, check to see if you have GNU Autoconf installed by entering the following command,
```
autoconf --version
```
his should return a version number. If it returns an error, download the latest stable release of [GNU Autoconf](https://www.gnu.org/software/autoconf/autoconf.html) and install based upon the procedures listed in its README file within the tarball or zip file. If you are using a version of the MacOSX operating system and need to install the GNU Autotools, please see the INSTALL_Autotools.md file included in this directory for an explanation on how to do so.

#### OpenMPI/MPICH
To check to see if either OpenMPI or MPICH are installed, you need to check to see if either is installed. If they are not, _petSc_ will install a library during its install process.

To check for OpenMPI enter the following,
```
ompi_info --version
```
To check for MPICH enter the following,
```
mpiexec --version
```
If the functions are not recognized, it isn't installed.

#### BLAS/LAPACK
To check to see if the BLAS or LAPACK libraries are installed, please use the following,
```
sudo apt-get update
sudo apt-get install gfortran
<lots of output...>
sudo apt-get install libblas-dev && liblapack-dev
```
If BLAS or LAPACK were not installed, they will be after this apt-get.

#### GraphViz
To determine if GraphViz is binary installed, please check its version by the following command,
```
dot -V
```
If GraphViz is installed through binary, a version number should be return. If it is not installed, please install it through a source install, available through the [GraphViz](https://www.graphviz.org/) website. Installation information is available [here](https://graphviz.gitlab.io/_pages/Download/Download_source.html).

#### GNUPlot
To determine if GNUPLOT is installed through command line, please try the following command,
```
gnuplot --version
```
If GNUPlot is installed, this command should return a version number. If it is not installed, please install it from its repository [here](https://sourceforge.net/p/gnuplot/gnuplot-main/ci/master/tree/). For installation please see its INSTALL file in its repository.

### Installing Libraries
It is necessary to install the four packages in the correct order to build deal ii with all of its functionality enabled. The order of installation is as follows:
..* PetSc
..* p4est
..* Trilinos, and
..* deal ii

After these four packages are installed, the PRISMS packages are then installed over deal ii.

#### Installing PetSc
To install PetSc, first the zipped tarball will need to be unpacked into a folder. This is done by
```
cd
export $build = ~/opt/petsc   #This sets the build directory, the convention is /opt
sudo mkdir -p $build
sudo chown user:group $build
tar xfzv petsc.X.Y.Z.tar.gz -C $build
cd $build/petsc.*
```
The package should be unzipped and a folder built. The working directory should also be within the unpacked directory. The next step is to configure the working directory. This will be done with the GCC compiler, and by installing the MPI library as well as BLAS/LAPACK libraries.

```
./configure --with-cc=gcc --with-cxx=g++ --with-fc=0 --download-f2cblaslapack --download-openmpi
make
sudo make install
```
This specifies the C compiler as GCC, the C++ compiler as the GNU C++ compiler (inlcuded in GCC), no fortran settings, and downloads the BLAS/LAPACK and MPI libraries in C format. There will be lots of output after this. Additionally, the BLAS/LAPACK and OpenMPI should be downloaded and installed now.

#### Installing p4est
Now that OpenMPI and BLAS/LAPACK are installed, p4est can be installed, as p4est uses the MPI libraries to do parallel processing.

This is a straightforward installation, and should be done as follows:
```
cd
export $build=~/opt/p4est
sudo mkdir -p $build
sudo chown user:group $build
tar xfzv p4est-X.Y.tar.gz -C $build
cd $build/p4est-*

./configure --enable-mpi CC="gcc" CXX="g++"
make
sudo make install
make clean
```
#### Install Trilinos
This uses CMake, and as such looks a bit different from the above.

Here is a list of the packages used for a simple install.
```
cd
export $build=~/opt/trilinos-source
sudo mkdir -p $build
sudo mkdir -p /opt/trilinos
sudo chown user:group $build
tar xfzv trilinos.X.Y.Z.Source.tar.gz -C /opt/trilinos-source

EXTRA_ARGS = $@

cmake \
-DTPL_ENABLE_MPI=ON \
-DMPI_BASE_DIR=/opt/mpi \
-DCMAKE_C_COMPILER=/usr/local/gcc \
-DCMAKE_CXX_COMPILER=/usr/local/gcc \
-DCMAKE_Fortran_COMPILER=OFF \
-DTrilinos_ENABLE_ALL_PACKAGES=ON \
-DCMAKE_INSTALL_PATH=\opt\trilinos
/opt/trilinos-source/Trilinos.X.Y.Z.Source

sudo make -j<n> install
make clean
```
#### Install deal-ii
Now it is (finally) time to install deal-ii. In the configuration of this package, we'll need to flag Trilinos, p4est, and PetSc as packages we are using. This will integrate these packages into deal-ii's architecture and make them accessible to deal-ii's precompiler.

To intall and configure deal-ii to do so, the following should be applied.
```
cd
export $build=~/opt/deal-ii-source
sudo mkdir -p $build
sudo mkdir -p /opt/deal-ii
sudo chown user:group $build
tar xfzv trilinos.X.Y.Z.Source.tar.gz -C /opt/deal-ii-source

EXTRA_ARGS = $@

cmake \
-D DEAL-II-WITH-MPI=ON \
-D DEAL-II-WITH-P4EST=ON \
-D DEAL-II-WITH-PETSC=ON \
-D DEAL-II-WITH-TRILINOS=ON \
