#pragma once

#include "set_impl.h"

#include <vector>
#include <algorithm>

class VectorSetImpl : public SetImpl
{
public:
    VectorSetImpl() = default;

    VectorSetImpl(const VectorSetImpl& other)
        : elements_(other.elements_) {}

    VectorSetImpl(const std::vector<int>& elements)
        : elements_(elements) {}
    
    void add(int element) override
    {
        if (!contains(element))
        {
            elements_.push_back(element);
        }
    }

    void remove(int element) override
    {
        auto it = std::find(elements_.begin(), elements_.end(), element);
        if (it != elements_.end())
        {
            elements_.erase(it);
        }
    }

    bool contains(int element) const override
    {
        return std::find(elements_.begin(), elements_.end(), element) != elements_.end();
    }

    std::size_t getSize() const override
    {
        return elements_.size();
    }

    std::vector<int> getElements() const override
    {
        return elements_;
    }

    std::unique_ptr<SetImpl> clone() const override
    {
        return std::make_unique<VectorSetImpl>(*this);
    }

private:
    std::vector<int> elements_;
};