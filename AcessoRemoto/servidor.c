#include <stdio.h>
#include <winsock2.h>

int main() {
    // 1. declare uma variável WSADATA
    WSADATA wsaData; 
    // 2. chame WSAStartup(MAKEWORD(2, 2), &suaVariavel)
    int resultado = WSAStartup (MAKEWORD(2, 2), &wsaData);
    // 3. verifique se retornou 0; se não, imprima erro e saia
    if (resultado !=0){
        printf ("Winsock não iniciado! \n");
        return 1;
    }
    // 4. imprima "Winsock iniciado"
    printf ("Winsock iniciado! \n");
    // 5. chame WSACleanup() no final
    WSACleanup();
    return 0;
}