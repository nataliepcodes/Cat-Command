#include <stdio.h>
#include <fcntl.h>  // for open()
#include <unistd.h> // for read() and for close()


int main(int ac, char **av)
{
    // If a number of arguments is less than 2, print an error message; first argument is ./a.out command
    if (ac < 2)
    {
        printf("Usage: Invalid number of arguments.\n");
        return 1;
    }

    // Create a file descriptor which is an integer that represents the open file
    int file_descriptor;

    // Create a buffer of 1024 bytes
    char buffer[1024];
    ssize_t bytes_read;

    for (int i = 1; i < ac; i++)
    {
        // Open a file in read-only mode
        file_descriptor = open(av[i], O_RDONLY);

        // If file cannot be opened, print an error message
        if (file_descriptor == -1)
        {
            printf("Error: Could not open file: %s\n", av[i]);
            return 1;
        }

        printf("\n\nFILE: %s\n", av[i]);
        printf("================================================\n");

        // Read the contents of each file with read()
        //read() attempts to read up to count bytes from file descriptor fd into the buffer starting at buf.
        //ssize_t read(int fd, void *buf, size_t count);

        bytes_read = read(file_descriptor, buffer, sizeof(buffer));
        printf("%s\n", buffer);

        // Close the file descriptor
        close(file_descriptor);

    }
    
    return 0;
}
