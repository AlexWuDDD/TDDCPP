#ifndef PORTFOLIO_H
#define PORTFOLIO_H

#include <string>
#include <exception>
#include <unordered_map>
#include <vector>
#include "boost/date_time.hpp"

class InvalidPurchaseException : public std::exception
{};

class InvalidSellException : public std::exception
{};

struct PurchaseRecord
{
    PurchaseRecord(unsigned int shareCount, const boost::gregorian::date& date)
        : ShareCount(shareCount), Date(date)
    { }

    unsigned int ShareCount;
    boost::gregorian::date Date;
    
};

class Portfolio 
{
public:
    static const boost::gregorian::date FIXED_PURCHASE_DATE;
    Portfolio();
    bool IsEmpty() const;
    void Purchase(const std::string& symbol, unsigned int shareCount, 
        const boost::gregorian::date& transactionDate=FIXED_PURCHASE_DATE);
    void Sell(const std::string& symbol, unsigned int shareCount);
    unsigned int ShareCount(const std::string& symbol) const;
    std::vector<PurchaseRecord> Purchases(const std::string& symbol) const;
private:
    std::unordered_map<std::string, unsigned int> m_holdings;
    std::vector<PurchaseRecord> m_purchases;
};



#endif