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
    UID_Process_2 = 5,
    UID_Process_2_Data0 = 6,
    UID_Process_3 = 7,
    UID_Process_3_Data0 = 8,
    UID_SV1_Extract_out0 = 9,
    UID_Process_1_Prefix = 10,
    UID_ParallelUnionAll_Extract_0 = 11
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
        FString m_Region;
        int m_Duration{};

        Extract_0_Data0() = default;
        Extract_0_Data0(const Extract_0_Data0 & c, IncrementalAllocator * alloc);


        friend std::ostream& operator<<(std::ostream& os, const Extract_0_Data0& row)
        {

            ScopeEngine::OutputRowContent(
                std::string{ u8"Region:string,Duration:int" },
                reinterpret_cast<const char*>(&row),
                os);

            return os;
        }
    };

    static_assert(sizeof(Extract_0_Data0) == 24, "Incorrect size of row schema");

    class Process_2_Data0
    {
    public:
        FString m_Region;
        int m_TotalDuration{};

        Process_2_Data0() = default;
        Process_2_Data0(const Process_2_Data0 & c, IncrementalAllocator * alloc);


        friend std::ostream& operator<<(std::ostream& os, const Process_2_Data0& row)
        {

            ScopeEngine::OutputRowContent(
                std::string{ u8"Region:string,TotalDuration:int" },
                reinterpret_cast<const char*>(&row),
                os);

            return os;
        }
    };

    static_assert(sizeof(Process_2_Data0) == 24, "Incorrect size of row schema");
#pragma endregion Schemas

#if defined(COMPILE_MANAGED)
#pragma region ManagedRows
    template<>
    struct ManagedRow<Process_2_Data0>
    {
        typedef ___Scope_Generated_Classes___::Row_Region_String_TotalDuration_Integer Row;

        ManagedRow()
        {
            m_row.reset(gcnew Row());
        }

        Row^ get()
        {
            return m_row.get();
        }
        
    private:
    
        ScopeTypedManagedHandle<Row^> m_row;
        ManagedRow & operator=(ManagedRow &);
    };
#pragma endregion ManagedRows

#pragma region ManagedUDTs
#pragma endregion ManagedUDTs
#endif // defined(COMPILE_MANAGED)


#pragma region AdapterRowPolicies
#pragma endregion AdapterRowPolicies

#pragma region BinaryPolicies


#if defined(COMPILE_NATIVE)
    template<> 
    class BinaryExtractPolicy<Extract_0_Data0>
    {
    public:
        static constexpr int StreamIdRangeMax = -1;

        static bool Deserialize(BinaryInputStream * input, Extract_0_Data0 & row)
        {
            try
            {
                char b = 0;
                input->Read(b);
                if (b==0)
                {
                    input->Read(row.m_Region);
                    input->Read(row.m_Duration);
                }
                else
                {
            char ___masking___[1];
            memset(___masking___, 0, sizeof(___masking___));
                    ___masking___[0] = b;
                    if ((___masking___[0] & 2 ) != 2)
                    {
                        input->Read(row.m_Region);
                    }
                    else
                    {
                        row.m_Region.SetNull();
                    }
                    input->Read(row.m_Duration);
                }
            }
            catch (ScopeStreamException &) 
            {
                // we reach the end of file
                return false;
            }

            return true;
        }
    };
