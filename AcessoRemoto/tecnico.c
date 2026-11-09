#include <stdio.h>
#include <winsock2.h>

int main() {
        SetConsoleOutputCP(CP_UTF8);
    WSADATA wsaData;
   
    int resultado = WSAStartup(MAKEWORD(2, 2), &wsaData);

        if (resultado != 0) {
            printf("Erro ao iniciar Winsock! Código: %d \n", resultado);
            return 1;
        }
    printf("Winsock iniciado! \n");

    SOCKET tecnico = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

        if (tecnico  == INVALID_SOCKET){
            printf("Erro ao criar Socket! Código: %d\n ",WSAGetLastError());
            WSACleanup();
            return 1;
        }
   
    struct sockaddr_in destino;
        destino.sin_family = AF_INET;
        destino.sin_addr.s_addr = inet_addr("127.0.0.1");
        destino.sin_port = htons(5000);
    

    int solicitaConexao = connect(tecnico, (struct sockaddr*)&destino, sizeof(destino));
        if (solicitaConexao == SOCKET_ERROR){
            printf ("Solicitação não efetuada! Código: %d \n", WSAGetLastError());
            closesocket(tecnico);
            WSACleanup();
            return 1;  // (Erro 10061 = não tem servidor escutando nessa porta.)
        }
        printf ("Conexão realizada com sucesso! \n");

    int token;
    char input [32];

    printf("Dígite o token do cliente: \n");

        if(fgets(input, sizeof(input), stdin) == NULL){
            printf("Erro na leitura! \n");
            closesocket(tecnico);
            WSACleanup();
            return 1;
        }

    input [strcspn(input, "\n")] = '\0';

        if (sscanf(input, "%d", &token) != 1){
            printf("Erro! Digite números. \n");
            closesocket(tecnico);
            WSACleanup();
            return 1;
        }
    
        if ((token < 100000) || (token > 999999)){
            printf("Inválido! \n");
            closesocket(tecnico);
            WSACleanup();
            return 1;
        }
    
    char tokenApresentar [64];
    snprintf(tokenApresentar, sizeof(tokenApresentar), "TECNICO:%d",token);

    char buffer [1024];
    // Cria um vetor de char de 1024 posições (buffer): onde a mensagem do servidor vai ficar guardada.
    int bytes;

    while ((bytes = recv(tecnico, buffer, sizeof(buffer) - 1, 0)) > 0){
        buffer[bytes]='\0'; // '\0' marca o fim do texto, e '-1' em 'recv' garante espaço para ele
        printf ("Mensagem do cliente: %s \n", buffer);
    }
    // Ele espera o servidor repassar a mensagem do cliente.
        
        if (bytes == 0) {
            printf ("Servidor fechou! \n");
        } else {
            printf ("Deu erro! %d \n", WSAGetLastError());
        }
    
    closesocket(tecnico);
    WSACleanup();
    return 0;
}