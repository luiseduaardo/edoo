#include "list.hpp"
#include <iostream>
#include <vector>

using namespace std;

// ADD CODE HERE

int main() {
    // ADD CODE HERE

    string game, card;
    int players, rounds, initial_cards, actual_player;
    bool endedWithBreak = false;

    cin >> game >> players >> rounds >> initial_cards;

    vector<Queue> listPlayerCards(players);
    vector<int> playerPoints(players);

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

        Stack cuzcuzRound;
        string playedCard;
        string winnerCard;
        vector<int> roundWinner;

        for (int p = 0; p < players; p++) {
            if (!listPlayerCards[p].size() == 0) {
                 playedCard = listPlayerCards[p].front();
                 cuzcuzRound.push(playedCard);
                 listPlayerCards[p].pop();

                if (roundWinner.empty()) {
                    roundWinner.push_back(p);
                    winnerCard = playedCard;
                } else {
                    if (playedCard >= winnerCard) {
                        if (playedCard > winnerCard) {
                            roundWinner.clear();
                            winnerCard = playedCard;
                        }
                        roundWinner.push_back(p);
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
        for (int player : roundWinner) {
            cout << player << " ";
        }
        cout << endl;
    }

    for (int pont : playerPoints) {
        cout << pont << " ";
    }
    cout << endl;

    vector<int> winnerPlayers;

    if (!endedWithBreak) {
        int greatest = 0;

        for (int i = 0; i < players; i++) {
            if (playerPoints[i] >= greatest) {
                if (playerPoints[i] > greatest) {
                    winnerPlayers.clear();
                    greatest = playerPoints[i];
                }

                winnerPlayers.push_back(i);
            }
        }
    } else {
        for (int i = 0; i < players; i++) {
            if (listPlayerCards[i].size() > 0) {
                winnerPlayers.push_back(i);
                break;
            }
        }
    }

    for (int w : winnerPlayers) {
        Queue winnerCards = listPlayerCards[w];

        cout << w << ": ";
        while (winnerCards.size() > 0) {
            cout << winnerCards.front() << " ";
            winnerCards.pop();
        }
        cout << endl;
    }

    return 0;
}