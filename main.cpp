#include <iostream>
#include <chrono>
// Authur: Aman Arabzadeh

void menu() {
    std::cout << "The is a chunck value alllocator.\n";
    std::cout << "Enter 1 to allocate for 1 GiB:\n";
    std::cout << "Enter 2 to allocate in KiB:\n";
    std::cout << "=====================================\n";
    std::cout << "Enter your choice: ";
}



void  ByteSize(int64_t& size, int choice) {
    int64_t total = 0;
    auto GBCounter = 0;
    auto KBCounter = 0;
    int x = 0;
    int64_t totalInSize = size / sizeof(int64_t);
    int64_t MiB = (1024 * 1024) * 3;
    try {
        do {
            // GB
            // GB / 8;
            //	std::cout << totalInSize * sizeof(int64_t) << std::endl;
            new int64_t[totalInSize];
            if (choice == 1) {

                total += totalInSize * sizeof(int64_t);
                GBCounter += 1;
                std::cout << "GB:  " << GBCounter << std::endl;
                std::cout << "Total: " << total << std::endl;
            }
            else if (choice == 2) {
                total += totalInSize * sizeof(int64_t);
                //std::cout << total << std::endl;
                KBCounter += 1;
                if (total % MiB == 0) {
                    std::cout << "KB:  " << KBCounter << std::endl;
                    std::cout << "Total in bytes: " << total << std::endl;
                }
            }
            else if (choice != 1 && choice != 2) {
                std::cout << "Total Byte allocated are: " << total << std::endl;
            }
        } while (true);
    }
    catch (const std::exception& e) {
        std::cerr << e.what();
    }
}


/*
nom att köra applikationer med virtuellt minne, vilket innebär att en del av minnesinnehållet som har använts minst nyligen kopieras ut till hårddisken så att minnet kan återanvänds till något annat. När det behövs igen måste det bytas tillbaka och något annat vräkas i dess ställe. När situationen blir svår sker så mycket utbyte att disken blir 100% upptagen och systemet överlag saktar ner till en genomsökning.
Detta är naturligtvis en dålig situation för användaren. Att lägga till mer minne är en relativt enkel lösning för att lätta på trycket.

*/



int main() {
    int selection = 0;
    menu();
    int64_t GB = (1024 * 1024 * 1024);
    int64_t KB = 1024;
    std::cin >> selection;
    auto start = std::chrono::system_clock::now();
    switch (selection) {
        case 1:
            ByteSize(GB, 1);
            break;
        case 2:
            ByteSize(KB, 2);
            break;
        default:
            std::cout << "Wrong choice! " << std::endl;
            break;
    }
    auto end = std::chrono::system_clock::now();
    auto total = std::chrono::duration_cast<std::chrono::seconds>(end - start);

    std::cout << "Total time is: " << total.count() << std::endl;
    std::cin.get();
    return 0;
}




