void companyname();
void newuser();
void searchuser();
void deleteuser();
void resetpassword();
void unblockuser();
void itemdashboard();
void mainmenu();
/*void additem();
void showitem();
void searchitem();
void modifyitem();
void deleteitem();    */
int checkadminpassword()
{
       int adminpassword=123,p;
       printf("enter password to login as admin:");
       scanf("%d",&p);
       if(p==adminpassword)
       return(1);
       else
       return(0);
}
void useroptions()
{
	int ch;
	clrscr();
	companyname();
		printf("\n\nmainmenu->admin dashboard->user options\n1.new user\n2.search user\n3.delete user\n4.reset password\n5.unblock user\n6.admin dashboard\n7.mainmenu\n8.exit\nenter your choice:");
			scanf("%d",&ch);
			if(ch==1)
				newuser();
			else if(ch==2)
				searchuser();
			else if(ch==3)
				deleteuser();
			else if(ch==4)
				resetpassword();
			else if(ch==5)
				unblockuser();
			else if(ch==6)
				dashboard();
			else if(ch==7)
				mainmenu();
			else
				exit(1);
}
void dashboard()
{
	int ch,n,k;
	clrscr();
	companyname();
	top:
	if(checkadminpassword())
	{
		clrscr();
		companyname();
		printf("\n\nmainmenu->admin dasboard\n1.user options\n2.itemdashboard\n3.mainmenu\n4.exit\nenter your choice:");
		scanf("%d",&ch);
		if(ch==1)
		{
			useroptions();
		       /*	clrscr();
			companyname();
			printf("\n\nmainmenu->admin dashboard->user options\n1.new user\n2.search user\n3.delete user\n4.reset password\n5.admin dashboard\n6.mainmenu\n7.exit\nenter your choice:");
			scanf("%d",&ch);
			if(ch==1)
				newuser();
			else if(ch==2)
				searchuser();
			else if(ch==3)
				deleteuser();
			else if(ch==4)
				resetpassword();
			else if(ch==5)
				dashboard();
			else if(ch==6)
				mainmenu();
			else
				exit(1);     */
		}
		else if(ch==2)
		{
			itemdashboard();
		      /*	printf("enter choice:");
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
			exit(1);  */
		}
	   //	else if(ch==3)
	     //	unblockuser();
		else if(ch==3)
		mainmenu();
		else
		exit(1);
	}
	else
	{
		printf("incorrect password..please try again\n");
		goto top;
	}
}