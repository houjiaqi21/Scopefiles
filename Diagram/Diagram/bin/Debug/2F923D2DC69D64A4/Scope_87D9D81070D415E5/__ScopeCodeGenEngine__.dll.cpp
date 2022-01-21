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
#include "StreamingUtils.h"
#endif
#if defined(COMPILE_NATIVE)
#endif
using namespace ScopeEngine;

static ScopeEngine::CompilerSettings GetCompilerSettings()
{
    static ScopeEngine::CompilerSettings settings;
    settings.m_enableWriteBehindCacheService = false;
    settings.m_allowUserDataInException = true;
    settings.m_restrictOperatorMemorySpilling = false;
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
    UID_SV1_Extract_out0 = 4,
    UID_Extract_2 = 5,
    UID_Extract_2_Data0 = 6,
    UID_Process_3 = 7,
    UID_Process_3_Data0 = 8,
    UID_Process_4 = 9,
    UID_SV2_Extract_out0 = 10,
    UID_Join_5 = 11,
    UID_Join_5_Data0 = 12,
    UID_Process_6 = 13,
    UID_Process_6_Data0 = 14,
    UID_Process_7 = 15,
    UID_Process_7_Data0 = 16,
    UID_Process_8 = 17,
    UID_Process_8_Data0 = 18,
    UID_SV3_Combine_out0 = 19,
    UID_Join_5_0,
    UID_Join_5_1,
    UID_Process_1_Prefix,
    UID_Process_4_Prefix,
    UID_Process_6_Prefix,
    UID_ParallelUnionAll_Extract_0,
    UID_ParallelUnionAll_Process_3
};

//namespace ScopeGeneratedClasses
//{
    // IDs representing UDTs to be used in native code
    enum UserDefinedTypeId
    {
        
    };

#if defined(COMPILE_MANAGED)
// Explicit instantiations for templated functions that are defined in managed code
#endif // defined(COMPILE_MANAGED)


    class Extract_0_Data0
    {
    public:
        int m_AdId;
        int m_IId;
        int m_Impression;

        Extract_0_Data0();
        Extract_0_Data0(const Extract_0_Data0 & c, IncrementalAllocator * alloc);

        template <typename Allocator>
        Extract_0_Data0(const Extract_0_Data0 & c, FixedArrayTypeMemoryManager<Allocator> * mmng);

        template <typename Allocator>
        void Delete(FixedArrayTypeMemoryManager<Allocator> * mmng);


        static constexpr bool containsUDT = false;

        friend std::ostream& operator<<(std::ostream& os, const Extract_0_Data0& row)
        {

            ScopeEngine::OutputRowContent(
                std::string{ u8"AdId:int,IId:int,Impression:int" },
                reinterpret_cast<const char*>(&row),
                os);

            return os;
        }
    };

    static_assert(sizeof(Extract_0_Data0) == 12, "Incorrect size of row schema");

    class Extract_2_Data0
    {
    public:
        int m_IId;
        FString m_Market;
        FString m_Query;
        int m_DwellTime;

        Extract_2_Data0();
        Extract_2_Data0(const Extract_2_Data0 & c, IncrementalAllocator * alloc);

        template <typename Allocator>
        Extract_2_Data0(const Extract_2_Data0 & c, FixedArrayTypeMemoryManager<Allocator> * mmng);

        template <typename Allocator>
        void Delete(FixedArrayTypeMemoryManager<Allocator> * mmng);


        static constexpr bool containsUDT = false;

        friend std::ostream& operator<<(std::ostream& os, const Extract_2_Data0& row)
        {

            ScopeEngine::OutputRowContent(
                std::string{ u8"IId:int,Market:string,Query:string,DwellTime:int" },
                reinterpret_cast<const char*>(&row),
                os);

            return os;
        }
    };

    static_assert(sizeof(Extract_2_Data0) == 48, "Incorrect size of row schema");

    class Process_3_Data0
    {
    public:
        FString m_Query;
        int m_DwellTime;
        int m_IId1;

        Process_3_Data0();
        Process_3_Data0(const Process_3_Data0 & c, IncrementalAllocator * alloc);

        template <typename Allocator>
        Process_3_Data0(const Process_3_Data0 & c, FixedArrayTypeMemoryManager<Allocator> * mmng);

        template <typename Allocator>
        void Delete(FixedArrayTypeMemoryManager<Allocator> * mmng);


        static constexpr bool containsUDT = false;

        friend std::ostream& operator<<(std::ostream& os, const Process_3_Data0& row)
        {

            ScopeEngine::OutputRowContent(
                std::string{ u8"Query:string,DwellTime:int,IId1:int" },
                reinterpret_cast<const char*>(&row),
                os);

            return os;
        }
    };

    static_assert(sizeof(Process_3_Data0) == 24, "Incorrect size of row schema");

    class Join_5_Data0
    {
    public:
        int m_AdId;
        int m_IId;
        int m_Impression;
        FString m_Query;
        int m_DwellTime;

        Join_5_Data0();
        Join_5_Data0(const Join_5_Data0 & c, IncrementalAllocator * alloc);

        template <typename Allocator>
        Join_5_Data0(const Join_5_Data0 & c, FixedArrayTypeMemoryManager<Allocator> * mmng);

        template <typename Allocator>
        void Delete(FixedArrayTypeMemoryManager<Allocator> * mmng);


        static constexpr bool containsUDT = false;

        friend std::ostream& operator<<(std::ostream& os, const Join_5_Data0& row)
        {

            ScopeEngine::OutputRowContent(
                std::string{ u8"AdId:int,IId:int,Impression:int,Query:string,DwellTime:int" },
                reinterpret_cast<const char*>(&row),
                os);

            return os;
        }
    };

    static_assert(sizeof(Join_5_Data0) == 40, "Incorrect size of row schema");

#if defined(COMPILE_MANAGED)
    template<>
    struct ManagedRow<Join_5_Data0>
    {
        typedef ___Scope_Generated_Classes___::Row_AdId_Integer_IId_Integer_Impression_Integer_Query_String_DwellTime_Integer Row;

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

#endif // defined(COMPILE_MANAGED)





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
                input->Read(row.m_AdId);
                input->Read(row.m_IId);
                input->Read(row.m_Impression);
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
            output->Write(row.m_AdId);
            output->Write(row.m_IId);
            output->Write(row.m_Impression);
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
            SCOPE_ASSERT(false); 
        }
            static void SerializeKeyForSS(MemoryOutputStream* output, const Extract_0_Data0 & row)
            {
                STRUCTURED_DATA_ASSERT(false); // there is no partition key in the schema
            }
    };



