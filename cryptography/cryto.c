#include <iostream>
#include <cstring>
#include <stdio.h>
#include <string>
#include <unistd.h>
#include <stdlib.h>

using std::cin;

void show(char *str)
{
        int len = strlen(str);
        for(int i = 0; i < len; i++)
        {
                printf("%c", str[i]);
                sleep(1);
        }
}

void CE(char *string, int n)
{
        for(int i=0; string[i] != '\x00'; i++)
        {
                if((string[i]>='a')&&(string[i]<='z'))//if(islower(str[i]))
                {
                        string[i] = (string[i] - 'a' + n) % 26 + 'a';
                }
                else
                {
                        if((string[i]>='A')&&(string[i]<='Z'))//if(isupper(str[i]))
                        {
                                string[i] = (string[i] - 'A' + n) % 26 + 'A';
                        }
                }
        }

        printf("\n=======================================\nEncrypt : ");
        for(int i = 0; string[i] != '\x00'; i++)
        {
                printf("%c", string[i]);
        }
        printf("\n=======================================\n\n");

}

void CD(char *string, int n)
{
        for(int i=0; string[i] != '\x00'; i++)
        {
                if((string[i]>='a')&&(string[i]<='z'))//if(islower(str[i]
                {
                        string[i] = (string[i] - 'a' - n) % 26 + 'a';
                }
                else
                {
                        if((string[i]>='A')&&(string[i]<='Z'))//if(isupper(str[i]
                        {
                                string[i] = (string[i] - 'A' - n) % 26 + 'A';
                        }
                }
        }
        printf("\n=======================================\nDecrypt : ");
                for(int i = 0; string[i] != '\x00'; i++)
        {
                printf("%c", string[i]);
        }
        printf("\n=======================================\n\n");
}

int main(void)
{
        bool prograss = true;
        while(prograss != false)
        {
                char cryptogram[1024] = {'\x00'};
                int input = 0, n = 0;
                printf("\n1. Quick Decryption\n2. Caesar Cipher\n3. Exit\n");
                cin >> input;
                if(input == 2)
                {
                        system("clear");
                        printf("1. String Encryption\n2. String Decryption\n");
                        printf("Enter : ");
                        cin >> input;
                        if(input == 1)
                        {
                                system("clear");
                                printf("\nEnter the string to be encrypted : ");
                                scanf(" %[^\n]s", cryptogram);
                                printf("\nEnter the Key value : ");
                                scanf(" %d", &n);
                                CE(cryptogram, n);
                        }
                        else
                        {
                                system("clear");
                                printf("\nEnter the string to be decrypted : ");
                                scanf(" %[^\n]s", cryptogram);
                                printf("\nEnter the Key value : ");
                                scanf(" %d", &n);
                                CD(cryptogram, n);
                        }
                }
                else if(input == 3)
                {
                        printf("\n[+]Quick Cryptography Exit\n");
                        prograss = false;
                }
                else
                {
                        system("clear");
                }
        }
        return 0;
}