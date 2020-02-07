// Collaborated with Dalton Claybaugh (for half of it)

#include "file.h"
#include "wav.h"
#include "stdio.h"
#include <string.h>
#include <stdlib.h>


/*****************************************************************
Simple program that will take a .wav file and reverse it

@author Ayden Martin
@Errors: -1=read,-2=badFile,-3=write
*****************************************************************/
int main (int argc, char** argv){
	//creates a null pointer which will in the future (at read_file call) 
	//be pointing to memory holding the entire file 
	char* buffer= NULL; 

	//checks to make sure you are atleast passing a .wav file to program, to avoid errors
	if(argc>1){
	
	//passing the filename which should be argv 1 and the address of buffer so it 
	//can malloc space ot buffer in read
	size_t size = read_file(argv[1],&buffer);
   	
	//returns -1 if there was an error in read_file function       
	if(size==-1||size==-2){
        	return -1;
    	}
	if(size<44){
		printf("Tried to use an invalid file");
		return -2;
	}


	//parsing the newly malloced and read buffer into a wav_file struct
	wav_file *song = parse(buffer);

	//printing out the wav_file struct members to see info about it
	printf("Total File size of the %s is %zu\n",argv[1],size);
	printf("Wave riff: %.*s \n",4,song->Riff);
	printf("Wave byte: %d \n",song->byte47);
	printf("Wave wave: %.*s \n",4,song->wave);
	printf("Wave fmt: %.*s \n",4,song->fmt);
	printf("Wave Formatsize: %d \n",song->formatSize);	
	printf("Wave format: %hd \n",song->format);
	printf("Wave Channels: %hd \n",song->numChannel);
	printf("Wave Sample Rate: %d \n",song->sampleRate);
	printf("Wave Bits per Sample: %d \n",song->bitsPerSample);
	printf("Wave Block Alignment: %hd \n",song->blockAlignment);
	printf("Wave Bits per Sample Short: %hd \n",song->bitsPerSampleShort);
	
	
	//figuring out how big the samples should be and then printing it out
	int bytes = song->numChannel*(song->bitsPerSampleShort/8);
	printf("bytes/samples: %d\n",bytes);

	//Makes sure there is a second arguement (the file we are writing to) 
	//before reversing wav_file
	if(argc >2 ){
		char *reffub = (char*)malloc(size);
		int counter=44;

		//reads first 44 bytes into the reverse buffer since those dont get reversed
		for(int k = 0; k<44;k++){
			reffub[k] = buffer[k];
		}
		
		//nested forloop to go through buffer and reverse it into reffub
		//first loop decrements by bytes
		//second loop increments from 0 to bytes to recreate samples of x amount of bytes
		//counter keeps track of reffub index, buffer index is calculated from for loop counters
		for(int i = size-1; i>=44; i-=bytes){	
		
			if(bytes>=1){
				for(int j = bytes-1; j>=0; j--){
				reffub[counter] = buffer[i-j];
				++counter;	
				}	
			}	
		}

		//writing the reversed buffer to a file then 
		//freeing the buffer made inside if statement to avoid errors and memory leak
		size_t read = write_file(argv[2],reffub,size);
		if(read <0){
			return -3;
		}
		free(reffub);
	}
	}
	//freeing buffer holding original song data to avoid memory leaks
	free(buffer);
	return 0;
}
