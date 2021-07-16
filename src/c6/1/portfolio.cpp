#include "portfolio.h"

using namespace std;
using namespace boost::gregorian;

const date Portfolio::FIXED_PURCHASE_DATE(date(2021, Jan, 1));

bool Portfolio::IsEmpty() const 
{
    return 0 == m_holdings.size();
}

void Portfolio::Purchase(const std::string &symbol, unsigned int shareCount,
     const boost::gregorian::date& transactionDate)
{
    Transact(symbol, shareCount, transactionDate);
}

void Portfolio::Sell(const std::string &symbol, unsigned int shareCount, 
    const boost::gregorian::date& transactionDate)
{
    if(shareCount > ShareCount(symbol)) throw InsufficientSharesException();
    Transact(symbol, -shareCount, transactionDate);
}

unsigned int Portfolio::ShareCount(const string& symbol) const
{
    return Find<unsigned int>(m_holdings, symbol);
}

std::vector<PurchaseRecord> Portfolio::Purchases(const std::string& symbol) const
{
    return Find<std::vector<PurchaseRecord>>(m_purchasesRecords, symbol);
}


void Portfolio::Transact(const std::string& symbol, int shareChange, 
        const boost::gregorian::date& transactionDate)
{
    ThrowIfShareCountIsZero(shareChange);
    UpdateShareCount(symbol, shareChange);
    AddPurchaseRecord(symbol, shareChange, transactionDate);
}

void Portfolio::ThrowIfShareCountIsZero(int shareChange) const
{
    if(0 == shareChange) throw ShareCountCannotBeZeroException();
}

void Portfolio::UpdateShareCount(const std::string& symbol, int shareChange)
{
    m_holdings[symbol] = ShareCount(symbol) + shareChange;
}

void Portfolio::AddPurchaseRecord(const std::string& symbol, int shareChange, const boost::gregorian::date& date)
{
    if(!ContainsSymbol(symbol)){
        InitializePurchaseRecords(symbol);
    }
    Add(symbol, {shareChange, date});
}

void Portfolio::InitializePurchaseRecords(const string& symbol) {
   m_purchasesRecords[symbol] = vector<PurchaseRecord>();
}
void Portfolio::Add(const string& symbol, PurchaseRecord&& record) {
   m_purchasesRecords[symbol].push_back(record);
}

bool Portfolio::ContainsSymbol(const string& symbol) const {
   return m_purchasesRecords.find(symbol) != m_purchasesRecords.end();
}
