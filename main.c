#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int counterAccounts = 0 ,actualAccountNum =0 , accountNum = 0 ,accountNumAdded = 0 , choice,breakNum =0;
int var=1 ;
char testingCin[20];
int testCin=1;
int numAccAdd;
float montantRetrait;
typedef struct
{
    char cin[20];
    char fName[20];
    char sName[20];
    float montant;
}accounts;
accounts  clients[100], clientsCpy ;
float montantIntroduit;
// les fonctions pour capter l'information via l'utilisateur.
void getClientInfo(void)
{
    char cinClient[20];
    printf("Entrez votre CIN : ");
    scanf("%s", &cinClient[20]);
    return cinClient[20];

}
char getClientFirstName(void)
{
    char fNameClient[20];
    printf("Entrez votre nom : ");
    scanf("%s", &fNameClient[20]);
    return fNameClient[20];

}
char getClientSecondName(void)
{
    char sNameClient[20];
    printf("Entrez votre prénom : ");
    scanf("%s", &sNameClient[20]);
    return sNameClient[20];

}
float getClientMontant(void)
{
    float clientMontant;
    printf("Entrez le montant : ");
    scanf("%f", &clientMontant);
    return clientMontant;
}

int main()
{
        do{

       // Afficher la menu
       printf("Choisir un nombre:\n \t- 1 : Creer un compte.\n\t- 2 : Creer plusieurs comptes.\n\t- 3 : Opérations.\n\t- 4 : Affichage.\n\t- 5 : Fidélisation. \n\t- 6 : Quitter l’application.\n ");
       scanf("%d",&choice);
       switch(choice)
       {
           case(1): //1 : Creer un compte.
           {

        printf(" Bonjour! Bienvenu, Pour debut un compte!\n Commencez par entrez votre information suivant:\n");



        var =1;

        do
        {
            var=1;
            printf("\n Donner Son CIN: ");
            scanf("%s",testingCin);
            for (int i=0;i < actualAccountNum;i++)
            {
                if (strcmp(testingCin,clients[i].cin)==0) // pour être CIN unique
                {
                    printf("\nCette carte deja exsite.\n");

                    var=0;
                    break;
                }
            }

        //if(var==1) strcpy(clients[counterAccounts].cin,testingCin);

        }while(var == 0);


                    strcpy(clients[counterAccounts].cin,testingCin);
                    printf("Entrez votre Nom : ");
                    scanf("%s", &clients[counterAccounts].sName);
                    printf("Entrez votre prenom : ");
                    scanf("%s", &clients[counterAccounts].fName);
                    printf("Entrez votre montant : ");
                    scanf("%f", &clients[counterAccounts].montant);

                    counterAccounts++;
                    actualAccountNum =counterAccounts;





           }break;
           case(2):
           {
        printf(" Bonjour! Bienvenu, Pour debut un compte!\n Commencez par entrez votre information suivant:\n");

        printf("\nTaper le nombre des comptes: ");
        scanf("%d",&numAccAdd);
        accountNumAdded = actualAccountNum + numAccAdd;
        for(counterAccounts;1;counterAccounts)
        {
            var =1;

        do
        {
            var=1;
            printf("\n Donner Son CIN: ");
            scanf("%s",testingCin);
            for (int i = 0;i < actualAccountNum ;i++)
            {
                if (strcmp(testingCin,clients[i].cin)== 0) // pour être CIN unique
                {
                    printf("\nCette carte deja exsite.\n");
                    var = 0;
                    break;
                }
            }



        }while(var==0);


                    strcpy(clients[counterAccounts].cin,testingCin);
                    printf("Entrez votre Nom : ");
                    scanf("%s", &clients[counterAccounts].sName);
                    printf("Entrez votre prenom : ");
                    scanf("%s", &clients[counterAccounts].fName);
                    printf("Entrez votre montant : ");
                    scanf("%f", &clients[counterAccounts].montant);
                    counterAccounts++;
                    //accountNumAdded++;
                    actualAccountNum = counterAccounts;
                    if(accountNumAdded - actualAccountNum <= 0 )break;

        }




           }break;
           case(3):
           {
               printf("\t taper le nombre :\n\t - 1 : Retrait.\n\t - 2 : Depot.\n :   ");
               scanf("%d",&choice);
               switch (choice)
               {
                case 1 :
                {
                    //
                    do{
                        printf("\nDonner CIN : ");
                        scanf("%s",&testingCin);
                        var=1;
                        for(int j = 0 ; j < actualAccountNum ; j++)
                        {

                            if(strcmp(testingCin,clients[j].cin) == 0)
                            {
                                printf("Enter le monatant : ");
                                scanf("%f",&montantRetrait);
                                clients[j].montant -= montantRetrait;
                                var = 0;
                                break;

                            }
                        }
                        if(var == 1 )
                        {
                            printf("CIN incorrect");

                        }

                      }while(var ==1 );
                    }break;
                    case 2 :
                {
                    //
                    do{
                        printf("\nDonner CIN : ");
                        scanf("%s",&testingCin);
                        var=1;
                        for(int j = 0 ; j < actualAccountNum ; j++)
                        {

                            if(strcmp(testingCin,clients[j].cin) == 0)
                            {
                                printf("Enter le monatant : ");
                                scanf("%f",&montantRetrait);
                                clients[j].montant += montantRetrait;
                                var = 0;
                                break;

                            }
                        }
                        if(var == 1 )
                        {
                            printf("CIN incorrect");

                        }

                      }while(var ==1 );
                    }break;


                }

               }break;

           case(4):
           {
               printf("\n\t\t Affichage par :\n\t - 1 : Ordre Ascendant.\n\t - 2 : Ordre Descendant.");
               printf("\n\t - 3 : Ordre Ascendant (les comptes bancaire ayant un montant supérieur à un chiffre introduit).");
               printf("\n\t - 4 : Ordre Descendant (les comptes bancaire ayant un montant supérieur à un chiffre introduit).");
               printf("\n\t - 5 : Recherche CIN.\n\t     : ");
               scanf("%d",&choice);
               switch(choice)
               {
                   case 1 :
                   {
                       for(int j = 0 ; j <actualAccountNum ; j++)
                       {
                           for(int u = j + 1 ; u < actualAccountNum;u++ )
                           {
                               if(clients[j].montant > clients[u].montant)
                               {
                                    strcpy(clientsCpy.cin, clients[j].cin);
                                    strcpy(clientsCpy.sName, clients[j].sName);
                                    strcpy(clientsCpy.fName, clients[j].fName);
                                    clientsCpy.montant = clients[j].montant;

                                    strcpy(clients[j].cin,clients[u].cin);
                                    strcpy(clients[j].sName,clients[u].sName);
                                    strcpy(clients[j].fName,clients[u].fName);
                                    clients[j].montant = clients[u].montant;

                                    strcpy(clients[u].cin,clientsCpy.cin);
                                    strcpy(clients[u].sName,clientsCpy.sName);
                                    strcpy(clients[u].fName,clientsCpy.fName);
                                    clients[u].montant = clientsCpy.montant;

                               }
                           }
                        }
                        for(int j = 0 ; j <actualAccountNum ; j++)
                        {
                            printf("\n Nom :  %s %s \n cin : %s \n montant : %.2f \n ", clients[j].sName,clients[j].fName, clients[j].cin, clients[j].montant);

                        }

                   }break;
                   case 2:
                   {
                       for(int j = 0 ; j <actualAccountNum ; j++)
                       {
                           for(int u = j +1 ; u < actualAccountNum;u++ )
                           {
                               if(clients[j].montant < clients[u].montant)
                               {
                                    strcpy(clientsCpy.cin, clients[j].cin);
                                    strcpy(clientsCpy.sName, clients[j].sName);
                                    strcpy(clientsCpy.fName, clients[j].fName);
                                    clientsCpy.montant =clients[j].montant;

                                    strcpy(clients[j].cin,clients[u].cin);
                                    strcpy(clients[j].sName,clients[u].sName);
                                    strcpy(clients[j].fName,clients[u].fName);
                                    clients[j].montant = clients[u].montant;

                                    strcpy(clients[u].cin,clientsCpy.cin);
                                    strcpy(clients[u].sName,clientsCpy.sName);
                                    strcpy(clients[u].fName,clientsCpy.fName);
                                    clients[u].montant = clientsCpy.montant;


                               }


                           }
                        }
                        for(int j = 0 ; j <actualAccountNum ; j++)
                        {
                            printf("\n Nom :  %s %s \n cin : %s \n montant : %.2f \n ", clients[j].sName,clients[j].fName, clients[j].cin, clients[j].montant);

                        }

                   }break;
                   case 3 :
                    {
                        for(int j = 0 ; j <actualAccountNum ; j++)
                        {
                           for(int u = j + 1 ; u < actualAccountNum;u++ )
                           {
                               if(clients[j].montant > clients[u].montant)
                               {
                                    strcpy(clientsCpy.cin, clients[j].cin);
                                    strcpy(clientsCpy.sName, clients[j].sName);
                                    strcpy(clientsCpy.fName, clients[j].fName);
                                    clientsCpy.montant = clients[j].montant;

                                    strcpy(clients[j].cin,clients[u].cin);
                                    strcpy(clients[j].sName,clients[u].sName);
                                    strcpy(clients[j].fName,clients[u].fName);
                                    clients[j].montant = clients[u].montant;

                                    strcpy(clients[u].cin,clientsCpy.cin);
                                    strcpy(clients[u].sName,clientsCpy.sName);
                                    strcpy(clients[u].fName,clientsCpy.fName);
                                    clients[u].montant = clientsCpy.montant;


                               }


                           }
                        }

                        printf("Donner le chiffre : ");
                        scanf("%f",&montantIntroduit);

                        for(int j = 0 ; j < actualAccountNum ; j++)
                        {
                            if(clients[j].montant >= montantIntroduit)
                            printf("\n Nom :  %s %s \n cin : %s \n montant : %.2f \n ", clients[j].sName,clients[j].fName, clients[j].cin, clients[j].montant);

                        }

                    }break;
                    case 4 :
                    {
                        for(int j = 0 ; j <actualAccountNum ; j++)
                        {
                           for(int u = j + 1 ; u < actualAccountNum;u++ )
                           {
                               if(clients[j].montant < clients[u].montant)
                               {
                                    strcpy(clientsCpy.cin, clients[j].cin);
                                    strcpy(clientsCpy.sName, clients[j].sName);
                                    strcpy(clientsCpy.fName, clients[j].fName);
                                    clientsCpy.montant = clients[j].montant;

                                    strcpy(clients[j].cin,clients[u].cin);
                                    strcpy(clients[j].sName,clients[u].sName);
                                    strcpy(clients[j].fName,clients[u].fName);
                                    clients[j].montant = clients[u].montant;

                                    strcpy(clients[u].cin,clientsCpy.cin);
                                    strcpy(clients[u].sName,clientsCpy.sName);
                                    strcpy(clients[u].fName,clientsCpy.fName);
                                    clients[u].montant = clientsCpy.montant;


                               }


                           }
                        }
                        printf("Donner le chiffre : ");
                        scanf("%f",&montantIntroduit);

                        for(int j = 0 ; j < actualAccountNum ; j++)
                        {
                            if(clients[j].montant >= montantIntroduit)
                            printf("\n Nom :  %s %s \n cin : %s \n montant : %.2f \n ", clients[j].sName,clients[j].fName, clients[j].cin, clients[j].montant);

                        }

                    }break;
                    case 5 :
                    {
                        do{
                        printf("\nDonner CIN de votre compte : ");
                        scanf("%s",&testingCin);
                        var=1;
                        for(int j = 0 ; j < actualAccountNum ; j++)
                        {

                            if(strcmp(testingCin,clients[j].cin) == 0)
                            {
                                printf("\n Nom :  %s %s \n cin : %s \n montant : %.2f \n ", clients[j].sName,clients[j].fName, clients[j].cin, clients[j].montant);
                                var = 0;
                                break;

                            }
                        }
                        if(var == 1 )
                        {
                            printf("CIN incorrect");

                        }

                      }while(var ==1 );



               }break;
            }
                //for(int j = 0 ; j <actualAccountNum ; j++)
                //{
                  //  printf("\n Nom :  %s %s \n cin : %s \n montant : %.2f \n ", clients[j].sName,clients[j].fName, clients[j].cin, clients[j].montant);

                //}
           }break;
           case(5):
           {
                for(int j = 0 ; j <actualAccountNum ; j++)
                    {
                       for(int u = j + 1 ; u < actualAccountNum;u++ )
                       {
                           if(clients[j].montant < clients[u].montant)
                           {
                                strcpy(clientsCpy.cin, clients[j].cin);
                                strcpy(clientsCpy.sName, clients[j].sName);
                                strcpy(clientsCpy.fName, clients[j].fName);
                                clientsCpy.montant = clients[j].montant;

                                strcpy(clients[j].cin,clients[u].cin);
                                strcpy(clients[j].sName,clients[u].sName);
                                strcpy(clients[j].fName,clients[u].fName);
                                clients[j].montant = clients[u].montant;

                                strcpy(clients[u].cin,clientsCpy.cin);
                                strcpy(clients[u].sName,clientsCpy.sName);
                                strcpy(clients[u].fName,clientsCpy.fName);
                                clients[u].montant = clientsCpy.montant;


                           }


                       }
                    }
                    for(int j = 0 ; j < 3 && j < actualAccountNum ; j++)
                    {
                        clients[j].montant *= 1.013;



                    }




           }break;
           case(6):
           {
               return 0;

           }break;

       }
    }while(1);

}
