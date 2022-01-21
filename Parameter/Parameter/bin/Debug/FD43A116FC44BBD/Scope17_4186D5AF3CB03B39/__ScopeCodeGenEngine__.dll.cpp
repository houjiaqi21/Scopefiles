#pragma warning( disable : 4100 )
#pragma warning( disable : 4127 )
#pragma warning( disable : 4189 )
#pragma warning( disable : 4355 )
#pragma warning( disable : 4503 )
#pragma warning( disable : 4505 )
#pragma warning( disable : 4512 )
#pragma warning( disable:  4651 )
#pragma warning( disable : 4691 )
#pragma warning( disable : 4723 )
#pragma warning( disable : 4702 )
#define SCOPE_NO_UDT
#if defined(COMPILE_NATIVE)
#include "ScopeCommonError.h"
#include "ScopeError.h"
#include "ScopeOperators.h"
#endif
#if defined(COMPILE_MANAGED)
#using <mscorlib.dll>
[assembly: System::Runtime::Versioning::TargetFrameworkAttribute(".NETFramework,Version=v4.7.2", FrameworkDisplayName = ".NET Framework, Version 4.7.2")];
#include "ScopeManaged.h"
#endif
#if defined(COMPILE_NATIVE)
#endif
using namespace ScopeEngine;

static ScopeEngine::CompilerSettings GetCompilerSettings()
{
    static ScopeEngine::CompilerSettings settings;
    settings.m_enableWriteBehindCacheService = false;
    settings.m_abfsOutputBufferSizeMB = 24;
    settings.m_enableNullsInKeyRanges = false;
    settings.m_restrictOperatorMemorySpilling = false;
    settings.m_hashCombineMultiPartitionSpillingFlag = true;
    settings.m_storeType = ScopeEngine::StoreType::LocalStore;
    settings.m_verboseRuntimeStatistic = false;
    settings.m_vertexClassifyStoreError = true;
    return settings;
};
enum OperatorUID
{
    UID_Extract_0 = 1,
    UID_Extract_0_Data0 = 2,
    UID_Process_1 = 3,
    UID_Process_1_Data0 = 4,
    UID_SV1_Extract_out0 = 5,
    UID_ParallelUnionAll_Process_1 = 6
};

    // IDs representing UDTs to be used in native code
    enum UserDefinedTypeId
    {
        
    };

#if defined(COMPILE_MANAGED)
// Explicit instantiations for templated functions that are defined in managed code
#endif // defined(COMPILE_MANAGED)

#pragma region StructSchemas
#pragma endregion StructSchemas

#pragma region Schemas

    class Extract_0_Data0
    {
    public:
        int m_IId{};

        Extract_0_Data0() = default;
        Extract_0_Data0(const Extract_0_Data0 & c, IncrementalAllocator * alloc);


        friend std::ostream& operator<<(std::ostream& os, const Extract_0_Data0& row)
        {

            ScopeEngine::OutputRowContent(
                std::string{ u8"IId:int" },
                reinterpret_cast<const char*>(&row),
                os);

            return os;
        }
    };

    static_assert(sizeof(Extract_0_Data0) == 4, "Incorrect size of row schema");

    class Process_1_Data0
    {
    public:
        int m_IId{};
        int m_b{};

        Process_1_Data0() = default;
        Process_1_Data0(const Process_1_Data0 & c, IncrementalAllocator * alloc);


        friend std::ostream& operator<<(std::ostream& os, const Process_1_Data0& row)
        {

            ScopeEngine::OutputRowContent(
                std::string{ u8"IId:int,b:int" },
                reinterpret_cast<const char*>(&row),
                os);

            return os;
        }
    };

    static_assert(sizeof(Process_1_Data0) == 8, "Incorrect size of row schema");
#pragma endregion Schemas

#if defined(COMPILE_MANAGED)
#pragma region ManagedRows
#pragma endregion ManagedRows

