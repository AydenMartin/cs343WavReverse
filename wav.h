


//just  strcture that defines what a wav_file header contains
//defined by the microsoft api
//called wav_file for convenience
typedef struct{

	char Riff[4];
	int byte47;
	char wave[4];
	char fmt[4];
	int formatSize;
	short format;
	short numChannel;
	int sampleRate;
	int bitsPerSample;
	short blockAlignment;
	short bitsPerSampleShort;
	char dataStart[4];
	int sizeOfData;
	char* data;
}wav_file;

    /*****************************************************************
    Takes a char* which points to data that is read from a .wav file
    and parses it to get readable header information
    
    @param char* that points to a wavfile contents
    @return a pointer to a wav_file struct
    *****************************************************************/
wav_file* parse(char* contents);



