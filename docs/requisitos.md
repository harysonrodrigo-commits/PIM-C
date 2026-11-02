# Levantamento de Requisitos: Sistema de Chamados com Acesso Remoto

## 1. Visão geral

Sistema para atendimento de problemas em computadores e outros aparelhos digitais. O **usuário** abre um chamado descrevendo o problema. O **técnico** analisa e define se o atendimento será **presencial** ou **remoto**. No atendimento remoto, o técnico visualiza a tela e controla mouse e teclado da máquina do usuário, mediante autorização.

Público-alvo: pessoas com dificuldade em informática, como idosos, com problemas simples.

## 2. Escopo

### Dentro do escopo

- Cadastro e login de usuários e técnicos
- Abertura de chamados (inclusive pelo celular) e fila de espera
- Triagem do chamado pelo técnico (urgência, prazo, modalidade)
- Acesso remoto em máquinas **Windows**: visualização da tela e controle de mouse e teclado
- Autorização e cancelamento do compartilhamento pelo usuário

### Fora do escopo

- Acesso remoto em Android, macOS e Linux
- Perfil de administrador e acesso do admin pelo celular
- Transferência de arquivos, chat e outras funções além das listadas

## 3. Atores

| Ator | Papel |
|---|---|
| **Usuário** | Abre o chamado, descreve o problema, autoriza e cancela o compartilhamento da máquina |
| **Técnico** | Atende o chamado, analisa, define urgência, prazo e modalidade (presencial ou remoto), acessa a máquina e resolve |

## 4. Requisitos funcionais (RF)

| ID | Descrição |
|---|---|
| RF01 | O usuário e o técnico devem poder se cadastrar e fazer login no sistema. |
| RF02 | O usuário deve poder abrir um chamado informando a descrição do problema; o chamado entra em uma fila de espera. |
| RF03 | O técnico deve analisar o chamado e definir o nível de urgência, o prazo estimado de atendimento e a modalidade (presencial ou remoto). |
| RF04 | Em atendimento remoto, o usuário deve poder aceitar o compartilhamento da sua máquina. |
| RF05 | Após a autorização, o técnico deve poder visualizar a tela da máquina e controlar mouse e teclado. |
| RF06 | O usuário deve poder cancelar o compartilhamento a qualquer momento com um clique. |
| RF07 | O técnico deve poder encerrar o chamado após resolver o problema. |

## 5. Requisitos não funcionais (RNF)

| ID | Descrição |
|---|---|
| RNF01 | O módulo de acesso remoto deve ser desenvolvido em linguagem **C**. |
| RNF02 | O sistema deve ser compatível com **Windows**. |
| RNF03 | A transmissão da tela deve ter bom desempenho: atualização em até **1 segundo** *(valor a ajustar após testes)*. |
| RNF04 | A conexão deve ser segura: o acesso remoto exige **token único**, válido apenas durante a sessão. |

## 6. Regras de negócio (RN)

| ID | Descrição |
|---|---|
| RN01 | Apenas o técnico responsável pelo chamado pode acessar a máquina do usuário. |
| RN02 | O acesso só começa após o usuário aceitar o compartilhamento. |
| RN03 | O usuário pode abrir o chamado pelo celular. |
| RN04 | O acesso remoto só ocorre quando a modalidade definida for remoto. |

## 7. Restrições

- Linguagem C obrigatória no módulo de acesso remoto
- Suporte apenas ao sistema Windows nesta versão
- Prazo de entrega definido pela faculdade (UNIP)
- Acesso do administrador pelo celular não será implementado

## 8. Priorização (MVP)

1. **Essencial:** sistema de cadastro funcionando (RF01, RF02, RF03).
2. **Essencial:** compartilhamento de tela funcionando, no mínimo visualização (RF04, RF05 parcial).
3. **Desejável:** controle de mouse e teclado, cancelamento com um clique, encerramento do chamado (RF05 completo, RF06, RF07).
4. **Futuro:** outros sistemas operacionais e perfil de administrador.
