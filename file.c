#include "file.h"
#include <stdio.h>
#include <sys/stat.h>

size_t read_file( char* filename, char **buffer){
	// using the sys/stat.h library to get the stat structure which automatically 
	// find out the size of the file, this stops from having to increement
	// all the way to the end of the file to manually see how big it is	
	struct stat st;
	stat(filename,&st);

	//mallocing the buffer in main to how big the file is
	*buffer = (char*)malloc(st.st_size);
	




	
	FILE *fp = fopen(filename,"r");    	

	//making sure that the file passed is an actual readable file
	if(fp==NULL){
		printf("Couldnt find file passed");
    		return -1;
    	}


	size_t rSize = fread(*buffer,1,st.st_size,fp);
	
	fclose(fp);
	
	//Checking to make sure the file is completely read
		if(rSize<st.st_size){
		printf("couldn't read whole file");
		return -2;
	}

	//returns how many bytes were read
	return rSize;

}


//opening, writing and closing the file
//filename is file being wrote to
//*buffer is the char* that hold the bytes that are being wrote to a file
//size is how big the file is
size_t write_file( char* filename, char *buffer, size_t size){
	FILE* fp = fopen(filename,"w");
	if(fp==NULL){
	printf("Couldn't open file");
	return -1;
	}	
	
	size_t wSize = fwrite(buffer,1,size,fp);
	
	//Makes sure that the entire buffer is written into the file
	if(wSize<size){
		printf("couldn't write whole buffer");
		return -2;
	}


	fclose(fp);	
	return wSize;
}

