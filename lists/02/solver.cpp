#include "list.hpp"
#include <iostream>

using namespace std;

// ADD CODE HERE

int main() {
    // ADD CODE HERE

    // inicialização de todas as variável do jogo
    string game, card;
    int players, rounds, initial_cards, actual_player;
    bool endedWithBreak = false;

    cin >> game >> players >> rounds >> initial_cards;

    Queue* listPlayerCards = new Queue[players];
    int* playerPoints = new int[players];
    for (int i = 0; i < players; i++) {
        playerPoints[i] = 0;
    }

    int total_cards = players * initial_cards;

    // loop de distribuição das cartas entre os jogadores
    for (int i = 0; i < total_cards; i++) {
        actual_player = i % players;

        cin >> card;

        (listPlayerCards[actual_player]).push(card);
    }

    // loop do jogo em si
    for (int r = 0; r < rounds; r++) {

        // verifica se todos os jogadores estão com cartas
        int playersWithCards = 0;
        for (int p = 0; p < players; p++) {
            if (!listPlayerCards[p].size() == 0) playersWithCards++;
        }

        // se apenas um jogador permanecer com cartas para jogar, encerra
        if (playersWithCards <= 1){
            endedWithBreak = true;
            break;
        }

        // inicialização das variáveis da rodada
        Stack cuzcuzRound;
        string playedCard, winnerCard;
        Vector roundWinner;


        for (int p = 0; p < players; p++) {
            if (!listPlayerCards[p].size() == 0) {
                 playedCard = listPlayerCards[p].front();
                 cuzcuzRound.push(playedCard);
                 listPlayerCards[p].pop();

                // primeira rodada do jogo, então ainda não definiu vencedor
                if (roundWinner.empty()) {
                    roundWinner.append(p);
                    winnerCard = playedCard;
                // não está mais na primeira rodada, faz a comparação de cartas
                } else {
                    if (playedCard >= winnerCard) {
                        if (playedCard > winnerCard) {
                            roundWinner.clear();
                            winnerCard = playedCard;
                        }
                        roundWinner.append(p);
                    }
                }
            }
        }
        
        // verifica se houve empate ou vitória de um jogador somente
        // caso em que só um jogador ganha
        if (roundWinner.size() == 1) {
            int winner = roundWinner[0];

            playerPoints[winner]++;

            while (!cuzcuzRound.size() == 0) {
                listPlayerCards[winner].push(cuzcuzRound.top());
                cuzcuzRound.pop();
            }
        // caso em que ocorre empate
        } else {
            for (int i = 0; i < roundWinner.size(); i++) {
                playerPoints[roundWinner[i]]++;
            }
        }

        // print do(s) vencedor(es) da rodada
        cout << r << " " << winnerCard << " ";
        for (int i = 0; i < roundWinner.size(); i++) {
            cout << roundWinner[i] << " ";
        }
        cout << endl;
    }
    
    // imprime a lista com as pontuações dos jogadores
    for (int i = 0; i < players; i++) {
        cout << playerPoints[i] << " ";
    }
    cout << endl;

    // imprime as mãos do(s) jogador(es) vencedor(es)
    Vector winnerPlayers;

    // se o loop do jogo encerrou com um break, ou seja, apenas um jogador permeneceu com cartas para jogar, ele é quem é o vencedor
    if (!endedWithBreak) {
        int greatest = 0;

        for (int i = 0; i < players; i++) {
            if (playerPoints[i] >= greatest) {
                if (playerPoints[i] > greatest) {
                    winnerPlayers.clear();
                    greatest = playerPoints[i];
                }

                winnerPlayers.append(i);
            }
        }
    // se todas as rodadas ocorreram normalmente, ou seja, mais de um jogador teve cartas para jogar até o final
    } else {
        for (int i = 0; i < players; i++) {
            if (listPlayerCards[i].size() > 0) {
                winnerPlayers.append(i);
                break;
            }
        }
    }

    // faz efetivamente a impressão da(s) mão(s) vencedora(s)
    for (int i = 0; i < winnerPlayers.size(); i++) {
        Queue& winnerCards = listPlayerCards[winnerPlayers[i]];

        cout << winnerPlayers[i] << ": ";
        while (winnerCards.size() > 0) {
            cout << winnerCards.front() << " ";
            winnerCards.pop();
        }
        cout << endl;
    }

    delete[] listPlayerCards;
    delete[] playerPoints;

    return 0;
}
