#include <stdio.h>
#include <mpi.h>

/*
- MPI_Init()
- MPI_Comm_size()
- MPI_Comm_rank()
- MPI_Finalize() 
*/
int main(int argc, char** argv){
    int processRank;
    int sizeCluster;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &sizeCluster);
    MPI_Comm_rank(MPI_COMM_WORLD, &processRank);

    printf("Process:%d \t Node:%d", processRank, sizeCluster)

    MPI_Finalize();
    return 0
}