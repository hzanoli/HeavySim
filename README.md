# HeavySim

Generating pythia8 events for heavy-flavour studies.

## Prerequisites

In order to configure the project, you will need CMake.
Additionally, you will need PYTHIA (8.2+) and ROOT (6.16+).

You can build them using [aliBuild](https://alice-doc.github.io/alice-analysis-tutorial/building/). Alternatively, you can install pythia by following the guide on the [PYTHIA official website](http://home.thep.lu.se/~torbjorn/Pythia.html) and you can download a pre-compiled [ROOT build](https://root.cern.ch/downloading-root) (or build it from source).

## Installation

First create folders to put the source and the compiled code:

```bash
mkdir HeavySim
cd HeavySim
mkdir build
mkdir src

```


Enter the source folder and close this repository

```bash
cd src
git clone https://github.com/hzanoli/HeavySim.git
```
This will create a folder called "HeavySim" with the contents of this repository. If you need to make changes to the code, you will have to change things here.

Enter in it the build folder:

```bash
cd ..
cd build
```

Be sure that you have sourced the ROOT environment (just check if you type "root" and can open it). 

If you have installed **ROOT and PYTHIA8 using aliBuild**, they will be find automatically, so you can just run the code bellow and wait for the generation of the make files. 

```bash
cmake ../src/HeavySim/ .
```
If you did **not use aliBuild to install ROOT and PYTHIA8** (very likely if you got a error message in the previous step), run CMake and tell it where PYTHIA8 is:

```bash
cmake ../src/HeavySim/ . -DPYTHIA8=<full path to PYTHIA8>
```

Now you can build the software. 

> Tip: you likely have more than one core in your computer. You can use all of them to compile the code faster!

To use two cores in the compilation, use:

```bash
make -j2
```

If you have more, you can just change the number after j, e.g., `make -j4 ` for 4 cores.

If you make changes in the code in the src folder, just go back the build folder and type `make` to rebuild the changes.

Wait for it to finish and you are done!


## Running

To run the program, enter the build folder and run it:

```bash
./hsim [number_of_events] [seed] [tune]
```