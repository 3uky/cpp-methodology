#include "gmock/gmock.h"

#include <memory>

using ::testing::Return;

namespace unit_testing
{
    class Database
    {
    public:
        virtual int GetData() = 0;
    };

    class MockDatabase : public Database
    {
    public:
        MOCK_METHOD(int, GetData, (), (override));
    };

    class User
    {
    public:
        User() {};

        void SetDatabase(std::shared_ptr<Database> database)
        {
            m_database = database;
        }

        int ExtractData()
        {
            return m_database->GetData();
        }

        std::shared_ptr<Database> m_database;
    };

TEST(DatabaseSimulationTest, ShouldSimulateGettingDataFromDatabase )
{
    // GIVEN
    std::shared_ptr<MockDatabase> database = std::make_shared<MockDatabase>(); 
    User user;
    user.SetDatabase(database);
    int expected_value = 5;

    EXPECT_CALL(*database, GetData()).WillOnce(Return(5)); // simulate behavior of database

    // WHEN
    int result = user.ExtractData();

    // THEN
    EXPECT_EQ(result, expected_value);
}
}