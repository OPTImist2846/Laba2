#include <iostream> // Для введення/виведення (cout, cin)
#include <string>   // Для роботи з рядками (string)
#include <vector>   // Для динамічних масивів (vector)
#include <fstream>  // Для файлових операцій (ifstream, ofstream)
#include <sstream>  // Для роботи з рядками як потоками (stringstream)
#include <limits>   // Для numeric_limits (обробка некоректного введення)
#include <iomanip>  // Для setprecision (форматування виводу чисел)

// Включаємо заголовні файли наших класів.
// Самі оголошення класів та їх реалізації повинні бути у відповідних .h та .cpp файлах.
#include "Plant.h"
#include "Flower.h"

#include "Bouquet.h"
#include "Florist.h"

// Константа для пароля адміністратора
const std::string ADMIN_PASSWORD = "admin";

// Функція для очищення консолі (більш портативний спосіб)
void clearScreen() {
    for (int i = 0; i < 50; ++i) {
        std::cout << std::endl;
    }
}

// Функція для отримання рядка введення від користувача
std::string getUserInput() { // Видалено параметр 'prompt'
    std::string input;
    std::getline(std::cin, input);
    return input;
}

// Функція для отримання цілого числа від користувача з перевіркою на коректність
int getIntegerInput() { // Видалено параметр 'prompt'
    int input;
    while (true) {
        std::cin >> input;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number." << std::endl;
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
    }
    return input;
}

// Функція для отримання числа з плаваючою комою від користувача з перевіркою на коректність
double getDoubleInput() { // Видалено параметр 'prompt'
    double input;
    while (true) {
        std::cin >> input;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number." << std::endl;
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
    }
    return input;
}

// Збереження даних про квіти у файл
void saveFlowersToFile(const std::vector<Flower>& flowers, const std::string& filename = "data/flowers.txt") {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (const auto& flower : flowers) {
            file << flower.getName() << "," << flower.getColor() << ","
                 << std::fixed << std::setprecision(2) << flower.getPrice() << ","
                 << flower.getShelfLifeDays() << std::endl;
        }
        file.close();
        std::cout << "Flowers data saved to " << filename << std::endl;
    } else {
        throw std::runtime_error("Error: Unable to open file '" + filename + "' for saving flowers data.");
    }
}

// Завантаження даних про квіти з файлу
std::vector<Flower> loadFlowersFromFile(const std::string& filename = "data/flowers.txt") {
    std::vector<Flower> flowers;
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::stringstream ss(line);
            std::string name, color, priceStr, shelfLifeDaysStr;
            std::getline(ss, name, ',');
            std::getline(ss, color, ',');
            std::getline(ss, priceStr, ',');
            std::getline(ss, shelfLifeDaysStr, ',');

            try {
                double price = std::stod(priceStr);
                int shelfLifeDays = std::stoi(shelfLifeDaysStr);
                flowers.emplace_back(name, color, price, shelfLifeDays);
            } catch (const std::invalid_argument& e) {
                std::cerr << "Error: Invalid numeric data in file '" << filename << "'. Skipping line: '" << line << "' (" << e.what() << ")" << std::endl;
                continue;
            } catch (const std::out_of_range& e) {
                 std::cerr << "Error: Numeric value out of range in file '" << filename << "'. Skipping line: '" << line << "' (" << e.what() << ")" << std::endl;
                 continue;
            }
        }
        file.close();
        std::cout << "Flowers data loaded from " << filename << std::endl;
    } else {
        std::cerr << "Warning: Unable to open file '" << filename << "' for loading flowers data. Starting with no pre-existing flower data." << std::endl;
    }
    return flowers;
}

// Збереження історії покупок у файл
void savePurchaseHistory(const std::vector<std::string>& history, const std::string& filename = "data/purchase_history.txt") {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (const auto& record : history) {
            file << record << std::endl;
        }
        file.close();
        std::cout << "Purchase history saved to " << filename << std::endl;
    } else {
        throw std::runtime_error("Error: Unable to open file '" + filename + "' for saving purchase history.");
    }
}