#pragma region ManagedUDTs
#pragma endregion ManagedUDTs
#endif // defined(COMPILE_MANAGED)


#pragma region AdapterRowPolicies
#pragma endregion AdapterRowPolicies

#pragma region BinaryPolicies
#pragma endregion BinaryPolicies
#pragma region IntermediateSStreamExtractPolicies
#pragma endregion IntermediateSStreamExtractPolicies
#pragma region Schema Constructors

    INLINE Process_1_Data0::Process_1_Data0(const Process_1_Data0 & c, IncrementalAllocator * alloc) :
            m_IId(c.m_IId),
            m_b(c.m_b)
    {
    }

#pragma endregion Schema Constructors
#pragma hdrstop


#if defined(COMPILE_INIT_SHUTDOWN)
#if defined(COMPILE_MANAGED)
extern "C" __declspec(dllexport) void __stdcall InitVertexManaged(std::string * argv, int argc)
{
#if defined(FORCEMANAGEDDATETIMESER)
    ScopeEngine::ScopeDateTime::ForceManagedSerialization = true;
#endif
    cli::array<String^>^ arguments = ScopeEngineManaged::GroupArguments(argv, argc);
    ScopeEngineManaged::InitializeScopeEngineManaged(arguments);

    // Register Debug Streams from command line arguments
    ScopeRuntime::Global::DebugStreamManager->RegisterDebugStreams(arguments);
    auto traceListener = gcnew System::Diagnostics::ConsoleTraceListener();
    traceListener->TraceOutputOptions = System::Diagnostics::TraceOptions::DateTime | System::Diagnostics::TraceOptions::ProcessId | System::Diagnostics::TraceOptions::ThreadId;
    ScopeRuntime::ScopeTrace::AddListener(traceListener);

    ScopeRuntime::RuntimeConfiguration::Initialize(___Scope_Generated_Classes___::__UdtTypeTable__);
}

extern "C" __declspec(dllexport) void __stdcall ShutdownVertexManaged(CLRMemoryStat& stat)
{
    ScopeEngineManaged::FinalizeScopeEngineManaged(stat);
    ScopeRuntime::ScopeTrace::RemoveAllListeners();
    ScopeRuntime::Global::DebugStreamManager->FinalizeDebugStreams();
}

// < 0 indicates that server GC config will be determined at vertex startup.
// = 0 indicates that default server GC should be used, with one affinitized blocking-GC thread per core.
// > 0 specifies number of heaps/blocking threads, but with core-affinity disabled.
extern "C" __declspec(dllexport) const int UnaffinitizedServerGcHeaps { -1 };
#endif //#if defined(COMPILE_MANAGED)

#if defined(COMPILE_NATIVE)


extern "C" __declspec(dllexport) const int StoreAccessMode{ 0 };

extern "C" __declspec(dllexport) void __stdcall InitVertexNative(VertexExecutionInfo * vertexExecutionInfo)
{
#if defined(FORCEMANAGEDDATETIMESER)
    ScopeEngine::ScopeDateTime::ForceManagedSerialization = true;
#endif

    ErrorManager::GetGlobal()->EnableJSON();
    ErrorManager::GetGlobal()->EnableRowDump(true);
}

// Add broadcast vertex code
extern "C" __declspec(dllexport) void __stdcall SV_CopyThrough_execute(std::string * argv, int argc, InputFileInfo* inputs, int inputCnt, OutputFileInfo* outputs, int outputCnt, VertexExecutionInfo * vertexExecutionInfo)
{
    ScopeEngine::Configuration::Create(ET_Cosmos, GetCompilerSettings(), vertexExecutionInfo);
    if (inputCnt != 1 || outputCnt != 1)
    {
        throw ScopeEngineException(E_INCORRECT_IO_STREAM_COUNT_IN_BROADCAST, { inputCnt, outputCnt });
    }

    IOManager::CopyStream(IOManager::GetGlobal()->GetDevice(inputs[0].inputFileName), IOManager::GetGlobal()->GetDevice(outputs[0].outputFileName));
}
#endif //#if defined(COMPILE_NATIVE)


