//
// Created by Anirban Dutta on 12/06/24.
//
#include "iostream"
#include "IDiscountStrategy.h"
using namespace std;

#ifndef CATAPULT_STRATEGYB3CF_H
#define CATAPULT_STRATEGYB3CF_H

class StartegyB3CF : public IDiscountStrategy{
public:
    /* method to implement buy 3 in a set and get cheap free strategy */
    double applyDiscountStrategy(vector<Item>& storedItems, unordered_set<string>& discountedCategories) override;
    ~StartegyB3CF() override = default;
};

#endif //CATAPULT_STRATEGYB3CF_H