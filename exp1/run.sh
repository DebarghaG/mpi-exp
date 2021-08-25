#!/bin/bash

#PBS -N BasicMPI
#PBS -q cpu
#PBS -l nodes=2:ppn=10
#PBS -o output.log
#PBS -e err.log

module load compiler/openmpi-3.1.6
mpic++ /home/debayan-student-03/mpi/mpi-exp/exp1/BasicRun.cpp -o /home/debayan-student-03/mpi/mpi-exp/exp1/BasicRun.exe
mpirun -np 20 /home/debayan-student-03/mpi/mpi-exp/exp1/BasicRun.exe
