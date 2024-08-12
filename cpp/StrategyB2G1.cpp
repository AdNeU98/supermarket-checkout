//
// Created by Anirban Dutta on 12/06/24.
//
#include <unordered_set>
#include "StrategyB2G1.h"
#include "Common.h"
using namespace std;

double StrategyB2G1::applyDiscountStrategy(vector<Item> &storedItems, unordered_set<string>& discountedCategories) {
    double discount = 0;
    for (auto & storedItem : storedItems) {
        if (discountedCategories.find(storedItem.getCategory()) != discountedCategories.end()) {
            int setOfItems = storedItem.getQuantity()/COUNT_OF_ITEMS_IN_SET;
            if (setOfItems != 0) {
                double discountForCurItem = storedItem.getPrice() * setOfItems;
                discount += discountForCurItem;
                cout<<"Item discounted : "<<storedItem.getName()<<" | Price = "<<discountForCurItem<<" | "<<"B2G1"<<endl;
                int countOfItemsLeftAfterDiscount  = storedItem.getQuantity() - setOfItems * COUNT_OF_ITEMS_IN_SET;
                storedItem.setQuantity(countOfItemsLeftAfterDiscount);
            }
        }
    }
    return discount;
}
