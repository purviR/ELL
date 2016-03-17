////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Project:  [projectName]
//  File:     CoordinateListTools.h (common)
//  Authors:  Ofer Dekel
//
//  [copyright]
//
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "Coordinate.h"
#include "Map.h"

// stl
#include <string>

namespace layers
{
    /// <summary>
    /// Gets a coordinate list from a coordinate list definition string. The string has the following format
    /// [defString] .=. [def];[defString]
    /// [def] .=. [layerIndex] || [layerIndex],[elementIndex] || [layerIndex],[elementInterval]
    /// [elementInterval] .=. [fromElementIndex]:[toElementIndex]   (used to define intervals of elements)
    /// [layerIndex] .=. [index]
    /// [elementIndex] .=. [index]
    /// [fromElementIndex] .=. [index]
    /// [toElementIndex] .=. [index]
    /// [index] .=. (uint) || e || e-(uint)                         ("e" gets translated to the maximal index possible in the map) 
    /// </summary>
    ///
    /// <param name="map"> The map which the coordinate list relates to. </param>
    /// <param name="coordinateListString"> The coordinate list definition string. </param>
    ///
    /// <returns> The coordinate list. </returns>
    layers::CoordinateList GetCoordinateList(const layers::Map& map, const std::string& coordinateListString);

    /// <summary> Gets the list of coordinates in a given layer in a map. </summary>
    ///
    /// <param name="map"> The map. </param>
    /// <param name="layerIndex"> Zero-based index of the layer. </param>
    ///
    /// <returns> The coordinate list. </returns>
    layers::CoordinateList GetCoordinateList(const layers::Map& map, uint64 layerIndex);

    /// <summary> Constructs a coordinate list which is a sequence of consecutive elements on one layer. </summary>
    ///
    /// <param name="layerIndex"> Zero-based index of the layer. </param>
    /// <param name="fromElementIndex"> Zero-based index of the first element. </param>
    /// <param name="toElementIndex"> Zero-based index of the last element. </param>
    ///
    /// <returns> The coordinate list. </returns>
    layers::CoordinateList GetCoordinateList(uint64 layerIndex, uint64 fromElementIndex, uint64 toElementIndex);
}

