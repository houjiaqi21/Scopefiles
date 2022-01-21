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
    UID_Split_1 = 3,
    UID_SV1_Extract_Split_out0 = 4,
    UID_SV1_Extract_Split_out1 = 5,
    UID_SV1_Extract_Split_out2 = 6,
    UID_MetadataAggregate_2 = 7,
    UID_MetadataAggregate_2_Data0 = 8,
    UID_SStreamMetadataOutput_3 = 9,
    UID_SV2_Aggregate_out0 = 10,
    UID_Concatenate_6 = 11,
    UID_Output_4 = 12,
    UID_Split_1_0 = 13,
    UID_Split_1_1 = 14,
    UID_Split_1_2 = 15,
    UID_ParallelUnionAll_Extract_0 = 16
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

    class Part_SStreamMetadataOutput_3
    {
    public:
        

        Part_SStreamMetadataOutput_3() = default;
        Part_SStreamMetadataOutput_3(const Part_SStreamMetadataOutput_3 & c, IncrementalAllocator * alloc);

        static string GetDefinition()
        {
            return std::string{};
        }

        friend std::ostream& operator<<(std::ostream& os, const Part_SStreamMetadataOutput_3& row)
        {

            return os;
        }
    };

    static_assert(sizeof(Part_SStreamMetadataOutput_3) == 1, "Incorrect size of row schema");

    class Extract_0_Data0
    {
    public:
        int m_UserId{};
        ScopeDateTime m_Start;
        FString m_Region;
        FString m_Query;
        int m_Duration{};
        FString m_Urls;
        FString m_ClickedUrls;

        Extract_0_Data0() = default;
        Extract_0_Data0(const Extract_0_Data0 & c, IncrementalAllocator * alloc);


        friend std::ostream& operator<<(std::ostream& os, const Extract_0_Data0& row)
        {

            ScopeEngine::OutputRowContent(
                std::string{ u8"UserId:int,Start:DateTime,Region:string,Query:string,Duration:int,Urls:string,ClickedUrls:string" },
                reinterpret_cast<const char*>(&row),
                os);

            return os;
        }
    };

    static_assert(sizeof(Extract_0_Data0) == 88, "Incorrect size of row schema");
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


#if defined(COMPILE_NATIVE)
    template<> 
    class BinaryExtractPolicy<Part_SStreamMetadataOutput_3>
    {
    public:
        static constexpr int StreamIdRangeMax = -1;

        static bool Deserialize(BinaryInputStream * input, Part_SStreamMetadataOutput_3 & row)
        {
            try
            {
                char b = 0;
                input->Read(b);
            }
            catch (ScopeStreamException &) 
            {
                // we reach the end of file
                return false;
            }

            return true;
        }
        static bool DeserializeKeyForSS(MemoryInputStream * input, Part_SStreamMetadataOutput_3 & row)
        {
            try
            {
                char b = 0;
                input->Read(b);
            }
            catch (ScopeStreamException &) 
            {
                // we reach the end of file
                return false;
            }

            return true;
        }
        static void DeserializeKey(ResourceInputStream * input, Part_SStreamMetadataOutput_3 & row)
        {
            char type = 0, null = 0;
        }
        static void DeserializePartitionSpec(ResourceInputStream * input, Part_SStreamMetadataOutput_3 & row)
        {
            return ;
        }

    };
