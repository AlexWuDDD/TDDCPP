#ifndef HOLDING_H
#define HOLDING_H

#include "purchaseRecord.h"
#include <numeric>

class Holding
{
public:
    void Add(PurchaseRecord& record)
    {
        m_records.emplace_back(record);
    }

    std::vector<PurchaseRecord> Purchases()
    {
        return m_records;
    }

    unsigned int ShareCount() const
    {
        return std::accumulate(m_records.begin(), m_records.end(), 0,  [](int total, PurchaseRecord record){
            return total + record.ShareCount;
        });
    }

private:
    std::vector<PurchaseRecord> m_records;
};




#endif