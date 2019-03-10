struct user u;
void companyname();
void newuser();
void mainmenu();
void getusername()
{
	int i,l,flag=0;
	printf("enter username:");
	fflush(stdin);
	gets(u.un);
	l=strlen(u.un);
	if(l>10)
	{
		printf("username must not exceed 10 characters..enter again\n");
		getusername();
	}
	else
	{
		for(i=0;u.un[i]!='\0';i++)
		{
			if(u.un[i]>=65&&u.un[i]<=90||u.un[i]>=97&&u.un[i]<=122)
			{
				flag++;
			}
		}
		if(flag!=l)
		{
			printf("username should not contain any symobls or numbers\n");
			getusername();
		}
	}
}
int getpassword()
{
	char rpw[15];
       //	int l,i,flag=0;
	int l,i,uc=0,lc=0,s=0,n=0;
	printf("enter password:");
	scanf("%s",u.pw);
	l=strlen(u.pw);
       /*	if(l>=8)
	{
		for(i=0;u.pw[i]!='\0';i++)
		{
			if(u.pw[i]>=65&&u.pw[i]<=90 && u.pw[i]>=97&&u.pw[i]<=122 && u.pw[i]>=48&&u.pw[i]<=57 && u.pw[i]>=32&&u.pw[i]<=47||u.pw[i]>=58&&u.pw[i]<=64||u.pw[i]>=91&&u.pw[i]<=96||u.pw[i]>=123&&u.pw[i]<=126)
			{
				flag=1;
				break;
			}
		}
		if(flag==1)
		{
			printf("renter password:");
			scanf("%s",rpw);
			if(strcmp(u.pw,rpw)==0)
			{
				return(1);
			}
			else
			{
				printf("sorry incorrect password...try again\n");
				getpassword();
			}
		}
		else
		{
			printf("\n\npassword must contain atleast one\ncapital letter\nsmall letter\nsymbol\nnumber\n");
			getpassword();
		}
	}
	else
	{
		printf("password must contain min. 8 characters\n");
		getpassword();
	}*/
	if(l>=8)
	{
		for(i=0;u.pw[i]!='\0';i++)
		{
			if(u.pw>=65&&u.pw[i]<=90)
			{
				uc++;
			}
		}
		if(uc>0)
		{
			for(i=0;u.pw[i]!='\0';i++)
			{
				if(u.pw[i]>=97&&u.pw[i]<=122)
				{
					lc++;
				}
			}
			if(lc>0)
			{
				for(i=0;u.pw[i]!='\0';i++)
				{
					if(u.pw[i]>=32&&u.pw[i]<=47||u.pw[i]>=58&&u.pw[i]<=64||u.pw[i]>=91&&u.pw[i]<=96||u.pw[i]>=123&&u.pw[i]<=126)
					{
						s++;
					}
				}
				if(s>0)
				{
					for(i=0;u.pw[i]!='\0';i++)
					{
						if(u.pw[i]>=48&&u.pw[i]<=57)
						{
							n++;
						}
					}
					if(n>0)
					{
						printf("renter password:");
						scanf("%s",rpw);
						if(strcmp(u.pw,rpw)!=0)
						{
							printf("sorry passwords donot match...try again\n");
							getpassword();
						}
						else
						{
							return(1);
						}
					}
					else
					{
						printf("password must contain atleast one number\n");
						getpassword();
					}
				}
				else
				{
					printf("password must contain atleast one symbol\n");
					getpassword();
				}
			}
			else
			{
				printf("password must contain atleast one small letter\n");
				getpassword();
			}
		}
		else
		{
			printf("password must contain atleast one capital letter\n");
			getpassword();
		}
	}
	else
	{
		printf("password must contain min. 8 characters\n");
		getpassword();
	}
}
void newuser()
{
	int ch;
	FILE* fp;
	clrscr();
	companyname();
	getusername();
	if(getpassword()==1)
	{
		printf("User Created..\n\n");
		fp=fopen("input","a+");
		u.test=0;
		fprintf(fp,"%s\t%s\t%d\n",u.un,u.pw,u.test);
		fclose(fp);
		printf("do you want to create another user??(i yes press 1):");
		scanf("%d",&ch);
		if(ch==1)
		{
			newuser();
		}
		else
		{
			mainmenu();
		}
	}
}