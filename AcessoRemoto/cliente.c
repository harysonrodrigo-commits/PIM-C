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

    
    // Cria uma variável SOCKET (chame de cliente) com socket(AF_INET, SOCK_STREAM, IPPROTO_TCP).
    // É o seu "telefone": AF_INET = IPv4, SOCK_STREAM = TCP (conexão confiável).
    // Se INVALID_SOCKET: imprima o código, WSACleanup() e return 1.

    // Cria uma struct sockaddr_in (chame de destino).
    // É a "ficha" com o endereço de quem você vai ligar.
    // Preencha três campos:
    //   sin_family = AF_INET                         (tipo de endereço: IPv4)
    //   sin_addr.s_addr = inet_addr("127.0.0.1")     (IP do servidor; 127.0.0.1 = este PC)
    //   sin_port = htons(5000)                       (porta do servidor; htons ajusta a ordem dos bytes para a rede)

    // Cria um int e atribua a ele o retorno de
    // connect(cliente, (struct sockaddr*)&destino, sizeof(destino)).
    // É o ato de "discar" para o servidor.
    // Se SOCKET_ERROR: imprima o código, feche o socket, WSACleanup() e return 1.
    // (Erro 10061 = não tem servidor escutando nessa porta.)

    // Mostra "Conectado ao servidor!"

    // Cria um vetor de char com o texto "Ola servidor" (mensagem).
    // É o conteúdo que vai ser enviado.

    // Cria um int e atribua a ele o retorno de send(cliente, mensagem, strlen(mensagem), 0).
    // Envia os bytes pela conexão; strlen informa quantos bytes mandar.
    // Se SOCKET_ERROR: imprima o código, feche o socket, WSACleanup() e return 1.

    // Mostra "Mensagem enviada!"

    // Fecha o socket com closesocket(cliente): desliga o telefone.
    // Chama WSACleanup(): desliga o Winsock.
    // return 0;
}