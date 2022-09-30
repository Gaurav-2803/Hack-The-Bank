#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void end()
{
    system("color c");
    printf("\n\tEnd Of Services\n\t====##################===========");
}


void main()
{
    int ori_pin, pin, choice, length=0,trial=0;
    long balance=10000,deposit,withdraw;
    char decision;
    system("cls");                              //Clear Screen Function
    system("color f");                          //Bright White Color

    printf("4 Digit Pin Only");
    do
    {
        printf("\n=============#####========\nEnter Your Pin : ");
        scanf("%d",&ori_pin);
        printf("=============######========");
        int x=ori_pin;
        while(x!=0)                                 //Check Length Of Pin
        {
            x/=10; 
            length++;
        }  
       
        if(length!=4)
        {
            system("color 4");                     //Red Color more specific brownish red colour
            printf("\nTry Again \nPin Length Should Be 4 Not %d",length);
            length=0;
            trial++;                            
            printf("\n%d Trial Remaning Of 3",3-trial);
            if(trial==3)                               //No. Of trial 
            {
                system("cls");
                printf("\n\t=========######======\n\tTrial Exhausted");
                end();
                break;
            }    
        }   
       
    }while(length!=4);
    
    if(length==4 & trial<3)
    {
        system("color f");                     //Bright White Color
        printf("\nDo You Want To Continue Transation ? (Y/N) : ");
        scanf("%s",&decision);
        system("cls");                        

        if(decision=='Y' || decision=='y')
        {
            printf("\n=====================\nEnter Your Pin : ");
            scanf("%d",&pin);
            if(pin==ori_pin)
            {   
                system("color f");              //Bright White Color
                printf("==========================================\nWelcome To 'Senior Citizen Bank Limited'");
                printf("\n==========================================\n1.Deposit\n2.Withdraw\n3.Balance Check\n4.Exit\n==========================================");
                printf("\n\tEnter Your Choice : ");
                scanf("%d",&choice);

                switch (choice){
                case 1:                         //Deposit
                    printf("\nCurrent Balance : Rs. %lu\nEnter The Amount To Deposit : Rs. ",balance);
                    scanf("%lu", &deposit);
                    balance+=deposit;
                    system("color b");          //Aqua Color
                    printf("\n\tTotal Balance = Rs. %lu\n\nThank You For Using SCBL Bank ATM Services\n==========================================",balance);
                    break;
                
                case 2:                         //Withdraw
                    printf("\nCurrent Balance : Rs. %lu\nEnter The Amount To Withdraw : Rs. ",balance);
                    scanf("%lu",&withdraw);
                    if (balance>=withdraw)
                    {
                        balance-=withdraw;
                        system("color b");      //Aqua Color
                        printf("\n\tTotal Balance = Rs. %lu\n\nThank You For Using SCBL Bank ATM Services\n==========================================",balance);
                        break;
                    }
                    else{
                        printf("\t===================\n\tInsuffient Balance");
                        end();
                    }
                    break;

                case 3:                         //Balance
                    system("color b");          //Aqua Color
                    printf("\n\tTotal Balance = Rs. %lu\n\nThank You For Using SCBL Bank ATM Services\n==========================================",balance);
                	break;
                
                case 4:                         //Exit
                    system("color 1");          //Blue Color
                	printf("\nThank You For Using SCBL Bank ATM Services\n==========================================");
                	break;
                
                default:    
                    system("color c");          //Light Red Color
                	printf("\n\t Invalid Choice");
                    end();
                }
            }
            else{
                printf("\t================\n\tPin Dosent Match");
                end();
            }
        }

        else if(decision=='N' || decision=='n')
        {
            printf("\t===============");
            end();
        }    
        else
        {
            printf("\t================\n\tUnexpected Error");
            end();
        }
    }
    getch(); 
}


// This code is awesome!
