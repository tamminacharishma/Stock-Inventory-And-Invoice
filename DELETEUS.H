void companyname();
void useroptions();
void deleteuser()
{
	FILE* fp;
	FILE* df;
	int count=0;
	char uname[15];
	clrscr();
	companyname();
	printf("enter username to be deleted:");
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
				count++;
			}
			fclose(fp);
			if(count==1)
			{
				fp=fopen("input","w");
				fclose(fp);
			}
			else
			{
			fp=fopen("input","r");
			df=fopen("dummy","w");
			while(!feof(fp))
			{
				fscanf(fp,"%s\t%s\t%d\n",u.un,u.pw,&u.test);
				if(strcmp(u.un,uname)!=0)
				{
					fprintf(df,"%s\t%s\t%d\n",u.un,u.pw,u.test);
				}
			}
			fclose(df);
		fclose(fp);
		df=fopen("dummy","r");
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
			fclose(fp);
			fclose(df);
		}
		}
			printf("press any key to enter user options\n");
			getch();
			useroptions();
}