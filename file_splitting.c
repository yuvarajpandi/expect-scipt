/*------------------------------------splitting a input file by lines and size---------------------------------------------------------
author name : yuvarajasekar
date        :23.10.2021.
description....
        In this proram we can split an input file by lines and size.
        
------------------------------------------------THANK YOU-------------------------------------------------------------------------------*/

#include <stdio.h>

int main() 
{
	FILE *ptr_readfile;       // input file 
	FILE *ptr_writefile;      // output file
	char line [128]; /* or some other suitable maximum line size */
	char fileoutputname[15];
	int filecounter=1, linecounter=1,bytecounter=1,split;
	char path [100];
	int splitmode;       
	char c;
        printf("Enter the file name to split:\n");
        scanf("%s",path);
	ptr_readfile = fopen(path,"r");
	if (!ptr_readfile)
	{
	   printf(" no files availabe..please check the file name..\n thank you...\n");
		return 1;
         }
         
         printf("Enter the number for splitting...\n press 1 for split the input file by lines.\n press 2 for split the input file by size.\n");
         scanf("%d",&splitmode);
         
         if(splitmode == 1)
         {
         
	sprintf(fileoutputname, "line_split%d", filecounter);
	ptr_writefile = fopen(fileoutputname, "w");
	
	printf("\nenter the line size for splitting...\n");
	scanf("%d",&split);

	while (fgets(line, sizeof line, ptr_readfile)!=NULL)  
	{
		if (linecounter == split) 
		{
			fclose(ptr_writefile);
			linecounter = 1;
			filecounter++;
			sprintf(fileoutputname, "line_split%d", filecounter);
			ptr_writefile = fopen(fileoutputname, "w");
			if (!ptr_writefile)
				return 1;
		}
		fprintf(ptr_writefile,"%s\n", line);
		linecounter++;
	}
	fclose(ptr_readfile);
	printf("your input file has splitted successfully..... \n kindly check it.....\n thank you...\n");
	}
        
        if(splitmode == 2)
        {
        ptr_readfile = fopen(path,"r");
	if (!ptr_readfile)
	{
		return 1;
         }
	sprintf(fileoutputname, "byte_split%d", filecounter);
	ptr_writefile = fopen(fileoutputname, "w");
	
	printf("\nenter the byte size for splitting\n");
	scanf("%d",&split);

	while ((c = fgetc(ptr_readfile)) != EOF)
   {
     
                //char_count++;
		if (bytecounter == split) 
		{
			fclose(ptr_writefile);
			bytecounter = 1;
			filecounter++;
			sprintf(fileoutputname, "byte_split%d", filecounter);
			ptr_writefile = fopen(fileoutputname, "w");
			if (!ptr_writefile)
				return 1;
		}
		
		 if(c !='\n'||'\t')
       {
        fprintf(ptr_writefile,"%c",c); 
		bytecounter++;
        }
		//fprintf(ptr_writefile,"%s\n", line);
		//bytecounter++;
	}
	fclose(ptr_readfile);
	printf("your input file has splitted successfully..... \n kindly check it......\n thank you....\n"); 	
	}
	return 0;
}

