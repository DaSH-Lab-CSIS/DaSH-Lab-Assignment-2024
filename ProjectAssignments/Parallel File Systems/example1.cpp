#include <iostream>
#include <string>
#include <vector>
#include <mpi.h>
 
int main(int argc, char *argv[]) {
    int rank;
    int size;
 
    // mpi initialization
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
 
    // i/o parameters
    const size_t num_files = 5;
    const size_t num_writes = 1024;
    const size_t block_size = 1024;
 
    // buffer to write
    const std::vector<char> data(block_size, 'A');
 
    for (size_t i = 0; i < num_files; ++i) {
 
        // generate different file per rank
        std::string filename = "file_";
        filename += std::to_string(rank) + "_" + std::to_string(i);
 
        // open new file using MPI_COMM_SELF (independent I/O)
        MPI_File fh;
        MPI_File_open(MPI_COMM_SELF, filename.c_str(), MPI_MODE_CREATE | MPI_MODE_WRONLY, MPI_INFO_NULL, &fh);
 
        // write same buffer num_writes times
        for(size_t j = 0; j < num_writes; j++) {
            MPI_Status status;
            MPI_File_write(fh, &data[0], block_size, MPI_CHAR, &status);
        }
 
        // close file
        MPI_File_close(&fh);
    }
 
    MPI_Finalize();
    return 0;
}