#endif // defined(COMPILE_NATIVE)

    template<> 
    class BinaryOutputPolicy<Extract_0_Data0>
    {
    public:
    
        static void SerializeHeader(BinaryOutputStream * output)
        {
            SCOPE_ASSERT(!"BinaryOutputPolicy::SerializeHeader method should not be invoked.");
        }
        
        __declspec(noinline) static void Serialize(BinaryOutputStream * output, Extract_0_Data0 & row)
        {
            SIZE_T rowStart =  output->GetOutputter().GetCurrentPosition();
            char b = 0;
            char ___masking___[1];
            memset(___masking___, 0, sizeof(___masking___));
            ___masking___[0] = 1;
            bool hasNull = false;
            if (row.m_Region.IsNull())
            {
                hasNull = true;
                ___masking___[0] |= 2;
            }
            if (hasNull)
            {
                output->Write(___masking___[0]);
            }
            else
            {
                output->Write(b);
            }
            if (!row.m_Region.IsNull())
            {
                output->Write(row.m_Region);
            }
            output->Write(row.m_Duration);
            SIZE_T rowSize =  output->GetOutputter().GetCurrentPosition() - rowStart;
            auto rowLimit = ScopeEngine::Configuration::GetGlobal().GetMaxOnDiskRowSize();
            if (rowSize > rowLimit)
            {
                std::stringstream ss;
                ss << row << std::endl;
                throw RuntimeException(E_USER_ONDISKROW_TOO_BIG, {rowSize, rowLimit, ss.str()});
            }
        }
        static void Serialize(DummyOutputStream * output, const Extract_0_Data0 & row)
        {
            SCOPE_ASSERT(!"BinaryOutputPolicy::Serialize method for type 'DummyOutputStream' should not be invoked."); 
        }
            static void SerializeKeyForSS(MemoryOutputStream* output, const Extract_0_Data0 & row)
            {
                STRUCTURED_DATA_ASSERT(false); // there is no partition key in the schema
            }
    };