#endif //#if defined(COMPILE_INIT_SHUTDOWN)
#pragma region SV1_Extract
#if defined(COMPILE_SV1_EXTRACT) || defined(COMPILE_ALL_VERTICES)

    static const char * StringTable_Process_1 [] =
    {
        "IId",
        "-1",
        "\"*** After Last Expression ***\"",
    };

    template<>
    class RowTransformPolicy<Extract_0_Data0, Process_1_Data0, UID_Process_1>
    {
    public:
        static bool FilterTransformRow(Extract_0_Data0 & input, Process_1_Data0 & output, IncrementalAllocator * alloc)
        {
            int exceptionIndex = 0;
            try
            {
                output.m_IId = input.m_IId;
                exceptionIndex++;
                output.m_b = -1;
                exceptionIndex++;
                return true;
            }
            catch(const ScriptExplicitlyRaisedException&)
            {
                throw;
            }
            catch(...)
            {
                std::throw_with_nested(RuntimeException(E_USER_EXPRESSION_ERROR, StringTable_Process_1[exceptionIndex]));
            }
        }

        static void InitializeStatics(IncrementalAllocator *) {}

        // get operator resource requirements
        static ScopeEngine::OperatorRequirements GetOperatorRequirements()
        {
            return ScopeEngine::OperatorRequirements();
        }
    };




#if defined(COMPILE_MANAGED)
#endif // defined(COMPILE_MANAGED)


#if defined(COMPILE_NATIVE)
    template<> 
    class TextExtractPolicy<Extract_0_Data0, UID_Extract_0>
    {
    public:
        static constexpr int StreamIdRangeMax = -1;

        static bool Deserialize(TextInputStream<TextInputStreamTraitsConst<'\t', '\0', '\0', false, false, Default, false, false, false, 0, CharFormat_uint16, false, false>, CosmosInput> * input, Extract_0_Data0 & row)
        {
            for(;;)
            {
                try
                {
                    // When we start a new row we always skip all empty lines first.
                    if (!input->StartRow())
                    {
                        return false;
                    }

                    input->Read(row.m_IId);
                    input->SkipColumn();
                    input->SkipColumn();
                    input->SkipColumn();
                    input->SkipColumn();
                    input->SkipColumn();
                    input->SkipColumn();

                    if (!input->EndRow())
                    {
                        // Too many columns in row - report error.
                        throw ScopeStreamExceptionWithEvidence(
                            E_EXTRACT_ROW_DELIMITER_EXPECTED,
                            { input->CurrentLineNumber(), input->CurrentField() },
                            EvidenceFormatter::FormatText(
                                input->GetBufferStart(),
                                input->GetReadPosition(),
                                input->GetBufferEnd(),
                                input->rowDelimiter,
                                input->delimiter));
                    }
                    return true;
                }
                catch (const ExtractInvalidCharacterException& e)
                {
                    std::throw_with_nested(ExtractException(
                        E_EXTRACT_ENCODING_ERROR,
                        { input->GetEncodedGlobalFileOffset() + e.GetErrorOffset(), input->CurrentLineNumber() },
                        false));
                }
                catch (const TextConversionException& e)
                {
                    std::throw_with_nested(ExtractException(
                        E_EXTRACT_ROW_ERROR,
                        { e.GetRowNumber(), e.GetColumnIndex(), GetColumnName(e.GetColumnIndex()) },
                        false));
                }
                catch (const RuntimeMemoryException& /* e */)
                {
                    std::throw_with_nested(ScopeStreamExceptionWithEvidence(
                        E_EXTRACT_ROW_TOO_LONG,
                        { input->CurrentLineNumber(), Configuration::GetGlobal().GetMaxInMemoryRowSize() },
                        EvidenceFormatter::FormatText(
                            input->GetBufferStart(),
                            input->GetReadPosition(),
                            input->GetBufferEnd(),
                            input->rowDelimiter,
                            input->delimiter)));
                }
                catch (const ScopeStreamException& e)
                {
                    switch(e.Error())
                    {
                    // Following error will terminate read
                    case ScopeStreamException::EndOfFile:
                    case ScopeStreamException::BadDevice:
                        return false;

                    // Bad rows throw exception
                    case ScopeStreamException::UnexpectedNewLine:
                        // Wrong number of columns in row - report error
                        // At this point, line number is increased to point at the next line. Subtract 1 to get line
                        // number of the offending row.
                        throw ScopeStreamExceptionWithEvidence(
                            E_EXTRACT_UNEXPECTED_ROW_DELIMITER,
                            { input->CurrentLineNumber() - 1, 7, input->CurrentField() },
                            EvidenceFormatter::FormatText(
                                input->GetBufferStart(),
                                input->GetReadPosition(),
                                input->GetBufferEnd(),
                                input->rowDelimiter,
                                input->delimiter));

                    // All exceptions should be handled above.
                    default:
                        SCOPE_ASSERT(false);
                    }
                }
            }
        }
        static const char* GetColumnName(std::size_t columnIndex)
        {
            static const std::array<const char*, 8> c_columnNames =
            {
                "IId",
                "Start",
                "Market",
                "Query",
                "DwellTime",
                "Results",
                "ClickedUrls",
                "*** END ***"
            };

            auto idx = std::min(columnIndex, c_columnNames.size() - 1);
            return c_columnNames[idx];
        }
    };

