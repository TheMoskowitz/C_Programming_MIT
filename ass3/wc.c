#include <stdio.h>
#include <stdlib.h>
int main(int argc,char* argv[])
{
    FILE* fp=NULL;
    int   nfiles =--argc; /*ignore the name of the program itself*/
    int   argidx =1;      /*ignore the name of the program itself*/
    char* currfile="";
    char  c;
    /*count of words,lines,characters*/
    unsigned long nw=0,nl=0,nc=0;

    if(nfiles==0) 
    {
        fp=stdin; /*standard input*/
        nfiles++; 
    }
    else /*set to first*/
    {
        currfile=argv[argidx++];
        fp=fopen(currfile,"r");
    }
    while(nfiles>0) /*files left >0*/
    {
       if(fp==NULL)
        {
            fprintf(stderr,"Unable to open input\n");
            exit(-1);
        }
        nc=nw=nl=0;
        char last_char = ' ';
        while((c=getc(fp))!=EOF)
        {
	        /*TODO:FILL HERE
		    process the file using getc(fp)
			*/
            if (last_char == ' ') {
                nw++;
            }
            // 10 is the digit of the '/n' char
            if (last_char == 10) {
                nl++;
            }
            nc++;
            last_char = c;

        }
        printf("%s \n",currfile);
        printf("%ld characters \n",nc);
        printf("%ld words \n",nw);
        printf("%ld lines \n",nl);
        /*next file if exists*/
        nfiles--;
        if(nfiles>0)
        {
            currfile=argv[argidx++];
            fp     =fopen(currfile,"r");
        }
    }
	return 0;
}