#if defined(COMPILE_NATIVE)
    template<> 
    class BinaryExtractPolicy<Process_3_Data0>
    {
    public:
        static constexpr int StreamIdRangeMax = -1;

        static bool Deserialize(BinaryInputStream * input, Process_3_Data0 & row)
        {
            try
            {
                char b = 0;
                input->Read(b);
                if (b==0)
                {
                    input->Read(row.m_Query);
                    input->Read(row.m_DwellTime);
                    input->Read(row.m_IId1);
                }
                else
                {
                    char ___masking___[1];
                    ___masking___[0] = b;
                    if ((___masking___[0] & 2 ) != 2)
                    {
                        input->Read(row.m_Query);
                    }
                    else
                    {
                        row.m_Query.SetNull();
                    }
                    input->Read(row.m_DwellTime);
                    input->Read(row.m_IId1);
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
    class BinaryOutputPolicy<Process_3_Data0>
    {
    public:
    
        static void SerializeHeader(BinaryOutputStream * output)
        {
            SCOPE_ASSERT(!"BinaryOutputPolicy::SerializeHeader method should not be invoked.");
        }
        
        __declspec(noinline) static void Serialize(BinaryOutputStream * output, Process_3_Data0 & row)
        {
            SIZE_T rowStart =  output->GetOutputter().GetCurrentPosition();
            char b = 0;
            char ___masking___[1];
            ___masking___[0] = 1;
            bool hasNull = false;
            if (row.m_Query.IsNull())
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
            if (!row.m_Query.IsNull())
            {
                output->Write(row.m_Query);
            }
            output->Write(row.m_DwellTime);
            output->Write(row.m_IId1);
            SIZE_T rowSize =  output->GetOutputter().GetCurrentPosition() - rowStart;
            auto rowLimit = ScopeEngine::Configuration::GetGlobal().GetMaxOnDiskRowSize();
            if (rowSize > rowLimit)
            {
                std::stringstream ss;
                ss << row << std::endl;
                throw RuntimeException(E_USER_ONDISKROW_TOO_BIG, {rowSize, rowLimit, ss.str()});
            }
        }
        static void Serialize(DummyOutputStream * output, const Process_3_Data0 & row)
        {
            SCOPE_ASSERT(false); 
        }
            static void SerializeKeyForSS(MemoryOutputStream* output, const Process_3_Data0 & row)
            {
                STRUCTURED_DATA_ASSERT(false); // there is no partition key in the schema
            }
    };



#if defined(COMPILE_NATIVE)
    template<> 
    class BinaryExtractPolicy<Join_5_Data0>
    {
    public:
        static constexpr int StreamIdRangeMax = -1;

        static bool Deserialize(BinaryInputStream * input, Join_5_Data0 & row)
        {
            try
            {
                char b = 0;
                input->Read(b);
                if (b==0)
                {
                    input->Read(row.m_AdId);
                    input->Read(row.m_IId);
                    input->Read(row.m_Impression);
                    input->Read(row.m_Query);
                    input->Read(row.m_DwellTime);
                }
                else
                {
                    char ___masking___[1];
                    ___masking___[0] = b;
                    input->Read(row.m_AdId);
                    input->Read(row.m_IId);
                    input->Read(row.m_Impression);
                    if ((___masking___[0] & 2 ) != 2)
                    {
                        input->Read(row.m_Query);
                    }
                    else
                    {
                        row.m_Query.SetNull();
                    }
                    input->Read(row.m_DwellTime);
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
    class BinaryOutputPolicy<Join_5_Data0>
    {
    public:
    
        static void SerializeHeader(BinaryOutputStream * output)
        {
            SCOPE_ASSERT(!"BinaryOutputPolicy::SerializeHeader method should not be invoked.");
        }
        
        __declspec(noinline) static void Serialize(BinaryOutputStream * output, Join_5_Data0 & row)
        {
            SIZE_T rowStart =  output->GetOutputter().GetCurrentPosition();
            char b = 0;
            char ___masking___[1];
            ___masking___[0] = 1;
            bool hasNull = false;
            if (row.m_Query.IsNull())
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
            output->Write(row.m_AdId);
            output->Write(row.m_IId);
            output->Write(row.m_Impression);
            if (!row.m_Query.IsNull())
            {
                output->Write(row.m_Query);
            }
            output->Write(row.m_DwellTime);
            SIZE_T rowSize =  output->GetOutputter().GetCurrentPosition() - rowStart;
            auto rowLimit = ScopeEngine::Configuration::GetGlobal().GetMaxOnDiskRowSize();
            if (rowSize > rowLimit)
            {
                std::stringstream ss;
                ss << row << std::endl;
                throw RuntimeException(E_USER_ONDISKROW_TOO_BIG, {rowSize, rowLimit, ss.str()});
            }
        }
        static void Serialize(DummyOutputStream * output, const Join_5_Data0 & row)
        {
            SCOPE_ASSERT(false); 
        }
            static void SerializeKeyForSS(MemoryOutputStream* output, const Join_5_Data0 & row)
            {
                STRUCTURED_DATA_ASSERT(false); // there is no partition key in the schema
            }
    };

#pragma region Schema Constructors


    INLINE Extract_0_Data0::Extract_0_Data0()
    {
        m_AdId = 0;
        m_IId = 0;
        m_Impression = 0;
    }
    INLINE Extract_0_Data0::Extract_0_Data0(const Extract_0_Data0 & c, IncrementalAllocator * alloc)
    {
        m_AdId = c.m_AdId;
        m_IId = c.m_IId;
        m_Impression = c.m_Impression;
    }



    INLINE Extract_2_Data0::Extract_2_Data0()
    {
        m_IId = 0;
        m_DwellTime = 0;
    }



    INLINE Process_3_Data0::Process_3_Data0()
    {
        m_DwellTime = 0;
        m_IId1 = 0;
    }
    INLINE Process_3_Data0::Process_3_Data0(const Process_3_Data0 & c, IncrementalAllocator * alloc) :
            m_Query(c.m_Query, alloc)
    {
        m_DwellTime = c.m_DwellTime;
        m_IId1 = c.m_IId1;
    }



    INLINE Join_5_Data0::Join_5_Data0()
    {
        m_AdId = 0;
        m_IId = 0;
        m_Impression = 0;
        m_DwellTime = 0;
    }
    INLINE Join_5_Data0::Join_5_Data0(const Join_5_Data0 & c, IncrementalAllocator * alloc) :
            m_Query(c.m_Query, alloc)
    {
        m_AdId = c.m_AdId;
        m_IId = c.m_IId;
        m_Impression = c.m_Impression;
        m_DwellTime = c.m_DwellTime;
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


extern "C" __declspec(dllexport) void __stdcall InitVertexNative(VertexExecutionInfo * vertexExecutionInfo)
{
#if defined(FORCEMANAGEDDATETIMESER)
    ScopeEngine::ScopeDateTime::ForceManagedSerialization = true;
#endif

    ErrorManager::GetGlobal()->EnableJSON();
    ErrorManager::GetGlobal()->EnableRowDump();
}

// Add broadcast vertex code
extern "C" __declspec(dllexport) void __stdcall SV_CopyThrough_execute(std::string * argv, int argc, InputFileInfo* inputs, int inputCnt, OutputFileInfo* outputs, int outputCnt, VertexExecutionInfo * vertexExecutionInfo)
{
    ScopeEngine::Configuration::Create(ET_Cosmos, GetCompilerSettings(), vertexExecutionInfo);
    SCOPE_ASSERT(inputCnt == 1 && outputCnt == 1);
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
            int m_IId;

            KeyStruct(Extract_0_Data0 & c) :
                m_IId(c.m_IId)
            {
            }

            KeyStruct(const Extract_0_Data0 & c, IncrementalAllocator * alloc) :
                m_IId(const_cast<Extract_0_Data0&>(c).m_IId)
            {
            }

            KeyStruct(KeyStruct & c) :
                m_IId(c.m_IId)
            {
            }

            KeyStruct(const KeyStruct & c, IncrementalAllocator * alloc) :
                m_IId(const_cast<KeyStruct&>(c).m_IId)
            {
            }

            KeyStruct() :
                m_IId(0)
            {
            }

            friend std::ostream& operator<<(std::ostream& os, const KeyStruct& row)
            {

                ScopeEngine::OutputRowContent(
                    std::string{ u8"IId:int" },
                    reinterpret_cast<const char*>(&row),
                    os);

                return os;
            }
        };

        typedef KeyStruct KeyType;

        static int Compare(Extract_0_Data0 & row, KeyType & key)
        {
            int r = 0;
            if ((r = ScopeTypeCompare(row.m_IId, key.m_IId)) != 0)
                return r;
            return r;
        }

        static int Compare(Extract_0_Data0 * n1, Extract_0_Data0 * n2)
        {
            int r = 0;
            if ((r = ScopeTypeCompare((*n1).m_IId, (*n2).m_IId)) != 0)
                return r;
            return r;
        }

        // Key function for MKQsort algorithm
        static __int64 Key(Extract_0_Data0 * p, int depth)
        {
            if (depth < 1)
            {
                // We only support interger number as MKQsort key for now
                return (__int64)((*p).m_IId);
            }

            --depth;

            return 0;
        }

        // End of Key function for MKQSort algorithm
        static bool EofKey(Extract_0_Data0 * p, int depth)
        {
            --depth;
            if (depth < 0)
                return false;
            return true;
        }
    };




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

                    input->Read(row.m_AdId);
                    input->Read(row.m_IId);
                    input->Read(row.m_Impression);
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
                            { input->CurrentLineNumber() - 1, 4, input->CurrentField() },
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
            static const std::array<const char*, 5> c_columnNames =
            {
                "AdId",
                "IId",
                "Impression",
                "IsClicked",
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



#if defined(COMPILE_NATIVE)
namespace ScopeGeneratedClasses
{
    extern "C" __declspec(dllexport) void __stdcall SV1_Extract_execute(std::string * argv, int argc, InputFileInfo* inputs, int inputCnt, OutputFileInfo* outputs, int outputCnt, VertexExecutionInfo * vertexExecutionInfo)
    {
#ifdef USE_SSE4_2
        ScopeEngine::CheckCpuSupportsInstructions();
#endif

        ScopeEngine::Configuration::Create(ET_Cosmos, GetCompilerSettings(), vertexExecutionInfo);
        SIZE_T x_inputBufSize, x_outputBufSize, x_inputVirtualMemoryLimit;
        int    x_inputBufCnt, x_outputBufCnt;
        
        MemoryManager::CalculateIOBufferSize(inputCnt, outputCnt, MemoryManager::x_vertexMemoryLimit, MemoryManager::x_vertexReserveMemory, x_inputBufSize, x_inputBufCnt, x_outputBufSize, x_outputBufCnt, x_inputVirtualMemoryLimit, false);

        constexpr bool IsNativeOnlyVertex = true;
        // If we have more than one input, we will random shuffle it
        if (inputCnt - 0 > 1)
        {
            ScopeRandom scopeRandom((int)vertexExecutionInfo->m_vertexId);
            auto lambda = [&scopeRandom](std::ptrdiff_t max) { return (scopeRandom.Next() % max + max) % max;}; // scopeRandom.Next() % max could be negative value
            random_shuffle(&inputs[0], inputs + inputCnt - 0, lambda ); 
            // move all empty inputs to the end of extractor array so we can always get metadata from the first input
            std::stable_partition(&inputs[0], inputs + inputCnt - 0, [](const InputFileInfo& input){ return input.length != 0; });
        }
        // Define extractor type and construct objects
        // 
        typedef Extractor<Extract_0_Data0, TextExtractPolicy<Extract_0_Data0, UID_Extract_0>, TextInputStream<TextInputStreamTraitsConst<'\t', '\0', '\0', false, false, Default, false, false, false, 0, CharFormat_uint16, false, false>, CosmosInput>> ExtractorType1_SV1_Extr;
        unique_ptr<unique_ptr<ExtractorType1_SV1_Extr>[]> extractor_0_array(new unique_ptr<ExtractorType1_SV1_Extr>[inputCnt - 0]);
        
        for (int i = 0; i < inputCnt; i++)
        {
            // 
            extractor_0_array[i - 0].reset(new ExtractorType1_SV1_Extr(inputs[i], false, x_inputBufSize, x_inputBufCnt, x_inputVirtualMemoryLimit, InputStreamParameters('\t', '\0', '\0', static_cast<const char*>(__nullptr), false, false, Default, false, false, 0, CharFormat_uint16), UID_Extract_0));
        }

    ExtractorType1_SV1_Extr ** extractor_0 = (ExtractorType1_SV1_Extr **)extractor_0_array.get();

        
        ULONG extractor_0_count = (ULONG) inputCnt - 0;
        // Merge streams N->1
        typedef ParallelUnionAll<ExtractorType1_SV1_Extr, Extract_0_Data0, IsNativeOnlyVertex> UnionAllType_Extract_0_Process_1_connector;
        unique_ptr<UnionAllType_Extract_0_Process_1_connector> unionall_Extract_0_Process_1_connector_ptr(new UnionAllType_Extract_0_Process_1_connector(extractor_0,extractor_0_count,12,419430400,UID_ParallelUnionAll_Extract_0));
        UnionAllType_Extract_0_Process_1_connector * unionall_Extract_0_Process_1_connector = unionall_Extract_0_Process_1_connector_ptr.get();
        ULONG unionall_Extract_0_Process_1_connector_count = 1;
        // Construct operator and initialize it.
        unique_ptr<OperatorDelegate<Extract_0_Data0>> delegate_unionall_Extract_0_Process_1_connector_ptr (new OperatorDelegate<Extract_0_Data0>(OperatorDelegate<Extract_0_Data0>::FromOperator(unionall_Extract_0_Process_1_connector)));
        OperatorDelegate<Extract_0_Data0> * delegate_unionall_Extract_0_Process_1_connector = delegate_unionall_Extract_0_Process_1_connector_ptr.get();
        ULONG delegate_unionall_Extract_0_Process_1_connector_count = 1;
        // Define sorter type
        typedef Sorter<Extract_0_Data0> SorterType_Process_1;
        // Construct operator and initialize it.
        unique_ptr<SorterType_Process_1> sorter_Process_1_ptr (new SorterType_Process_1(delegate_unionall_Extract_0_Process_1_connector, &StdSort<Extract_0_Data0>::Sort<KeyComparePolicy<Extract_0_Data0, UID_Process_1>, (sizeof(Extract_0_Data0)<=CACHELINE_SIZE)>, ScopeLoserTreeDelegate<Extract_0_Data0>::CreateDelegate<UID_Process_1>(), false, 4767167952 /*memoryQuota*/, UID_Process_1));
        SorterType_Process_1 * sorter_Process_1 = sorter_Process_1_ptr.get();
        ULONG sorter_Process_1_count = 1;
        // Define outputter type
        typedef Outputter<SorterType_Process_1, Extract_0_Data0, BinaryOutputPolicy<Extract_0_Data0>, BinaryOutputStream, false> OutputterType2_SV1_Extr;
        // Construct operator and initialize it
        unique_ptr<OutputterType2_SV1_Extr> outputter_SV1_Extract_out0_ptr(new OutputterType2_SV1_Extr(sorter_Process_1, outputs[0].outputFileName, false, x_outputBufSize, x_outputBufCnt, UID_SV1_Extract_out0, false));
        OutputterType2_SV1_Extr * outputter_SV1_Extract_out0 = outputter_SV1_Extract_out0_ptr.get();
        // Create timer to automatically dump statistics available at the time, when approaching max permitted time for vertex execution
        auto dumpStatsTimer{ ScopeEngine::CreateDumpStatsTimer(vertexExecutionInfo->m_updateStatusThresholdToAutoDumpStatistics, *outputter_SV1_Extract_out0) };

        try
        {
            // Init operator chain
            outputter_SV1_Extract_out0->InitOperatorPipeline();

            // Execute the whole vertex by calling the GetNextRow on top operator
            Extract_0_Data0 row;
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
#pragma region SV2_Extract
#if defined(COMPILE_SV2_EXTRACT) || defined(COMPILE_ALL_VERTICES)


    template<> 
    class KeyComparePolicy<Process_3_Data0,UID_Process_4>
    {
    public:
        struct KeyStruct
        {
            int m_IId1;

            KeyStruct(Process_3_Data0 & c) :
                m_IId1(c.m_IId1)
            {
            }

            KeyStruct(const Process_3_Data0 & c, IncrementalAllocator * alloc) :
                m_IId1(const_cast<Process_3_Data0&>(c).m_IId1)
            {
            }

            KeyStruct(KeyStruct & c) :
                m_IId1(c.m_IId1)
            {
            }

            KeyStruct(const KeyStruct & c, IncrementalAllocator * alloc) :
                m_IId1(const_cast<KeyStruct&>(c).m_IId1)
            {
            }

            KeyStruct() :
                m_IId1(0)
            {
            }

            friend std::ostream& operator<<(std::ostream& os, const KeyStruct& row)
            {

                ScopeEngine::OutputRowContent(
                    std::string{ u8"IId1:int" },
                    reinterpret_cast<const char*>(&row),
                    os);

                return os;
            }
        };

        typedef KeyStruct KeyType;

        static int Compare(Process_3_Data0 & row, KeyType & key)
        {
            int r = 0;
            if ((r = ScopeTypeCompare(row.m_IId1, key.m_IId1)) != 0)
                return r;
            return r;
        }

        static int Compare(Process_3_Data0 * n1, Process_3_Data0 * n2)
        {
            int r = 0;
            if ((r = ScopeTypeCompare((*n1).m_IId1, (*n2).m_IId1)) != 0)
                return r;
            return r;
        }

        // Key function for MKQsort algorithm
        static __int64 Key(Process_3_Data0 * p, int depth)
        {
            if (depth < 1)
            {
                // We only support interger number as MKQsort key for now
                return (__int64)((*p).m_IId1);
            }

            --depth;

            return 0;
        }

        // End of Key function for MKQSort algorithm
        static bool EofKey(Process_3_Data0 * p, int depth)
        {
            --depth;
            if (depth < 0)
                return false;
            return true;
        }
    };



    static const char * StringTable_Process_3 [] =
    {
        "DwellTime >= 120 && DwellTime <= 300 || Market == \"en-gb\"",
        "Query",
        "DwellTime",
        "IId",
        "\"*** After Last Expression ***\"",
    };

    template<>
    class RowTransformPolicy<Extract_2_Data0, Process_3_Data0, UID_Process_3>
    {
    public:
        static bool FilterTransformRow(Extract_2_Data0 & input, Process_3_Data0 & output, IncrementalAllocator * alloc)
        {
            int exceptionIndex = 0;
            try
            {
                if (input.m_DwellTime >= 120 && input.m_DwellTime <= 300 || input.m_Market == staticconstant_0)
                {

                    exceptionIndex++;
                    output.m_Query = input.m_Query;
                    exceptionIndex++;
                    output.m_DwellTime = input.m_DwellTime;
                    exceptionIndex++;
                    output.m_IId1 = input.m_IId;
                    exceptionIndex++;
                    return true;
                }
            
                return false;
        }
        catch(...)
        {
            std::throw_with_nested(RuntimeException(E_USER_EXPRESSION_ERROR, StringTable_Process_3[exceptionIndex]));
        }
        }
            static FString staticconstant_0;

        #pragma warning(push)
        #pragma warning(disable: 4100) // 'alloc': unreferenced formal parameter
        static void InitializeStatics(IncrementalAllocator * alloc)
        {
        #pragma warning(pop)

            staticconstant_0 = FString("en-gb", 5);
        }

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
    class TextExtractPolicy<Extract_2_Data0, UID_Extract_2>
    {
    public:
        static constexpr int StreamIdRangeMax = -1;

        static bool Deserialize(TextInputStream<TextInputStreamTraitsConst<'\t', '\0', '\0', false, false, Default, false, false, false, 0, CharFormat_uint16, false, false>, CosmosInput> * input, Extract_2_Data0 & row)
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
                    input->Read(row.m_Market);
                    input->Read(row.m_Query);
                    input->Read(row.m_DwellTime);
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
                            { input->CurrentLineNumber() - 1, 8, input->CurrentField() },
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
            static const std::array<const char*, 9> c_columnNames =
            {
                "IId",
                "UId",
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


#if defined(COMPILE_MANAGED)
#endif // defined(COMPILE_MANAGED)



#if defined(COMPILE_NATIVE)
namespace ScopeGeneratedClasses
{
    extern "C" __declspec(dllexport) void __stdcall SV2_Extract_execute(std::string * argv, int argc, InputFileInfo* inputs, int inputCnt, OutputFileInfo* outputs, int outputCnt, VertexExecutionInfo * vertexExecutionInfo)
    {
#ifdef USE_SSE4_2
        ScopeEngine::CheckCpuSupportsInstructions();
#endif

        ScopeEngine::Configuration::Create(ET_Cosmos, GetCompilerSettings(), vertexExecutionInfo);
        SIZE_T x_inputBufSize, x_outputBufSize, x_inputVirtualMemoryLimit;
        int    x_inputBufCnt, x_outputBufCnt;
        
        MemoryManager::CalculateIOBufferSize(inputCnt, outputCnt, MemoryManager::x_vertexMemoryLimit, MemoryManager::x_vertexReserveMemory, x_inputBufSize, x_inputBufCnt, x_outputBufSize, x_outputBufCnt, x_inputVirtualMemoryLimit, false);

        constexpr bool IsNativeOnlyVertex = true;
        // If we have more than one input, we will random shuffle it
        if (inputCnt - 0 > 1)
        {
            ScopeRandom scopeRandom((int)vertexExecutionInfo->m_vertexId);
            auto lambda = [&scopeRandom](std::ptrdiff_t max) { return (scopeRandom.Next() % max + max) % max;}; // scopeRandom.Next() % max could be negative value
            random_shuffle(&inputs[0], inputs + inputCnt - 0, lambda ); 
            // move all empty inputs to the end of extractor array so we can always get metadata from the first input
            std::stable_partition(&inputs[0], inputs + inputCnt - 0, [](const InputFileInfo& input){ return input.length != 0; });
        }
        // Define extractor type and construct objects
        // 
        typedef Extractor<Extract_2_Data0, TextExtractPolicy<Extract_2_Data0, UID_Extract_2>, TextInputStream<TextInputStreamTraitsConst<'\t', '\0', '\0', false, false, Default, false, false, false, 0, CharFormat_uint16, false, false>, CosmosInput>> ExtractorType1_SV2_Extr;
        unique_ptr<unique_ptr<ExtractorType1_SV2_Extr>[]> extractor_0_array(new unique_ptr<ExtractorType1_SV2_Extr>[inputCnt - 0]);
        
        for (int i = 0; i < inputCnt; i++)
        {
            // 
            extractor_0_array[i - 0].reset(new ExtractorType1_SV2_Extr(inputs[i], false, x_inputBufSize, x_inputBufCnt, x_inputVirtualMemoryLimit, InputStreamParameters('\t', '\0', '\0', static_cast<const char*>(__nullptr), false, false, Default, false, false, 0, CharFormat_uint16), UID_Extract_2));
        }

    ExtractorType1_SV2_Extr ** extractor_0 = (ExtractorType1_SV2_Extr **)extractor_0_array.get();

        
        ULONG extractor_0_count = (ULONG) inputCnt - 0;
        // Define the type of the operator
        typedef FilterTransformer<ExtractorType1_SV2_Extr, Extract_2_Data0, Process_3_Data0, UID_Process_3> FilterTransformerType_Process_3;
        // Allocate memory for the operator array
        unique_ptr<unique_ptr<FilterTransformerType_Process_3>[]> filterTransformer_Process_3_array(new unique_ptr<FilterTransformerType_Process_3>[extractor_0_count]);
        
        // Construct operator objects
        for(ULONG i = 0; i < extractor_0_count; i++)
        {
            filterTransformer_Process_3_array[i].reset(new FilterTransformerType_Process_3(extractor_0[i], UID_Process_3)); 
        }
        
        FilterTransformerType_Process_3 ** filterTransformer_Process_3 = (FilterTransformerType_Process_3 **)filterTransformer_Process_3_array.get();
        ULONG filterTransformer_Process_3_count = extractor_0_count;
        // Merge streams N->1
        typedef ParallelUnionAll<FilterTransformerType_Process_3, Process_3_Data0, IsNativeOnlyVertex> UnionAllType_Process_3_Process_4_connector;
        unique_ptr<UnionAllType_Process_3_Process_4_connector> unionall_Process_3_Process_4_connector_ptr(new UnionAllType_Process_3_Process_4_connector(filterTransformer_Process_3,filterTransformer_Process_3_count,12,419430400,UID_ParallelUnionAll_Process_3));
        UnionAllType_Process_3_Process_4_connector * unionall_Process_3_Process_4_connector = unionall_Process_3_Process_4_connector_ptr.get();
        ULONG unionall_Process_3_Process_4_connector_count = 1;
        // Construct operator and initialize it.
        unique_ptr<OperatorDelegate<Process_3_Data0>> delegate_unionall_Process_3_Process_4_connector_ptr (new OperatorDelegate<Process_3_Data0>(OperatorDelegate<Process_3_Data0>::FromOperator(unionall_Process_3_Process_4_connector)));
        OperatorDelegate<Process_3_Data0> * delegate_unionall_Process_3_Process_4_connector = delegate_unionall_Process_3_Process_4_connector_ptr.get();
        ULONG delegate_unionall_Process_3_Process_4_connector_count = 1;
        // Define sorter type
        typedef Sorter<Process_3_Data0> SorterType_Process_4;
        // Construct operator and initialize it.
        unique_ptr<SorterType_Process_4> sorter_Process_4_ptr (new SorterType_Process_4(delegate_unionall_Process_3_Process_4_connector, &StdSort<Process_3_Data0>::Sort<KeyComparePolicy<Process_3_Data0, UID_Process_4>, (sizeof(Process_3_Data0)<=CACHELINE_SIZE)>, ScopeLoserTreeDelegate<Process_3_Data0>::CreateDelegate<UID_Process_4>(), false, 3718591808 /*memoryQuota*/, UID_Process_4));
        SorterType_Process_4 * sorter_Process_4 = sorter_Process_4_ptr.get();
        ULONG sorter_Process_4_count = 1;
        // Define outputter type
        typedef Outputter<SorterType_Process_4, Process_3_Data0, BinaryOutputPolicy<Process_3_Data0>, BinaryOutputStream, false> OutputterType2_SV2_Extr;
        // Construct operator and initialize it
        unique_ptr<OutputterType2_SV2_Extr> outputter_SV2_Extract_out0_ptr(new OutputterType2_SV2_Extr(sorter_Process_4, outputs[0].outputFileName, false, x_outputBufSize, x_outputBufCnt, UID_SV2_Extract_out0, false));
        OutputterType2_SV2_Extr * outputter_SV2_Extract_out0 = outputter_SV2_Extract_out0_ptr.get();
        // Create timer to automatically dump statistics available at the time, when approaching max permitted time for vertex execution
        auto dumpStatsTimer{ ScopeEngine::CreateDumpStatsTimer(vertexExecutionInfo->m_updateStatusThresholdToAutoDumpStatistics, *outputter_SV2_Extract_out0) };

        try
        {
            // Init operator chain
            outputter_SV2_Extract_out0->InitOperatorPipeline();

            // Execute the whole vertex by calling the GetNextRow on top operator
            Process_3_Data0 row;
            outputter_SV2_Extract_out0->GetNextRow(row);

            // Close operator chain
            outputter_SV2_Extract_out0->Close();
        }
        catch (const ExceptionWithStack& ex)
        {
            std::cout << "Caught exception: " << ex.what() << std::endl << ex.GetStack() << std::endl;
            throw;
        }


        MemoryManager::GetGlobal()->WriteRuntimeStats(vertexExecutionInfo->m_statsRoot);
        outputter_SV2_Extract_out0->WriteRuntimeStats(vertexExecutionInfo->m_statsRoot);
    }
}
#endif // defined(COMPILE_NATIVE)

#if defined(COMPILE_MANAGED)
#endif // defined(COMPILE_MANAGED)
#if defined(COMPILE_NATIVE)
#endif // defined(COMPILE_NATIVE)

#endif
#pragma endregion SV2_Extract
#pragma region SV3_Combine
#if defined(COMPILE_SV3_COMBINE) || defined(COMPILE_ALL_VERTICES)


    template<> 
    class KeyComparePolicy<Join_5_Data0,UID_Process_6>
    {
    public:
        struct KeyStruct
        {
            int m_DwellTime;

            KeyStruct(Join_5_Data0 & c) :
                m_DwellTime(c.m_DwellTime)
            {
            }

            KeyStruct(const Join_5_Data0 & c, IncrementalAllocator * alloc) :
                m_DwellTime(const_cast<Join_5_Data0&>(c).m_DwellTime)
            {
            }

            KeyStruct(KeyStruct & c) :
                m_DwellTime(c.m_DwellTime)
            {
            }

            KeyStruct(const KeyStruct & c, IncrementalAllocator * alloc) :
                m_DwellTime(const_cast<KeyStruct&>(c).m_DwellTime)
            {
            }

            KeyStruct() :
                m_DwellTime(0)
            {
            }

            friend std::ostream& operator<<(std::ostream& os, const KeyStruct& row)
            {

                ScopeEngine::OutputRowContent(
                    std::string{ u8"DwellTime:int" },
                    reinterpret_cast<const char*>(&row),
                    os);

                return os;
            }
        };

        typedef KeyStruct KeyType;

        static int Compare(Join_5_Data0 & row, KeyType & key)
        {
            int r = 0;
            if ((r = ScopeTypeCompare(row.m_DwellTime, key.m_DwellTime)) != 0)
                return -r;
            return r;
        }

        static int Compare(Join_5_Data0 * n1, Join_5_Data0 * n2)
        {
            int r = 0;
            if ((r = ScopeTypeCompare((*n1).m_DwellTime, (*n2).m_DwellTime)) != 0)
                return -r;
            return r;
        }

        // Key function for MKQsort algorithm
        static __int64 Key(Join_5_Data0 * p, int depth)
        {
            if (depth < 1)
            {
                // We only support interger number as MKQsort key for now
                return -(__int64)((*p).m_DwellTime);
            }

            --depth;

            return 0;
        }

        // End of Key function for MKQSort algorithm
        static bool EofKey(Join_5_Data0 * p, int depth)
        {
            --depth;
            if (depth < 0)
                return false;
            return true;
        }
    };




    template<> 
    class KeyComparePolicy<Extract_0_Data0,UID_Join_5_0>
    {
    public:
        struct KeyStruct
        {
            int m_IId;

            KeyStruct(Extract_0_Data0 & c) :
                m_IId(c.m_IId)
            {
            }

            KeyStruct(const Extract_0_Data0 & c, IncrementalAllocator * alloc) :
                m_IId(const_cast<Extract_0_Data0&>(c).m_IId)
            {
            }

            KeyStruct(KeyStruct & c) :
                m_IId(c.m_IId)
            {
            }

            KeyStruct(const KeyStruct & c, IncrementalAllocator * alloc) :
                m_IId(const_cast<KeyStruct&>(c).m_IId)
            {
            }

            KeyStruct() :
                m_IId(0)
            {
            }

            friend std::ostream& operator<<(std::ostream& os, const KeyStruct& row)
            {

                ScopeEngine::OutputRowContent(
                    std::string{ u8"IId:int" },
                    reinterpret_cast<const char*>(&row),
                    os);

                return os;
            }
        };

        typedef KeyStruct KeyType;

        static int Compare(Extract_0_Data0 & row, KeyType & key)
        {
            int r = 0;
            if ((r = ScopeTypeCompare(row.m_IId, key.m_IId)) != 0)
                return r;
            return r;
        }

        static int Compare(Extract_0_Data0 * n1, Extract_0_Data0 * n2)
        {
            int r = 0;
            if ((r = ScopeTypeCompare((*n1).m_IId, (*n2).m_IId)) != 0)
                return r;
            return r;
        }

    };




    template<> 
    class KeyComparePolicy<Process_3_Data0,UID_Join_5_1>
    {
    public:
        struct KeyStruct
        {
            int m_IId1;

            KeyStruct(Process_3_Data0 & c) :
                m_IId1(c.m_IId1)
            {
            }

            KeyStruct(const Process_3_Data0 & c, IncrementalAllocator * alloc) :
                m_IId1(const_cast<Process_3_Data0&>(c).m_IId1)
            {
            }

            KeyStruct(KeyStruct & c) :
                m_IId1(c.m_IId1)
            {
            }

            KeyStruct(const KeyStruct & c, IncrementalAllocator * alloc) :
                m_IId1(const_cast<KeyStruct&>(c).m_IId1)
            {
            }

            KeyStruct() :
                m_IId1(0)
            {
            }

            friend std::ostream& operator<<(std::ostream& os, const KeyStruct& row)
            {

                ScopeEngine::OutputRowContent(
                    std::string{ u8"IId1:int" },
                    reinterpret_cast<const char*>(&row),
                    os);

                return os;
            }
        };

        typedef KeyStruct KeyType;

        static int Compare(Process_3_Data0 & row, KeyType & key)
        {
            int r = 0;
            if ((r = ScopeTypeCompare(row.m_IId1, key.m_IId1)) != 0)
                return r;
            return r;
        }

        static int Compare(Process_3_Data0 * n1, Process_3_Data0 * n2)
        {
            int r = 0;
            if ((r = ScopeTypeCompare((*n1).m_IId1, (*n2).m_IId1)) != 0)
                return r;
            return r;
        }

    };



#if defined(COMPILE_NATIVE)
    template<>
    class RowHashPolicy<Extract_0_Data0,UID_Join_5>
    {
    public:
        static __int64 Hash(Extract_0_Data0* row)
        {
            ScopeRowHasher hasher;
            hasher.HashColumnValue<int> ((*row).m_IId);
            return hasher.ComputeHashCode();
        }

        INLINE static int Bucket(Extract_0_Data0* row, int bucketCount)
        {
            return ScopeRowHasher::ComputeBucket(Hash(row), bucketCount);
        }
    };

#endif // defined(COMPILE_NATIVE)


#if defined(COMPILE_MANAGED)
#endif // defined(COMPILE_MANAGED)


#if defined(COMPILE_NATIVE)
    template<> 
    class CombinerPolicy<UID_Join_5> 
    {
    public:
        typedef KeyComparePolicy<Extract_0_Data0,UID_Join_5_0> LeftKeyPolicy;
        typedef KeyComparePolicy<Process_3_Data0,UID_Join_5_1> RightKeyPolicy;

        static constexpr unsigned MaxPerKeyCrossSizeLimit = 0;

        static LONGLONG JoinerMemQuota()
        {
            return 1073741824ULL;
        }

        // compare key from left and right schema object
        static int Compare(const Extract_0_Data0 * left, const Process_3_Data0 * right)
        {
            int r = 0;
            Extract_0_Data0 * n1 = const_cast<Extract_0_Data0 *>(left);
            Process_3_Data0 * n2 = const_cast<Process_3_Data0 *>(right);

            if ((r = ScopeTypeCompare((*n1).m_IId, (*n2).m_IId1)) != 0)
                return r;
            
            // Everything matches
            return 0;
        }

        static void CopyRow(Extract_0_Data0 * left, Process_3_Data0 * right, Join_5_Data0 * out)
        {
                (*out).m_AdId = (*left).m_AdId;
                (*out).m_IId = (*left).m_IId;
                (*out).m_Impression = (*left).m_Impression;
                (*out).m_Query = (*right).m_Query;
                (*out).m_DwellTime = (*right).m_DwellTime;
        }

        static void CopyLeftRow(Extract_0_Data0 * left, Join_5_Data0 * out)
        {
            (*out).m_AdId = (*left).m_AdId;
            (*out).m_IId = (*left).m_IId;
            (*out).m_Impression = (*left).m_Impression;
        }

        static void NullifyRightSide(Join_5_Data0 * out)
        {
            (*out).m_Query.SetNull();
        }

        static void CopyRightRow(Process_3_Data0 * right, Join_5_Data0 * out)
        {
            (*out).m_Query = (*right).m_Query;
            (*out).m_DwellTime = (*right).m_DwellTime;
        }

        static void NullifyLeftSide(Join_5_Data0 * out)
        {
        }
    };
#endif // defined(COMPILE_NATIVE)




#if defined(COMPILE_MANAGED)
#endif // defined(COMPILE_MANAGED)


    template<>
    class RowTransformPolicy<Join_5_Data0, Join_5_Data0, UID_Process_7>
    {
    public:
        static bool FilterTransformRow(Join_5_Data0 & input, Join_5_Data0 & output, IncrementalAllocator * alloc)
        {
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


    template<>
    class RowTransformPolicy<Join_5_Data0, Join_5_Data0, UID_Process_8>
    {
    public:
        static bool FilterTransformRow(Join_5_Data0 & input, Join_5_Data0 & output, IncrementalAllocator * alloc)
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
    struct ManagedUDO<UID_Process_8>
    {
        typedef ScopeRuntime::Processor UDO;

        ManagedUDO(std::string * argv, int argc)
        {
            try
            {
                m_udo.reset(___Scope_Generated_Classes___::__OperatorFactory__::Create_Process_8());
                m_args.reset(gcnew Generic::List<String^>(ConvertArgsToArray(std::wstring{})));
            }
            catch (Exception ^ex)
            {
                ScopeEngineManaged::ExceptionHelper::WrapException(___Scope_Generated_Classes___::__OperatorFactory__::Name_Process_8, "Constructor", ex);
                throw;
            }
            auto curRow = gcnew ___Scope_Generated_Classes___::Row_AdId_Integer_IId_Integer_Impression_Integer_Query_String_DwellTime_Integer();
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
    class InteropToManagedRowPolicy<Join_5_Data0, UID_Process_8>
    {
    public:
        static void Marshal(Join_5_Data0& nativeRow, ScopeRuntime::Row^% managedRow, InteropAllocator * alloc)
        {
            alloc->CopyToManagedColumn(nativeRow.m_AdId, managedRow[0], 0);
            alloc->CopyToManagedColumn(nativeRow.m_IId, managedRow[1], 1);
            alloc->CopyToManagedColumn(nativeRow.m_Impression, managedRow[2], 2);
            alloc->CopyToManagedColumn(nativeRow.m_Query, managedRow[3], 3);
            alloc->CopyToManagedColumn(nativeRow.m_DwellTime, managedRow[4], 4);
        }
    };
    template<>
    class InteropToNativeRowPolicy<Join_5_Data0, UID_Process_8>
    {
    public:
        static void Marshal(ScopeRuntime::Row^ managedRow, Join_5_Data0& nativeRow, IncrementalAllocator* alloc)
        {
            ScopeEngine::ScopeManagedInterop::CopyToNativeColumn(nativeRow.m_AdId, managedRow[0]->Integer, alloc);
            ScopeEngine::ScopeManagedInterop::CopyToNativeColumn(nativeRow.m_IId, managedRow[1]->Integer, alloc);
            ScopeEngine::ScopeManagedInterop::CopyToNativeColumn(nativeRow.m_Impression, managedRow[2]->Integer, alloc);
            ScopeEngine::ScopeManagedInterop::CopyToNativeColumn(nativeRow.m_Query, managedRow[3]->Binary, alloc);
            ScopeEngine::ScopeManagedInterop::CopyToNativeColumn(nativeRow.m_DwellTime, managedRow[4]->Integer, alloc);
        }
    };
#endif // defined(COMPILE_MANAGED)


    template<> 
    class TextOutputPolicy<Join_5_Data0, UID_SV3_Combine_out0>
    {
    public:

        static void Serialize(TextOutputStream<TextOutputStreamTraitsConst<'\t', '\0', false, true, false, false, false, Default, false, CharFormat_uint16>, CosmosOutput> * output, Join_5_Data0 & row)
        {
            output->Write<int,false>(row.m_AdId);
            output->WriteDelimiter();
            output->Write<int,false>(row.m_IId);
            output->WriteDelimiter();
            output->Write<int,false>(row.m_Impression);
            output->WriteDelimiter();
            if (!row.m_Query.IsNull())
            {
                output->Write<FString,false>(row.m_Query);
            }
            output->WriteDelimiter();
            output->Write<int,false>(row.m_DwellTime);
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
namespace ScopeGeneratedClasses
{
    extern "C" __declspec(dllexport) void __stdcall SV3_Combine_execute(std::string * argv, int argc, InputFileInfo* inputs, int inputCnt, OutputFileInfo* outputs, int outputCnt, VertexExecutionInfo * vertexExecutionInfo)
    {
#ifdef USE_SSE4_2
        ScopeEngine::CheckCpuSupportsInstructions();
#endif

        ScopeEngine::Configuration::Create(ET_Cosmos, GetCompilerSettings(), vertexExecutionInfo);
        SIZE_T x_inputBufSize, x_outputBufSize, x_inputVirtualMemoryLimit;
        int    x_inputBufCnt, x_outputBufCnt;
        
        MemoryManager::CalculateIOBufferSize(inputCnt, outputCnt, MemoryManager::x_vertexMemoryLimit, MemoryManager::x_vertexReserveMemory, x_inputBufSize, x_inputBufCnt, x_outputBufSize, x_outputBufCnt, x_inputVirtualMemoryLimit, false);

        constexpr bool IsNativeOnlyVertex = false;
        // Define extractor type and construct object
        typedef Extractor<Extract_0_Data0, BinaryExtractPolicy<Extract_0_Data0>, BinaryInputStream> ExtractorType1_SV3_Cmbn;        
        unique_ptr<ExtractorType1_SV3_Cmbn> extractor_0_ptr= make_unique<ExtractorType1_SV3_Cmbn>(inputs[0], false, x_inputBufSize, x_inputBufCnt, x_inputVirtualMemoryLimit, UID_SV1_Extract_out0);
        ExtractorType1_SV3_Cmbn * extractor_0 = extractor_0_ptr.get();
        ULONG extractor_0_count = 1;
        // Define extractor type and construct object
        typedef Extractor<Process_3_Data0, BinaryExtractPolicy<Process_3_Data0>, BinaryInputStream> ExtractorType2_SV3_Cmbn;        
        unique_ptr<ExtractorType2_SV3_Cmbn> extractor_1_ptr= make_unique<ExtractorType2_SV3_Cmbn>(inputs[1], false, x_inputBufSize, x_inputBufCnt, x_inputVirtualMemoryLimit, UID_SV2_Extract_out0);
        ExtractorType2_SV3_Cmbn * extractor_1 = extractor_1_ptr.get();
        ULONG extractor_1_count = 1;

        // Define the combiner operator
        typedef NativeCombinerWrapper<ExtractorType1_SV3_Cmbn, Extract_0_Data0, ExtractorType2_SV3_Cmbn, Process_3_Data0, Join_5_Data0, InnerJoiner, UID_Join_5> CombinerType_Join_5;
        unique_ptr<CombinerType_Join_5> combiner_Join_5_ptr;
        combiner_Join_5_ptr.reset(new CombinerType_Join_5(extractor_0, extractor_1, UID_Join_5, 0, false, nullptr));
 
        CombinerType_Join_5 * combiner_Join_5 = combiner_Join_5_ptr.get();
        ULONG combiner_Join_5_count = 1;
        // Construct operator and initialize it.
        unique_ptr<OperatorDelegate<Join_5_Data0>> delegate_combiner_Join_5_ptr (new OperatorDelegate<Join_5_Data0>(OperatorDelegate<Join_5_Data0>::FromOperator(combiner_Join_5)));
        OperatorDelegate<Join_5_Data0> * delegate_combiner_Join_5 = delegate_combiner_Join_5_ptr.get();
        ULONG delegate_combiner_Join_5_count = 1;
        // Define sorter type
        typedef Sorter<Join_5_Data0> SorterType_Process_6;
        // Construct operator and initialize it.
        unique_ptr<SorterType_Process_6> sorter_Process_6_ptr (new SorterType_Process_6(delegate_combiner_Join_5, &StdSort<Join_5_Data0>::Sort<KeyComparePolicy<Join_5_Data0, UID_Process_6>, (sizeof(Join_5_Data0)<=CACHELINE_SIZE)>, ScopeLoserTreeDelegate<Join_5_Data0>::CreateDelegate<UID_Process_6>(), false, 2147483648 /*memoryQuota*/, UID_Process_6));
        SorterType_Process_6 * sorter_Process_6 = sorter_Process_6_ptr.get();
        ULONG sorter_Process_6_count = 1;
        // Define the type of the operator
        typedef Topper<SorterType_Process_6, Join_5_Data0, UID_Process_7> TopperType_Process_7;
        // Construct operator and initialize it.
        unique_ptr<TopperType_Process_7> topper_Process_7_ptr (new TopperType_Process_7(sorter_Process_6, 100ull, UID_Process_7));
        TopperType_Process_7 * topper_Process_7 = topper_Process_7_ptr.get();
        ULONG topper_Process_7_count = 1;
        // Construct operator and initialize it.
        unique_ptr<OperatorDelegate<Join_5_Data0>> delegate_topper_Process_7_ptr (new OperatorDelegate<Join_5_Data0>(OperatorDelegate<Join_5_Data0>::FromOperator(topper_Process_7)));
        OperatorDelegate<Join_5_Data0> * delegate_topper_Process_7 = delegate_topper_Process_7_ptr.get();
        ULONG delegate_topper_Process_7_count = 1;
        // Define the type of the operator
        typedef ScopeProcessor<Join_5_Data0, Join_5_Data0> ProcessorType_Process_8;
        // Construct operator and initialize it.
        unique_ptr<ProcessorType_Process_8> processor_Process_8_ptr (new ProcessorType_Process_8(ScopeProcessorManagedFactory::Make<Join_5_Data0,Join_5_Data0,UID_Process_8>(delegate_topper_Process_7), delegate_topper_Process_7, UID_Process_8));
        ProcessorType_Process_8 * processor_Process_8 = processor_Process_8_ptr.get();
        ULONG processor_Process_8_count = 1;
        // Define outputter type
        typedef Outputter<ProcessorType_Process_8, Join_5_Data0, TextOutputPolicy<Join_5_Data0, UID_SV3_Combine_out0>, TextOutputStream<TextOutputStreamTraitsConst<'\t', '\0', false, true, false, false, false, Default, false, CharFormat_uint16>, CosmosOutput>, false> OutputterType3_SV3_Cmbn;
        // Construct operator and initialize it
        unique_ptr<OutputterType3_SV3_Cmbn> outputter_SV3_Combine_out0_ptr(new OutputterType3_SV3_Cmbn(processor_Process_8, outputs[0].outputFileName, false, x_outputBufSize, x_outputBufCnt, OutputStreamParameters('\t', "\r\n", '\0', static_cast<const char*>(__nullptr), false, true, false, false, NULL, Default, false, CharFormat_uint16), UID_SV3_Combine_out0));
        OutputterType3_SV3_Cmbn * outputter_SV3_Combine_out0 = outputter_SV3_Combine_out0_ptr.get();
        // Create timer to automatically dump statistics available at the time, when approaching max permitted time for vertex execution
        auto dumpStatsTimer{ ScopeEngine::CreateDumpStatsTimer(vertexExecutionInfo->m_updateStatusThresholdToAutoDumpStatistics, *outputter_SV3_Combine_out0) };

        try
        {
            // Init operator chain
            outputter_SV3_Combine_out0->InitOperatorPipeline();

            // Execute the whole vertex by calling the GetNextRow on top operator
            Join_5_Data0 row;
            outputter_SV3_Combine_out0->GetNextRow(row);

            // Close operator chain
            outputter_SV3_Combine_out0->Close();
        }
        catch (const ExceptionWithStack& ex)
        {
            std::cout << "Caught exception: " << ex.what() << std::endl << ex.GetStack() << std::endl;
            throw;
        }


        MemoryManager::GetGlobal()->WriteRuntimeStats(vertexExecutionInfo->m_statsRoot);
        outputter_SV3_Combine_out0->WriteRuntimeStats(vertexExecutionInfo->m_statsRoot);
    }
}
#endif // defined(COMPILE_NATIVE)

#if defined(COMPILE_MANAGED)
template ScopeProcessorManaged<Join_5_Data0, Join_5_Data0> * ScopeEngine::ScopeProcessorManagedFactory::Make<Join_5_Data0, Join_5_Data0, UID_Process_8>(OperatorDelegate<Join_5_Data0>*);
#endif // defined(COMPILE_MANAGED)
#if defined(COMPILE_NATIVE)
#endif // defined(COMPILE_NATIVE)

#endif
#pragma endregion SV3_Combine
#if defined(COMPILE_SHARED_DATA) || defined(COMPILE_ALL_VERTICES)
#if defined(COMPILE_NATIVE)
#endif // COMPILE_NATIVE
#endif //#if defined(COMPILE_SHARED_DATA) || defined(COMPILE_ALL_VERTICES)
#if defined(COMPILE_SV1_EXTRACT) || defined(COMPILE_ALL_VERTICES)
#if defined(COMPILE_NATIVE)


#endif // COMPILE_NATIVE
#endif //#if defined(COMPILE_SV1_EXTRACT) || defined(COMPILE_ALL_VERTICES)
#if defined(COMPILE_SV2_EXTRACT) || defined(COMPILE_ALL_VERTICES)
#if defined(COMPILE_NATIVE)


#pragma warning(push)
#pragma warning(disable:4592)
FString RowTransformPolicy<Extract_2_Data0, Process_3_Data0, UID_Process_3>::staticconstant_0;
#pragma warning(pop)


#endif // COMPILE_NATIVE
#endif //#if defined(COMPILE_SV2_EXTRACT) || defined(COMPILE_ALL_VERTICES)
#if defined(COMPILE_SV3_COMBINE) || defined(COMPILE_ALL_VERTICES)
#if defined(COMPILE_NATIVE)


#endif // COMPILE_NATIVE
#endif //#if defined(COMPILE_SV3_COMBINE) || defined(COMPILE_ALL_VERTICES)
// Empty footer
