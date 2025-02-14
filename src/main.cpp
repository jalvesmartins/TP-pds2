#include <iostream>
#include <sstream>
#include <string>
#include "../include/headers.hpp"
#include "../include/system_operations.hpp"

int main() {
    try {
        Registration registry("players.csv");
        SystemOperations gameManage;
        bool running = true;

        while (running) {
            gameManage.displayMenu();

            int option;
            try {
                if (!(std::cin >> option)) {
                    throw std::invalid_argument("Entrada invalida. Por favor, insira um numero entre 1 e 5.");
                }

                switch (option) {
                    case 1:
                        gameManage.handleRegisterPlayer(registry);
                        break;
                    case 2:
                        gameManage.handleRemovePlayer(registry);
                        break;
                    case 3:
                        gameManage.handleListPlayers(registry);
                        break;
                    case 4:
                        gameManage.handleExecuteGame(registry);
                        break;
                    case 5:
                        running = false;
                        std::cout << "\nFinalizando o sistema. Ate logo!\n";
                        break;
                    default:
                        throw std::out_of_range("Opcao invalida. Escolha uma opcao entre 1 e 5.");
                }
            } catch (const std::exception& e) {
                std::cerr << "\nERRO: " << e.what() << "\n";
                std::cin.clear();
                std::cin.ignore(10000, '\n');
            }
        }
    } catch (const std::exception& e) {
        std::cerr << "\nErro critico: " << e.what() << "\n";
        return 1;
    }

    return 0;
}