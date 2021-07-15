#include "portfolio.h"

using namespace std;
using namespace boost::gregorian;

const date Portfolio::FIXED_PURCHASE_DATE(date(2021, Jan, 1));

Portfolio::Portfolio()
{}

bool Portfolio::IsEmpty() const 
{
    return 0 == m_holdings.size();
}

void Portfolio::Purchase(const std::string &symbol, unsigned int shareCount,
     const boost::gregorian::date& transactionDate)
{
    if(0 == shareCount) throw InvalidPurchaseException();
    m_holdings[symbol] = shareCount + ShareCount(symbol);
    m_purchases.emplace_back(PurchaseRecord(shareCount, transactionDate));
}

void Portfolio::Sell(const std::string &symbol, unsigned int shareCount)
{
    if(shareCount > ShareCount(symbol)) throw InvalidSellException();
    m_holdings[symbol] = ShareCount(symbol) - shareCount;
}

unsigned int Portfolio::ShareCount(const string& symbol) const
{
    auto it = m_holdings.find(symbol);
    if(it == m_holdings.end()) return 0;
    return it->second;
}

std::vector<PurchaseRecord> Portfolio::Purchases(const std::string& symbol) const
{
    return m_purchases;
}


