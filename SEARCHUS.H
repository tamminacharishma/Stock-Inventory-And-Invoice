void companyname();
void useroptions();
void searchuser()
{
	FILE* fp;
	char uname[15];
	int flag=0;
	clrscr();
	companyname();
	printf("enter username for search:");
	fflush(stdin);
	gets(uname);
	fp=fopen("input","r");
	if(fp==NULL)
		printf("no such file exists\n");
		else
		{
			while(!feof(fp))
			{
				fscanf(fp,"%s\t%s\t%d\n",u.un,u.pw,&u.test);
				if(strcmp(uname,u.un)==0)
				{
					flag=1;
					break;
				}
			}
			fclose(fp);
			if(flag==1)
			{
				printf("username %s exists\n",uname);
			}
			else
			{
				printf("username %s doesnot exist\n",uname);
			}
		}
		printf("press any key to enter user options\n");
		getch();
		useroptions();
}