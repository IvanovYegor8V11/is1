#include <limits>

#include "knowledge_base.h"


int main() {
    std::string input, team1, team2;
    size_t pos_of_vs;

    std::cout << "Enter name of the first team:\n";
    std::getline(std::cin, team1);

    std::cout << "Enter name of the second team:\n";
    std::getline(std::cin, team2);

    std::cout << "Match: " << team1 << " vs. " << team2 << std::endl;

    knowledge_base kb(team1, team2);

    kb.get_KU();

    char first_answer;
    do {
        std::cout << "Who is the host of the game?" 
                << "\n\t 1 - " << team1 
                << "\n\t 2 - " << team2 
                << "\n\t 3 - Neutral pitch\n";
        std::cin >> first_answer;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "You entered: " << first_answer << std::endl;
    }
    while (first_answer < '1' || first_answer > '3');

    switch (first_answer) {
        case '1':
            kb.shortliff(0.8, 0.2, 0.1, 0.6);
            break;
        case '2':
            kb.shortliff(0.2, 0.8, 0.6, 0.1);
            break;
        case '3':
            kb.shortliff(0.0, 0.0, 0.0, 0.0);
            break;
    }

    kb.get_KU();

    char second_answer;
    do {
        std::cout << "Who has injuries?" 
                << "\n\t 1 - Both teams have injuries" 
                << "\n\t 2 - " << team1 << " has injuries, " << team2 << " doesn\'t have injuries"
                << "\n\t 3 - " << team2 << " has injuries, " << team1 << " doesn\'t have injuries"
                << "\n\t 4 - Both teams don\'t have injuries\n";
        std::cin >> second_answer;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "You entered: " << second_answer << std::endl;
    }
    while (second_answer < '1' || second_answer > '4');

    switch (second_answer) {
        case '1':
            kb.shortliff(0.1, 0.1, 0.6, 0.6);
            break;
        case '2':
            kb.shortliff(0.1, 0.8, 0.8, 0.1);
            break;
        case '3':
            kb.shortliff(0.8, 0.1, 0.1, 0.8);
            break;
        case '4':
            kb.shortliff(0.0, 0.0, 0.0, 0.0);
            break;
    }

    kb.get_KU();

    char third_answer;
    do {
        std::cout << "Who has more wins in face-to-face games?" 
                << "\n\t 1 - " << team1 
                << "\n\t 2 - " << team2
                << "\n\t 3 - Equality or not met yet\n";
        std::cin >> third_answer;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "You entered: " << third_answer << std::endl;
    }
    while (third_answer < '1' || third_answer > '3');

    switch (third_answer) {
        case '1':
            kb.shortliff(0.9, 0.1, 0.1, 0.9);
            break;
        case '2':
            kb.shortliff(0.1, 0.9, 0.9, 0.1);
            break;
        case '3':
            kb.shortliff(0.0, 0.0, 0.0, 0.0);
            break;
    }

    kb.get_KU();

    char fourth_answer;
    do {
        std::cout << "Who has more wins in last games?" 
                << "\n\t 1 - " << team1 
                << "\n\t 2 - " << team2
                << "\n\t 3 - Equality\n";
        std::cin >> fourth_answer;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "You entered: " << fourth_answer << std::endl;
    }
    while (fourth_answer < '1' || fourth_answer > '3');

    switch (fourth_answer) {
        case '1':
            kb.shortliff(0.7, 0.4, 0.4, 0.7);
            break;
        case '2':
            kb.shortliff(0.4, 0.7, 0.7, 0.4);
            break;
        case '3':
            kb.shortliff(0.0, 0.0, 0.0, 0.0);
            break;
    }

    kb.get_KU();

    kb.verdict();

    return 0;
}