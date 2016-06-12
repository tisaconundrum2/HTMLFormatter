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

int main (int argc, char *argv[]){
    /*you should have exactly 3 arguments argv[0]-argv[2]*/
    if(argc != 3){
        printf ("Usage: finderFormatHTML.exe <file1> <file2>");
        return 1;
    }
    FILE *ifile = fopen(argv[1], "r");
    FILE *ofile = fopen(argv[2], "w+");
    char buffer[1024];
    char *v[4];
    //===================================
    if (ifile == NULL){
        printf("Your input file %s: ", argv[1]);
        perror(ifile);
        return 1;
    }

    if (ofile == NULL){
        printf("Your output file %s: ", argv[2]);
        perror(ofile);
        return 1;
    }

    while (fgets(buffer, sizeof buffer, ifile)!= NULL){
        //<p><a href = "var_here">var_here</a>
        //v[0] = <p><a href = "
        //v[1] = var_here
        //v[2] = ">
        //v[3] = </a>
        // v[0],v[1],v[2],v[1],v[3]
        size_t ln = strlen(buffer) -1;
        if (buffer[ln] == '\n')
            buffer[ln] ='\0';
        v[0] = "<p><a href = '";
        v[1] = buffer;
        v[2] = "'>";
        v[3] = "</a>\n";
        fprintf(ofile,"%s", v[0]);
        fprintf(ofile,"%s", v[1]);
        fprintf(ofile,"%s", v[2]);
        fprintf(ofile,"%s", v[1]);
        fprintf(ofile,"%s", v[3]);

    }
    fclose(ifile);
    fclose(ofile);
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
 */