#endif // defined(COMPILE_NATIVE)



#if defined(COMPILE_MANAGED)
#endif // defined(COMPILE_MANAGED)


    template<> 
    class TextOutputPolicy<Process_1_Data0, UID_SV1_Extract_out0>
    {
    public:

        static void Serialize(TextOutputStream<TextOutputStreamTraitsConst<'\t', '\0', false, true, false, false, false, Default, false, CharFormat_uint16>, CosmosOutput> * output, Process_1_Data0 & row)
        {
            output->Write<int,false>(row.m_IId);
            output->WriteDelimiter();
            output->Write<int,false>(row.m_b);
            output->WriteNewLine();
        }

        static void SerializeHeader(TextOutputStream<TextOutputStreamTraitsConst<'\t', '\0', false, true, false, false, false, Default, false, CharFormat_uint16>, CosmosOutput> * output)
        {
            SCOPE_ASSERT(!"TextOutputPolicy::SerializeHeader method should not be invoked.");
        }
    };



#if defined(COMPILE_MANAGED)
#endif // defined(COMPILE_MANAGED)

#if defined(COMPILE_NATIVE)
struct ExtractorType1_SV1_Extr : Extractor<Extract_0_Data0, TextExtractPolicy<Extract_0_Data0, UID_Extract_0>, TextInputStream<TextInputStreamTraitsConst<'\t', '\0', '\0', false, false, Default, false, false, false, 0, CharFormat_uint16, false, false>, CosmosInput>> { using Extractor<Extract_0_Data0, TextExtractPolicy<Extract_0_Data0, UID_Extract_0>, TextInputStream<TextInputStreamTraitsConst<'\t', '\0', '\0', false, false, Default, false, false, false, 0, CharFormat_uint16, false, false>, CosmosInput>>::Extractor; };
struct FilterTransformerType_Process_1 : FilterTransformer<ExtractorType1_SV1_Extr, Extract_0_Data0, Process_1_Data0, UID_Process_1> { using FilterTransformer<ExtractorType1_SV1_Extr, Extract_0_Data0, Process_1_Data0, UID_Process_1>::FilterTransformer; };
struct UnionAllType_Process_1_SV1_Extract_out0_connector : ParallelUnionAll<FilterTransformerType_Process_1, Process_1_Data0, true> { using ParallelUnionAll<FilterTransformerType_Process_1, Process_1_Data0, true>::ParallelUnionAll; };
#endif // defined(COMPILE_NATIVE)



