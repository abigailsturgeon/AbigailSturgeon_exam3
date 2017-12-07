// File: HousePrice
// Created by Hugo Valle on 11/22/2017.
// Copyright (c) 2017 WSU
//

#include "HousePrice.h"


HousePrice::HousePrice()
{
    id = 0;
    number = 0;
    street = " ";
    city = " ";
    state = " ";
    postalCode = 0;
    price = 0;
}

HousePrice::HousePrice(int id, int number, const string &street, const string &city, const string &state,
                       int postalCode, double price)
{

}
