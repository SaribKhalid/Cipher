#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>


char Main_Array[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789,./;:@#$%!";
char Mapping_Key[sizeof(Main_Array)];

//Basic printf to display the menu
void show()
{
    printf("--------------- CIPHER PROGRAM ---------------\n");
    printf("1. Encrypt\n");
    printf("2. Decrypt\n");
    printf("3. Generate a New Key\n");
    printf("4. Exit\n");
    printf("----------------------------------------------\n");
}



void shuffle()
{
    strcpy(Mapping_Key,Main_Array);
    int length = strlen(Mapping_Key);

    printf("Generating new Key....\n");
    for (int i = length - 1; i > 0; i--)
    {
        // Generate Random Number fom 0 to i+1
        int j = rand() % (i+1); 
        // Swapping characters on index positions
        char temporary = Mapping_Key[i]; 
        Mapping_Key[i] = Mapping_Key[j]; 
        Mapping_Key[j] = temporary;
    }
    Sleep(1000);
    printf("Key Generated!\n");
}

void Encrypt(char message[], char encrypted_message[])
{
    
    int length = strlen(Mapping_Key);
    printf("Encrypting your message....\n");

    for (int j = 0; j < strlen(message); j++)
    {
        int found = 0;

        for (int i = 0; i < length ; i++)
        {
            //Main part
            if (message[j] == Main_Array[i])
            {
                encrypted_message[j] = Mapping_Key[i];
                found = 1;
                break;
            }

        }

        //Space not in main array so found would be zero so as it is copy.
        if(!found)
        {
            encrypted_message[j] = message[j];
        }
    }

    encrypted_message[strlen(message)] = '\0';
    Sleep(2000);
    printf("Your Encrypted message is: %s\n", encrypted_message);
}

void Decrypt(char encrypted_message[], char decrypted_message[])
{
    
    int message_len = strlen(encrypted_message);
    int key_len = strlen(Main_Array);

    printf("Decrypting Your Message...\n");

   

    for (int i = 0; i < message_len; i++)
    { 
        int found = 0;
        for (int j = 0; j < key_len; j++)
        {
            //reverse-logic of encrypt
            //we checked in main array in encrypt we check in MappinKey over here
            if(encrypted_message[i] == Mapping_Key[j])
            {
                decrypted_message[i] = Main_Array[j];
                found = 1;
                break;
            }
        }
        if (!found)
        {
            decrypted_message[i] = encrypted_message[i];
        }
    }
    
    decrypted_message[message_len] = '\0';
    Sleep(2000);
    printf("Your Decrypted message is: %s\n", decrypted_message);
}

int main()
{
    char message[100];
    char encrypted_message[100];
    char decrypted_message[100];
    int Option;

    //random seed generator
    srand(time(NULL));
    // generating key once
    shuffle(); 

    //Menu Program
    while (1)
    {
        show();
        
        printf("Enter your Option: ");
        scanf("%d", &Option);
        getchar();
        
        switch (Option)
        {
        //For Encrypt
        case 1:
            printf("Enter the message you want to encrpyt: ");
            fgets(message, sizeof(message), stdin);
            message[strcspn(message, "\n")] = '\0';
            Encrypt(message, encrypted_message);
            break;
        
        //For Decrypt
        case 2:
            printf("Enter the message you want to decrpyt: ");
            fgets(message, sizeof(message), stdin);
            message[strcspn(message, "\n")] = '\0';
            Decrypt(message, decrypted_message);
            break;
        
        //Generating New key, basically calling shuffle module
        case 3:
            shuffle();
            break;
        
        //Exit
        case 4:
            printf("====================== THANK YOU FOR USING THE APPLICATION ======================\n");
            printf("=================================== GOODBYE ====================================\n");
            return 0;
        
        //For invalid Option by user
        default:
            printf("Invalid Option entered.\nPlease enter an option from 1-4.\n");
            break;
        }
    }
}