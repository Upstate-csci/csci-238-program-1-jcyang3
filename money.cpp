/********
 Author: Joe Yang
 Program: Money class - program assignment #1
 Due Date: Feb. 3, 2020
 Purpose: Converts money into different ways including change, float, change-float, and change-change.
 ********/
#include "money.h"
using namespace std;

                        // convert current currency values to a string
string Money::toString()
{
    stringstream result;

    result << hundreds << " hundreds " << tens << " tens " << fives << " fives " << ones << "ones " << quarters  << " quarters " <<  dimes  << " dimes " <<  nickels  << " nickels " <<  cents  << " cents ";
}
                        // format amount as a local currency and return
string Money::toCurrency(double amount)
{
    stringstream ss;

    ss.imbue(locale(""));
    // ss << showbase <<put_money(amount*100);
    ss << "$" << left << setfill('0') << setw(4) << amount;
    return ss.str();
}

                        //  Convert currency to float.
string Money::processChange()
{
                        //  read currency values from stdin and compute value
    cin >> hundreds >> tens >> fives >> ones >> quarters >> dimes >> nickels >> cents;
                        // add the total amount of money
    total = hundreds * 100 + tens * 10 + fives * 5 + ones * 1 + quarters * 0.25 + dimes * 0.10 + nickels * 0.05 + cents * .01;
                        // return results
    return to_string(hundreds) + " hundreds " + to_string(tens) + " tens " + to_string(fives) + " fives " + to_string(ones) + " ones " + to_string(quarters) + " quarters " + to_string(dimes) + " dimes " + to_string(nickels) + " nickels " + to_string(cents) + " cents = " +  toCurrency(total);
}


                        // take in float format, output change format
string Money::processFloat()
{
                        // read from stdin and process float command
    float input;
    cin >> input;
    int inputInt = (int) (input*100);
                        // std::strings found from en.cppreference.com/w/cpp/string/basic_string
    std::ostringstream decimalPlaces;
    decimalPlaces << fixed << std::setprecision(2);
    decimalPlaces << input;
    std::string strObj = decimalPlaces.str();
                        // math to compute the float of each currency item
    hundreds = inputInt / 10000;
    tens = (inputInt % 10000) / 1000;
    fives = ((inputInt % 10000) % 1000) / 500;
    ones = (((inputInt % 10000) % 1000) % 500) / 100;
    quarters = ((((inputInt % 10000) % 1000) % 500) % 100) / 25;
    dimes = (((((inputInt % 10000) % 1000) % 500) % 100) % 25) / 10;
    nickels = ((((((inputInt % 10000) % 1000) % 500) % 100) % 25) % 10) / 5;
    cents = (((((((inputInt % 10000) % 1000) % 500) % 100) % 25) % 10) % 5);

                        // return result

    return toCurrency(input) + " = " + to_string(hundreds) + " hundreds " + to_string(tens) + " tens "  + to_string(fives) + " fives " +  to_string(ones) + " ones " + to_string(quarters) + " quarters " + to_string(dimes) + " dimes " + to_string(nickels) + " nickels " + to_string(cents) + " pennies ";

}

string Money::processChangeFloat()
{
                            // read from stdin and process change-float command
    double cPayment, tPayment, answer;
                            // read float of customer payment
    cin >> cPayment;
                            // read float of transaction cost
    cin >> tPayment;
                            // calculate difference and compute change values
    answer = cPayment - tPayment;

    int intAnswer = (int) (answer * 100);


    std::ostringstream decimalPlaces;
    decimalPlaces << fixed << std::setprecision(2);
    decimalPlaces << answer;
    std::string strObj = decimalPlaces.str();

    hundreds = intAnswer / 10000;
    tens = (intAnswer % 10000) / 1000;
    fives = ((intAnswer % 10000) % 1000) / 500;
    ones = (((intAnswer % 10000) % 1000) % 500) / 100;
    quarters = ((((intAnswer % 10000) % 1000) % 500) % 100) / 25;
    dimes = (((((intAnswer % 10000) % 1000) % 500) % 100) % 25) / 10;
    nickels = ((((((intAnswer % 10000) % 1000) % 500) % 100) % 25) % 10) / 5;
    cents = (((((((intAnswer % 10000) % 1000) % 500) % 100) % 25) % 10) % 5) ;


                            // return the results

    return "change back on $" + to_string(cPayment) + " for purchase of " + toCurrency(tPayment) + " is " +toCurrency(answer) + " which is " + to_string(hundreds) + " hundreds " + to_string(tens) + " tens "  + to_string(fives) + " fives " +  to_string(ones) + " ones " + to_string(quarters) + " quarters " + to_string(dimes) + " dimes " + to_string(nickels) + " nickels " + to_string(cents) + " pennies ";
}

string Money::processChangeChange() {
                            // read from stdin and process change-change command
                            // read change of customer payment
    double purchasePrice, changeTotal;
    cin >> hundreds >> tens >> fives >> ones >> quarters >> dimes >> nickels;
    cin >> purchasePrice;
                            //add the total amount of money
    total = (hundreds * 100) + (tens * 10) + (fives * 5) + (ones * 1) + (quarters * 0.25) + (dimes * 0.10) +
            (nickels * 0.05);

                             // calculate difference and compute change values

    changeTotal = total - purchasePrice;

    double finalAnswer = changeTotal;
    int answerToInt = (int) (changeTotal * 100);

    int hundreds1, tens1, fives1, ones1, quarters1, dimes1, nickels1, cents1;

    std::ostringstream decimalPlaces;
    decimalPlaces << fixed << std::setprecision(2);
    decimalPlaces << answerToInt;
    std::string strObj = decimalPlaces.str();

    hundreds1 = answerToInt / 10000;
    tens1 = (answerToInt % 10000) / 1000;
    fives1 = ((answerToInt % 10000) % 1000) / 500;
    ones1 = (((answerToInt % 10000) % 1000) % 500) / 100;
    quarters1 = ((((answerToInt % 10000) % 1000) % 500) % 100) / 25;
    dimes1 = (((((answerToInt % 10000) % 1000) % 500) % 100) % 25) / 10;
    nickels1 = ((((((answerToInt % 10000) % 1000) % 500) % 100) % 25) % 10) / 5;
    cents1 = (((((((answerToInt % 10000) % 1000) % 500) % 100) % 25) % 10) % 5);

                             // output the results

    return "change back on " + to_string(hundreds) + " hundreds " + to_string(tens) + " tens " + to_string(fives) +
           " fives " + to_string(ones) + " ones " + to_string(quarters) + " quarters " + to_string(dimes) + " dimes " +
           to_string(nickels) + " nickels" + " for purchase of " + toCurrency(purchasePrice) + " is " +
           toCurrency(finalAnswer) + " which is " + to_string(hundreds1) + " hundreds " + to_string(tens1) + " tens " +
           to_string(fives1) + " fives " + to_string(ones1) + " ones " + to_string(quarters1) + " quarters " +
           to_string(dimes1) + " dimes " + to_string(nickels1) + " nickels " + to_string(cents1) + " cents ";
}
