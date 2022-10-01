/**
 * @author Nirre Pluf {@literal pluf@wfu.edu}
 * @date Oct. 1, 2022
 * @assignment Lab 5
 * @course CSC 250
 *
 * source files for parsing the command line arguments
 **/   
#include "getWavArgs.h"

/**
 *  function processes the command line arguments using getopt()
 *
 *  function returns 1 if the arguments are "correct", 0 otherwise
 *
 *  argc - number of command line arguments
 *  argv - list of command line arguments (list of C-strings)
 *  bitPtr - pointer to integer, number of LSB bits (1, 2, or 4)
 *  wavFileName - pointer to the WAV filename  
 *  textFileName - pointer to the filename that will store the hiden text 
 */
int getWavArgs(int argc, char *argv[], int* bitPtr, char wavFileName[], char textFileName[]) {
    int opt;
    int gotBit = 0;

    while ((opt = getopt(argc, argv, "b:")) != -1) {
        switch (opt) {
        case 'b':
            *bitPtr = atoi(optarg);
            gotBit = *bitPtr == 1 || *bitPtr == 2 || *bitPtr == 4;
            break;
        default:
            printCommandUsage(argv[0]);
            return 0;
        }
    }

    if(!gotBit || (optind + 2) != argc){
        printCommandUsage(argv[0]);
        return 0;
    }

    strcpy(wavFileName, argv[optind]);
    strcpy(textFileName, argv[optind + 1]);

    /* 
    printf("b: %d, wavF: [%s], txtF:[%s] \n", *bitPtr, wavFileName, textFileName); 
    */

    return 1;
}


/**
 *  function to print a useful help message
 */
void printCommandUsage(char executableName[]) {
    fprintf(stderr, "Usage: %s -b bit wavFileName textFileName \n", executableName);
    fprintf(stderr, " -b bits per sample to encode (1, 2, or 4)\n");
}




