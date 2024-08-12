//
// Created by Anirban Dutta on 12/06/24.
//

#include "string"
using namespace std;
#ifndef CATAPULT_ITEM_H
#define CATAPULT_ITEM_H

class Item {
private:
    string name;
    string category;
    double price;
    int quantity;
public:
    Item(string_view name = "testing", string_view category = "testingCategory", double price = 1, int quantity = 1)
            : name(name), category(category), price(price), quantity(quantity) {}

    string getName() const {
        return name;
    }

    void setName(const string& nameOfItem) {
       this->name = nameOfItem;
    }

    string getCategory() const {
        return category;
    }

    void setCategory(const string& categoryOfItem) {
        this->category = categoryOfItem;
    }

    double getPrice() const {
        return price;
    }

    void setPrice(double priceOfItem) {
        this->price = priceOfItem;
    }

    int getQuantity() const {
        return quantity;
    }

    void setQuantity(int quantityOfItem) {
        this->quantity = quantityOfItem;
    }
};

#endif //CATAPULT_ITEM_H