////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Project:  Embedded Learning Library (ELL)
//  File:     DCTNode.h (nodes)
//  Authors:  Chuck Jacobs
//
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <model/include/CompilableNode.h>
#include <model/include/IRMapCompiler.h>
#include <model/include/InputPort.h>
#include <model/include/MapCompiler.h>
#include <model/include/ModelTransformer.h>
#include <model/include/Node.h>
#include <model/include/OutputPort.h>
#include <model/include/PortElements.h>

#include <math/include/Matrix.h>

#include <utilities/include/TypeName.h>
#include <utilities/include/TypeTraits.h>

#include <cmath>
#include <string>
#include <vector>

namespace ell
{
namespace nodes
{
    /// <summary> A node that performs a real-valued discrete cosine transform (DCT) on its input </summary>
    ///
    /// <typeparam name="ValueType"> The element type. </typeparam>
    ///
    template <typename ValueType>
    class DCTNode : public model::Node
    {
    public:
        /// @name Input and Output Ports
        /// @{
        const model::InputPort<ValueType>& input = _input;
        const model::OutputPort<ValueType>& output = _output;
        /// @}

        /// <summary> Default Constructor </summary>
        DCTNode();

        /// <summary> Constructor </summary>
        ///
        /// <param name="input"> The signal to process. </param>
        /// <param name="numFilters"> The number of DCT filters to use. Also, the output dimension. </param>
        DCTNode(const model::OutputPort<ValueType>& input, size_t numFilters);

        /// <summary> Gets the name of this type (for serialization). </summary>
        ///
        /// <returns> The name of this type. </returns>
        static std::string GetTypeName() { return utilities::GetCompositeTypeName<ValueType>("DCTNode"); }

        /// <summary> Gets the name of this type (for serialization). </summary>
        ///
        /// <returns> The name of this type. </returns>
        std::string GetRuntimeTypeName() const override { return GetTypeName(); }

    protected:
        void Compute() const override;
        bool Refine(model::ModelTransformer& transformer) const override;
        void WriteToArchive(utilities::Archiver& archiver) const override;
        void ReadFromArchive(utilities::Unarchiver& archiver) override;
        bool HasState() const override { return true; } // Stored state: size

    private:
        void Copy(model::ModelTransformer& transformer) const override;

        // Inputs
        model::InputPort<ValueType> _input;

        // Output
        model::OutputPort<ValueType> _output;

        // DCT Matrix
        math::RowMatrix<ValueType> _dctCoeffs;
    };
} // namespace nodes
} // namespace ell
