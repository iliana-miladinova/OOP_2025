// task06.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
namespace Constraints {
    constexpr size_t NAME_LEN = 100;
    constexpr size_t DELIVER_LEN = 100;
    constexpr size_t MAX_PRODUCTS = 100;
}

enum class Category {
    ELECTRONICS,
    CLOTHING,
    BOOKS,
    FOOD,
    BEAUTY,
    UNKNOWN
};

struct Product {
    char name[Constraints::NAME_LEN + 1] ;
    int quantity;
    double price;
    Category category;
    char deliver[Constraints::DELIVER_LEN + 1];
};

void readProducts(const char* fileName, Product* products, size_t& count) {
    std::ifstream ifs(fileName, std::ios::binary);
    if (!ifs.is_open()) {
        std::cout << "Cannot open file for reading" << std::endl;
        return;
    }

    ifs.read((char*)&count, sizeof(count));
    ifs.read((char*)products, count * sizeof(Product));
}

Category getCategory(int ind) {
    switch (ind)
    {
    case 0: return Category::ELECTRONICS;
    case 1: return Category::CLOTHING;
    case 2: return Category::BOOKS;
    case 3: return Category::FOOD;
    case 4: return Category::BEAUTY;
    default:
        return Category::UNKNOWN;
    }
}
void readProductFromConsole(Product& p) {
    std::cin >> p.name;
    std::cin >> p.quantity;
    std::cin >> p.price;
    std::cin >> p.deliver;
    int catInd;
    std::cin >> catInd;
    p.category = getCategory(catInd);
}

bool constinsProduct(const Product* products, size_t count, const Product& p) {
    for (size_t i = 0; i < count; i++)
    {
        if (strcmp(products[i].name, p.name) == 0) {
            return true;
        }
    }
    return false;
}

void saveNProducts(const char* filename, int n) {
    std::ifstream ifs(filename, std::ios::binary);
    if (!ifs.is_open()) {
        std::cout << "Cannot open file for reading" << std::endl;
        return;
    }

    Product currProducts[Constraints::MAX_PRODUCTS];
    size_t currCount = 0;

    readProducts(filename, currProducts, currCount);
    ifs.close();

    std::ofstream ofs(filename, std::ios::binary | std::ios::app);
    if (!ofs.is_open()) {
        std::cout << "Cannot open file for writing" << std::endl;
        return;
    }

    for (size_t i = 0; i < n; i++)
    {
        Product p;
        readProductFromConsole(p);
        if (!constinsProduct(currProducts, currCount, p)) {
            ofs.write((const char*)&p, sizeof(p));
        }
    }

    ofs.close();
}

void writeProductsToFileFromTheConsole(const char* fileName, size_t count) {
    std::ofstream ofs(fileName, std::ios::binary);
    if (!ofs.is_open()) {
        std::cout << "Cannot open file for writing" << std::endl;
        return;
    }
    ofs.write((const char*)&count, sizeof(count));

    for (size_t i = 0; i < count; i++)
    {
        Product p;
        readProductFromConsole(p);
        ofs.write((const char*)&p, sizeof(p));
    }
    ofs.close();
}

void writeProducts(std::ofstream& ofs, const Product* pr, size_t count) {
    ofs.write((const char*)&count, sizeof(count));
    ofs.write((const char*)pr, count * sizeof(Product));
}

void changeQuantityInFile(const char* fileName, int newQuantity, const char* productName){
    std::ifstream ifs(fileName, std::ios::binary);
    if (!ifs.is_open()) {
        std::cout << "Cannot open file for reading" << std::endl;
        return;
    }

    Product products[Constraints::MAX_PRODUCTS];
    size_t count = 0;
    readProducts(fileName, products, count);

    ifs.close();

    std::ofstream ofs(fileName, std::ios::binary);
    if (!ofs.is_open()) {
        std::cout << "Cannot open file for writing" << std::endl;
        return;
    }
    for (size_t i = 0; i < count; i++)
    {
        if (strcmp(productName, products[i].name) == 0) {
            products[i].quantity = newQuantity;
            break;
        }
    }
    writeProducts(ofs, products, count);
    ofs.close();
}

const char* getTextFromCategory(Category c) {
    switch (c)
    {
    case Category::ELECTRONICS: return "Electronics";
    case Category::CLOTHING: return "Clothing";
    case Category::BOOKS: return "Books";
    case Category::FOOD: return "Food";
    case Category::BEAUTY: return "Beauty";
    default:
        return "Unknown";
    }
}

void printProduct(const Product& product) {
    std::cout << "Name: " << product.name
        << ", Quantity: " << product.quantity
        << ", Price: " << product.price
        << ", Deliver: " << product.deliver
        << ", Category: " << getTextFromCategory(product.category)
        << std::endl;
}
void printProducts(const char* fileName, Product* products, size_t& count) {
    readProducts(fileName, products, count);
    std::cout << "Products in file:\n";
    for (size_t i = 0; i < count; i++)
    {
        printProduct(products[i]);
    }
}

void printProductByName(const char* fileName, Product* products, size_t& count, const char* productName) {
    readProducts(fileName, products, count);
    for (size_t i = 0; i < count; i++)
    {
        if (strcmp(productName, products[i].name) == 0) {
            printProduct(products[i]);
        }
    }
}

void saveProductsByCategory(const char* input, const char* output, const Category& c) {
    std::ifstream ifs(input, std::ios::binary);
    if (!ifs.is_open()) {
        std::cout << "Cannot open file for reading" << std::endl;
        return;
    }

    Product products[Constraints::MAX_PRODUCTS];
    size_t count = 0;
    readProducts(input, products, count);

    ifs.close();

    std::ofstream ofs(output, std::ios::binary);
    if (!ofs.is_open()) {
        std::cout << "Cannot open file for writing" << std::endl;
        return;
    }

    for (size_t i = 0; i < count; i++)
    {
        if (products[i].category == c) {
            ofs.write((const char*)&products[i], sizeof(Product));
        }
    }
    ofs.close();
}

int main()
{
    const char* fileName = "products.dat";

    // Запис на продукти в бинарния файл
    ///*int n;
    //std::cout << "Enter number of products to add: ";
    //std::cin >> n;
    //writeProductsToFileFromTheConsole(fileName, n);*/

    //saveNProducts(fileName, n);

    // Четене и извеждане на всички продукти от файла
    //changeQuantityInFile(fileName, 18, "Potato");
    Product products[Constraints::MAX_PRODUCTS];
    size_t count = 0;
    printProducts(fileName, products, count);
    printProductByName(fileName, products, count, "Potato");

    saveProductsByCategory("products.dat", "new.dat", Category::FOOD);
    

    //ifs.close();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
