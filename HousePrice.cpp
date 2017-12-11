// File: HousePrice
// Created by Hugo Valle on 11/22/2017.
// Copyright (c) 2017 WSU
//

#include "HousePrice.h"

/*!
 * Default constructor
 */
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
/*!
 * Constructor to build an instance of HousePrice with given parameters
 * @param id
 * @param number
 * @param street
 * @param city
 * @param state
 * @param postalCode
 * @param price
 */
HousePrice::HousePrice(int id, int number, const string &street, const string &city, const string &state,
                       int postalCode, double price)
{
    this -> id = id;
    this -> number = number;
    this -> street = street;
    this -> city = city;
    this -> state = state;
    this -> postalCode = postalCode;
    this -> price = price;
}
/*!
 * Get the price of the house
 * @return price
 */
double HousePrice::getPrice() const
{
    return price;
}
/*!
 * Get the house state
 * @return state
 */
const string &HousePrice::getState() const
{
    return state;
}
/*!
 * Operator overload to present output
 * @param os
 * @param price
 * @return
 */
ostream &operator<<(ostream &os, const HousePrice &price)
{
    os << "\nid: " << price.id << " number: " << price.number << " postalCode: " << price.postalCode << " street: " << price.street <<
    " city: " << price.city << " state: " << price.state << " price: " << price.price;
    return os;
}

