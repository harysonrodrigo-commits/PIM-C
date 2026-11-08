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

    
    int resultadoListen = listen(servidor, 1); 
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

    char buffer [1024]; // Onde os bytes recebidos vão ser guardados.

    int bytes = recv(socketCliente, buffer, sizeof(buffer) - 1, 0);
    // recv espera chegar dados e devolve quantos bytes vieram.
    // - 1 deixa uma posição livre para o '\0' no fim do texto.
 
        if (bytes > 0){
            buffer[bytes]='\0'; // '\0' marca o fim do texto, e '-1' em 'recv' garante espaço para ele
            printf ("Mensagem recebida! %s \n", buffer);
        } else if (bytes == 0) {
            printf ("Cliente desconectou! \n");
        } else {
            printf ("Deu erro! %d \n", WSAGetLastError());
        }
    closesocket(socketCliente); // Fecha o socket do cliente 
    closesocket(servidor); //fecha socket do servidor
    WSACleanup(); // Encerra a biblioteca e libera os recursos Winsock alocados
        return 0;
}