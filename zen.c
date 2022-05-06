void deleted(void)
{
FILE <em>oldrecord,</em>newrecord;
int test=0;
oldrecord=fopen("record.dat","r");
newrecord=fopen("new.dat","w");
printf("Enter the account no. of the customer you want to delete:");
scanf("%d",&amp;remittance.account_number);
while (fscanf(oldrecord,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d",&amp;adding.account_number,adding.client_name,&amp;adding.client_dob.mm,&amp;adding.client_dob.dd,&amp;adding.client_dob.yy,&amp;adding.client_age,adding.client_address,adding.client_citizenship,&amp;adding.client_phone,adding.client_account_type,&amp;adding.client_amount,&amp;adding.client_deposit.mm,&amp;adding.client_deposit.dd,&amp;adding.client_deposit.yy)!=EOF)
{
if(adding.account_number!=remittance.account_number)
fprintf(newrecord,"%d %s %d/%d/%d %d %s %s %lf %s %f %d/%d/%d\n",adding.account_number,adding.client_name,adding.client_dob.mm,adding.client_dob.dd,adding.client_dob.yy,adding.client_age,adding.client_address,adding.client_citizenship,adding.client_phone,adding.client_account_type,adding.client_amount,adding.client_deposit.mm,adding.client_deposit.dd,adding.client_deposit.yy);
else {test++; printf("\nRecord deleted successfully!\n"); }
}
fclose(oldrecord);
fclose(newrecord);
remove("record.dat");
rename("new.dat","record.dat");
if(test==0)
{
printf("\nRecord not found!!\a\a\a");
deleted_invalid:
printf("\nEnter 0 to try again,1 to return to main menu and 2 to exit:");
scanf("%d",&amp;exits);
if (exits==1) menu(); else if (exits==2) close(); else if(exits==0) deleted(); else {printf("\nInvalid!\a"); goto deleted_invalid;} } else {printf("\nEnter 1 to go to the main menu and 0 to exit:"); scanf("%d",&amp;exits); system("cls"); if (exits==1) menu(); else close(); }
}
