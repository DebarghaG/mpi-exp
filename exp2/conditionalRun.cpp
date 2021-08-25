#include <stdio.h>
#include <mpi.h>

/*
- MPI_Init()
- MPI_Comm_size()
- MPI_Comm_rank()
- MPI_Finalize() 
- MPI_Barrier() // Barrier Function for sync'd processes
*/
int main(int argc, char** argv){
    int processRank;
    int sizeCluster;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &sizeCluster);
    MPI_Comm_rank(MPI_COMM_WORLD, &processRank);

    for(int i=0; i<sizeCluster; i++){
        if (i==processRank){
            printf("Process:%d \t Node:%d \n", processRank, sizeCluster);
        }
        MPI_Barrier(MPI_COMM_WORLD)
    }

    MPI_Finalize();
    return 0;
}
