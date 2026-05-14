#pragma once

#include "set_impl.h"

#include <unordered_set>

class HashSetImpl : public SetImpl 
{
public:
    HashSetImpl() = default;

    HashSetImpl(const HashSetImpl& other)
        : elements_(other.elements_) {}
        
    HashSetImpl(const std::vector<int>& elements) 
        : elements_(elements.begin(), elements.end()) {}

    void add(int element) override
    {
        elements_.insert(element);
    }

    void remove(int element) override
    {
        elements_.erase(element);
    }

    bool contains(int element) const override
    {
        return elements_.find(element) != elements_.end();
    }

    std::size_t getSize() const override
    {
        return elements_.size();
    }

    std::vector<int> getElements() const override
    {
        return std::vector<int>(elements_.begin(), elements_.end());
    }

    std::unique_ptr<SetImpl> clone() const override
    {
        return std::make_unique<HashSetImpl>(*this);
    }
private:
    std::unordered_set<int> elements_;
};