//stdlib is for the size_t type that is being used
#include <stdlib.h>

    /*****************************************************************
    Will take a filename arguement and will figure out the size of file,
    malloc space inside buffer for buffer for file, and read the stream
    into the buffer
    
    @param string, contains the name of file being read from
    @param char*, the buffer being written into from read filestream
    @return size_t, number of bytes read from file
    *****************************************************************/
size_t read_file( char* filename, char **buffer );

    /*****************************************************************
    Will take a filename and write Size amount of bytes from
    buffer into that file
    
    @param string, contains the name of file being written to
    @param char*, the bytes being written into the file
    @param size_t, number of bites that should br written to file
    @return size_t, number of bytes written to file
    *****************************************************************/
size_t write_file( char* filename, char *buffer, size_t size);
