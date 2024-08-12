//
// Created by Anirban Dutta on 12/06/24.
//
#include "iostream"
#include <unordered_set>
#include "IDiscountStrategy.h"
using namespace std;

#ifndef CATAPULT_STRATEGYB2G1_H
#define CATAPULT_STRATEGYB2G1_H

class StrategyB2G1 : public IDiscountStrategy{
public:
    /* method to implement buy 2, get 1 strategy */
     double applyDiscountStrategy(vector<Item>& storedItems, unordered_set<string>& discountedCategories) override;
    ~StrategyB2G1() override = default;
};

#endif //CATAPULT_STRATEGYB2G1_H