#pragma endregion BinaryPolicies
#pragma region IntermediateSStreamExtractPolicies
#pragma endregion IntermediateSStreamExtractPolicies
#pragma region Schema Constructors
    INLINE Extract_0_Data0::Extract_0_Data0(const Extract_0_Data0 & c, IncrementalAllocator * alloc) :
            m_Region(c.m_Region, alloc),
            m_Duration(c.m_Duration)
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


    template<> 
    class KeyComparePolicy<Extract_0_Data0,UID_Process_1>
    {
    public:
        struct KeyStruct
        {
            FString m_Region;

            KeyStruct(Extract_0_Data0 & c) :
                m_Region(c.m_Region)
            {
            }

            KeyStruct(const Extract_0_Data0 & c, IncrementalAllocator * alloc) :
                m_Region(const_cast<Extract_0_Data0&>(c).m_Region, alloc)
            {
            }

            KeyStruct(KeyStruct & c) :
                m_Region(c.m_Region)
            {
            }

            KeyStruct(const KeyStruct & c, IncrementalAllocator * alloc) :
                m_Region(const_cast<KeyStruct&>(c).m_Region, alloc)
            {
            }

            KeyStruct() :
                m_Region()
            {
            }

            friend std::ostream& operator<<(std::ostream& os, const KeyStruct& row)
            {

                ScopeEngine::OutputRowContent(
                    std::string{ u8"Region:string" },
                    reinterpret_cast<const char*>(&row),
                    os);

                return os;
            }
        };

        typedef KeyStruct KeyType;

        static int Compare(Extract_0_Data0 & row, KeyType & key)
        {
            int r = 0;
            if ((r = ScopeTypeCompare(row.m_Region, key.m_Region)) != 0)
                return r;
            return r;
        }

        static int Compare(Extract_0_Data0 * n1, Extract_0_Data0 * n2)
        {
            int r = 0;
            if ((r = ScopeTypeCompare((*n1).m_Region, (*n2).m_Region)) != 0)
                return r;
            return r;
        }

        // Key function for MKQsort algorithm
        static __int64 Key(Extract_0_Data0 * p, int depth)
        {
            if (depth < 1 && (*p).m_Region.IsNull())
            {
                // Special case for "null" string
                return (__int64)(256);
            }
            else if (depth == (int) (*p).m_Region.size())
            {
                // Special case for end-of-string (field separator)
                return (__int64)(-1);
            }
            else if (depth < (int) (*p).m_Region.size())
            {
                // For string convert to unsigned char first. Otherwise, unicode will have negative value which will have different order than binary comparison.
                return (__int64)((unsigned char)((*p).m_Region.buffer()[depth]));
            }

            depth -= (int) ((*p).m_Region.size() + 1);


            return 0;
        }

        // End of Key function for MKQSort algorithm
        static bool EofKey(Extract_0_Data0 * p, int depth)
        {
            depth -= (int) ((*p).m_Region.size() + 1);
            if (depth < 0)
                return false;
            return true;
        }
    };



    static const char * StringTable_Process_2 [] =
    {
        "Region",
        "Duration",
        "\"*** After Last Expression ***\"",
    };

    template<>
    class RowTransformPolicy<Extract_0_Data0, Process_2_Data0, UID_Process_2>
    {
    public:
        static bool FilterTransformRow(Extract_0_Data0 & input, Process_2_Data0 & output, IncrementalAllocator * alloc)
        {
            int exceptionIndex = 0;
            try
            {
                output.m_Region = input.m_Region;
                exceptionIndex++;
                output.m_TotalDuration = input.m_Duration;
                exceptionIndex++;
                return true;
            }
            catch(const ScriptExplicitlyRaisedException&)
            {
                throw;
            }
            catch(...)
            {
                std::throw_with_nested(RuntimeException(E_USER_EXPRESSION_ERROR, StringTable_Process_2[exceptionIndex]));
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

                    input->SkipColumn();
                    input->SkipColumn();
                    input->Read(row.m_Region);
                    input->SkipColumn();
                    input->Read(row.m_Duration);
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
                "UserId",
                "Start",
                "Region",
                "Query",
                "Duration",
                "Urls",
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


#if defined(COMPILE_MANAGED)
#endif // defined(COMPILE_MANAGED)


    template<>
    class RowTransformPolicy<Process_2_Data0, Process_2_Data0, UID_Process_3>
    {
    public:
        static bool FilterTransformRow(Process_2_Data0 & input, Process_2_Data0 & output, IncrementalAllocator * alloc)
        {
return true;
}

        static void InitializeStatics(IncrementalAllocator *) {}

        // get operator resource requirements
        static ScopeEngine::OperatorRequirements GetOperatorRequirements()
        {
            return ScopeEngine::OperatorRequirements().AddMemoryInRows(1, 1);
        }
    };




#if defined(COMPILE_MANAGED)
    template<>
    struct ManagedUDO<UID_Process_3>
    {
        typedef ScopeRuntime::Processor UDO;

        ManagedUDO(std::string * argv, int argc)
        {
            try
            {
                m_udo.reset(___Scope_Generated_Classes___::__OperatorFactory__::Create_Process_3());
                m_args.reset(gcnew Generic::List<String^>(ConvertArgsToArray(std::wstring{})));
            }
            catch (Exception ^ex)
            {
                ScopeEngineManaged::ExceptionHelper::WrapException(___Scope_Generated_Classes___::__OperatorFactory__::Name_Process_3, "Constructor", ex);
                throw;
            }
            auto curRow = gcnew ___Scope_Generated_Classes___::Row_Region_String_TotalDuration_Integer();
            m_udo->GetType()->GetField("_outputRow", BindingFlags::NonPublic | BindingFlags::Instance)->SetValue(m_udo.get(), curRow);
            m_udo->GetType()->GetField("_outputSchema", BindingFlags::NonPublic | BindingFlags::Instance)->SetValue(m_udo.get(), m_udo->DefaultRow->Schema);
        }


        UDO^ get()
        {
            return m_udo.get();
        }

        Generic::List<String^>^ args()
        {
            return m_args.get();
        }
        cli::array<String^>^ ReadOnlyColumns_Output()
        {
            return nullptr;
        }

        cli::array<String^>^ ReadOnlyColumns_Input()
        {
            return nullptr;
        }

    private:
        ScopeTypedManagedHandle<UDO^> m_udo;
        ScopeTypedManagedHandle<Generic::List<String^>^> m_args;
        ManagedUDO & operator=(ManagedUDO &);
    };
    template<>
    class InteropToManagedRowPolicy<Process_2_Data0, UID_Process_3>
    {
    public:
        static void Marshal(Process_2_Data0& nativeRow, ScopeRuntime::Row^% managedRow, InteropAllocator * alloc)
        {
            alloc->CopyToManagedColumn(nativeRow.m_Region, managedRow[0], 0);
            alloc->CopyToManagedColumn(nativeRow.m_TotalDuration, managedRow[1], 1);
        }
    };
    template<>
    class InteropToNativeRowPolicy<Process_2_Data0, UID_Process_3>
    {
    public:
        static void Marshal(ScopeRuntime::Row^ managedRow, Process_2_Data0& nativeRow, IncrementalAllocator* alloc)
        {
            ScopeEngine::ScopeManagedInterop::CopyToNativeColumn(nativeRow.m_Region, managedRow[0]->Binary, alloc);
            ScopeEngine::ScopeManagedInterop::CopyToNativeColumn(nativeRow.m_TotalDuration, managedRow[1]->Integer, alloc);
        }
    };
#endif // defined(COMPILE_MANAGED)


    template<> 
    class TextOutputPolicy<Process_2_Data0, UID_SV1_Extract_out0>
    {
    public:

        static void Serialize(TextOutputStream<TextOutputStreamTraitsConst<'\t', '\0', false, true, false, false, false, Default, false, CharFormat_uint16>, CosmosOutput> * output, Process_2_Data0 & row)
        {
            if (!row.m_Region.IsNull())
            {
                output->Write<FString,false>(row.m_Region);
            }
            output->WriteDelimiter();
            output->Write<int,false>(row.m_TotalDuration);
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
struct UnionAllType_Extract_0_Process_1_connector : ParallelUnionAll<ExtractorType1_SV1_Extr, Extract_0_Data0, false> { using ParallelUnionAll<ExtractorType1_SV1_Extr, Extract_0_Data0, false>::ParallelUnionAll; };
struct SorterType_Process_1 : Sorter<Extract_0_Data0> { using Sorter<Extract_0_Data0>::Sorter; };
struct FilterTransformerType_Process_2 : FilterTransformer<SorterType_Process_1, Extract_0_Data0, Process_2_Data0, UID_Process_2> { using FilterTransformer<SorterType_Process_1, Extract_0_Data0, Process_2_Data0, UID_Process_2>::FilterTransformer; };
struct ProcessorType_Process_3 : ScopeProcessor<Process_2_Data0, Process_2_Data0> { using ScopeProcessor<Process_2_Data0, Process_2_Data0>::ScopeProcessor; };
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

        constexpr bool IsNativeOnlyVertex = false;
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

        // Merge streams N->1
        // UnionAllType_Extract_0_Process_1_connector: ParallelUnionAll<ExtractorType1_SV1_Extr, Extract_0_Data0, false>
        unique_ptr<UnionAllType_Extract_0_Process_1_connector> unionall_Extract_0_Process_1_connector_ptr(new UnionAllType_Extract_0_Process_1_connector(extractor_0,extractor_0_count,16,12,419430400,UID_ParallelUnionAll_Extract_0));
        UnionAllType_Extract_0_Process_1_connector * unionall_Extract_0_Process_1_connector = unionall_Extract_0_Process_1_connector_ptr.get();
        ULONG unionall_Extract_0_Process_1_connector_count = 1;
        unique_ptr<OperatorDelegate<Extract_0_Data0>> delegate_unionall_Extract_0_Process_1_connector_ptr (new OperatorDelegate<Extract_0_Data0>(unionall_Extract_0_Process_1_connector));
        OperatorDelegate<Extract_0_Data0> * delegate_unionall_Extract_0_Process_1_connector = delegate_unionall_Extract_0_Process_1_connector_ptr.get();
        ULONG delegate_unionall_Extract_0_Process_1_connector_count = 1;

        // SorterType_Process_1: Sorter<Extract_0_Data0>
        unique_ptr<SorterType_Process_1> sorter_Process_1_ptr (new SorterType_Process_1(delegate_unionall_Extract_0_Process_1_connector, &MKQSort<Extract_0_Data0>::Sort<KeyComparePolicy<Extract_0_Data0, UID_Process_1>, (sizeof(Extract_0_Data0)<=CACHELINE_SIZE)>, ScopeLoserTreeDelegate<Extract_0_Data0>::CreateDelegate<UID_Process_1>(), false, 2147483648 /*memoryQuota*/, UID_Process_1));
        SorterType_Process_1 * sorter_Process_1 = sorter_Process_1_ptr.get();
        ULONG sorter_Process_1_count = 1;

        // FilterTransformerType_Process_2: FilterTransformer<SorterType_Process_1, Extract_0_Data0, Process_2_Data0, UID_Process_2>
        unique_ptr<FilterTransformerType_Process_2> filterTransformer_Process_2_ptr (new FilterTransformerType_Process_2(sorter_Process_1, UID_Process_2));
        FilterTransformerType_Process_2 * filterTransformer_Process_2 = filterTransformer_Process_2_ptr.get();
        ULONG filterTransformer_Process_2_count = 1;
        unique_ptr<OperatorDelegate<Process_2_Data0>> delegate_filterTransformer_Process_2_ptr (new OperatorDelegate<Process_2_Data0>(filterTransformer_Process_2));
        OperatorDelegate<Process_2_Data0> * delegate_filterTransformer_Process_2 = delegate_filterTransformer_Process_2_ptr.get();
        ULONG delegate_filterTransformer_Process_2_count = 1;

        // ProcessorType_Process_3: ScopeProcessor<Process_2_Data0, Process_2_Data0>
        unique_ptr<ProcessorType_Process_3> processor_Process_3_ptr (new ProcessorType_Process_3(ScopeGrouperManagedFactory::Make<Process_2_Data0,Process_2_Data0,UID_Process_3>(delegate_filterTransformer_Process_2), delegate_filterTransformer_Process_2, UID_Process_3));
        ProcessorType_Process_3 * processor_Process_3 = processor_Process_3_ptr.get();
        ULONG processor_Process_3_count = 1;

        using OutputterType2_SV1_Extr = Outputter<ProcessorType_Process_3, Process_2_Data0, TextOutputPolicy<Process_2_Data0, UID_SV1_Extract_out0>, TextOutputStream<TextOutputStreamTraitsConst<'\t', '\0', false, true, false, false, false, Default, false, CharFormat_uint16>, CosmosOutput>, false>;
        unique_ptr<OutputterType2_SV1_Extr> outputter_SV1_Extract_out0_ptr(new OutputterType2_SV1_Extr(processor_Process_3, outputs[0].outputFileName, false, outputs[0].bufferSize, outputs[0].bufferCount, OutputStreamParameters('\t', "\r\n", '\0', static_cast<const char*>(__nullptr), false, true, false, false, NULL, Default, false, CharFormat_uint16), UID_SV1_Extract_out0));
        OutputterType2_SV1_Extr * outputter_SV1_Extract_out0 = outputter_SV1_Extract_out0_ptr.get();
        // Create timer to automatically dump statistics available at the time, when approaching max permitted time for vertex execution
        auto dumpStatsTimer{ ScopeEngine::CreateDumpStatsTimer(vertexExecutionInfo->m_updateStatusThresholdToAutoDumpStatistics, *outputter_SV1_Extract_out0) };

        try
        {
            // Init operator chain
            outputter_SV1_Extract_out0->InitOperatorPipeline();

            // Execute the whole vertex by calling the GetNextRow on top operator
            Process_2_Data0 row;
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
template ScopeProcessorManaged<Process_2_Data0, Process_2_Data0> * ScopeEngine::ScopeGrouperManagedFactory::Make<Process_2_Data0, Process_2_Data0, UID_Process_3>(OperatorDelegate<Process_2_Data0>*);
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
