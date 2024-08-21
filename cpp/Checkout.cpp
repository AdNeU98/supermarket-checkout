#include "Checkout.h"
#include "StrategyB2G1.h"
#include "StrategyB3CF.h"
#include "iostream"
#include "fstream"
#include "string"
#include "sstream"
#include "unordered_map"
#include "cctype"
using namespace std;

Checkout* Checkout::instance = nullptr;

Checkout* Checkout::getInstance() {
    if (instance == nullptr) {
        instance = new Checkout();
    }
    return instance;
}

void Checkout::populateItems() {
    ifstream cartItemsFile("../data/cart_items.txt");
    string line;
    unordered_map<string, Item> bindInputs;

    try {
        while (getline(cartItemsFile, line)) {
            transform(line.begin(), line.end(), line.begin(), ::tolower);
            //remove extra spaces at end of line
            line.erase(remove(line.begin(), line.end(), ' '), line.end());
            stringstream eachEntry(line);
            string name, category, priceStr, quantityStr;
            vector<string> tokens;
            string token;

            while (getline(eachEntry, token, ',')) {
                tokens.push_back(token);
            }

            if (tokens.size() != 4) {
                faultInput = true;
                return;
            }

            name = tokens[0];
            category = tokens[1];
            priceStr = tokens[2];
            quantityStr = tokens[3];

            double price = stod(priceStr);
            int quantity = stoi(quantityStr);
            if (quantity <= 0 || price <= 0) {
                faultInput = true;
                return;
            }

            Item obj(name, category, price, quantity);
            if (bindInputs.find(name) == bindInputs.end()) {
                bindInputs[name] = obj;
            } else {
                Item& currObj = bindInputs[name];
                if(currObj.getPrice() != price){
                    faultInput = true;
                    return;
                }
                int prevQuantity = currObj.getQuantity();
                currObj.setQuantity(prevQuantity + quantity);
            }
        }
        for (const pair<string, Item> eachEntry : bindInputs) {
            storeItems.push_back(eachEntry.second);
        }
    } catch (const exception& e) {
        cout << "Incorrect data formats provided by user : " << e.what() << endl;
    }

    cartItemsFile.close();
}


void Checkout::calculateTotalPriceBeforeDiscount() {
    double totalPrice = 0.0;
    for (const Item& storeItem : storeItems) {
        double totalCostOfEachItem = storeItem.getPrice() * storeItem.getQuantity();
        totalPrice += totalCostOfEachItem;
    }
    totalCostBeforeDiscount = totalPrice;
}

void Checkout::displayItems() {
    for (const Item& each: storeItems) {
        cout<<each.getName()<<" | "<<each.getCategory()<<" | "<<each.getPrice()<<" | "<<each.getQuantity()<<endl;
    }
    cout<<endl;
}

void Checkout::calculateDiscount() {
    for (unique_ptr<IDiscountStrategy>& strategyPtr : strategies) {
        totalDiscount += strategyPtr->applyDiscountStrategy(storeItems, discountedCategories);
    }
}

void Checkout::populateDiscountCategories() {
    ifstream discountCategoriesFile("../data/discount_categories.txt");
    string line;
    while (getline(discountCategoriesFile, line)) {
        transform(line.begin(), line.end(), line.begin(), ::tolower);
        if (line == "categories"){
            continue;
        } else {
            discountedCategories.insert(line);
        }
    }
    discountCategoriesFile.close();
}

void Checkout::calculateBill(){
    calculateTotalPriceBeforeDiscount();
    calculateDiscount();
    totalCostAfterDiscount = totalCostBeforeDiscount - totalDiscount;
    publishReceipt();
}

void Checkout::publishReceipt() const{
    cout<<"Total Cost Before Discount = "<<getTotalCostBeforeDiscount()<<endl;
    cout<<"Total Discount = "<<getTotalDiscount()<<endl;
    cout<<"Total Cost After Discount = "<<getTotalCostAfterDiscount()<<endl;
}

bool Checkout::checkIfDataExists() {
    ifstream discountCategoriesFile("../data/discount_categories.txt");
    if (!discountCategoriesFile) {
        return false;
    }
    discountCategoriesFile.close();

    ifstream cartItemsFile("../data/cart_items.txt");
    if (!cartItemsFile) {
        return false;
    }
    cartItemsFile.close();
    return true;
}

void Checkout::pushDiscountStrategies() {
    unique_ptr<StrategyB2G1> strategy1 = std::make_unique<StrategyB2G1>();
    unique_ptr<StartegyB3CF> strategy2 = std::make_unique<StartegyB3CF>();

    strategies.push_back(std::move(strategy1));
    strategies.push_back(std::move(strategy2));
}

 void Checkout::initialiseCheckout() {
    // Lazy singleton implementation
    Checkout* checkout = Checkout::getInstance();
    if (checkout->checkIfDataExists()) {
        checkout->populateDiscountCategories();
        checkout->populateItems();
        if(checkout->faultInput){
            cout<<"Incorrect input by user"<<endl;
            return;
        }
        checkout->displayItems();
        checkout->pushDiscountStrategies();
        checkout->calculateBill();
    } else {
        cout<<"Required files are not provided by user"<<endl;
    }
    checkout = nullptr;
}

