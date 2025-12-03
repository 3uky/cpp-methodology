#include "gmock/gmock.h"

#include "graph_cycle_detection.h"

TEST(DSAGraphTest, NoCycle)
{
    std::vector<std::unique_ptr<Node>> nodes;
    for (int i = 0; i < 3; ++i)
        nodes.push_back(std::make_unique<Node>());

    Node* a = nodes[0].get();
    Node* b = nodes[1].get();
    Node* c = nodes[2].get();

    a->children.push_back(b);
    b->children.push_back(c);
    
    EXPECT_FALSE(has_cycle(a));
}

TEST(DSAGraphTest, SimpleCycle)
{
    std::vector<std::unique_ptr<Node>> nodes;
    for (int i = 0; i < 3; ++i)
        nodes.push_back(std::make_unique<Node>());

    Node* a = nodes[0].get();
    Node* b = nodes[1].get();
    Node* c = nodes[2].get();

    a->children.push_back(b);
    b->children.push_back(c);
    c->children.push_back(a); // cycle
    
    EXPECT_TRUE(has_cycle(a));
}

TEST(DSAGraphTest, SelfLoop)
{
    std::vector<std::unique_ptr<Node>> nodes;
    for (int i = 0; i < 3; ++i)
        nodes.push_back(std::make_unique<Node>());

    Node* a = nodes[0].get();

    a->children.push_back(a); // cycle
    
    EXPECT_TRUE(has_cycle(a));
}

TEST(DSAGraphTest, DisconnectedNode)
{
    std::vector<std::unique_ptr<Node>> nodes;
    for (int i = 0; i < 3; ++i)
        nodes.push_back(std::make_unique<Node>());

    Node* a = nodes[0].get();
    
    EXPECT_FALSE(has_cycle(a));
}
