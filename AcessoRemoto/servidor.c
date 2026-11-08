#include <stdio.h>
#include <winsock2.h>

int main() {
       SetConsoleOutputCP(CP_UTF8);// aceitar acentos
    WSADATA wsaData; //Recebe info. Sobre a implementação Winsock
   
    int resultado = WSAStartup (MAKEWORD(2, 2), &wsaData); 
    //Inicializa Winsock, solicita versão e guarda o cod. Retornado pela função
   
        if (resultado !=0){ // Se diferente de zero, há um erro na inicialização do Winsock
            printf ("Winsock não iniciado! \n");
            return 1;
        }
    printf ("Winsock iniciado! \n");

    SOCKET servidor = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); // Criar o socket

        if (servidor == INVALID_SOCKET){  //Se servidor for igual a socket invalido, deu erro, então imprima o erro e saia.
            printf ("Erro ao criar Socket! Código: %d \n", WSAGetLastError());
            WSACleanup();
            return 1;
        }

    
    struct sockaddr_in endereco;
    //Rascunho salvo na memória para BIND reservar endereço e porta
        endereco.sin_family = AF_INET;
        endereco.sin_addr.s_addr = INADDR_ANY;
        endereco.sin_port = htons(5000);

    int resultadoBind = bind (servidor, (struct sockaddr*)&endereco, sizeof (endereco));
    //Reserva porta e endereço ao socket
   
        if (resultadoBind == SOCKET_ERROR){ // Se IP e porta não for atribuida, imprima o erro, encerre e saia
            printf ("Erro ao atribuir a porta! Codigo: %d \n", WSAGetLastError());
            closesocket(servidor);
            WSACleanup();
            return 1;
        }

    
    int resultadoListen = listen(servidor, 5); 
    //Põe o Socket em modo de espera, pronto para ouvir e receber pedidos de conexão
    
        if (resultadoListen == SOCKET_ERROR){ //Mesmo tratamento de BIND
                printf ("Erro ao colocar na fila de espera! Código: %d \n", WSAGetLastError());
                closesocket(servidor);
                WSACleanup();
                return 1;
        }


    printf("Servidor escutando na porta 5000...\n");

    printf ("Aguardando conexão do cliente! \n"); // esperando alguém conectar

    SOCKET socketCliente = accept (servidor, NULL, NULL); 
    //SOCKET para cliente, com função accept, para atender e devolver um novo socket para o cliente  
   
        if (socketCliente == INVALID_SOCKET){
            printf ("Conexão deu erro! Código: %d \n", WSAGetLastError());
            closesocket(servidor);
            WSACleanup(); //Se INVALID_SOCKET então, deu erro
            return 1;
        }
    printf ("Cliente conectado! \n"); //ligação foi atendida

    printf ("Aguardando o técnico! \n");

    SOCKET socketTecnico = accept(servidor, NULL, NULL);
        if (socketTecnico == INVALID_SOCKET){
            printf ("Conexão deu erro! Código: %d \n", WSAGetLastError());
            closesocket(socketCliente);
            closesocket(servidor);
            WSACleanup(); //Se INVALID_SOCKET então, deu erro
            return 1;
        }
            printf("Técnico conectado! \n");

    char buffer [1024]; // Onde os bytes recebidos vão ser guardados.7
    int bytes;
  
    while ((bytes = recv(socketCliente, buffer, sizeof(buffer) - 1, 0)) > 0) {
            buffer[bytes] = '\0';
            printf("Repassando: %s \n", buffer);

            int enviado = send(socketTecnico, buffer, bytes, 0);
        if (enviado == SOCKET_ERROR) {
            printf("Mensagem não repassada! Código: %d \n", WSAGetLastError());
            break;   // sai do laço
        }
    }
       
        if (bytes == 0) {
            printf ("Cliente desconectou! \n");
        } else {
            printf ("Deu erro no recv! %d \n", WSAGetLastError());
        }

    closesocket(socketTecnico); // Fecha o socket do Tecnico
    closesocket(socketCliente); // Fecha o socket do cliente 
    closesocket(servidor); //fecha socket do servidor
    WSACleanup(); // Encerra a biblioteca e libera os recursos Winsock alocados
        return 0;
}