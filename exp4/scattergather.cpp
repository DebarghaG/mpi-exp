#include <stdio.h>
#include <mpi.h>

int main(int argc, char** argv){
    int processRank;
    int sizeComm;

    int distroArray[4] = {11,22,33,44};
    int scatteredData;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &sizeComm);
    MPI_Comm_rank(MPI_COMM_WORLD, &processRank);

    //
    MPI_Scatter(&distroArray, 1, MPI_INT, &scatteredData, 1, MPI_INT, 0, MPI_COMM_WORLD);
    //

    printf("Recieved : %d \n", scatteredData);
    MPI_Finalize();
    return 0;
}