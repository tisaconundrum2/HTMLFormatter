#include <stdio.h>
#include <fcntl.h>

/* Summary:
 * Create a file that can be read in a browswer.
 *
 * Start with this
 * |----------------------------|
 * | C:\some\directory          |
 * | C:\another\directory       |
 * |----------------------------|
 *
 * End with this
 * |----------------------------------|
 * | <a href="C:\some\...\>C:\...\</a>|
 * | <a href="C:\anot\...\>C:\...</a> |
 * |                                  |
 * |----------------------------------|
 *
 *
 * "<a href = /"%s/">%s</a>", line
 *
 */


int main(int argc, char* argv[]){
    /*you should have exactly 3 arguments argv[0]-argv[2]*/
    if(argc != 3){
        printf ("Usage: cp <file1> <file2>");
        return 1;
    }
}

int main(int argc, char* argv[]){
    if (argc < 3) {
        perror(argc);
        return 1;                                                            // check to see if there are file arguments input
    }
    char fp1[] = argv[1];
    char fp2[] = argv[2];
    char buffer[1024];
    FILE *input_file = fopen(fp1, 'r');
    FILE *output_file = fopen(fp2, 'w');
    // ======================================

    if (input != NULL){
        //read one line from the file and put it into the buffer
        while (fgets(buffer, sizeof buffer, fp) != NULL){
            fprintf(stdout, "%s", buffer);
            //<p><a href = "var_here">var_here</a>
            //v[0] = <p><a href = "
            //v[1] = var_here
            //v[2] = ">
            //v[3] = </a>
            // v[0],v[1],v[2],v[1],v[3]
            char *v[3];
            v[0] = "<p><a href = '";
            v[1] = buffer;
            v[2] = "'>";
            v[3] = "</a>";
            fprintf(output_file, "%s","%s","%s","%s","%s",v[0],v[1],v[2],v[1],v[3]);

        }
    } else {
        perror(filename1); //print the error message on stderr.
        return 1;
    }
    return 0;
}




/*         create a buffer
 *
 *                   buffer [1024]= this/n/0/0/0/0/0/0
 *                                   ^
 *                                   |
 *                                 grab the this
 *                                 and put it into another variable
 *                                          |
 *              temp_var = "this"       <--/
 *
 * clear the buffer an
 *      using a while loop we can then
 * add the content into the buffer to be written later
 * we then use another while loop to lseek to the end of the file
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *


