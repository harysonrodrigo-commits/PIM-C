#include <stdio.h>
#include <string.h>
#include <winsock2.h>

int main() {
        SetConsoleOutputCP(CP_UTF8);
    WSADATA wsaData;
   
    int resultado = WSAStartup(MAKEWORD(2, 2), &wsaData);

        if (resultado != 0) {
            printf("Erro ao iniciar Winsock! %d \n", resultado);
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

    char mensagem [] = "Olá servidor!";
    // Cria um vetor de char com o texto "Ola servidor" (mensagem).
    // É o conteúdo que vai ser enviado.

    int bytesEnviados = send(cliente, mensagem, strlen(mensagem), 0);
    // Envia os bytes pela conexão; strlen informa quantos bytes mandar.

        if (bytesEnviados == SOCKET_ERROR){
            printf ("Bytes não enviados! Código: %d \n", WSAGetLastError());
            closesocket(cliente);
            WSACleanup();
            return 1;
        }
    printf ("Mensagem enviada! \n");
    
    closesocket(cliente);
    WSACleanup();
    return 0;
}