void companyname();
void userloginoptions();
void changepassword()
{
	FILE* fp;
	FILE* df;
	char pword[15];
	clrscr();
	companyname();
  /*	printf("enter username to reset password:");
	fflush(stdin);
	gets(uname);   */
	fp=fopen("input","r");
	df=fopen("dummy","w");
	if(fp==NULL)
		printf("no such file exists\n");
		else
		{
				while(!feof(fp))
				{
				fscanf(fp,"%s\t%s\t%d\n",u.un,u.pw,&u.test);
				if(strcmp(u.un,ref)==0)
				{
					password:
					printf("enter password:");
					fflush(stdin);
					gets(pword);
					if(strcmp(u.pw,pword)==0)
					{
						printf("change your password\n");
						getpassword();
						fprintf(df,"%s\t%s\t%d\n",u.un,u.pw,u.test);
					}
					else
					{
						printf("sorry!incorrect password..try again\n");
						goto password;
					}
				}
				else
				{
					fprintf(df,"%s\t%s\t%d\n",u.un,u.pw,u.test);
				}
			}
			fclose(fp);
			fclose(df);
		}
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
				fclose(df);
				fclose(fp);
			}
			printf("press any key to enter userlogin options\n");
			getch();
			userloginoptions();
}