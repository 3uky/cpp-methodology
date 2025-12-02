// https://sourcemaking.com/design_patterns/builder
// https://refactoring.guru/design-patterns/builder
// https://refactoring.guru/design-patterns/builder/cpp/example#lang-features

// When is needed to create an object with lots of possible configuration options.
// It makes sense to use the Builder pattern only when your products are quite complex and require extensive configuration.

#pragma once

#include <memory>

using namespace std;

namespace design_patterns
{

class Product1
{
public:
    std::vector<std::string> m_parts;

    const std::vector<std::string>& GetParts() { return m_parts; };
};

class Builder {
public:
    virtual ~Builder() {}
    virtual void ProducePartA() = 0;
    virtual void ProducePartB() = 0;
    virtual void ProducePartC() = 0;
    virtual std::unique_ptr<Product1> GetProduct() = 0;
};

class ConcreteBuilder1 : public Builder {
public:
    ConcreteBuilder1() : m_product(std::make_unique<Product1>()) {}

    void ProducePartA() override
    {
	    m_product->m_parts.push_back("PartA1");
    }

    void ProducePartB() override
    {
	    m_product->m_parts.push_back("PartB1");
    }

    void ProducePartC() override
    {
	    m_product->m_parts.push_back("PartC1");
    }

    std::unique_ptr<Product1> GetProduct()
    {
        /*
        auto product = std::move(m_product);
        m_product.reset(new Product1);
	    return product;
	    */

    	return std::move(m_product);
    }

private:
	std::unique_ptr<Product1> m_product;
};


/**
 * The Director is only responsible for executing the building steps in a
 * particular sequence. It is helpful when producing products according to a
 * specific order or configuration. Strictly speaking, the Director class is
 * optional, since the client can control builders directly.
 */
class Director {

public:

    void set_builder(std::shared_ptr<Builder> b)
    {
	    m_builder = b;
    }

    void BuildMinimalViableProduct()
    {
	    m_builder->ProducePartA();
    }

    void BuildFullFeaturedProduct()
	{
        m_builder->ProducePartA();
        m_builder->ProducePartB();
        m_builder->ProducePartC();
    }

	std::shared_ptr<Builder> m_builder;
};

}