#endif // defined(COMPILE_NATIVE)

    template<> 
    class BinaryOutputPolicy<Part_SStreamMetadataOutput_3>
    {
    public:
    
        static void SerializeHeader(BinaryOutputStream * output)
        {
            SCOPE_ASSERT(!"BinaryOutputPolicy::SerializeHeader method should not be invoked.");
        }
        
        __declspec(noinline) static void Serialize(BinaryOutputStream * output, Part_SStreamMetadataOutput_3 & row)
        {
            SIZE_T rowStart =  output->GetOutputter().GetCurrentPosition();
            char b = 0;
            output->Write(b);
            SIZE_T rowSize =  output->GetOutputter().GetCurrentPosition() - rowStart;
            auto rowLimit = ScopeEngine::Configuration::GetGlobal().GetMaxOnDiskRowSize();
            if (rowSize > rowLimit)
            {
                std::stringstream ss;
                ss << row << std::endl;
                throw RuntimeException(E_USER_ONDISKROW_TOO_BIG, {rowSize, rowLimit, ss.str()});
            }
        }
        static void Serialize(DummyOutputStream * output, const Part_SStreamMetadataOutput_3 & row)
        {
            SCOPE_ASSERT(!"BinaryOutputPolicy::Serialize method for type 'DummyOutputStream' should not be invoked."); 
        }
        static void SerializeKeyForSS(MemoryOutputStream* output, const Part_SStreamMetadataOutput_3 & row)
        {
            output->Write(false);
        }
    };



    template<typename StreamSchemaType>
    class KeyRangeOutputPolicy<Part_SStreamMetadataOutput_3, StreamSchemaType>
    {
    public:
        static void Serialize(MemoryOutputStream* output, const Part_SStreamMetadataOutput_3 & row, bool isFinal = false)
        {
            output->Write(false);
        }
    };


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
                    input->Read(row.m_UserId);
                    input->Read(row.m_Start);
                    input->Read(row.m_Region);
                    input->Read(row.m_Query);
                    input->Read(row.m_Duration);
                    input->Read(row.m_Urls);
                    input->Read(row.m_ClickedUrls);
                }
                else
                {
            char ___masking___[1];
            memset(___masking___, 0, sizeof(___masking___));
                    ___masking___[0] = b;
                    input->Read(row.m_UserId);
                    input->Read(row.m_Start);
                    if ((___masking___[0] & 2 ) != 2)
                    {
                        input->Read(row.m_Region);
                    }
                    else
                    {
                        row.m_Region.SetNull();
                    }
                    if ((___masking___[0] & 4 ) != 4)
                    {
                        input->Read(row.m_Query);
                    }
                    else
                    {
                        row.m_Query.SetNull();
                    }
                    input->Read(row.m_Duration);
                    if ((___masking___[0] & 8 ) != 8)
                    {
                        input->Read(row.m_Urls);
                    }
                    else
                    {
                        row.m_Urls.SetNull();
                    }
                    if ((___masking___[0] & 16 ) != 16)
                    {
                        input->Read(row.m_ClickedUrls);
                    }
                    else
                    {
                        row.m_ClickedUrls.SetNull();
                    }
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
            if (row.m_Query.IsNull())
            {
                hasNull = true;
                ___masking___[0] |= 4;
            }
            if (row.m_Urls.IsNull())
            {
                hasNull = true;
                ___masking___[0] |= 8;
            }
            if (row.m_ClickedUrls.IsNull())
            {
                hasNull = true;
                ___masking___[0] |= 16;
            }
            if (hasNull)
            {
                output->Write(___masking___[0]);
            }
            else
            {
                output->Write(b);
            }
            output->Write(row.m_UserId);
            output->Write(row.m_Start);
            if (!row.m_Region.IsNull())
            {
                output->Write(row.m_Region);
            }
            if (!row.m_Query.IsNull())
            {
                output->Write(row.m_Query);
            }
            output->Write(row.m_Duration);
            if (!row.m_Urls.IsNull())
            {
                output->Write(row.m_Urls);
            }
            if (!row.m_ClickedUrls.IsNull())
            {
                output->Write(row.m_ClickedUrls);
            }
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
    INLINE Part_SStreamMetadataOutput_3::Part_SStreamMetadataOutput_3(const Part_SStreamMetadataOutput_3 & c, IncrementalAllocator * alloc)
    {
    }

    INLINE Extract_0_Data0::Extract_0_Data0(const Extract_0_Data0 & c, IncrementalAllocator * alloc) :
            m_UserId(c.m_UserId),
            m_Start(c.m_Start),
            m_Region(c.m_Region, alloc),
            m_Query(c.m_Query, alloc),
            m_Duration(c.m_Duration),
            m_Urls(c.m_Urls, alloc),
            m_ClickedUrls(c.m_ClickedUrls, alloc)
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
#pragma region SV1_Extract_Split
#if defined(COMPILE_SV1_EXTRACT_SPLIT) || defined(COMPILE_ALL_VERTICES)


#if defined(COMPILE_NATIVE)
    template<>
    class SStreamV3OutputPolicy<Extract_0_Data0, UID_SV1_Extract_Split_out0>
    {
    public:
        SStreamV3OutputPolicy(UINT)
        {
        }

        static const string& DataSchemaString()
        {
            static string* spDataSchemaString = new string(std::string{ u8"<?xml version=\"1.0\"?>\r\n<Schema>\r\n  <Format>1</Format>\r\n  <Columns>\r\n    <Column>\r\n      <Name>UserId</Name>\r\n      <Type>int</Type>\r\n    </Column>\r\n    <Column>\r\n      <Name>Start</Name>\r\n      <Type>DateTime</Type>\r\n    </Column>\r\n    <Column>\r\n      <Name>Region</Name>\r\n      <Type>string</Type>\r\n    </Column>\r\n    <Column>\r\n      <Name>Query</Name>\r\n      <Type>string</Type>\r\n    </Column>\r\n    <Column>\r\n      <Name>Duration</Name>\r\n      <Type>int</Type>\r\n    </Column>\r\n    <Column>\r\n      <Name>Urls</Name>\r\n      <Type>string</Type>\r\n    </Column>\r\n    <Column>\r\n      <Name>ClickedUrls</Name>\r\n      <Type>string</Type>\r\n    </Column>\r\n  </Columns>\r\n</Schema>" });
            return *spDataSchemaString;
        }

        static std::array<const char *, 7> m_columnNames;
        static std::array<const char *, 7> m_columnTypes;
        static std::array<BYTE, 7> m_dataColumnSizes;
        static std::array<BYTE, 3> m_indexColumnSizes;
        static UINT* m_dataPageSortKeys;
        static const char ** m_dataPageSortOrders;
        static const char *  m_dataPageSortUniq;
        static constexpr UINT m_dataPageSortKeysCnt = 0;

        static const char m_partitionType[];
        static constexpr UINT m_partitionColumnCount = 0;

        static UINT *     m_partitionKeys;
        static const char **  m_partitionOrders;
        static constexpr int m_blockSize = 4194304;
        static constexpr int m_uncompressedBlockSize = 12455800;
        static constexpr bool m_enableAutoPrimaryBloomFilter = true;
        static constexpr int m_bloomFilterSizeWriteRatio = -1;
        static constexpr int m_bloomFilterVersion = -1;
        static int GetPartitionIndex(const Extract_0_Data0& row)
        {
            // Global sstream outputter does not care partition index.
            UNREFERENCED_PARAMETER(row);
            return 0;
            
        }        
        static void SerializeRow(HANDLE rowHandle, AutoBuffer* buffer, int* columnOffsets, SIZE_T arraySize)
        {
            UNREFERENCED_PARAMETER(arraySize);
            
            Extract_0_Data0& row = *(Extract_0_Data0*)rowHandle;
            SStreamDataOutputStream output(buffer);

            char ___masking___[1];
            memset(___masking___, 0, sizeof(___masking___));
            if (row.m_Region.IsNull())
            {
                ___masking___[0] |= 4;
            }
            if (row.m_Query.IsNull())
            {
                ___masking___[0] |= 8;
            }
            if (row.m_Urls.IsNull())
            {
                ___masking___[0] |= 32;
            }
            if (row.m_ClickedUrls.IsNull())
            {
                ___masking___[0] |= 64;
            }
            auto rowStart = output.GetPosition();

            // write a null mask regardless whether there are nullable columns,
            // if there aren't any nullable column, simply write the array's 
            // initial values, which are zeros.
            output.Write(___masking___, sizeof(___masking___));


            columnOffsets[0] = (int)(output.GetPosition() - rowStart);
            output.Write(row.m_UserId);

            columnOffsets[1] = (int)(output.GetPosition() - rowStart);
            output.Write(row.m_Start);

            columnOffsets[2] = (int)(output.GetPosition() - rowStart);
            if (!row.m_Region.IsNull())
            {
                output.Write(row.m_Region);
            }

            columnOffsets[3] = (int)(output.GetPosition() - rowStart);
            if (!row.m_Query.IsNull())
            {
                output.Write(row.m_Query);
            }

            columnOffsets[4] = (int)(output.GetPosition() - rowStart);
            output.Write(row.m_Duration);

            columnOffsets[5] = (int)(output.GetPosition() - rowStart);
            if (!row.m_Urls.IsNull())
            {
                output.Write(row.m_Urls);
            }

            columnOffsets[6] = (int)(output.GetPosition() - rowStart);
            if (!row.m_ClickedUrls.IsNull())
            {
                output.Write(row.m_ClickedUrls);
            }

            columnOffsets[7] = (int)(output.GetPosition() - rowStart);
        }

        static constexpr SStreamVersion m_streamVersion = ScopeEngine::SStreamVersion::SSTREAM_VERSION_V3;
    };

#endif // defined(COMPILE_NATIVE)


#if defined(COMPILE_NATIVE)
    template<>
    class SStreamPartitionWriter<Extract_0_Data0, UID_SV1_Extract_Split_out0>
    {
    private:
        SStreamOutputStream<Extract_0_Data0, SStreamV3OutputPolicy<Extract_0_Data0, UID_SV1_Extract_Split_out0>, void, -1> sstreamOutputStream_0;
        BlockDevice*    m_metadataDevice;
        int             m_bufCount;
        int             m_sequenceNumber;
        int             m_distributionId;
        bool            m_preferSSD;
    public:
        static constexpr int VALUE_NOT_INITIALIZED = -3;

        
        SStreamPartitionWriter(OutputFileInfo outputs, const string& outputMetadataFileName, bool preferSSD, bool enableBloomFilter)
            : SStreamPartitionWriter(&outputs, 1, outputMetadataFileName, preferSSD, enableBloomFilter)
        {
        }

        
        SStreamPartitionWriter(OutputFileInfo* outputs, int fileCnt, const string& outputMetadataFileName, bool preferSSD, bool enableBloomFilter)
            : m_bufCount(0)
            , m_sequenceNumber(VALUE_NOT_INITIALIZED)
            , m_preferSSD(preferSSD)
            , m_distributionId(0)
            
            , sstreamOutputStream_0(outputs[0].outputFileName, 0, outputs[0].bufferSize, outputs[0].bufferCount, preferSSD, enableBloomFilter)
            , m_metadataDevice(ScopeEngine::IOManager::GetGlobal()->GetDevice(outputMetadataFileName))
        {
            STRUCTURED_DATA_ASSERT(fileCnt == 1);

            for(int idx = 0; idx < fileCnt; ++idx)
            {
                m_bufCount = std::max(m_bufCount, outputs[idx].bufferCount);
            }
        }

        void Init()
        {
            constexpr int64_t expectedNumberOfRowsPerPartition_0 = 4995000000ll;
            sstreamOutputStream_0.Init(expectedNumberOfRowsPerPartition_0);
        }

        void SetSequenceNumber(int sequenceNumber)
        {
            m_sequenceNumber = sequenceNumber;
            m_distributionId = 0;
        }

        bool NeedMetadata()
        {
            return -1 != -1;
        }

        void SetPartitionInfo(PartitionMetadata* payload)
        {
            sstreamOutputStream_0.SetPartitionInfo(payload);
            // If the m_distributionId hasn't been set, then we can initialize it
            // If the first OutputStream has a valid PartitionID, then use it. 
            // do we have a value from our payload?
            // all column groups must have the same distribution id, so just use the first group
            if(sstreamOutputStream_0.ValidPartition())
            {
                m_distributionId = sstreamOutputStream_0.GetPartitionIndex();
            }
        }

        bool ValidPartition()
        {
            return m_distributionId != PartitionMetadata::PARTITION_NOT_EXIST;
        }

        void AppendRow(Extract_0_Data0 & output)
        {
            sstreamOutputStream_0.AppendRow(output);
        }

        void Close()
        {
            sstreamOutputStream_0.Close();


            unique_ptr<SStreamMetadata> metadata(SStreamMetadata::CreateMetadataByVersion(ScopeEngine::SStreamVersion::SSTREAM_VERSION_V3, MemoryManager::GetGlobal()));
            std::string streamSchema = std::string{ u8"<?xml version=\"1.0\"?>\r\n<Schema>\r\n  <Format>1</Format>\r\n  <Columns>\r\n    <Column>\r\n      <Name>UserId</Name>\r\n      <Type>int</Type>\r\n    </Column>\r\n    <Column>\r\n      <Name>Start</Name>\r\n      <Type>DateTime</Type>\r\n    </Column>\r\n    <Column>\r\n      <Name>Region</Name>\r\n      <Type>string</Type>\r\n    </Column>\r\n    <Column>\r\n      <Name>Query</Name>\r\n      <Type>string</Type>\r\n    </Column>\r\n    <Column>\r\n      <Name>Duration</Name>\r\n      <Type>int</Type>\r\n    </Column>\r\n    <Column>\r\n      <Name>Urls</Name>\r\n      <Type>string</Type>\r\n    </Column>\r\n    <Column>\r\n      <Name>ClickedUrls</Name>\r\n      <Type>string</Type>\r\n    </Column>\r\n  </Columns>\r\n</Schema>" };

            shared_ptr<vector<ScopeEngine::SSLibV3::ColumnGroupInfo>> colGroupInfos = make_shared<vector<ScopeEngine::SSLibV3::ColumnGroupInfo>>(1);
            shared_ptr<vector<ScopeEngine::SSLibV3::DataunitTableRow>> dataUnitTableRows = make_shared<vector<ScopeEngine::SSLibV3::DataunitTableRow>>(1);
            shared_ptr<ScopeEngine::SSLibV3::SStreamStatistics> statistics;
            statistics = sstreamOutputStream_0.GetStatistics();
            std::string dataSchema_0 = SStreamV3OutputPolicy<Extract_0_Data0, UID_SV1_Extract_Split_out0>::DataSchemaString();

            ScopeEngine::SSLibV3::ColumnGroupInfo& colGroupInfo_0 = (*colGroupInfos)[0];
            colGroupInfo_0.m_columnGroupIndex = 0;
            colGroupInfo_0.m_columnGroupSchema = dataSchema_0;

            ScopeEngine::SSLibV3::DataunitTableRow& dataunitInfo_0 = (*dataUnitTableRows)[0];
            dataunitInfo_0.m_PartitionIndex = m_distributionId;
            dataunitInfo_0.m_ColumnGroupIndex = 0;
            dataunitInfo_0.m_Offset = 0;
            dataunitInfo_0.m_Length = sstreamOutputStream_0.Length();
            dataunitInfo_0.m_DataLength = sstreamOutputStream_0.DataLength();
            dataunitInfo_0.m_RowCount = sstreamOutputStream_0.RowCount();
            dataunitInfo_0.m_DeltaIndex = 0;

            shared_ptr<vector<ScopeEngine::SSLibV3::PartitionInfoTableRow>> partInfoRows = make_shared<vector<ScopeEngine::SSLibV3::PartitionInfoTableRow>>(1);
            ScopeEngine::SSLibV3::PartitionInfoTableRow& partInfo = (*partInfoRows)[0];
            // all column groups have the same partition information
            partInfo.m_PartitionKeyRange = sstreamOutputStream_0.GetPartitionKeyRange();
            partInfo.m_BeginPartitionIndex = m_distributionId;
            partInfo.m_AffinityId = GuidToString(sstreamOutputStream_0.GetAffinityGuid());

            metadata->Initialize(streamSchema,
                colGroupInfos,
                dataUnitTableRows,
                partInfoRows,
                statistics);

            metadata->PreferSSD(m_preferSSD);
            metadata->Write(m_metadataDevice);
        }

        LONGLONG GetTotalIoWaitTime() const
        {
            LONGLONG time = 0;
            time += sstreamOutputStream_0.GetTotalIoWaitTime();
            return time;
        }

        void WriteRuntimeStats(TreeNode & root) const
        {
            sstreamOutputStream_0.WriteRuntimeStats(root);
        }

        // get operator resource requirements
        ScopeEngine::OperatorRequirements GetOperatorRequirements(SIZE_T bufferCount)
        {
            return ScopeEngine::OperatorRequirements()
                .AddMemoryForOutputSStreams(1, Configuration::GetGlobal().GetMaxInMemoryRowSize(), m_bufCount);
        }

        // the following methods are for SplitOutputter
        void WriteMetadata(PartitionMetadata* metadata)
        {
            SetPartitionInfo(metadata);
        }

        void Finish()
        {
            // do nothing
        }

        void Flush(bool forcePersistent = false)
        {
            // do nothing
            (forcePersistent);
        }
    };

#endif


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

                    input->Read(row.m_UserId);
                    input->Read(row.m_Start);
                    input->Read(row.m_Region);
                    input->Read(row.m_Query);
                    input->Read(row.m_Duration);
                    input->Read(row.m_Urls);
                    input->Read(row.m_ClickedUrls);

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


    template<> 
    class TextOutputPolicy<Extract_0_Data0, UID_Output_4>
    {
    public:

        static void Serialize(TextOutputStream<TextOutputStreamTraitsConst<'\t', '\0', false, true, false, false, false, Default, false, CharFormat_uint16>, CosmosOutput> * output, Extract_0_Data0 & row)
        {
            output->Write<int,false>(row.m_UserId);
            output->WriteDelimiter();
            output->Write<ScopeDateTime,false>(row.m_Start);
            output->WriteDelimiter();
            if (!row.m_Region.IsNull())
            {
                output->Write<FString,false>(row.m_Region);
            }
            output->WriteDelimiter();
            if (!row.m_Query.IsNull())
            {
                output->Write<FString,false>(row.m_Query);
            }
            output->WriteDelimiter();
            output->Write<int,false>(row.m_Duration);
            output->WriteDelimiter();
            if (!row.m_Urls.IsNull())
            {
                output->Write<FString,false>(row.m_Urls);
            }
            output->WriteDelimiter();
            if (!row.m_ClickedUrls.IsNull())
            {
                output->Write<FString,false>(row.m_ClickedUrls);
            }
            output->WriteNewLine();
        }

        static void SerializeHeader(TextOutputStream<TextOutputStreamTraitsConst<'\t', '\0', false, true, false, false, false, Default, false, CharFormat_uint16>, CosmosOutput> * output)
        {
            SCOPE_ASSERT(!"TextOutputPolicy::SerializeHeader method should not be invoked.");
        }
    };



#if defined(COMPILE_MANAGED)
#endif // defined(COMPILE_MANAGED)

    static const char * StringTable_Split_1_1 [] =
    {
        "UserId",
        "Start",
        "Region",
        "Query",
        "Duration",
        "Urls",
        "ClickedUrls",
        "\"*** After Last Expression ***\"",
    };

    template<>
    class RowTransformPolicy<Extract_0_Data0, Extract_0_Data0, UID_Split_1_1>
    {
    public:
        void Init(ManagedRow<Extract_0_Data0> *)
        {
            // Nothing to do
        }
        static bool FilterTransformRow(Extract_0_Data0 & input, Extract_0_Data0 & output, IncrementalAllocator * alloc)
        {
            int exceptionIndex = 0;
            try
            {
                output.m_UserId = input.m_UserId;
                exceptionIndex++;
                output.m_Start = input.m_Start;
                exceptionIndex++;
                output.m_Region = input.m_Region;
                exceptionIndex++;
                output.m_Query = input.m_Query;
                exceptionIndex++;
                output.m_Duration = input.m_Duration;
                exceptionIndex++;
                output.m_Urls = input.m_Urls;
                exceptionIndex++;
                output.m_ClickedUrls = input.m_ClickedUrls;
                exceptionIndex++;
                return true;
            }
            catch(const ScriptExplicitlyRaisedException&)
            {
                throw;
            }
            catch(...)
            {
                std::throw_with_nested(RuntimeException(E_USER_EXPRESSION_ERROR, StringTable_Split_1_1[exceptionIndex]));
            }
        }

        static void InitializeStatics(IncrementalAllocator *) {}

        // get operator resource requirements
        static ScopeEngine::OperatorRequirements GetOperatorRequirements()
        {
            return ScopeEngine::OperatorRequirements();
        }
    };



    static const char * StringTable_Split_1_2 [] =
    {
        "UserId",
        "Start",
        "Region",
        "Query",
        "Duration",
        "Urls",
        "ClickedUrls",
        "\"*** After Last Expression ***\"",
    };

    template<>
    class RowTransformPolicy<Extract_0_Data0, Extract_0_Data0, UID_Split_1_2>
    {
    public:
        void Init(ManagedRow<Extract_0_Data0> *)
        {
            // Nothing to do
        }
        static bool FilterTransformRow(Extract_0_Data0 & input, Extract_0_Data0 & output, IncrementalAllocator * alloc)
        {
            int exceptionIndex = 0;
            try
            {
                output.m_UserId = input.m_UserId;
                exceptionIndex++;
                output.m_Start = input.m_Start;
                exceptionIndex++;
                output.m_Region = input.m_Region;
                exceptionIndex++;
                output.m_Query = input.m_Query;
                exceptionIndex++;
                output.m_Duration = input.m_Duration;
                exceptionIndex++;
                output.m_Urls = input.m_Urls;
                exceptionIndex++;
                output.m_ClickedUrls = input.m_ClickedUrls;
                exceptionIndex++;
                return true;
            }
            catch(const ScriptExplicitlyRaisedException&)
            {
                throw;
            }
            catch(...)
            {
                std::throw_with_nested(RuntimeException(E_USER_EXPRESSION_ERROR, StringTable_Split_1_2[exceptionIndex]));
            }
        }

        static void InitializeStatics(IncrementalAllocator *) {}

        // get operator resource requirements
        static ScopeEngine::OperatorRequirements GetOperatorRequirements()
        {
            return ScopeEngine::OperatorRequirements();
        }
    };






#if defined(COMPILE_NATIVE)
    template<> 
    class SplitPolicy<typename Extract_0_Data0, UID_Split_1>
    {
        int bufferCount[3];
        std::size_t bufferSize[3];
        
        typedef SplitOutputterSentinel<Extract_0_Data0> SplitOutputType_Split_1_3;
        SplitOutputType_Split_1_3 splitOutputter_Split_1_3;

        // OutputPolicyWrapper for Splitter
        typedef OutputPolicyWrapper<Extract_0_Data0, TextOutputStream<TextOutputStreamTraitsConst<'\t', '\0', false, true, false, false, false, Default, false, CharFormat_uint16>, CosmosOutput>, TextOutputPolicy<Extract_0_Data0, UID_Output_4>> OutputPolicyWrapperType_Split_1_2;

        typedef SplitOutputter<
            SplitOutputType_Split_1_3, 
            Extract_0_Data0, 
            OutputPolicyWrapperType_Split_1_2, 
            ExecutionStats, 
            UID_Split_1_2> 
            SplitOutputType_Split_1_2;

        SplitOutputType_Split_1_2 splitOutputter_Split_1_2;


        // OutputPolicyWrapper for Splitter
        typedef OutputPolicyWrapper<Extract_0_Data0, SStreamPartitionWriter<Extract_0_Data0, UID_SV1_Extract_Split_out0>, SplitterSStreamV3OutputPolicy<Extract_0_Data0, UID_SV1_Extract_Split_out0>> OutputPolicyWrapperType_Split_1_0;

        typedef SplitOutputter<
            SplitOutputType_Split_1_2, 
            Extract_0_Data0, 
            OutputPolicyWrapperType_Split_1_0, 
            ExecutionStats, 
            UID_Split_1_1> 
            SplitOutputType_Split_1_0;

        SplitOutputType_Split_1_0 splitOutputter_Split_1_0;


    public:
        SplitPolicy(OutputFileInfo * outputFiles) :
            splitOutputter_Split_1_2(&splitOutputter_Split_1_3, new OutputPolicyWrapperType_Split_1_2(outputFiles[2].outputFileName, outputFiles[2].bufferSize, outputFiles[2].bufferCount, OutputStreamParameters('\t', "\r\n", '\0', static_cast<const char*>(__nullptr), false, true, false, false, NULL, Default, false, CharFormat_uint16), false), outputFiles[2].outputFileName, false, UID_SV1_Extract_Split_out2),
            splitOutputter_Split_1_0(&splitOutputter_Split_1_2, new OutputPolicyWrapperType_Split_1_0(outputFiles[0].outputFileName, outputFiles[0].bufferSize, outputFiles[0].bufferCount, OutputSStreamParameters(1, false, outputFiles[1].outputFileName), false), outputFiles[0].outputFileName, false, UID_SV1_Extract_Split_out0)
        {
            for(int idx = 0; idx < 3; ++idx)
            {
                bufferCount[idx] = outputFiles[idx].bufferCount;
                bufferSize[idx] = outputFiles[idx].bufferSize;
            }
        }

        void SetSequenceNumber(int sequenceNumber)
        {
            splitOutputter_Split_1_2.SetSequenceNumber(sequenceNumber);
            splitOutputter_Split_1_0.SetSequenceNumber(sequenceNumber);
        }

        void Init()
        {
            
            splitOutputter_Split_1_0.Init(nullptr);
        }

        void BeginDataRead()
        {
            splitOutputter_Split_1_0.BeginDataRead();
        }

        void Close()
        {
            splitOutputter_Split_1_0.Close();
        }

        void ProcessMetadata(PartitionMetadata * metadata)
        {
            splitOutputter_Split_1_0.ProcessMetadata(metadata);
        }

        void OutputHeader()
        {
            splitOutputter_Split_1_0.OutputHeader();
        }

        void ProcessRow(Extract_0_Data0 & input)
        {
            splitOutputter_Split_1_0.ProcessRow(input);
        }

        __declspec(noinline)
        void WriteRuntimeStats(TreeNode & root) const
        {
            splitOutputter_Split_1_0.WriteRuntimeStats(root);
        }

        LONGLONG GetTotalIoWaitTime() const
        {
            return splitOutputter_Split_1_0.GetTotalIoWaitTime();
        }

        // get operator resource requirements
        ScopeEngine::OperatorRequirements GetOperatorRequirements()
        {
            return splitOutputter_Split_1_0.GetOperatorRequirements()
	.AddMemoryForOutputUStreams(1, ScopeEngine::Configuration::GetGlobal().GetMaxOnDiskRowSize(), bufferCount[2])
	.AddMemoryForOutputSStreams(1, ScopeEngine::Configuration::GetGlobal().GetMaxOnDiskRowSize(), bufferCount[0]);
        }

        void FlushOutput(bool forcePersistent = false)
        {
            splitOutputter_Split_1_0.FlushOutput(forcePersistent);
        }

    };

#endif // defined(COMPILE_NATIVE)

#if defined(COMPILE_NATIVE)
struct ExtractorType1_SV1_Extr_Split : Extractor<Extract_0_Data0, TextExtractPolicy<Extract_0_Data0, UID_Extract_0>, TextInputStream<TextInputStreamTraitsConst<'\t', '\0', '\0', false, false, Default, false, false, false, 0, CharFormat_uint16, false, false>, CosmosInput>> { using Extractor<Extract_0_Data0, TextExtractPolicy<Extract_0_Data0, UID_Extract_0>, TextInputStream<TextInputStreamTraitsConst<'\t', '\0', '\0', false, false, Default, false, false, false, 0, CharFormat_uint16, false, false>, CosmosInput>>::Extractor; };
struct UnionAllType_Extract_0_Split_1_connector : ParallelUnionAll<ExtractorType1_SV1_Extr_Split, Extract_0_Data0, true> { using ParallelUnionAll<ExtractorType1_SV1_Extr_Split, Extract_0_Data0, true>::ParallelUnionAll; };
#endif // defined(COMPILE_NATIVE)



#if defined(COMPILE_NATIVE)
namespace ScopeGeneratedClasses
{
    extern "C" __declspec(dllexport) void __stdcall SV1_Extract_Split_execute(std::string * argv, int argc, InputFileInfo* inputs, int inputCnt, OutputFileInfo* outputs, int outputCnt, VertexExecutionInfo * vertexExecutionInfo)
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

        // ExtractorType1_SV1_Extr_Split: Extractor<Extract_0_Data0, TextExtractPolicy<Extract_0_Data0, UID_Extract_0>, TextInputStream<TextInputStreamTraitsConst<'\t', '\0', '\0', false, false, Default, false, false, false, 0, CharFormat_uint16, false, false>, CosmosInput>>
        unique_ptr<unique_ptr<ExtractorType1_SV1_Extr_Split>[]> extractor_0_array(new unique_ptr<ExtractorType1_SV1_Extr_Split>[inputCnt - 0]);
        
        for (int i = 0; i < inputCnt; i++)
        {
            extractor_0_array[i - 0].reset(new ExtractorType1_SV1_Extr_Split(inputs[i], false, x_inputBufSize, x_inputBufCnt, x_inputVirtualMemoryLimit, InputStreamParameters('\t', '\0', '\0', static_cast<const char*>(__nullptr), false, false, Default, false, false, 0, CharFormat_uint16), UID_Extract_0));
        }

    ExtractorType1_SV1_Extr_Split ** extractor_0 = (ExtractorType1_SV1_Extr_Split **)extractor_0_array.get();

        
        ULONG extractor_0_count = (ULONG) inputCnt - 0;

        // Merge streams N->1
        // UnionAllType_Extract_0_Split_1_connector: ParallelUnionAll<ExtractorType1_SV1_Extr_Split, Extract_0_Data0, true>
        unique_ptr<UnionAllType_Extract_0_Split_1_connector> unionall_Extract_0_Split_1_connector_ptr(new UnionAllType_Extract_0_Split_1_connector(extractor_0,extractor_0_count,16,12,419430400,UID_ParallelUnionAll_Extract_0));
        UnionAllType_Extract_0_Split_1_connector * unionall_Extract_0_Split_1_connector = unionall_Extract_0_Split_1_connector_ptr.get();
        ULONG unionall_Extract_0_Split_1_connector_count = 1;

        using SplitterType_Split_1 = Splitter<UnionAllType_Extract_0_Split_1_connector, Extract_0_Data0, false, UID_Split_1>;
        unique_ptr<SplitterType_Split_1> splitter_Split_1_ptr (new SplitterType_Split_1(unionall_Extract_0_Split_1_connector, outputs, UID_Split_1, false));
        SplitterType_Split_1 * splitter_Split_1 = splitter_Split_1_ptr.get();

        if (argv != nullptr && argc > 0)
        {
            try
            {
                int sequenceNumber = GetSequenceNumber(argv, argc);
                splitter_Split_1->SetSequenceNumber(sequenceNumber);
            }
            catch(const RuntimeException&)
            {
                // Sequence number will remain 0 in splitter_Split_1.
            }
        }

        // Create timer to automatically dump statistics available at the time, when approaching max permitted time for vertex execution
        auto dumpStatsTimer{ ScopeEngine::CreateDumpStatsTimer(vertexExecutionInfo->m_updateStatusThresholdToAutoDumpStatistics, *splitter_Split_1) };

        try
        {
            // Init operator chain
            splitter_Split_1->InitOperatorPipeline();

            // Execute the whole vertex by calling the GetNextRow on top operator
            Extract_0_Data0 row;
            splitter_Split_1->GetNextRow(row);

            // Close operator chain
            splitter_Split_1->Close();
        }
        catch (const ExceptionWithStack& ex)
        {
            std::cout << "Caught exception: " << ex.what() << std::endl << ex.GetStack() << std::endl;
            throw;
        }


        MemoryManager::GetGlobal()->WriteRuntimeStats(vertexExecutionInfo->m_statsRoot);
        splitter_Split_1->WriteRuntimeStats(vertexExecutionInfo->m_statsRoot);
    }
}
#endif // defined(COMPILE_NATIVE)

