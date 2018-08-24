# Short Crack Propagation Model

## Getting Started

To begin running the model of the short crack model distribution, there are package dependencies that you will need to install. After building these, you should be able to work with the files included in this repository. For a list of the package dependencies, please see _**Prerequisites**_. A complete set of build and install instructions is then given in _**Installing**_, following that. Afterwards, you should be able to run the example _short-crack-model_ file listed in the _build_ directory.

### Dependencies

Before installing or depolying any of the libraries mentioned, please make sure you have the [GCC](http://gcc.gnu.org/) compiler, [CMAKE](https://cmake.org/), [GNU Make](https://www.gnu.org/software/make/), [GNU Autoconf](https://www.gnu.org/software/autoconf/autoconf.html), the [GraphViz](https://www.graphviz.org/) package, and [GNUPlot](http://www.gnuplot.info/) all installed on your machine.

The short-crack-propagation model relies on four software packages:
1. [deal-ii](http://www.dealii.org/) - The finite element library used for modeling the problem
2. [Trilinos](https://trilinos.org/) - The "solver" for both linear and non-linear systems
3. [PetSc](https://www.mcs.anl.gov/petsc/) - Important for _deal-ii_'s parallel frameworks
4. [p4est](http://www.p4est.org/) - A scalable octree generator for adaptive meshing

Additionally, the _deal-ii_ library is modified by two packages developed by the [PRISMS Center](http://www.prisms-center.org/#/home):
1. [Plasticity](https://github.com/prisms-center/plasticity) - For implementing the crystal plasticity model for grains
2. [Phase Field](https://github.com/prisms-center/phaseField) - For implementing a phase-field model for crack propagation

Additionally, the _deal-ii_ library need to find the _Trilinos_, _PetSc_, _p4est_, and _PRISMS_ packages to be able to reference them. Please see the INSTALL file for detailed instructions on building these packages.

### Running
Once all the dependencies are installed, running the package is fairly straight forward.

```
cd short-crack-model
./archmage.sh
cd bin
export PATH=$PATH:$(pwd)
schmod --help
```

This will run the _short-crack-model_'s help function. The examples can be listed with

```
cd short-crack-model/bin
schmod --list -E
```

To run an example,

```
schmod --run [example]
```
where `[example]` is the name given from the list.

Additionally, the results can be viewed through,

```
schmod --view [example]
```

#### Changing the input mesh files
To use another mesh file, please save a new `mesh.msh` type file in the directory `resources/input` for the given example .

#### Handling boundary conditions
The boundary conditions (both essential and natural) should be indicated in the `.msh` file.

### Removing
As this is a local build, removal is simple:

```
cd ../short-crack-model
rm -rf short-crack-model
```
This will remove the project folder and all folders and files within.
