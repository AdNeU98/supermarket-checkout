//
// Created by Anirban Dutta on 12/06/24.
//
#include <unordered_set>
#include <unordered_map>
#include "Item.h"
#include "StrategyB3CF.h"
#include "Common.h"
using namespace std;

double StartegyB3CF::applyDiscountStrategy(vector<Item> &storedItems, unordered_set<string>& discountedCategories) {
    double discount = 0;
    unordered_map<string, vector<pair<double, Item>>> storeItemsByCategory;

    for (Item& eachItem : storedItems) {
        if (eachItem.getQuantity() != 0 &&
            discountedCategories.find(eachItem.getCategory()) != discountedCategories.end()) {
            string itemCategory = eachItem.getCategory();
            double itemPrice = eachItem.getPrice();
            storeItemsByCategory[itemCategory].emplace_back(itemPrice, eachItem);
        }
    }

    for(const auto& [category, items] : storeItemsByCategory){
        vector<pair<double,Item>> categorizedData = items;
        sort(categorizedData.begin(), categorizedData.end(), [](const auto& a, const auto& b) {
            return a.first < b.first;
        });
        int totalQuantityOfCategory = 0;
        for (const pair<double, Item>& eachItem : categorizedData) {
            totalQuantityOfCategory += eachItem.second.getQuantity();
        }

        int totalSets = totalQuantityOfCategory/COUNT_OF_ITEMS_IN_SET;
        int countSets = 0;
        int index = 0;
        if (totalSets >= 1) {
            while (countSets < totalSets) {
                int currentItemQuantity = categorizedData[index].second.getQuantity();
                double currentItemPrice = categorizedData[index].second.getPrice();
                string currentItemName = categorizedData[index].second.getName();

                for (int i = 0; i < currentItemQuantity && countSets < totalSets; ++i) {
                    ++countSets;
                    discount += currentItemPrice;
                    cout << "Item discounted : " << currentItemName
                              << " | Price = " << currentItemPrice << " | B3CF" <<endl;
                }
                if (countSets < totalSets) {
                    ++index;
                }
            }
        }
    }
    cout<<endl;
    return discount;

}