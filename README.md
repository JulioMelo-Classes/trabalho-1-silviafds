# Trabalho-1

Projeto de uma versão do jogo Keno. A pessoa que vai jogar passa, através da linha de comando, um arquivo contendo o valor que deseja apostar, a quantidade de rodadas que deseja jogar e os números que deseja apostar, tendo como limite máximo para aposta, 15 números. O programa lê o arquivo, divide o valor total da aposta pela quantidade de apostas para descobrir quanto o usuário irá apostar em cada rodada. 
Depois, o programa sorteia 20 números, sendo eles de 1 a 80. Após o sorteio, o programa verifica quais números apostados foram sorteados e calcula o prêmio com base na quantidade de acertos. Ao final, o programa mostra quantos créditos a pessoa que jogou ganhou. 

**Como compilar o projeto**
- cd build
- cmake ../
- cmake --build .
**Como executar o projeto**
./run_program 
**Como executar o conjunto de testes planejados pelo grupo**
./run_program *nome do arquivo*
**Limitações ou funcionalidades não implementadas no programa**
Não conseguimos implementar a *validação de símbolos*
