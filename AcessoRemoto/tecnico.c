#include <stdio.h>
#include <windows.h>
#include <winsock2.h>

int main (){
     SetConsoleOutputCP(CP_UTF8);// aceitar acentos

     WSADATA wsaData;

     int resultado = WSAStartup(MAKEWORD (2, 2), &wsaData);

        if (resultado !=0){ // Se diferente de zero, há um erro na inicialização do Winsock
            printf ("Winsock não iniciado! \n");
            return 1;
        }
     printf ("Winsock iniciado! \n");

     SOCKET tecnico = socket (AF_INET, SOCK_STREAM, IPPROTO_TCP);
     
        









}