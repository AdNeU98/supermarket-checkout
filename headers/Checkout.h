#ifndef CHECKOUT_H
#define CHECKOUT_H

#include <iostream>
#include <unordered_set>
#include "Item.h"
#include "IDiscountStrategy.h"

using namespace std;

class Checkout {
private:
    static Checkout* instance;
    vector<Item> storeItems;
    vector<unique_ptr<IDiscountStrategy>> strategies;
    double totalCostAfterDiscount;
    double totalCostBeforeDiscount;
    double totalDiscount;
    unordered_set<string> discountedCategories;
    Checkout(): totalCostAfterDiscount(0.0), totalCostBeforeDiscount(0.0), totalDiscount(0.0) {}
    bool faultInput = false;
public:
    /* starts the checkout process and acts as a controller */
    static void initialiseCheckout();

    /* getInstance is required for using singleton pattern & checkout having only 1 instance */
    static Checkout* getInstance();

    /* method to retrieve item data from data/cart_items.txt in a CSV format */
    void populateItems();

    /* method to display all items for checkout process */
    void displayItems();

    /* method to retrieve discount categories from data/discount_categories.txt and store in memory */
    void populateDiscountCategories();

    /* method to calculate total price of all items in checkout considering no discounts */
    void calculateTotalPriceBeforeDiscount();

    /* method to calculate discount for every strategy - displaying strategy pattern */
    void calculateDiscount();

    /* initiates the billing process and calculates the bill after considering discount strategies */
    void calculateBill();

    /* prints all the information about billing */
    void publishReceipt() const;

    double getTotalCostAfterDiscount() const {
        return totalCostAfterDiscount;
    }

    double getTotalCostBeforeDiscount() const {
        return totalCostBeforeDiscount;
    }

    double getTotalDiscount() const {
        return totalDiscount;
    }

    /* method to push various discount strategies/ */
    void pushDiscountStrategies();

    /* method required to check if data exists in data/ */
    bool checkIfDataExists();

};

#endif // CHECKOUT_H
