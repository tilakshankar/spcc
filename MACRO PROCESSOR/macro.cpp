#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
FILE *mdt,*mnt,*ala;
FILE *input=fopen("source.txt","r"); 
mdt= fopen("MDT.txt", "w");
mnt=fopen("MNT.txt","w");
ala=fopen("ALA.txt","w");
char col1[50],col2[50];
int mdtc= 0, mntc= 0, alac= 0;
fprintf(mdt,"Index\tCode\n");
fprintf(mnt,"Index\tM_name\tMDT_Index\n");
fprintf(ala, "Index\tA_name\n");
while(fscanf(input,"%s",col1)!=EOF){ 
if(strcmp(col1, "MACRO") == 0) {
mntc++;
fscanf(input, "%s", col1); // Read macro name
fprintf(mnt,"%d\t%s\t%d\n",mntc,col1,mdtc+1);
fprintf(mdt,"%d\t",++mdtc);//IncrementMDTindexandprint
fprintf(mdt, "%s\t", col1); // Print macro name
fscanf(input, "%s", col2); // Read first argument
fprintf(mdt,"%s\n",col2); //Printfirstargument
while(fscanf(input,"%s",col1)!=EOF&&strcmp(col1,"MEND")!=0){ 
fprintf(mdt,"%d\t%s\n", ++mdtc, col1); // Print MDT index and code
}
fprintf(mdt,"%d\tMEND\n", ++mdtc);
//UpdateALA
fprintf(ala,"1\t%s\n",col2);
}
}
fclose(input);
fclose(mdt);
fclose(mnt);
fclose(ala);
printf("MDT,MNT,andALAtablescreatedsuccessfully.\n");
return 0;
}
