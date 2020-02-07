#include "wav.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

//passing a buffer that contains all the bytes of a wav file
wav_file* parse(char* contents){

	//returns a pointer which will automatically assume the first 
	//44 bytes of contents is relavant to the wav file struct
	return (wav_file*)contents;
}
