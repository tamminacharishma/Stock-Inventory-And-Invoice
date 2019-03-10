void dashboard();
void userlogin();
void companyname()
{
	printf("\n\n\nKIRAN GROUP OF COMPANIES\n");
}
void mainmenu()
{
	int ch;
	clrscr();
	companyname();
	printf("\n\nmainmenu\n1.admin dashboard\n2.user login\n3.exit\nenter your choice:");
	scanf("%d",&ch);
	if(ch==1)
	dashboard();
	else if(ch==2)
	userlogin();
	else
	exit(1);
}
