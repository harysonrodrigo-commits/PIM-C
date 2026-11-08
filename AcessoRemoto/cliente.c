#include <stdio.h>
#include <string.h>
#include <winsock2.h>
#include <stdlib.h>
#include <time.h>

int main() {
        SetConsoleOutputCP(CP_UTF8);
        srand (time(NULL));
    WSADATA wsaData;
   
    int resultado = WSAStartup(MAKEWORD(2, 2), &wsaData);

        if (resultado != 0) {
            printf("Erro ao iniciar Winsock! Código: %d \n", resultado);
            return 1;
        }
    printf("Winsock iniciado! \n");

    SOCKET cliente = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

        if (cliente == INVALID_SOCKET){
            printf("Erro ao criar Socket! Código: %d\n ",WSAGetLastError());
            WSACleanup();
            return 1;
        }
   
    struct sockaddr_in destino;
        destino.sin_family = AF_INET;
        destino.sin_addr.s_addr = inet_addr("127.0.0.1");
        destino.sin_port = htons(5000);
    

    int solicitaConexao = connect(cliente, (struct sockaddr*)&destino, sizeof(destino));
        if (solicitaConexao == SOCKET_ERROR){
            printf ("Solicitação não efetuada! Código: %d \n", WSAGetLastError());
            closesocket(cliente);
            WSACleanup();
            return 1;  // (Erro 10061 = não tem servidor escutando nessa porta.)
        }
    printf ("Conexão realizada com sucesso! \n");

    int token = (rand() * 32768 + rand ()) % 900000 + 100000;
    printf ("Seu token: %d \n", token);

    char tokenApresentar [64];
    snprintf(tokenApresentar, sizeof(tokenApresentar), "CLIENTE:%d",token);
    
    int envioToken = send(cliente, tokenApresentar, strlen(tokenApresentar), 0);
        
        if (envioToken == SOCKET_ERROR){
                printf ("Token não enviado! Código: %d \n", WSAGetLastError());
                closesocket(cliente);
                WSACleanup();
                return 1;
        }
    printf ("Token enviado com sucesso! \n");

    char resposta [64];
    int bytes = recv(cliente, resposta, sizeof(resposta) - 1, 0);

        if (bytes == SOCKET_ERROR){
            printf ("Resposta não recebida! Código: %d \n", WSAGetLastError());
            closesocket(cliente);
             WSACleanup();
            return 1;
        } else if (bytes==0) {
            printf ("Servidor sem conexão! \n");  
            closesocket(cliente);
            WSACleanup();
            return 1;
        }else{
            printf("Resposta do servidor recebida com sucesso! \n");
            resposta[bytes] = '\0';
                if (strcmp(resposta, "OK") == 0){
                    printf("Acesso liberado! \n");
                } else {
                    printf("Acesso negado! \n");
                    closesocket(cliente);
                    WSACleanup();
                    return 1;
                }
        }
            
    char mensagem [] = "Olá servidor!";
    // Cria um vetor de char com o texto "Ola servidor" (mensagem).
    // É o conteúdo que vai ser enviado.
    for (int i = 1; i <= 5; i++){
        char mensagem [64];
        sprintf(mensagem, " Mensagem: %d\n", i);
    
        int bytesEnviados = send(cliente, mensagem, strlen(mensagem), 0);
        // Envia os bytes pela conexão; strlen informa quantos bytes mandar.

            if (bytesEnviados == SOCKET_ERROR){
                printf ("Bytes não enviados! Código: %d \n", WSAGetLastError());
                closesocket(cliente);
                WSACleanup();
                return 1;
                break;
            }
        printf ("Mensagem enviada! \n");
        Sleep (2000);
    }
    closesocket(cliente);
    WSACleanup();
    return 0;
}