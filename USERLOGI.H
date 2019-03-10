//void showitem();
void companyname();
void mainmenu();
void userloginoptions();
void mis();
void changepassword();
int selection()
{
	int code;
	printf("enter item code:");
	scanf("%d",&code);
	return(code);
}
void invoice()
{
	float ta=0,k,amount;
	int code,q,flag=0,noi,billno=0,p=0,t,f;
	char month[10],m[10];
	FILE* fp;
	FILE* df;
	FILE* bd;
	FILE* d1;
       //	FILE* d2;
	df=fopen("dummy","w");
	select:
	fp=fopen("items","r");
     //	showitem();
	code=selection();
	if(fp==NULL)
		printf("no such file exists\n");
	else
	{
	      /*	while(!feof(fp))
		{
			fscanf(fp,"%d\t%d\t%s\t%f\n",&i.ino,&i.icode,i.iname,&i.icost);
			count++;
		}
		fclose(fp);
		if(count!=0)
		{
			code=selection();
			fp=fopen("items","r");  */
			while(!feof(fp))
			{
				fscanf(fp,"%d\t%d\t%s\t%d\t%f\n",&i.ino,&i.icode,i.iname,&i.stock,&i.icost);
				if(code==i.icode)
				{
					flag=1;
					t=i.ino;
					printf("enter no. of quantity:");
					scanf("%d",&q);
					if(i.stock>0&&i.stock==q)
					{
					   //	printf("enter no. of quantity:");
					     //	scanf("%d",&q);
						p=p+q;
						amount=q*i.icost;
						fprintf(df,"%d\t%d\t%s\t%f\t%d\t%f\n",i.ino,i.icode,i.iname,i.icost,q,amount);
					}
					else
					{
						f=0;
						printf("sorry!out of stock\n");
					}
				}
				noi=p;
			}
			if(flag==0)
			{
				printf("sorry!no such item found..try again\n");
				goto select;
			}
			else
			{
				fclose(fp);
				fp=fopen("items","r");
				d1=fopen("dummie","w");
				if(fp==NULL)
				printf("no such file exists\n");
				else
				{
					while(!feof(fp))
					{
						fscanf(fp,"%d\t%d\t%s\t%d\t%f\n",&i.ino,&i.icode,i.iname,&i.stock,&i.icost);
						if(i.ino!=t)
						{
							fprintf(d1,"%d\t%d\t%s\t%d\t%f\n",i.ino,i.icode,i.iname,i.stock,i.icost);
						}
						else
						{
							if(i.stock>0)
							{
								i.stock=i.stock-q;
							}
							fprintf(d1,"%d\t%d\t%s\t%d\t%f\n",i.ino,i.icode,i.iname,i.stock,i.icost);
						}
					}
				}
				fclose(fp);
				fclose(d1);
				fp=fopen("items","w");
				d1=fopen("dummie","r");
				if(d1==NULL)
				printf("no such file exists\n");
				else
				{
					while(!feof(d1))
					{
						fscanf(d1,"%d\t%d\t%s\t%d\t%f\n",&i.ino,&i.icode,i.iname,&i.stock,&i.icost);
						fprintf(fp,"%d\t%d\t%s\t%d\t%f\n",i.ino,i.icode,i.iname,i.stock,i.icost);
					}
				}
				fclose(fp);
				fclose(d1);
			}
			printf("do you want to select another item??(if yes press 1)\n");
			scanf("%d",&q);
			if(q==1)
			{
			 //	fclose(fp);
				goto select;
			}
			else
			{
			   //	fclose(fp);
				if(f!=0)
				{
					printf("enter month:");
					fflush(stdin);
					gets(month);
				}
				fclose(df);
				df=fopen("dummy","r");
				if(df==NULL)
				printf("no such file exists\n");
				else
				{
					companyname();
					printf("your bill\nino.\ticode\tiname\ticost\t\tq\tamount\n");
					while(!feof(df))
					{
						fscanf(df,"%d\t%d\t%s\t%f\t%d\t%f\n",&i.ino,&i.icode,i.iname,&i.icost,&q,&amount);
						if(q>0)
						{
							printf("%d\t%d\t%s\t%f\t%d\t%f\n",i.ino,i.icode,i.iname,i.icost,q,amount);
							ta+=amount;
						}
						else
						{
							clrscr();
							printf("thank you!visit again\n");
							printf("press any key to enter mainmenu\n");
							getch();
							mainmenu();
						}
					}
				      //	printf("total no. of items:%d\ntotal amount:%f\nTHANK YOU...VISIT AGAIN\n",noi,ta);
					bd=fopen("billdetails","r");
					if(bd==NULL)
					printf("no such file exists\n");
					else
					{
						while(!feof(bd))
						{
							fscanf(bd,"%s\t%d\t%d\t%f\n",m,&billno,&p,&k);
						}
						billno++;
					}
					fclose(bd);
					bd=fopen("billdetails","a+");
					if(bd==NULL)
						printf("no such file exists\n");
						else
						{
							if(noi>0)
							{
								fprintf(bd,"%s\t%d\t%d\t%f\n",month,billno,noi,ta);
							}
							fclose(bd);
						}
						fclose(df);
						printf("total no. of items:%d\ntotal amount:%f\nTHANK YOU...VISIT AGAIN\n",noi,ta);
				}
			}
	       /*	}
		else
		{
			printf("no items found\n");
		}      */

	}
	printf("press any key to enter userlogin options");
	getch();
	userloginoptions();
}
void billdetails()
{
	FILE* bd;
	int bno,billno,noi,s;
	float ta;
	char m[10];
	clrscr();
	companyname();
	printf("enter bill no. to get details:");
	scanf("%d",&bno);
	bd=fopen("billdetails","r");
	if(bd==NULL)
		printf("no such file exists\n");
		else
		{
			printf("month\tbill no.\tno.ofitems\ttotamnt\n");
			while(!feof(bd))
			{
				fscanf(bd,"%s\t%d\t%d\t%f\n",m,&billno,&noi,&ta);
				if(billno==bno)
				{
					printf("%s\t%d\t\t%d\t\t%f\n",m,billno,noi,ta);
				}
			}
			fclose(bd);
		}
		printf("\n\ndo you want to get another bill detail(if yes press 1)?\n");
		scanf("%d",&s);
		if(s==1)
			billdetails();
		else
		{
			printf("\n\npress any key to enter userlogin options\n");
			getch();
			userloginoptions();
		}
}
void mis()
{
	char month[10],m[10];
	int count=0,s,billno,noi,flag=0;
	float ttlamnt=0,ta;
	FILE* bd;
	clrscr();
	companyname();
	printf("enter month:");
	fflush(stdin);
	gets(month);
	bd=fopen("billdetails","r");
	if(bd==NULL)
		printf("no such file exists\n");
	else
	{
		printf("total bill details of %s\n",month);
		printf("bill no.\tq\tamount\n");
		while(!feof(bd))
		{
			fscanf(bd,"%s\t%d\t%d\t%f\n",m,&billno,&noi,&ta);
			if(strcmp(m,month)==0)
			{
				 flag=1;
				 count++;
				 if(count!=4)
				 printf("%d\t\t%d\t\t%f\n",billno,noi,ta);
				 else
				 {
					printf("press any key to continue\n");
					getch();
					clrscr();
					printf("bill no.\tq\tamount\n");
					printf("%d\t\t%d\t\t%f\n",billno,noi,ta);
					count=1;
				 }
				 ttlamnt+=ta;
			}
		}
	}
	if(flag==0)
	{
		clrscr();
		printf("no bills found\n");
	}
	else
		printf("total amount of %s is %f\n",month,ttlamnt);
	printf("do you want to get details of another month(if yes press 1)?");
	scanf("%d",&s);
	if(s==1)
		mis();
	else
	{
		printf("press any key to enter userloaginoptions\n");
		getch();
		userloginoptions();
	}
}
void userloginoptions()
{
	int n;
	clrscr();
	companyname();
	printf("\n\nmaimenu->userlogin\n1.invoice\n2.change password\n3.bill details\n4.MIS\n5.mainmenu\n6.exit\nenter your choice\n");
	scanf("%d",&n);
	if(n==1)
	invoice();
	else if(n==2)
	changepassword();
	else if(n==3)
	billdetails();
	else if(n==4)
	mis();
	else if(n==5)
	mainmenu();
	else
	exit(1);
}
void userlogin()
{
	char username[15],password[10];
	int count,flag=0,l=0;
	FILE* fp;
	FILE* dy;
	clrscr();
	companyname();
	un:
	fp=fopen("input","r");
	printf("enter username:");
	fflush(stdin);
	gets(username);
	strcpy(ref,username);//ref is for reset password
	if(fp==NULL)
	{
		printf("no such file exists\n");
		fclose(fp);
	}
	else
	{
	while(!feof(fp))
	{
		count=0;
		fscanf(fp,"%s\t%s\t%d\n",u.un,u.pw,&u.test);
		if(strcmp(u.un,username)==0)
		{
		       /*	if(u.test!=0)
			{
				printf("sorry!your account is blocked..contact administrator\n");
				printf("\npress any key to enter mainmenu\n");
				getch();
				mainmenu();
			}*/
			flag=1;
			if(u.test!=0)
			{
				printf("sorry!your account is blocked..contact administrator\n");
				printf("\npress any key to enter mainmenu\n");
				getch();
				mainmenu();
			}
			else
			{
				pword:
				printf("enter password:");
				fflush(stdin);
				gets(password);
				if(strcmp(u.pw,password)==0)
				{
					printf("login successful\n");
					userloginoptions();
				  /*	clrscr();
					companyname();
					printf("\n\nmaimenu->userlogin\n1.invoice\n2.bill details\n3.mainmenu\n4.exit\nenter your choice\n");
					scanf("%d",&n);
					if(n==1)
					invoice();
					else if(n==2)
					billdetails();
					else if(n==3)
					mainmenu();
					else
					exit(1);          */
				}
				else
				{
					count++;
					if(count!=3)
					{
						printf("sorry!incorrect password..try again\n");
						goto pword;
					}
					else
					{
						printf("sorry!your account is blocked\n");
						fclose(fp);
						fp=fopen("input","r");
						dy=fopen("dupli","w");
						if(fp==NULL)
						printf("no such file exists\n");
						else
						{
							while(!feof(fp))
							{
								fscanf(fp,"%s\t%s\t%d\n",u.un,u.pw,&u.test);
								if(strcmp(u.un,username)!=0)
								{
									fprintf(dy,"%s\t%s\t%d\n",u.un,u.pw,u.test);
								}
								else
								{
									u.test=1;
									fprintf(dy,"%s\t%s\t%d\n",u.un,u.pw,u.test);
								}
							}
							fclose(fp);
							fclose(dy);
							dy=fopen("dupli","r");
							fp=fopen("input","w");
							if(dy==NULL)
							printf("no such file exists\n");
							else
							{
								while(!feof(dy))
								{
									fscanf(dy,"%s\t%s\t%d\n",u.un,u.pw,&u.test);
									fprintf(fp,"%s\t%s\t%d\n",u.un,u.pw,u.test);
								}
							}
							fclose(fp);
							fclose(dy);
							printf("press any key to enter mainmenu\n");
							getch();
							mainmenu();
						}
					}
				}
		       }
		    /*   else
		       {
				printf("sorry!your account is blocked..contact administrator\n");
				printf("\npress any key to enter mainmenu\n");
				getch();
				mainmenu();
		       }      */
		}
	}
	}
       //	fclose(fp);
	if(flag==0)
	{
		printf("sorry!no such username exists\n");
		goto un;
	}
     /*	printf("press any key to enter mainmenu\n");
	getch();
	mainmenu();    */
}