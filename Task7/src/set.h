#pragma once

#include "set_impl.h"
#include "vector_set_impl.h"
#include "hash_set_impl.h"

#include <memory>
#include <vector>
#include <typeinfo>

class Set
{
public:
    Set() : impl_(std::make_unique<VectorSetImpl>()) {}
    Set(const Set& other) : impl_(other.impl_->clone()) {}

    Set& operator=(const Set& other)
    {
        if (this != &other)
        {
            impl_ = other.impl_->clone();
        }
        return *this;
    }

    void add(int element)
    {
        impl_->add(element);
        switchImplementation();
    }

    void remove(int element)
    {
        impl_->remove(element);
        switchImplementation();
    }

    bool contains(int element) const
    {
        return impl_->contains(element);
    }

    std::size_t getSize() const
    {
        return impl_->getSize();
    }

    std::vector<int> getElements() const
    {
        return impl_->getElements();
    }

    Set unionWith(const Set& other) const
    {
        Set result(*this);
        for (int element : other.getElements())
        {
            result.add(element);
        }
        return result;
    }

    Set intersectionWith(const Set& other) const
    {
        Set result;
        for (int element : impl_->getElements())
        {
            if (other.contains(element))
            {
                result.add(element);
            }
        }
        return result;
    }

private:
    std::unique_ptr<SetImpl> impl_;

    static constexpr std::size_t SwitchLimit = 10;

    void switchImplementation()
    {
        std::size_t currentSize = impl_->getSize();
        bool isHash = typeid(*impl_) == typeid(HashSetImpl);

        if (currentSize > SwitchLimit && !isHash)
        {
            impl_ = std::make_unique<HashSetImpl>(impl_->getElements());
        }
        else if (currentSize <= SwitchLimit && isHash)
        {
            impl_ = std::make_unique<VectorSetImpl>(impl_->getElements());
        }
    }
};