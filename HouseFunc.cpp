// File: HouseFunc
// Created by Hugo Valle on 11/22/2017.
// Copyright (c) 2017 WSU
//

#include <iostream>
#include <vector>
#include <map>
#include "HouseFunc.h"
#include "HousePrice.h"
#include "csv.h" // library to read csv files
#include <algorithm>

using namespace std;

/*!
 * Read CSV Mock Data. Parses each record in the file to
 * an object of HousePrice house. Then, populate a vector
 * of HousePrice objects with all the records.
 * It uses special library to parse CSV file "csv.h"
 * @param fileIn File name <string>
 * @param hp Reference to Vector of HousePrice Objects
 */
void readCSV(const string fileIn,vector<HousePrice>& hp)
{
    io::CSVReader<7> in(fileIn);
    in.read_header(io::ignore_extra_column, "id", "number", "street", "city", "state", "postalCode", "price");
    int id, number;
    string street, city, state;
    int postalCode;
    double price;
    while(in.read_row(id, number, street, city, state, postalCode, price))
    {
        HousePrice hp1(id, number, street, city, state, postalCode, price);
        hp.push_back(hp1);
    }
    for(auto i = hp.begin(); i != hp.end(); ++i)
    {
        cout << *i << ' ' << endl;
    }
}

/*!
 * Sort the Vector of HousePrice Objects by price. Display the most affordable
 * and the most expensive house from the vector.
 * @param hp Reference to vector<HousePrice>
 */
void houseMarketValues(vector<HousePrice> &hp)
{
   sort(hp.begin(), hp.end(), [](const HousePrice& lhs, const HousePrice& rhs)
    {
        return lhs.getPrice() < rhs.getPrice();
    });

    cout << "Most Affordable House: " << hp.front();
    cout << "\nMost Expensive House: " << hp.back();

}


/*!
 * Sort the Vector of HousePrice Objects by state. Display the
 * number of houses per state.
 * It uses a map to count instances per state.
 * @param hp Reference to vector<HousePrice>
 */
void houseMarketPerState(vector<HousePrice> &hp)
{
    int n = 1;
    sort(hp.begin(), hp.end(), [](const HousePrice& lhs, const HousePrice& rhs)
    {
        return lhs.getState() < rhs.getState();
    });

    map<string, int> mState;
    for(auto item:hp)
    {
        mState[item.getState()] = n;
        n++;
    }

    cout << "\n#Homes per State: " << endl;
    int i = 0;
    for(auto item:mState)
    {
        cout << item.first << " " << item.second << '\t';
        i++;
    }
}