#if defined(COMPILE_MANAGED)
#endif // defined(COMPILE_MANAGED)
#if defined(COMPILE_NATIVE)
#endif // defined(COMPILE_NATIVE)

#endif
#pragma endregion SV1_Extract_Split
#pragma region SV2_Aggregate
#if defined(COMPILE_SV2_AGGREGATE) || defined(COMPILE_ALL_VERTICES)


    template<> 
    class KeyComparePolicy<Part_SStreamMetadataOutput_3,UID_SStreamMetadataOutput_3>
    {
    public:
        struct KeyStruct
        {

            KeyStruct(Part_SStreamMetadataOutput_3 & c) 

            {
            }

            KeyStruct(const Part_SStreamMetadataOutput_3 & c, IncrementalAllocator * alloc) 

            {
            }

            KeyStruct(KeyStruct & c) 

            {
            }

            KeyStruct(const KeyStruct & c, IncrementalAllocator * alloc) 

            {
            }

            KeyStruct() 

            {
            }

            friend std::ostream& operator<<(std::ostream& os, const KeyStruct& row)
            {
                return os;
            }
        };

        typedef KeyStruct KeyType;

        static int Compare(Part_SStreamMetadataOutput_3 & row, KeyType & key)
        {
            int r = 0;
            return r;
        }

        static int Compare(Part_SStreamMetadataOutput_3 * n1, Part_SStreamMetadataOutput_3 * n2)
        {
            int r = 0;
            return r;
        }

    };



