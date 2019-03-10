void useroptions();
void companyname();
void unblockuser()
{
	FILE* fp;
	FILE* df;
	int flag=0;
	char uname[15];
	clrscr();
	companyname();
	printf("enter username to be unblocked:");
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
			if(strcmp(u.un,uname)==0)
				flag=1;
		}
	}
	fclose(fp);
	if(flag!=1)
	printf("no such username exists\n");
	else
	{
		fp=fopen("input","r");
		df=fopen("dum","w");
		if(fp==NULL)
		printf("no such file exists\n");
		else
		{
			while(!feof(fp))
			{
				fscanf(fp,"%s\t%s\t%d\n",u.un,u.pw,&u.test);
				if(strcmp(u.un,uname)!=0)
				{
					fprintf(df,"%s\t%s\t%d\n",u.un,u.pw,u.test);
				}
				else
				{
					u.test=0;
					fprintf(df,"%s\t%s\t%d\n",u.un,u.pw,u.test);
				}
			}
		}
		fclose(fp);
		fclose(df);
		df=fopen("dum","r");
		fp=fopen("input","w");
		if(df==NULL)
		printf("no such file exists\n");
		else
		{
			while(!feof(df))
			{
				fscanf(df,"%s\t%s\t%d\n",u.un,u.pw,&u.test);
				fprintf(fp,"%s\t%s\t%d\n",u.un,u.pw,u.test);
			}
		}
		fclose(df);
		fclose(fp);
		printf("successfully unblocked\n");
	}
	printf("enter any key to enter user options\n");
	getch();
	useroptions();
}