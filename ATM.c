#include <stdio.h>
#include<string.h>
struct user{
  char name[20];
  char pass[10];
  int balance;
  char history[100];
}user1={"Akram","5337",0};

void deposit()
{
  printf("\nEnter your Password : ");
  char pin[100];
  scanf("%s",pin);
  if(strcmp(pin,user1.pass)==0){
    printf("\nWelcome %s !!",user1.name);
    printf("\nEnter Deposit Amount : ");
    int dep;
    scanf("%d",&dep);
    char transaction[50];
    sprintf(transaction, "Deposited: %d\n", dep);
    strcat(user1.history, transaction); 
    user1.balance+=dep;
    printf("Amount Deposited Successfully !!");
    printf("\nDo you want to check Balance ?\n");
    int ch;
    printf("\n1.Yes\t2.No");
    scanf("%d",&ch);
    switch(ch){
      case 1:printf("Available Balance : %d",user1.balance);
            break;
      case 2:break;
      default:printf("Invalid Choice..!!");
    }
  }else{
    printf("Password Incorrect !!");
  }
}

void withdraw()
{
  printf("\nEnter your Password : ");
  char pin[100];
  scanf("%s",pin);
  if(strcmp(pin,user1.pass)==0){
    printf("\nWelcome %s !!",user1.name);
    printf("\nEnter Amount To Withdraw : ");
    int draw;
    scanf("%d",&draw);
    if(user1.balance>draw){
      //user1.history=draw;
      user1.balance-=draw;
      char transaction[50];
      sprintf(transaction, "Withdrawn: %d\n", draw);
      strcat(user1.history, transaction);  
      printf("Amount Withdrawn Successfully..!!");
      printf("\nDo you want to check Balance ?");
      int ch;
      printf("\n1.Yes\t2.No\n");
      scanf("%d",&ch);
      switch(ch){
        case 1:printf("Available Balance : %d",user1.balance);
              break;
        case 2:break;
        default:printf("Invalid Choice..!!");
      }
    }else{
      printf("Not Enough Amount Available..!!");
    }
  }else{
    printf("Password Incorrect !!");
  }
}

void balance()
{
  printf("\nEnter your Password : ");
  char pin[100];
  scanf("%s",pin);
  if(strcmp(pin,user1.pass)==0){
    printf("\nWelcome %s !!",user1.name);
    printf("\nAvailable Balance : %d",user1.balance);
  }else{
    printf("Password Incorrect !!");
  }
}

void history()
{
  printf("\nEnter your Password : ");
  char pin[100];
  scanf("%s",pin);
  if(strcmp(pin,user1.pass)==0){
    printf("\nWelcome %s !!",user1.name);
    printf("\nYour Transaction History...!! : \n");
    printf("%s",user1.history);
  }else{
    printf("Password Incorrect !!");
  }
}

void changePin()
{
  printf("\nEnter your Password : ");
  char pin[100];
  scanf("%s",pin);
  if(strcmp(pin,user1.pass)==0){
    printf("\nWelcome %s !!",user1.name);
    printf("\nEnter New Password : ");
    char ps[10];
    char ps1[10];
    scanf("%s",ps);
    int i=0;
    printf("\nRe-Enter your Password : \n");
    scanf("%s",ps1);
    if(strcmp(ps,ps1)==0){
      while(ps[i]!='\0'){
       user1.pass[i]=ps[i];
       i++;
      }
    printf("Password Set Successfully..!!");
    }
    else{
        printf("Password Incorrect..!!\n");
        printf("Try Again...!!\n");
    }
  }else{
    printf("Password Incorrect !!");
  }
}

int main()
{
  while(1){
    printf("\n*****\tWelcome To ATM MACHINE\t*****\n\n");
    printf("\t1.Deposit\n");
    printf("\t2.Withdraw\n");
    printf("\t3.Balance Enquiry\n");
    printf("\t4.Transaction History\n");
    printf("\t5.Pin Change\n");
    printf("\t6.Exit\n");
    int choice;
    printf("\nPlease Enter Your Choice : ");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1:deposit();
            break;
      case 2:withdraw();
            break;
      case 3:balance();
            break;
      case 4:history();
            break;
      case 5:changePin();
            break;
      case 6:printf("Thanks You...Visit Again...!!");
      return 0;
      default:printf("Invalid Choice...!!\n");
    }
  }
}