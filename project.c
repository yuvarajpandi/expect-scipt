#include<stdio.h>
#include<string.h>
int main()
{   
    FILE *ptr,*ptr1;
	char src[100];
	char line[256];
	int i=2;
	char get_char;
	int chr_count=0;
	int linecount=0;
	int split_count=0;
	int choice=0;
	char fileoutput[100]="E:\\input_file.txt";
	char store[10];
	ptr1=fopen(fileoutput,"r");
	

	
	printf("\nEenter the choice number to select split mode \n1.Line Split\n2.Unit Split\n :");
    scanf("%d",&choice);

    
	if(choice==1)
	{
		printf("\nenter the line count size :");
		scanf("%d",&split_count);
			strcpy(src,"E:\\lines");
    sprintf(store,"%d",1);
	strcat(src,store);
	strcat(src,".txt");
	ptr=fopen(src,"w");
	src[0]='\0';
	
	while(!feof(ptr1))
	{
		
	
		
		get_char=fgetc(ptr1);	     
	    chr_count++;
		if(linecount==split_count)
		{
			fclose(ptr);
			
	strcpy(src,"E:\\lines");
    sprintf(store,"%d",i);
	strcat(src,store);
	strcat(src,".txt");

	printf("\n%s",src);
	
    ptr=fopen(src,"w");

    src[0]='\0';
    i++;
    linecount=0;
        }
        if(get_char=='\n')
        {
        	linecount++;
		}
    fprintf(ptr,"%c",get_char); 	
        }     
    
  fclose(ptr1);
  fclose(ptr);
printf("\n successful");
}
 
 if(choice==2)
 {
	printf("\nenter the unit split size :");
	scanf("%d",&split_count);
    strcpy(src,"F:\\char");
    sprintf(store,"%d",1);
	strcat(src,store);
	strcat(src,".txt");
	ptr=fopen(src,"w");
	src[0]='\0';
 	while(!feof(ptr1))
	{
	
		
		get_char=fgetc(ptr1);	     
	    
		if(chr_count==split_count)
		{
			fclose(ptr);
			
      	strcpy(src,"F:\\char");
        sprintf(store,"%d",i);
	    strcat(src,store);
	    strcat(src,".txt");

	    printf("\n%s",src);
	
        ptr=fopen(src,"w");

         src[0]='\0';
         i++;
         chr_count=0;
        }
        
       if(get_char!='\n'||'\t')
       {
        fprintf(ptr,"%c",get_char); 
		chr_count++;
        }     
    

	}
    fclose(ptr1);
    fclose(ptr);
    printf("\n successful"); 
    
    
     
    //author yuvaraj
    }
	 
	return 0;
}