#if defined(COMPILE_NATIVE)
struct ExtractorType1_SV2_Agg : SStreamMetadataExtractor<Extract_0_Data0> { using SStreamMetadataExtractor<Extract_0_Data0>::SStreamMetadataExtractor; };
struct MetadataAggregateType_MetadataAggregate_2 : Merger<ExtractorType1_SV2_Agg, Extract_0_Data0, ScopeUnionAll<ExtractorType1_SV2_Agg, Extract_0_Data0>, UID_MetadataAggregate_2> { using Merger<ExtractorType1_SV2_Agg, Extract_0_Data0, ScopeUnionAll<ExtractorType1_SV2_Agg, Extract_0_Data0>, UID_MetadataAggregate_2>::Merger; };
#endif // defined(COMPILE_NATIVE)



#if defined(COMPILE_NATIVE)
namespace ScopeGeneratedClasses
{
    extern "C" __declspec(dllexport) void __stdcall SV2_Aggregate_execute(std::string * argv, int argc, InputFileInfo* inputs, int inputCnt, OutputFileInfo* outputs, int outputCnt, VertexExecutionInfo * vertexExecutionInfo)
    {
#ifdef USE_SSE4_2
        ScopeEngine::CheckCpuSupportsInstructions();
#endif

        ScopeEngine::Configuration::Create(ET_Cosmos, GetCompilerSettings(), vertexExecutionInfo);
        SIZE_T x_inputBufSize, x_inputVirtualMemoryLimit;
        int    x_inputBufCnt;
        
        MemoryManager::CalculateIOBufferSize(inputs, inputCnt, outputs, outputCnt, MemoryManager::x_vertexMemoryLimit, MemoryManager::x_vertexReserveMemory, x_inputBufSize, x_inputBufCnt, x_inputVirtualMemoryLimit, false);

        constexpr bool IsNativeOnlyVertex = true;
        // remove the empty stream
        // For the case "PARTITION_NOT_EXIST", the output stream is blank. So here the input stream may be blank.
        int inputIdx2 = 0;
        
        for (int inputIdx = 0; inputIdx < inputCnt; ++inputIdx)
        {
            if(inputs[inputIdx].length == 0)
            {
                continue;
            }
            inputs[inputIdx2] = inputs[inputIdx];
            ++inputIdx2;
        }
        inputCnt =inputIdx2;

        // ExtractorType1_SV2_Agg: SStreamMetadataExtractor<Extract_0_Data0>
        unique_ptr<unique_ptr<ExtractorType1_SV2_Agg>[]> extractor_0_array(new unique_ptr<ExtractorType1_SV2_Agg>[inputCnt - 0]);
        
        for (int i = 0; i < inputCnt; i++)
        {
            extractor_0_array[i - 0].reset(new ExtractorType1_SV2_Agg(inputs[i], i, false, false, UID_SV1_Extract_Split_out1));
        }

    ExtractorType1_SV2_Agg ** extractor_0 = (ExtractorType1_SV2_Agg **)extractor_0_array.get();

        
        ULONG extractor_0_count = (ULONG) inputCnt - 0;

        // MetadataAggregateType_MetadataAggregate_2: Merger<ExtractorType1_SV2_Agg, Extract_0_Data0, ScopeUnionAll<ExtractorType1_SV2_Agg, Extract_0_Data0>, UID_MetadataAggregate_2>
        unique_ptr<MetadataAggregateType_MetadataAggregate_2> metadataAggregate_MetadataAggregate_2_ptr(new MetadataAggregateType_MetadataAggregate_2(extractor_0, extractor_0_count, false, UID_MetadataAggregate_2));
        MetadataAggregateType_MetadataAggregate_2* metadataAggregate_MetadataAggregate_2 = metadataAggregate_MetadataAggregate_2_ptr.get();

        using OutputterType2_SV2_Agg = SStreamMetadataOutputter<MetadataAggregateType_MetadataAggregate_2, Extract_0_Data0, Part_SStreamMetadataOutput_3, UID_SStreamMetadataOutput_3>;
        unique_ptr<OutputterType2_SV2_Agg> outputter_SStreamMetadataOutput_3_ptr(new OutputterType2_SV2_Agg(metadataAggregate_MetadataAggregate_2, outputs[0].outputFileName, "", false, false, 0, UID_SStreamMetadataOutput_3));
        OutputterType2_SV2_Agg * outputter_SStreamMetadataOutput_3 = outputter_SStreamMetadataOutput_3_ptr.get();
        // Create timer to automatically dump statistics available at the time, when approaching max permitted time for vertex execution
        auto dumpStatsTimer{ ScopeEngine::CreateDumpStatsTimer(vertexExecutionInfo->m_updateStatusThresholdToAutoDumpStatistics, *outputter_SStreamMetadataOutput_3) };

        try
        {
            // Init operator chain
            outputter_SStreamMetadataOutput_3->InitOperatorPipeline();

            // Execute the whole vertex by calling the GetNextRow on top operator
            Extract_0_Data0 row;
            outputter_SStreamMetadataOutput_3->GetNextRow(row);

            // Close operator chain
            outputter_SStreamMetadataOutput_3->Close();
        }
        catch (const ExceptionWithStack& ex)
        {
            std::cout << "Caught exception: " << ex.what() << std::endl << ex.GetStack() << std::endl;
            throw;
        }


        MemoryManager::GetGlobal()->WriteRuntimeStats(vertexExecutionInfo->m_statsRoot);
        outputter_SStreamMetadataOutput_3->WriteRuntimeStats(vertexExecutionInfo->m_statsRoot);
    }
}
#endif // defined(COMPILE_NATIVE)

