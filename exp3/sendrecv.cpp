#include <stdio.h>
#include <mpi.h>

/*
MPI_Send(
    &message_Item,      //Address of the message we are sending.
    1,                  //Number of elements handled by that address.
    MPI_INT,            //MPI_TYPE of the message we are sending.
    1,                  //Rank of receiving process
    1,                  //Message Tag
    MPI_COMM_WORLD      //MPI Communicator
);

MPI_Recv(
    &message_Item,      //Address of the message we are receiving.
    1,                  //Number of elements handled by that address.
    MPI_INT,            //MPI_TYPE of the message we are sending.
    0,                  //Rank of sending process
    1,                  //Message Tag
    MPI_COMM_WORLD      //MPI Communicator
    MPI_STATUS_IGNORE   //MPI Status Object
);
*/

int main(int argc, char** argv){
    int processRank;
    int sizeCluster;
    int messageItem;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &sizeCluster);
    MPI_Comm_rank(MPI_COMM_WORLD, &processRank);

    if(processRank==0){
        messageItem = 42;
        MPI_Send(&messageItem, 1, MPI_INT, 1, 1, MPI_COMM_WORLD);
        printf("Message sent: %d \n", messageItem)
    }

    else if(processRank==1){
        MPI_Recv(&messageItem, 1, MPI_INT, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("Message recv: %d \n", messageItem);
    }

    MPI_Finalize();
    return 0;
}