// Завантаження історії покупок з файлу
std::vector<std::string> loadPurchaseHistory(const std::string& filename = "data/purchase_history.txt") {
    std::vector<std::string> history;
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            history.push_back(line);
        }
        file.close();
        std::cout << "Purchase history loaded from " << filename << std::endl;
    } else {
        std::cerr << "Warning: Unable to open file '" << filename << "' for loading purchase history. Starting with empty history." << std::endl;
    }
    return history;
}

int main() {
    std::vector<Flower> flowersInShop; // Квіти, доступні в магазині (зберігаються за значенням)
    std::vector<std::string> purchaseHistory;
    Florist florist("Alice");

    try {
        flowersInShop = loadFlowersFromFile();
        purchaseHistory = loadPurchaseHistory();
    } catch (const std::exception& e) {
        std::cerr << "An error occurred during initial data load: " << e.what() << std::endl;
    }

    std::string userType;
    std::string password;

    while (true) {
        clearScreen();
        std::cout << "Welcome to the Flower Shop" << std::endl;
        std::cout << "Are you an administrator or a regular user? (admin/user/exit): ";
        std::getline(std::cin, userType);

        if (userType == "admin") {
            std::cout << "Enter the administrator password: ";
            std::getline(std::cin, password);
            if (password == ADMIN_PASSWORD) {
                std::cout << "Logged in as administrator" << std::endl;
                break;
            } else {
                std::cout << "Incorrect password. Press Enter to try again." << std::endl;
                std::cin.get();
            }
        } else if (userType == "user") {
            std::cout << "Logged in as user" << std::endl;
            break;
        } else if (userType == "exit") {
            std::cout << "Exiting program." << std::endl;
            return 0;
        }
        else {
            std::cout << "Invalid user type. Please enter 'admin', 'user', or 'exit'. Press Enter to try again." << std::endl;
            std::cin.get();
        }
    }

    std::vector<Bouquet> currentSessionBouquets;

    while (true) {
        clearScreen();
        if (userType == "admin") {
            std::cout << "\n--- Administrator Menu ---" << std::endl;
            std::cout << "1. Add New Flower to Shop" << std::endl;
            std::cout << "2. Display All Available Flowers" << std::endl;
            std::cout << "3. Create a Bouquet" << std::endl;
            std::cout << "4. View Bouquets Created This Session" << std::endl;
            std::cout << "5. Display Full Purchase History" << std::endl;
            std::cout << "6. Save All Data (Flowers & History) to File" << std::endl;
            std::cout << "7. Exit Application" << std::endl;
            std::cout << "Enter your choice: ";
        } else { // Regular user
            std::cout << "\n--- User Menu ---" << std::endl;
            std::cout << "1. Display All Available Flowers" << std::endl;
            std::cout << "2. Create a Bouquet" << std::endl;
            std::cout << "3. View Your Bouquets Created This Session" << std::endl;
            std::cout << "4. Display Your Purchase History" << std::endl;
            std::cout << "5. Exit Application" << std::endl;
            std::cout << "Enter your choice: ";
        }

        int choice = getIntegerInput(); // Отримання вибору користувача

        try {
            if (userType == "admin") {
                switch (choice) {
                    case 1: { // Додати нову квітку
                        std::cout << "Enter flower name: "; // Підказка виводиться тут
                        std::string name = getUserInput();
                        std::cout << "Enter flower color: ";
                        std::string color = getUserInput();
                        std::cout << "Enter flower price (UAH): ";
                        double price = getDoubleInput();
                        std::cout << "Enter flower shelf life (days): ";
                        int shelfLifeDays = getIntegerInput();
                        flowersInShop.emplace_back(name, color, price, shelfLifeDays);
                        std::cout << "Flower '" << name << "' added successfully." << std::endl;
                        break;
                    }
                    case 2: {
                        std::cout << "\n--- Currently Available Flowers ---\n";
                        if (flowersInShop.empty()) {
                            std::cout << "No flowers available in the shop. Admin, please add some." << std::endl;
                        } else {
                            for (size_t i = 0; i < flowersInShop.size(); ++i) {
                                std::cout << i + 1 << ". ";
                                flowersInShop[i].displayInfo();
                                std::cout << std::endl;
                            }
                        }
                        break;
                    }
                    case 3: {
                        if (flowersInShop.empty()) {
                            std::cout << "Cannot create bouquet: No flowers available to choose from. Admin, please add some first." << std::endl;
                            break;
                        }
                        std::cout << "Enter a name for the new bouquet: "; // Підказка виводиться тут
                        std::string bouquetName = getUserInput();
                        std::vector<Flower*> flowersToCreateBouquet;
                        std::cout << "Select flowers to add to the bouquet (enter 0 to finish selection):\n";
                        while (true) {
                            for (size_t i = 0; i < flowersInShop.size(); ++i) {
                                std::cout << i + 1 << ". ";
                                flowersInShop[i].displayInfo();
                                std::cout << std::endl;
                            }
                            std::cout << "Enter the number of the flower to add to the bouquet (or 0 to finish): ";
                            int flowerNumber = getIntegerInput();
                            if (flowerNumber == 0) {
                                break;
                            }
                            if (flowerNumber > 0 && flowerNumber <= flowersInShop.size()) {
                                flowersToCreateBouquet.push_back(&flowersInShop[flowerNumber - 1]);
                                std::cout << "Flower added to bouquet selection." << std::endl;
                            } else {
                                std::cout << "Invalid flower number. Please choose from the list or enter 0." << std::endl;
                            }
                        }
                        if (flowersToCreateBouquet.empty()) {
                            std::cout << "No flowers were selected for the bouquet. Bouquet not created." << std::endl;
                            break;
                        }
                        Bouquet newBouquet = florist.createBouquet(bouquetName, flowersToCreateBouquet);
                        currentSessionBouquets.push_back(newBouquet);

                        std::string record = "Bouquet created: '" + newBouquet.getName() + "' by " + florist.getName() + " for " + std::to_string(newBouquet.getTotalPrice()) + " UAH.";
                        purchaseHistory.push_back(record);
                        std::cout << "Bouquet '" << newBouquet.getName() << "' created and recorded in history." << std::endl;
                        break;
                    }
                    case 4: {
                        std::cout << "\n--- Bouquets Created During This Session ---\n";
                        if (currentSessionBouquets.empty()) {
                            std::cout << "No bouquets have been created in this session yet." << std::endl;
                        } else {
                            for (const auto& b : currentSessionBouquets) {
                                b.displayBouquet();
                                std::cout << "  Total price: " << std::fixed << std::setprecision(2) << b.getTotalPrice() << " UAH" << std::endl;
                                std::cout << "-----------------------------------\n";
                            }
                        }
                        break;
                    }
                    case 5: {
                        std::cout << "\n--- Full Purchase History ---\n";
                        if (purchaseHistory.empty()) {
                            std::cout << "No purchase history available yet." << std::endl;
                        } else {
                            for (const auto& record : purchaseHistory) {
                                std::cout << record << std::endl;
                            }
                        }
                        break;
                    }
                    case 6: {
                        saveFlowersToFile(flowersInShop);
                        savePurchaseHistory(purchaseHistory);
                        std::cout << "All current data saved successfully." << std::endl;
                        break;
                    }
                    case 7: {
                        std::cout << "Exiting application. Saving all data before closing..." << std::endl;
                        saveFlowersToFile(flowersInShop);
                        savePurchaseHistory(purchaseHistory);
                        return 0;
                    }
                    default:
                        std::cout << "Invalid choice for Administrator menu. Please try again." << std::endl;
                        break;
                }
            } else { // Regular user
                switch (choice) {
                    case 1: {
                        std::cout << "\n--- Currently Available Flowers ---\n";
                        if (flowersInShop.empty()) {
                            std::cout << "No flowers available at the moment. Please check back later." << std::endl;
                        } else {
                            for (size_t i = 0; i < flowersInShop.size(); ++i) {
                                std::cout << i + 1 << ". ";
                                flowersInShop[i].displayInfo();
                                std::cout << std::endl;
                            }
                        }
                        break;
                    }
                    case 2: {
                        if (flowersInShop.empty()) {
                            std::cout << "Cannot create bouquet: No flowers available at the moment." << std::endl;
                            break;
                        }
                        std::cout << "Enter a name for your new bouquet: "; // Підказка виводиться тут
                        std::string bouquetName = getUserInput();
                        std::vector<Flower*> flowersToCreateBouquet;
                        std::cout << "Select flowers to add to your bouquet (enter 0 to finish selection):\n";
                        while (true) {
                            for (size_t i = 0; i < flowersInShop.size(); ++i) {
                                std::cout << i + 1 << ". ";
                                flowersInShop[i].displayInfo();
                                std::cout << std::endl;
                            }
                            int flowerNumber = getIntegerInput();
                            if (flowerNumber == 0) {
                                break;
                            }
                            if (flowerNumber > 0 && flowerNumber <= flowersInShop.size()) {
                                flowersToCreateBouquet.push_back(&flowersInShop[flowerNumber - 1]);
                                std::cout << "Flower added to your bouquet selection." << std::endl;
                            } else {
                                std::cout << "Invalid flower number. Please choose from the list or enter 0." << std::endl;
                            }
                        }
                        if (flowersToCreateBouquet.empty()) {
                            std::cout << "No flowers were selected for the bouquet. Bouquet not created." << std::endl;
                            break;
                        }
                        Bouquet newBouquet = florist.createBouquet(bouquetName, flowersToCreateBouquet);
                        currentSessionBouquets.push_back(newBouquet);

                        std::string record = "Bouquet created: '" + newBouquet.getName() + "' (User Purchase) for " + std::to_string(newBouquet.getTotalPrice()) + " UAH.";
                        purchaseHistory.push_back(record);
                        std::cout << "Bouquet '" << newBouquet.getName() << "' created and recorded in your purchase history." << std::endl;
                        break;
                    }
                    case 3: { // Переглянути букети, створені в поточній сесії користувача
                        std::cout << "\n--- Your Bouquets Created This Session ---\n";
                        if (currentSessionBouquets.empty()) {
                            std::cout << "You haven't created any bouquets in this session yet." << std::endl;
                        } else {
                            for (const auto& b : currentSessionBouquets) {
                                b.displayBouquet();
                                std::cout << "  Total price: " << std::fixed << std::setprecision(2) << b.getTotalPrice() << " UAH" << std::endl;
                                std::cout << "-----------------------------------\n";
                            }
                        }
                        break;
                    }
                    case 4: { // Відобразити історію покупок користувача
                        std::cout << "\n--- Your Purchase History ---\n";
                        if (purchaseHistory.empty()) {
                            std::cout << "No purchase history available yet." << std::endl;
                        } else {
                             for (const auto& record : purchaseHistory) {
                                std::cout << record << std::endl;
                            }
                        }
                        break;
                    }
                    case 5: {
                        std::cout << "Exiting application. Goodbye!" << std::endl;
                        return 0;
                    }
                    default:
                        std::cout << "Invalid choice for User menu. Please try again." << std::endl;
                        break;
                }
            }
        } catch (const std::exception& e) {
            std::cerr << "An unexpected error occurred: " << e.what() << std::endl;
        }
        std::cout << "\nPress Enter to continue...";
        std::cin.get();
    }

    return 0;
}