#if defined(COMPILE_MANAGED)
#endif // defined(COMPILE_MANAGED)
#if defined(COMPILE_NATIVE)
#endif // defined(COMPILE_NATIVE)

#endif
#pragma endregion SV2_Aggregate
#if defined(COMPILE_SHARED_DATA) || defined(COMPILE_ALL_VERTICES)
#if defined(COMPILE_NATIVE)
#endif // COMPILE_NATIVE
#endif //#if defined(COMPILE_SHARED_DATA) || defined(COMPILE_ALL_VERTICES)
#if defined(COMPILE_SV1_EXTRACT_SPLIT) || defined(COMPILE_ALL_VERTICES)
#if defined(COMPILE_NATIVE)

std::array<const char *, 7> SStreamV3OutputPolicy<Extract_0_Data0, UID_SV1_Extract_Split_out0>::m_columnNames =
{{"UserId", "Start", "Region", "Query", "Duration", "Urls", "ClickedUrls"}};
std::array<const char *, 7> SStreamV3OutputPolicy<Extract_0_Data0, UID_SV1_Extract_Split_out0>::m_columnTypes =
{{"int", "DateTime", "string", "string", "int", "string", "string"}};
std::array<BYTE, 7> SStreamV3OutputPolicy<Extract_0_Data0, UID_SV1_Extract_Split_out0>::m_dataColumnSizes =
{{4, 8, 0, 0, 4, 0, 0}};
std::array<BYTE, 3> SStreamV3OutputPolicy<Extract_0_Data0, UID_SV1_Extract_Split_out0>::m_indexColumnSizes =
{{8, 8, 4}};
UINT* SStreamV3OutputPolicy<Extract_0_Data0, UID_SV1_Extract_Split_out0>::m_dataPageSortKeys = nullptr;
const char** SStreamV3OutputPolicy<Extract_0_Data0, UID_SV1_Extract_Split_out0>::m_dataPageSortOrders = nullptr;
const char* SStreamV3OutputPolicy<Extract_0_Data0, UID_SV1_Extract_Split_out0>::m_dataPageSortUniq = nullptr;
const char SStreamV3OutputPolicy<Extract_0_Data0, UID_SV1_Extract_Split_out0>::m_partitionType[] =
"RandomPartition";
UINT *      SStreamV3OutputPolicy<Extract_0_Data0, UID_SV1_Extract_Split_out0>::m_partitionKeys = nullptr;
const char **  SStreamV3OutputPolicy<Extract_0_Data0, UID_SV1_Extract_Split_out0>::m_partitionOrders = nullptr;

#endif // COMPILE_NATIVE
#endif //#if defined(COMPILE_SV1_EXTRACT_SPLIT) || defined(COMPILE_ALL_VERTICES)
#if defined(COMPILE_SV2_AGGREGATE) || defined(COMPILE_ALL_VERTICES)
#if defined(COMPILE_NATIVE)


#endif // COMPILE_NATIVE
#endif //#if defined(COMPILE_SV2_AGGREGATE) || defined(COMPILE_ALL_VERTICES)
// Empty footer
