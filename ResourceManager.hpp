#pragma once

#include "Resource.hpp"

class ResourceManager
{
    Resource* resource;

public:
    ResourceManager() : resource(new Resource()) {}
    
    ~ResourceManager() { delete resource; }

    ResourceManager(const ResourceManager& other)
        : resource(new Resource(*other.resource)) {}

    ResourceManager& operator=(const ResourceManager& other)
    {
        if (this != &other)
        {
            delete resource;
            resource = new Resource(*other.resource);
        }
        return *this;
    }

    ResourceManager(ResourceManager&& other) : resource(other.resource)
    {
        other.resource = nullptr;
    }

    ResourceManager& operator=(ResourceManager&& other)    {
        if (this != &other)
        {
            delete resource;
            resource = other.resource;
            other.resource = nullptr;
        }
        return *this;
    }

    double get() { return resource->get(); }
};
