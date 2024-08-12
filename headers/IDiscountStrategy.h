//
// Created by Anirban Dutta on 12/06/24.
//

#include "Item.h"
#include <unordered_set>
#ifndef CATAPULT_DISCOUNTSTRATEGY_H
#define CATAPULT_DISCOUNTSTRATEGY_H

class IDiscountStrategy {
public:
    /* pure virtual method where different strategies will be applied by classes that inherit IDiscountStrategy */
    virtual double applyDiscountStrategy(vector<Item>& storedItems, unordered_set<string>& discountedCategories) = 0;
    virtual ~IDiscountStrategy() = default;
};

#endif //CATAPULT_DISCOUNTSTRATEGY_H

