Supermarket Checkout
=====================

Description
------------

The code snippet represents a shopping cart system's backend logic, which manages cart items, applies various discount strategies, and calculates the total bill amount.

Overview
------------

The code consists of the implementation of the `Supermarket Check Out` in C++.

Discount Strategies
--------------------

The code implements the following discount strategies:

*   **B2G1**: Buy 3 identical items and pay for 2
*   **B3CF**: Buy 3 (in a set of items) and the cheapest is free

Essential Key Points
-------------------------

1.  **Data Input**: The data is read from the files in `data/*.txt` folder.
    *   `cart_items.txt` consists of the item details in format (Item Name, Item Category, Price, Quantity)
    *   `discount_categories.txt` consists of categories in which discount will be applicable. Categories which are not in the file won't be considered for the discount.
2.  **Design Patterns**: Singleton pattern and Strategy design pattern have been employed to solve the problem.
3.  **Discount Application**: Discounts are applied in the following way:
    *   First, `buy 3 identical items and pay for 2` is applied on discounted categories
    *   After, the first discount is processed, then `buy 3 (in a set of items) and the cheapest is free` is applied on remaining items if found in same category.

Example
------------

Considering the following example:

*   Discounted Categories are `fruits`

| Name   | Category | Price | Quantity |
|--------|----------|-------|----------|
| apples | fruits   | 2.5   | 4        |
| grapes | fruits   | 4.5   | 2        |
| lays   | snacks   | 3.99  | 6        |

*   Item discounted : apples | Price = 2.5 | B2G1 (buy 3 identical items and pay for 2)
*   Item discounted : apples | Price = 2.5 | B3CF (buy 3 (in a set of items) and the cheapest is free)

*   Total Cost Before Discount = 42.94
*   Total Discount = 5
*   Total Cost After Discount = 37.94

    *   Out of 4 apples, when 3 apples are processed, 1 is free.
    *   The remaining 1 apple will be processed with grapes, as it's set of 3 in fruits category and the cheapest among all will be free, i.e apples
    *   The snacks category is not a part of discounted category so user will be billed for full price

Instructions to Run the Code
--------------------------------

1.  `Driver.cpp` consists the `int main()` and starts the execution of the code.
