void companyname();
void mainmenu();
void additem();
void showitem();
void searchitem();
void modifyitem();
void deleteitem();
void itemdashboard()
{
	int k;
	clrscr();
	companyname();
	printf("\n\nmainmenu->admin dashboard->item dashboard\n1.add item\n2.show item\n3.search item\n4.modify item\n5.delete item\n6.mainmenu\n7.admin dashboard\n8.exit\n");
	printf("enter choice:");
	scanf("%d",&k);
	if(k==1)
	additem();
	else if(k==2)
	showitem();
	else if(k==3)
	searchitem();
	else if(k==4)
	modifyitem();
	else if(k==5)
	deleteitem();
	else if(k==6)
	mainmenu();
	else if(k==7)
	dashboard();
	else
	exit(1);
}
void additem()
{
	FILE* fp;
	int n;
	clrscr();
	i.ino=0;
	companyname();
	fp=fopen("items","a+");
	if(fp==NULL)
	printf("no such file exists\n");
	else
	{
		while(!feof(fp))
		{
			fscanf(fp,"%d\t%d\t%s\t%d\t%f\n",&i.ino,&i.icode,i.iname,&i.stock,&i.icost);
		}
	      //	fclose(fp);
		     //  fp=fopen("items","w");
			i.ino++;
		       //	printf("null");
			printf("enter details\nenter item code:");
			scanf("%d",&i.icode);
			printf("enter item name:");
			fflush(stdin);
			gets(i.iname);
			printf("enter no. of stock:");
			scanf("%d",&i.stock);
			printf("enter item cost:");
			scanf("%f",&i.icost);
			fprintf(fp,"%d\t%d\t%s\t%d\t%f\n",i.ino,i.icode,i.iname,i.stock,i.icost);
	}
	fclose(fp);
	printf("do you want to add another item?(if yes press 1)\n");
	scanf("%d",&n);
	if(n==1)
		additem();
	else
	{
		printf("press any key to enter item dashbord");
		getch();
		itemdashboard();
	}
}
void showitem()
{
	FILE* fp;
	int count=0;
	clrscr();
	companyname();
	fp=fopen("items","r");
	if(fp==NULL)
	printf("no such file exists\n");
	else
	{
		while(!feof(fp))
		{
			fscanf(fp,"%d\t%d\t%s\t%d\t%f\n",&i.ino,&i.icode,i.iname,&i.stock,&i.icost);
		}
		fclose(fp);
		if(i.ino>=1)
		{
			fp=fopen("items","r");
			printf("itemno.\t\titemcode\titemname\tstock\titemcost\n");
			while(!feof(fp))
			{
				fscanf(fp,"%d\t%d\t%s\t%d\t%f\n",&i.ino,&i.icode,i.iname,&i.stock,&i.icost);
				count++;
				if(count!=4)
					printf("%d\t\t%d\t\t%s\t\t%d\t%f\n",i.ino,i.icode,i.iname,i.stock,i.icost);
				else
				{
					count=1;
					printf("press enter to continue\n");
					getch();
					clrscr();
					printf("itemno.\t\titemcode\titemname\tstock\titemcost\n");
					printf("%d\t\t%d\t\t%s\t\t%d\t%f\n",i.ino,i.icode,i.iname,i.stock,i.icost);
				}
			}
		}
		else
		{
			printf("no items found\n");
		}
	}
	fclose(fp);
	printf("press any key to enter item dashboard");
	getch();
	itemdashboard();
}
void searchitem()
{
	int code,flag=0,n;
	FILE* fp;
	companyname();
	printf("enter item code of item to be searched:");
	scanf("%d",&code);
	fp=fopen("items","r");
	if(fp==NULL)
	printf("no such file exists\n");
	else
	{
		while(!feof(fp))
		{
			fscanf(fp,"%d\t%d\t%s\t%d\t%f\n",&i.ino,&i.icode,i.iname,&i.stock,&i.icost);
			if(code==i.icode)
			{
				flag=1;
			}
		}
		fclose(fp);
	}
	if(flag==1)
	{
		fp=fopen("items","r");
		if(fp==NULL)
		printf("no such file exists\n");
		else
		{
			while(!feof(fp))
			{
				fscanf(fp,"%d\t%d\t%s\t%d\t%f\n",&i.ino,&i.icode,i.iname,&i.stock,&i.icost);
				if(code==i.icode)
				{
					printf("item details\nitem code:%d\nitem name:%s\nstock:%d\nitem cost:%f\n",i.icode,i.iname,i.stock,i.icost);
				}
			}
			fclose(fp);
		}
	}
	else
	{
		printf("sorry!no such item found..try again\n");
		searchitem();
	}
	printf("do you want to search another item?(if yes press 1)\n");
	scanf("%d",&n);
	if(n==1)
		searchitem();
	else
	{
		printf("press any key to enter item dashboard");
		getch();
		itemdashboard();
	}
}
void modifyitem()
{
	int check,ch,n;
	FILE* fp;
	FILE* df;
	clrscr();
	companyname();
	fp=fopen("items","r");
	df=fopen("dummy","w");
	if(fp==NULL)
	printf("no such file exists\n");
	else
	{
	printf("enter itemcode of item to be modified:");
	scanf("%d",&check);
	while(!feof(fp))
	{
		fscanf(fp,"%d\t%d\t%s\t%d\t%f\n",&i.ino,&i.icode,i.iname,&i.stock,&i.icost);
		if(check==i.icode)
		{
			choice:
			printf("what do you need to modify??\n1.itemcode\n2.itemname\n3.stock\n4.itemcost\n");
			scanf("%d",&ch);
			if(ch==1)
			{
				printf("enter modified item code:");
				scanf("%d",&i.icode);
			}
			else if(ch==2)
			{
				printf("enter modified item name:");
				gets(i.iname);
			}
			else if(ch==3)
			{
				printf("enter modified stock:");
				scanf("%d",&i.stock);
			}
			else if(ch==4)
			{
				printf("enter modified item cost:");
				scanf("%f",&i.icost);
			}
			else
			{
				printf("invalid choice\n");
				goto choice;
			}
			printf("do you need to modify another option(if yes press 1)");
			scanf("%d",&ch);
			if(ch==1)
		      //	modifyitem();
			goto choice;
			fprintf(df,"%d\t%d\t%s\t%d\t%f\n",i.ino,i.icode,i.iname,i.stock,i.icost);
		}
		else
		{
			fprintf(df,"%d\t%d\t%s\t%d\t%f\n",i.ino,i.icode,i.iname,i.stock,i.icost);
		}
	}
	}
	fclose(fp);
	fclose(df);
	df=fopen("dummy","r");
	fp=fopen("items","w");
	if(df==NULL)
	printf("no such file exists\n");
	else
	{
		while(!feof(df))
		{
			fscanf(df,"%d\t%d\t%s\t%d\t%f\n",&i.ino,&i.icode,i.iname,&i.stock,&i.icost);
			fprintf(fp,"%d\t%d\t%s\t%d\t%f\n",i.ino,i.icode,i.iname,i.stock,i.icost);
		}
	}
	fclose(df);
	fclose(fp);
	printf("do you want to modify another item?(if yes press 1)\n");
	scanf("%d",&n);
	if(n==1)
		modifyitem();
	else
	{
		printf("press any key to enter item dashboard");
		getch();
		itemdashboard();
	}
}
void deleteitem()
{
	int check,count=0,t,n;
	FILE* fp;
	FILE* df;
	clrscr();
	companyname();
	fp=fopen("items","r");
	if(fp==NULL)
	printf("no such file exists\n");
	else
	{
		printf("enter item code of item to be deleted:");
		scanf("%d",&check);
		while(!feof(fp))
		{
			fscanf(fp,"%d\t%d\t%s\t%d\t%f\n",&i.ino,&i.icode,i.iname,&i.stock,&i.icost);
			count++;
		}
		fclose(fp);
		if(count==1)
		{
			fp=fopen("items","w");
			fclose(fp);
		}
		else
		{
			fp=fopen("items","r");
			df=fopen("dummy","w");
			while(!feof(fp))
			{
			fscanf(fp,"%d\t%d\t%s\t%d\t%f\n",&i.ino,&i.icode,i.iname,&i.stock,&i.icost);
			if(i.icode!=check)
			fprintf(df,"%d\t%d\t%s\t%d\t%f\n",i.ino,i.icode,i.iname,i.stock,i.icost);
			else
			t=i.ino;
			}
			fclose(fp);
			fclose(df);
			df=fopen("dummy","r");
			fp=fopen("items","w");
			if(df==NULL)
				printf("no such file exists\n");
			else
			{
				while(!feof(df))
				{
					fscanf(df,"%d\t%d\t%s\t%d\t%f\n",&i.ino,&i.icode,i.iname,&i.stock,&i.icost);
					if(i.ino<t)
					fprintf(fp,"%d\t%d\t%s\t%d\t%f\n",i.ino,i.icode,i.iname,i.stock,i.icost);
					else
					{
						i.ino--;
						fprintf(fp,"%d\t%d\t%s\t%d\t%f\n",i.ino,i.icode,i.iname,i.stock,i.icost);
					}
				}
			}
			fclose(fp);
			fclose(df);
		}
	}
	printf("deleted\n");
	printf("do you want to add delete item?(if yes press 1)\n");
	scanf("%d",&n);
	if(n==1)
		deleteitem();
	else
	{
		printf("press any key to enter item dashboard");
		getch();
		itemdashboard();
	}
}