#if defined(COMPILE_NATIVE)
namespace ScopeGeneratedClasses
{
    extern "C" __declspec(dllexport) void __stdcall SV1_Extract_execute(std::string * argv, int argc, InputFileInfo* inputs, int inputCnt, OutputFileInfo* outputs, int outputCnt, VertexExecutionInfo * vertexExecutionInfo)
    {
#ifdef USE_SSE4_2
        ScopeEngine::CheckCpuSupportsInstructions();
#endif

        ScopeEngine::Configuration::Create(ET_Cosmos, GetCompilerSettings(), vertexExecutionInfo);
        SIZE_T x_inputBufSize, x_inputVirtualMemoryLimit;
        int    x_inputBufCnt;
        
        MemoryManager::CalculateIOBufferSize(inputs, inputCnt, outputs, outputCnt, MemoryManager::x_vertexMemoryLimit, MemoryManager::x_vertexReserveMemory, x_inputBufSize, x_inputBufCnt, x_inputVirtualMemoryLimit, false);

        constexpr bool IsNativeOnlyVertex = true;
        // If we have more than one input, we will random shuffle it
        if (inputCnt - 0 > 1)
        {
            ScopeRandom scopeRandom((int)vertexExecutionInfo->m_vertexId);
            auto lambda = [&scopeRandom](std::ptrdiff_t max) { return (scopeRandom.Next() % max + max) % max;}; // scopeRandom.Next() % max could be negative value
            random_shuffle(&inputs[0], inputs + inputCnt - 0, lambda ); 
        }

        // ExtractorType1_SV1_Extr: Extractor<Extract_0_Data0, TextExtractPolicy<Extract_0_Data0, UID_Extract_0>, TextInputStream<TextInputStreamTraitsConst<'\t', '\0', '\0', false, false, Default, false, false, false, 0, CharFormat_uint16, false, false>, CosmosInput>>
        unique_ptr<unique_ptr<ExtractorType1_SV1_Extr>[]> extractor_0_array(new unique_ptr<ExtractorType1_SV1_Extr>[inputCnt - 0]);
        
        for (int i = 0; i < inputCnt; i++)
        {
            extractor_0_array[i - 0].reset(new ExtractorType1_SV1_Extr(inputs[i], false, x_inputBufSize, x_inputBufCnt, x_inputVirtualMemoryLimit, InputStreamParameters('\t', '\0', '\0', static_cast<const char*>(__nullptr), false, false, Default, false, false, 0, CharFormat_uint16), UID_Extract_0));
        }

    ExtractorType1_SV1_Extr ** extractor_0 = (ExtractorType1_SV1_Extr **)extractor_0_array.get();

        
        ULONG extractor_0_count = (ULONG) inputCnt - 0;

        // FilterTransformerType_Process_1: FilterTransformer<ExtractorType1_SV1_Extr, Extract_0_Data0, Process_1_Data0, UID_Process_1>
        // Allocate memory for the operator array
        unique_ptr<unique_ptr<FilterTransformerType_Process_1>[]> filterTransformer_Process_1_array(new unique_ptr<FilterTransformerType_Process_1>[extractor_0_count]);

        // Construct operator objects
        for(ULONG i = 0; i < extractor_0_count; i++)
        {
            filterTransformer_Process_1_array[i].reset(new FilterTransformerType_Process_1(extractor_0[i], UID_Process_1)); 
        }

        FilterTransformerType_Process_1 ** filterTransformer_Process_1 = (FilterTransformerType_Process_1 **)filterTransformer_Process_1_array.get();
        ULONG filterTransformer_Process_1_count = extractor_0_count;

        // Merge streams N->1
        // UnionAllType_Process_1_SV1_Extract_out0_connector: ParallelUnionAll<FilterTransformerType_Process_1, Process_1_Data0, true>
        unique_ptr<UnionAllType_Process_1_SV1_Extract_out0_connector> unionall_Process_1_SV1_Extract_out0_connector_ptr(new UnionAllType_Process_1_SV1_Extract_out0_connector(filterTransformer_Process_1,filterTransformer_Process_1_count,16,12,419430400,UID_ParallelUnionAll_Process_1));
        UnionAllType_Process_1_SV1_Extract_out0_connector * unionall_Process_1_SV1_Extract_out0_connector = unionall_Process_1_SV1_Extract_out0_connector_ptr.get();
        ULONG unionall_Process_1_SV1_Extract_out0_connector_count = 1;

        using OutputterType2_SV1_Extr = Outputter<UnionAllType_Process_1_SV1_Extract_out0_connector, Process_1_Data0, TextOutputPolicy<Process_1_Data0, UID_SV1_Extract_out0>, TextOutputStream<TextOutputStreamTraitsConst<'\t', '\0', false, true, false, false, false, Default, false, CharFormat_uint16>, CosmosOutput>, false>;
        unique_ptr<OutputterType2_SV1_Extr> outputter_SV1_Extract_out0_ptr(new OutputterType2_SV1_Extr(unionall_Process_1_SV1_Extract_out0_connector, outputs[0].outputFileName, false, outputs[0].bufferSize, outputs[0].bufferCount, OutputStreamParameters('\t', "\r\n", '\0', static_cast<const char*>(__nullptr), false, true, false, false, NULL, Default, false, CharFormat_uint16), UID_SV1_Extract_out0));
        OutputterType2_SV1_Extr * outputter_SV1_Extract_out0 = outputter_SV1_Extract_out0_ptr.get();
        // Create timer to automatically dump statistics available at the time, when approaching max permitted time for vertex execution
        auto dumpStatsTimer{ ScopeEngine::CreateDumpStatsTimer(vertexExecutionInfo->m_updateStatusThresholdToAutoDumpStatistics, *outputter_SV1_Extract_out0) };

        try
        {
            // Init operator chain
            outputter_SV1_Extract_out0->InitOperatorPipeline();

            // Execute the whole vertex by calling the GetNextRow on top operator
            Process_1_Data0 row;
            outputter_SV1_Extract_out0->GetNextRow(row);

            // Close operator chain
            outputter_SV1_Extract_out0->Close();
        }
        catch (const ExceptionWithStack& ex)
        {
            std::cout << "Caught exception: " << ex.what() << std::endl << ex.GetStack() << std::endl;
            throw;
        }


        MemoryManager::GetGlobal()->WriteRuntimeStats(vertexExecutionInfo->m_statsRoot);
        outputter_SV1_Extract_out0->WriteRuntimeStats(vertexExecutionInfo->m_statsRoot);
    }
}
#endif // defined(COMPILE_NATIVE)

#if defined(COMPILE_MANAGED)
#endif // defined(COMPILE_MANAGED)
#if defined(COMPILE_NATIVE)
#endif // defined(COMPILE_NATIVE)

#endif
#pragma endregion SV1_Extract
#if defined(COMPILE_SHARED_DATA) || defined(COMPILE_ALL_VERTICES)
#if defined(COMPILE_NATIVE)
#endif // COMPILE_NATIVE
#endif //#if defined(COMPILE_SHARED_DATA) || defined(COMPILE_ALL_VERTICES)
#if defined(COMPILE_SV1_EXTRACT) || defined(COMPILE_ALL_VERTICES)
#if defined(COMPILE_NATIVE)



#endif // COMPILE_NATIVE
#endif //#if defined(COMPILE_SV1_EXTRACT) || defined(COMPILE_ALL_VERTICES)
// Empty footer
