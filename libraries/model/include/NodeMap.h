////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Project:  Embedded Learning Library (ELL)
//  File:     NodeMap.h (model)
//  Authors:  Umesh Madan
//
////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma once

#include "Node.h"

#include <unordered_map>

namespace ell
{
namespace model
{
    /// <summary> Used by the compiler to maintain tables for data associated with each node. </summary>
    template <typename ValueType, ValueType defaultValue = ValueType(0)>
    class NodeMap
    {
    public:
        /// <summary> Get the mapped value for this node, or the default. </summary>
        ///
        /// <param name="node"> The node to look up. </param>
        /// <returns> The value associated with the node, if it has one, otherwise the default. </returns>
        ValueType Get(const model::Node& node) const;

        /// <summary> Set the mapped value for this node. </summary>
        ///
        /// <param name="node"> The node to set a value for. </param>
        /// <param name="value"> The value to set for the node. </param>
        void Set(const model::Node& node, ValueType value);

        /// <summary> True if the given node is mapped. </summary>
        ///
        /// <param name="node"> The node to look up. </param>
        /// <returns> `true` if the node is in the map. </returns>
        bool Contains(const model::Node& node) const;

        /// <summary> Remove the mapped value for this node. </summary>
        ///
        /// <param name="node"> The node to remove. </param>
        void Remove(const model::Node& node);

        /// <summary> Clear the map </summary>
        void Clear();

    private:
        std::unordered_map<model::Node::NodeId, ValueType> _map;
    };
} // namespace model
} // namespace ell

#pragma region implementation

namespace ell
{
namespace model
{
    template <typename T, T defaultValue>
    T NodeMap<T, defaultValue>::Get(const model::Node& node) const
    {
        T value = defaultValue;
        auto search = _map.find(node.GetId());
        if (search != _map.end())
        {
            value = search->second;
        }
        return value;
    }

    template <typename T, T defaultValue>
    void NodeMap<T, defaultValue>::Set(const model::Node& node, T value)
    {
        _map[node.GetId()] = value;
    }

    template <typename T, T defaultValue>
    bool NodeMap<T, defaultValue>::Contains(const model::Node& node) const
    {
        return (Get(node) != nullptr);
    }

    template <typename T, T defaultValue>
    void NodeMap<T, defaultValue>::Remove(const model::Node& node)
    {
        auto search = _map.find(node.GetId());
        if (search != _map.end())
        {
            _map.erase(search);
        }
    }

    template <typename T, T defaultValue>
    void NodeMap<T, defaultValue>::Clear()
    {
        _map.clear();
    }
} // namespace model
} // namespace ell

#pragma endregion implementation
