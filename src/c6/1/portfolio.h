#ifndef PORTFOLIO_H
#define PORTFOLIO_H

#include <string>
#include <exception>
#include <unordered_map>
#include <vector>
#include "holding.h"

class ShareCountCannotBeZeroException : public std::exception
{};

class InsufficientSharesException : public std::exception
{};


class Portfolio 
{
public:
    static const boost::gregorian::date FIXED_PURCHASE_DATE;

    bool IsEmpty() const;
    void Purchase(const std::string& symbol, unsigned int shareCount, 
        const boost::gregorian::date& transactionDate=FIXED_PURCHASE_DATE);
    void Sell(const std::string& symbol, unsigned int shareCount, 
        const boost::gregorian::date& transactionDate=FIXED_PURCHASE_DATE);


    unsigned int ShareCount(const std::string& symbol) const;
    std::vector<PurchaseRecord> Purchases(const std::string& symbol) const;

private:
    void Transact(const std::string& symbol, int shareChange, 
        const boost::gregorian::date& transactionDate);
    void ThrowIfShareCountIsZero(int shareChange) const ;
    void AddPurchaseRecord(const std::string& symbol, int shareChange, const boost::gregorian::date& date);

    bool ContainsSymbol(const std::string& symbol) const;
    void InitializePurchaseRecords(const std::string& symbol);
    void Add(const std::string& symbol, PurchaseRecord&& record);

    template<typename T>
    T Find(std::unordered_map<std::string, T> map, const std::string& key) const
    {
        auto it = map.find(key);
        return it == map.end() ? T{} : it->second;
    }    

private:
    // std::unordered_map<std::string, unsigned int> m_holdings;
    // std::unordered_map<std::string, std::vector<PurchaseRecord>> m_purchasesRecords;
    // std::unordered_map<std::string, std::vector<PurchaseRecord>> m_purchasesRecords;
    std::unordered_map<std::string, Holding> m_holdings;
};



#endif