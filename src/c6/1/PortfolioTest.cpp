#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "portfolio.h"

using namespace testing;
using namespace boost::gregorian;

class APortfolio : public Test
{
public:
    static const std::string IBM;
    static const std::string SAMSUNG;
    Portfolio m_portfolio;
    static const date ArbitraryDate;

    void Purchase(
        const std::string& symbol,
        unsigned int shareCount,
        const date& transactionsDate = ArbitraryDate
    )
    {
        m_portfolio.Purchase(symbol, shareCount,  transactionsDate);
    };

    void Sell(
        const std::string& symbol,
        unsigned int shareCount,
        const date& transactionsDate = ArbitraryDate
    )
    {
        m_portfolio.Sell(symbol, shareCount,  transactionsDate);
    };

    void ASSERT_PURCHASE(
        PurchaseRecord& purchase, int shareCount, const date& date
    )
    {
        ASSERT_EQ(shareCount, purchase.ShareCount);
        ASSERT_EQ(date, purchase.Date);
    }
};

const date APortfolio::ArbitraryDate(2021, Jul, 15);
const std::string APortfolio::IBM = "IBM";
const std::string APortfolio::SAMSUNG = "SAMSUNG";

bool operator==(const PurchaseRecord& lhs, const PurchaseRecord& rhs)
{
    return lhs.ShareCount == rhs.ShareCount && lhs.Date == rhs.Date;
}


TEST_F(APortfolio, IsEmptyWhenCreated)
{
    ASSERT_TRUE(m_portfolio.IsEmpty());
}

TEST_F(APortfolio, IsnNOtEmptyAfterPurchase)
{
    Purchase(IBM, 1);
    ASSERT_FALSE(m_portfolio.IsEmpty());
}

TEST_F(APortfolio, AnswerZeroForShareCountOfUnpurchasedSymbol)
{
    ASSERT_THAT(m_portfolio.ShareCount("AAPL"), Eq(0u));
}

// But for tests where we’re specifically testing Purchase() behavior, we should directly invoke it.
TEST_F(APortfolio, AnswersShareCountForPurchasedSymbol)
{
    m_portfolio.Purchase(IBM, 2);
    ASSERT_THAT(m_portfolio.ShareCount(IBM), Eq(2u));
}

TEST_F(APortfolio, ThrowOnPurchaseOfZeroShares)
{
    ASSERT_THROW(Purchase(IBM, 0), ShareCountCannotBeZeroException);
}

TEST_F(APortfolio, ThrowOnSellOfZeroShares)
{
    ASSERT_THROW(Sell(IBM, 0), ShareCountCannotBeZeroException);
}

TEST_F(APortfolio, AnswersShareCountForAppropriateSymbol)
{
    Purchase(IBM, 5);
    Purchase(SAMSUNG, 10);
    ASSERT_THAT(m_portfolio.ShareCount(IBM), Eq(5u));
}

TEST_F(APortfolio, ShareCountReflectsAccumulatedPurchasesOfSameSymbol)
{
    Purchase(IBM, 5);
    Purchase(IBM, 15);
    ASSERT_THAT(m_portfolio.ShareCount(IBM), Eq(5u + 15));
}

TEST_F(APortfolio, ReducesShareCountOfSymbolOnSell)
{
    Purchase(SAMSUNG, 30);
    m_portfolio.Sell(SAMSUNG, 13);
    ASSERT_THAT(m_portfolio.ShareCount(SAMSUNG), Eq(30u - 13));
}

TEST_F(APortfolio, ThrowsWhenSellingMoreSharesThanPurchased)
{
    ASSERT_THROW(Sell(SAMSUNG, 1), InsufficientSharesException);
}


TEST_F(APortfolio, AnswersThePurchaseRecoredForASinglePurchase)
{
    date dateOfPurchase(2021, Jul, 14);
    Purchase(SAMSUNG, 5, dateOfPurchase);
    auto purchases = m_portfolio.Purchases(SAMSUNG);

    ASSERT_THAT(purchases[0].ShareCount, Eq(5u));
    ASSERT_THAT(purchases[0].Date, Eq(dateOfPurchase));
}

TEST_F(APortfolio, IncludesSalesInPurchasedRecords)
{
    Purchase(SAMSUNG, 10);
    Sell(SAMSUNG, 5, ArbitraryDate);

    auto sales = m_portfolio.Purchases(SAMSUNG);
    ASSERT_PURCHASE(sales[1], -5, ArbitraryDate);
}

TEST_F(APortfolio, SeparatesPurchasesBySymbol)
{
    Purchase(SAMSUNG, 5, ArbitraryDate);
    Purchase(IBM, 1, ArbitraryDate);

    auto sales = m_portfolio.Purchases(SAMSUNG);
    ASSERT_THAT(sales, ElementsAre(PurchaseRecord{5, ArbitraryDate}));
}

TEST_F(APortfolio, AnswersEmptyPurchaseRecordVectorWhenSymbolNotFound)
{
    ASSERT_THAT(m_portfolio.Purchases(SAMSUNG), Eq(std::vector<PurchaseRecord>{}));
}