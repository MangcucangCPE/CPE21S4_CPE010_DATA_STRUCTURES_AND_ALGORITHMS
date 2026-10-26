#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "sortingAlgo2.h"

const int VOTE_COUNT = 100;

struct Candidate {
    int id;
    std::string name;
    int votes;
};

int main() {
    Candidate candidates[5] = {
        {1, "Bo Dalton Capistrano", 0},
        {2, "Cornelius Raymon Agustin", 0},
        {3, "Deja Jayla Banaga", 0},
        {4, "Laila Brielle Yabut", 0},
        {5, "Franklin Relano Castro", 0}
    };

    int votesArr[VOTE_COUNT];

    srand(time(0));

    for (int i = 0; i < VOTE_COUNT; i++) {
        votesArr[i] = (rand() % 5) + 1;
    }

    std::cout << "Unsorted Votes:\n";

    for (int i = 0; i < VOTE_COUNT; i++) {
        std::cout << votesArr[i] << " ";
    }

    std::cout << "\n\n";

    insertionSort(votesArr, VOTE_COUNT);

    std::cout << "Sorted Votes:\n";

    for (int i = 0; i < VOTE_COUNT; i++) {
        std::cout << votesArr[i] << " ";
    }

    std::cout << "\n\n";

    for (int i = 0; i < VOTE_COUNT; i++) {
        if (votesArr[i] == 1) {
            candidates[0].votes++;
        }
        else if (votesArr[i] == 2) {
            candidates[1].votes++;
        }
        else if (votesArr[i] == 3) {
            candidates[2].votes++;
        }
        else if (votesArr[i] == 4) {
            candidates[3].votes++;
        }
        else if (votesArr[i] == 5) {
            candidates[4].votes++;
        }
    }

    std::cout << "Vote Count:\n";

    for (int i = 0; i < 5; i++) {
        std::cout << "Candidate " << candidates[i].id
                  << " - " << candidates[i].name
                  << ": " << candidates[i].votes
                  << " votes\n";
    }

    int winner = 0;

    for (int i = 1; i < 5; i++) {
        if (candidates[i].votes > candidates[winner].votes) {
            winner = i;
        }
    }

    std::cout << "\nWinner: Candidate "
              << candidates[winner].id
              << " - " << candidates[winner].name
              << " with " << candidates[winner].votes
              << " votes\n";

    return 0;
}