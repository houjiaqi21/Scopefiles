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
#define UDO_ADAPTER_IMPORTS
#if defined(COMPILE_NATIVE)
#include "ScopeCommonError.h"
#include "ScopeError.h"
#include "ScopeOperators.h"
#include "UdoAdapterProxy.h"
#endif
#if defined(COMPILE_MANAGED)
#using <mscorlib.dll>
[assembly: System::Runtime::Versioning::TargetFrameworkAttribute(".NETFramework,Version=v4.7.2", FrameworkDisplayName = ".NET Framework, Version 4.7.2")];
#include "ScopeManaged.h"
#endif
#if defined(COMPILE_NATIVE)
#endif
using namespace ScopeEngine;
#if defined(COMPILE_NATIVE)
using namespace UdoAdapter;
#endif // defined(COMPILE_NATIVE)

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
    UID_SV1_Extract_out0 = 7,
    UID_Extract_4 = 8,
    UID_Extract_4_Data0 = 9,
    UID_SV2_Extract_out0 = 10,
    UID_Process_1_Prefix = 11,
    UID_ParallelUnionAll_Extract_0 = 12,
    UID_ParallelUnionAll_Extract_4 = 13
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
        double m_SepalLength{};
        double m_SepalWidth{};
        double m_PetalLength{};
        double m_PetalWidth{};
        FString m_Name;

        Extract_0_Data0() = default;
        Extract_0_Data0(const Extract_0_Data0 & c, IncrementalAllocator * alloc);


        friend std::ostream& operator<<(std::ostream& os, const Extract_0_Data0& row)
        {

            ScopeEngine::OutputRowContent(
                std::string{ u8"SepalLength:double,SepalWidth:double,PetalLength:double,PetalWidth:double,Name:string" },
                reinterpret_cast<const char*>(&row),
                os);

            return os;
        }
    };

    static_assert(sizeof(Extract_0_Data0) == 48, "Incorrect size of row schema");

    class Process_2_Data0
    {
    public:
        double m_SepalLength_Mean{};
        double m_SepalWidth_Mean{};
        double m_PetalLength_Mean{};
        double m_PetalWidth_Mean{};
        FString m_Name;
        int m_Count{};

        Process_2_Data0() = default;
        Process_2_Data0(const Process_2_Data0 & c, IncrementalAllocator * alloc);


        friend std::ostream& operator<<(std::ostream& os, const Process_2_Data0& row)
        {

            ScopeEngine::OutputRowContent(
                std::string{ u8"SepalLength_Mean:double,SepalWidth_Mean:double,PetalLength_Mean:double,PetalWidth_Mean:double,Name:string,Count:int" },
                reinterpret_cast<const char*>(&row),
                os);

            return os;
        }
    };

    static_assert(sizeof(Process_2_Data0) == 56, "Incorrect size of row schema");

    class ReduceKey_Process_2
    {
    public:
        FString m_Name;

        ReduceKey_Process_2() = default;
        ReduceKey_Process_2(const ReduceKey_Process_2 & c, IncrementalAllocator * alloc);


        friend std::ostream& operator<<(std::ostream& os, const ReduceKey_Process_2& row)
        {

            ScopeEngine::OutputRowContent(
                std::string{ u8"Name:string" },
                reinterpret_cast<const char*>(&row),
                os);

            return os;
        }
    };

    static_assert(sizeof(ReduceKey_Process_2) == 16, "Incorrect size of row schema");

    class Extract_4_Data0
    {
    public:
        FString m_UserId;
        FString m_Start;
        FString m_Region;
        FString m_Query;
        FString m_Duration;
        FString m_Urls;
        FString m_ClickedUrls;

        Extract_4_Data0() = default;
        Extract_4_Data0(const Extract_4_Data0 & c, IncrementalAllocator * alloc);


        friend std::ostream& operator<<(std::ostream& os, const Extract_4_Data0& row)
        {

            ScopeEngine::OutputRowContent(
                std::string{ u8"UserId:string,Start:string,Region:string,Query:string,Duration:string,Urls:string,ClickedUrls:string" },
                reinterpret_cast<const char*>(&row),
                os);

            return os;
        }
    };

    static_assert(sizeof(Extract_4_Data0) == 112, "Incorrect size of row schema");
#pragma endregion Schemas

#if defined(COMPILE_MANAGED)
#pragma region ManagedRows
#pragma endregion ManagedRows

#pragma region ManagedUDTs
#pragma endregion ManagedUDTs
#endif // defined(COMPILE_MANAGED)


#pragma region AdapterRowPolicies
#if defined(COMPILE_NATIVE)
    template<>
    class ProxyHostRowPolicy<Extract_0_Data0>
    {
    public:
        ColumnAccessData m_accessData[5];
        ProxyHostColumnMeta m_columns[5];
        std::map<const char*, int, CStringCompare> m_columnMap;

        ProxyHostRowPolicy(): ProxyHostRowPolicy(std::vector<columnIndex_t>()) {}

        ProxyHostRowPolicy(const std::vector<columnIndex_t>& readOnlyColumns)
        {
            bool isReadOnlyColumn[5];
            std::fill(isReadOnlyColumn, isReadOnlyColumn + 5, false);
            for(auto& index : readOnlyColumns)
            {
                isReadOnlyColumn[index] = true;
            }

            m_accessData[0].Initialize(true, offsetof(Extract_0_Data0, m_SepalLength), sizeof(decltype(Extract_0_Data0::m_SepalLength)));
            m_columns[0].Initialize("SepalLength", USqlColumnType::Double, isReadOnlyColumn[0]);
            m_columnMap.insert(make_pair("SepalLength", 0));
            m_accessData[1].Initialize(true, offsetof(Extract_0_Data0, m_SepalWidth), sizeof(decltype(Extract_0_Data0::m_SepalWidth)));
            m_columns[1].Initialize("SepalWidth", USqlColumnType::Double, isReadOnlyColumn[1]);
            m_columnMap.insert(make_pair("SepalWidth", 1));
            m_accessData[2].Initialize(true, offsetof(Extract_0_Data0, m_PetalLength), sizeof(decltype(Extract_0_Data0::m_PetalLength)));
            m_columns[2].Initialize("PetalLength", USqlColumnType::Double, isReadOnlyColumn[2]);
            m_columnMap.insert(make_pair("PetalLength", 2));
            m_accessData[3].Initialize(true, offsetof(Extract_0_Data0, m_PetalWidth), sizeof(decltype(Extract_0_Data0::m_PetalWidth)));
            m_columns[3].Initialize("PetalWidth", USqlColumnType::Double, isReadOnlyColumn[3]);
            m_columnMap.insert(make_pair("PetalWidth", 3));
            m_accessData[4].Initialize(false, offsetof(Extract_0_Data0, m_Name), sizeof(decltype(Extract_0_Data0::m_Name)));
            m_columns[4].Initialize("Name", USqlColumnType::String, isReadOnlyColumn[4]);
            m_columnMap.insert(make_pair("Name", 4));
        }

        columnIndex_t GetColumnCount() const noexcept
        {
            return 5;
        }

        void GetFixedLengthColumn(columnIndex_t index, FixedLengthColumnData& columnData, const Extract_0_Data0& row) const
        {
            if (index >= 5)
                throw ProxyHostRuntimeException(E_COLUMN_INDEX_OUT_OF_RANGE, {index, 5});
            if (!m_accessData[index].m_fixedLength)
                throw ProxyHostRuntimeException(E_WRONG_METHOD_TO_READ_COLUMN_VALUE, { "Variable length", "GetFixedLengthColumn"});

            switch (index)
            {
                case 0: case 1: case 2: case 3: // double
                {
                    double* data = reinterpret_cast<double*>((char*)(&row) + m_accessData[index].m_offset);
                    columnData.SetNonNullValue<double>(USqlColumnType::Double, *data);
                    break;
                }
            default:
                throw ProxyHostRuntimeException(E_UNSUPPORTED_COLUMN_TYPE, { index });
            }
        }

        void GetVariableLengthColumn(columnIndex_t index, IColumnDataWriter& columnData, const Extract_0_Data0& row) const
        {
            if (index >= 5)
                throw ProxyHostRuntimeException(E_COLUMN_INDEX_OUT_OF_RANGE, {index, 5});
            if (m_accessData[index].m_fixedLength)
            throw ProxyHostRuntimeException(E_WRONG_METHOD_TO_READ_COLUMN_VALUE, { "Fixed length", "GetVariableLengthColumn"});

            switch (index)
            {
                case 4: // FString
                {
                    FString *data = reinterpret_cast<FString*>((char*)(&row) + m_accessData[index].m_offset);
                    if (data->IsNull())
                        columnData.Nullify(USqlColumnType::String);
                    else
                        columnData.SetData(USqlColumnType::String, (const char*)data->buffer(), data->size());
                     break;
                }

            default: 
                throw ProxyHostRuntimeException(E_UNSUPPORTED_COLUMN_TYPE, { index });
            }
        }
    };
#endif // defined(COMPILE_NATIVE)
#if defined(COMPILE_NATIVE)
    template<>
    class ProxyHostRowPolicy<Process_2_Data0>
    {
    public:
        ColumnAccessData m_accessData[6];
        ProxyHostColumnMeta m_columns[6];
        std::map<const char*, int, CStringCompare> m_columnMap;

        ProxyHostRowPolicy(): ProxyHostRowPolicy(std::vector<columnIndex_t>()) {}

        ProxyHostRowPolicy(const std::vector<columnIndex_t>& readOnlyColumns)
        {
            bool isReadOnlyColumn[6];
            std::fill(isReadOnlyColumn, isReadOnlyColumn + 6, false);
            for(auto& index : readOnlyColumns)
            {
                isReadOnlyColumn[index] = true;
            }

            m_accessData[0].Initialize(true, offsetof(Process_2_Data0, m_SepalLength_Mean), sizeof(decltype(Process_2_Data0::m_SepalLength_Mean)));
            m_columns[0].Initialize("SepalLength_Mean", USqlColumnType::Double, isReadOnlyColumn[0]);
            m_columnMap.insert(make_pair("SepalLength_Mean", 0));
            m_accessData[1].Initialize(true, offsetof(Process_2_Data0, m_SepalWidth_Mean), sizeof(decltype(Process_2_Data0::m_SepalWidth_Mean)));
            m_columns[1].Initialize("SepalWidth_Mean", USqlColumnType::Double, isReadOnlyColumn[1]);
            m_columnMap.insert(make_pair("SepalWidth_Mean", 1));
            m_accessData[2].Initialize(true, offsetof(Process_2_Data0, m_PetalLength_Mean), sizeof(decltype(Process_2_Data0::m_PetalLength_Mean)));
            m_columns[2].Initialize("PetalLength_Mean", USqlColumnType::Double, isReadOnlyColumn[2]);
            m_columnMap.insert(make_pair("PetalLength_Mean", 2));
            m_accessData[3].Initialize(true, offsetof(Process_2_Data0, m_PetalWidth_Mean), sizeof(decltype(Process_2_Data0::m_PetalWidth_Mean)));
            m_columns[3].Initialize("PetalWidth_Mean", USqlColumnType::Double, isReadOnlyColumn[3]);
            m_columnMap.insert(make_pair("PetalWidth_Mean", 3));
            m_accessData[4].Initialize(false, offsetof(Process_2_Data0, m_Name), sizeof(decltype(Process_2_Data0::m_Name)));
            m_columns[4].Initialize("Name", USqlColumnType::String, isReadOnlyColumn[4]);
            m_columnMap.insert(make_pair("Name", 4));
            m_accessData[5].Initialize(true, offsetof(Process_2_Data0, m_Count), sizeof(decltype(Process_2_Data0::m_Count)));
            m_columns[5].Initialize("Count", USqlColumnType::Integer, isReadOnlyColumn[5]);
            m_columnMap.insert(make_pair("Count", 5));
        }

        columnIndex_t GetColumnCount() const noexcept
        {
            return 6;
        }

        void GetFixedLengthColumn(columnIndex_t index, FixedLengthColumnData& columnData, const Process_2_Data0& row) const
        {
            if (index >= 6)
                throw ProxyHostRuntimeException(E_COLUMN_INDEX_OUT_OF_RANGE, {index, 6});
            if (!m_accessData[index].m_fixedLength)
                throw ProxyHostRuntimeException(E_WRONG_METHOD_TO_READ_COLUMN_VALUE, { "Variable length", "GetFixedLengthColumn"});

            switch (index)
            {
                case 5: // int
                {
                    int* data = reinterpret_cast<int*>((char*)(&row) + m_accessData[index].m_offset);
                    columnData.SetNonNullValue<int>(USqlColumnType::Integer, *data);
                    break;
                }
                case 0: case 1: case 2: case 3: // double
                {
                    double* data = reinterpret_cast<double*>((char*)(&row) + m_accessData[index].m_offset);
                    columnData.SetNonNullValue<double>(USqlColumnType::Double, *data);
                    break;
                }
            default:
                throw ProxyHostRuntimeException(E_UNSUPPORTED_COLUMN_TYPE, { index });
            }
        }

        void GetVariableLengthColumn(columnIndex_t index, IColumnDataWriter& columnData, const Process_2_Data0& row) const
        {
            if (index >= 6)
                throw ProxyHostRuntimeException(E_COLUMN_INDEX_OUT_OF_RANGE, {index, 6});
            if (m_accessData[index].m_fixedLength)
            throw ProxyHostRuntimeException(E_WRONG_METHOD_TO_READ_COLUMN_VALUE, { "Fixed length", "GetVariableLengthColumn"});

            switch (index)
            {
                case 4: // FString
                {
                    FString *data = reinterpret_cast<FString*>((char*)(&row) + m_accessData[index].m_offset);
                    if (data->IsNull())
                        columnData.Nullify(USqlColumnType::String);
                    else
                        columnData.SetData(USqlColumnType::String, (const char*)data->buffer(), data->size());
                     break;
                }

            default: 
                throw ProxyHostRuntimeException(E_UNSUPPORTED_COLUMN_TYPE, { index });
            }
        }
    };
#endif // defined(COMPILE_NATIVE)
#if defined(COMPILE_NATIVE)
    template<>
    class ProxyHostRowPolicy<ReduceKey_Process_2>
    {
    public:
        ColumnAccessData m_accessData[1];
        ProxyHostColumnMeta m_columns[1];
        std::map<const char*, int, CStringCompare> m_columnMap;

        ProxyHostRowPolicy(): ProxyHostRowPolicy(std::vector<columnIndex_t>()) {}

        ProxyHostRowPolicy(const std::vector<columnIndex_t>& readOnlyColumns)
        {
            bool isReadOnlyColumn[1];
            std::fill(isReadOnlyColumn, isReadOnlyColumn + 1, false);
            for(auto& index : readOnlyColumns)
            {
                isReadOnlyColumn[index] = true;
            }

            m_accessData[0].Initialize(false, offsetof(ReduceKey_Process_2, m_Name), sizeof(decltype(ReduceKey_Process_2::m_Name)));
            m_columns[0].Initialize("Name", USqlColumnType::String, isReadOnlyColumn[0]);
            m_columnMap.insert(make_pair("Name", 0));
        }

        columnIndex_t GetColumnCount() const noexcept
        {
            return 1;
        }

        void GetFixedLengthColumn(columnIndex_t index, FixedLengthColumnData& columnData, const ReduceKey_Process_2& row) const
        {
            if (index >= 1)
                throw ProxyHostRuntimeException(E_COLUMN_INDEX_OUT_OF_RANGE, {index, 1});
            if (!m_accessData[index].m_fixedLength)
                throw ProxyHostRuntimeException(E_WRONG_METHOD_TO_READ_COLUMN_VALUE, { "Variable length", "GetFixedLengthColumn"});
        }

        void GetVariableLengthColumn(columnIndex_t index, IColumnDataWriter& columnData, const ReduceKey_Process_2& row) const
        {
            if (index >= 1)
                throw ProxyHostRuntimeException(E_COLUMN_INDEX_OUT_OF_RANGE, {index, 1});
            if (m_accessData[index].m_fixedLength)
            throw ProxyHostRuntimeException(E_WRONG_METHOD_TO_READ_COLUMN_VALUE, { "Fixed length", "GetVariableLengthColumn"});

            switch (index)
            {
                case 0: // FString
                {
                    FString *data = reinterpret_cast<FString*>((char*)(&row) + m_accessData[index].m_offset);
                    if (data->IsNull())
                        columnData.Nullify(USqlColumnType::String);
                    else
                        columnData.SetData(USqlColumnType::String, (const char*)data->buffer(), data->size());
                     break;
                }

            default: 
                throw ProxyHostRuntimeException(E_UNSUPPORTED_COLUMN_TYPE, { index });
            }
        }
    };
#endif // defined(COMPILE_NATIVE)
#if defined(COMPILE_NATIVE)
    template<>
    class ProxyHostRowPolicy<Extract_4_Data0>
    {
    public:
        ColumnAccessData m_accessData[7];
        ProxyHostColumnMeta m_columns[7];
        std::map<const char*, int, CStringCompare> m_columnMap;

        ProxyHostRowPolicy(): ProxyHostRowPolicy(std::vector<columnIndex_t>()) {}

        ProxyHostRowPolicy(const std::vector<columnIndex_t>& readOnlyColumns)
        {
            bool isReadOnlyColumn[7];
            std::fill(isReadOnlyColumn, isReadOnlyColumn + 7, false);
            for(auto& index : readOnlyColumns)
            {
                isReadOnlyColumn[index] = true;
            }

            m_accessData[0].Initialize(false, offsetof(Extract_4_Data0, m_UserId), sizeof(decltype(Extract_4_Data0::m_UserId)));
            m_columns[0].Initialize("UserId", USqlColumnType::String, isReadOnlyColumn[0]);
            m_columnMap.insert(make_pair("UserId", 0));
            m_accessData[1].Initialize(false, offsetof(Extract_4_Data0, m_Start), sizeof(decltype(Extract_4_Data0::m_Start)));
            m_columns[1].Initialize("Start", USqlColumnType::String, isReadOnlyColumn[1]);
            m_columnMap.insert(make_pair("Start", 1));
            m_accessData[2].Initialize(false, offsetof(Extract_4_Data0, m_Region), sizeof(decltype(Extract_4_Data0::m_Region)));
            m_columns[2].Initialize("Region", USqlColumnType::String, isReadOnlyColumn[2]);
            m_columnMap.insert(make_pair("Region", 2));
            m_accessData[3].Initialize(false, offsetof(Extract_4_Data0, m_Query), sizeof(decltype(Extract_4_Data0::m_Query)));
            m_columns[3].Initialize("Query", USqlColumnType::String, isReadOnlyColumn[3]);
            m_columnMap.insert(make_pair("Query", 3));
            m_accessData[4].Initialize(false, offsetof(Extract_4_Data0, m_Duration), sizeof(decltype(Extract_4_Data0::m_Duration)));
            m_columns[4].Initialize("Duration", USqlColumnType::String, isReadOnlyColumn[4]);
            m_columnMap.insert(make_pair("Duration", 4));
            m_accessData[5].Initialize(false, offsetof(Extract_4_Data0, m_Urls), sizeof(decltype(Extract_4_Data0::m_Urls)));
            m_columns[5].Initialize("Urls", USqlColumnType::String, isReadOnlyColumn[5]);
            m_columnMap.insert(make_pair("Urls", 5));
            m_accessData[6].Initialize(false, offsetof(Extract_4_Data0, m_ClickedUrls), sizeof(decltype(Extract_4_Data0::m_ClickedUrls)));
            m_columns[6].Initialize("ClickedUrls", USqlColumnType::String, isReadOnlyColumn[6]);
            m_columnMap.insert(make_pair("ClickedUrls", 6));
        }

        columnIndex_t GetColumnCount() const noexcept
        {
            return 7;
        }

        void GetFixedLengthColumn(columnIndex_t index, FixedLengthColumnData& columnData, const Extract_4_Data0& row) const
        {
            if (index >= 7)
                throw ProxyHostRuntimeException(E_COLUMN_INDEX_OUT_OF_RANGE, {index, 7});
            if (!m_accessData[index].m_fixedLength)
                throw ProxyHostRuntimeException(E_WRONG_METHOD_TO_READ_COLUMN_VALUE, { "Variable length", "GetFixedLengthColumn"});
        }

        void GetVariableLengthColumn(columnIndex_t index, IColumnDataWriter& columnData, const Extract_4_Data0& row) const
        {
            if (index >= 7)
                throw ProxyHostRuntimeException(E_COLUMN_INDEX_OUT_OF_RANGE, {index, 7});
            if (m_accessData[index].m_fixedLength)
            throw ProxyHostRuntimeException(E_WRONG_METHOD_TO_READ_COLUMN_VALUE, { "Fixed length", "GetVariableLengthColumn"});

            switch (index)
            {
                case 0: case 1: case 2: case 3: case 4: case 5: case 6: // FString
                {
                    FString *data = reinterpret_cast<FString*>((char*)(&row) + m_accessData[index].m_offset);
                    if (data->IsNull())
                        columnData.Nullify(USqlColumnType::String);
                    else
                        columnData.SetData(USqlColumnType::String, (const char*)data->buffer(), data->size());
                     break;
                }

            default: 
                throw ProxyHostRuntimeException(E_UNSUPPORTED_COLUMN_TYPE, { index });
            }
        }
    };
#endif // defined(COMPILE_NATIVE)
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
                    input->Read(row.m_SepalLength);
                    input->Read(row.m_SepalWidth);
                    input->Read(row.m_PetalLength);
                    input->Read(row.m_PetalWidth);
                    input->Read(row.m_Name);
                }
                else
                {
            char ___masking___[1];
            memset(___masking___, 0, sizeof(___masking___));
                    ___masking___[0] = b;
                    input->Read(row.m_SepalLength);
                    input->Read(row.m_SepalWidth);
                    input->Read(row.m_PetalLength);
                    input->Read(row.m_PetalWidth);
                    if ((___masking___[0] & 2 ) != 2)
                    {
                        input->Read(row.m_Name);
                    }
                    else
                    {
                        row.m_Name.SetNull();
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
            if (row.m_Name.IsNull())
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
            output->Write(row.m_SepalLength);
            output->Write(row.m_SepalWidth);
            output->Write(row.m_PetalLength);
            output->Write(row.m_PetalWidth);
            if (!row.m_Name.IsNull())
            {
                output->Write(row.m_Name);
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
    INLINE Extract_0_Data0::Extract_0_Data0(const Extract_0_Data0 & c, IncrementalAllocator * alloc) :
            m_SepalLength(c.m_SepalLength),
            m_SepalWidth(c.m_SepalWidth),
            m_PetalLength(c.m_PetalLength),
            m_PetalWidth(c.m_PetalWidth),
            m_Name(c.m_Name, alloc)
    {
    }



    INLINE Extract_4_Data0::Extract_4_Data0(const Extract_4_Data0 & c, IncrementalAllocator * alloc) :
            m_UserId(c.m_UserId, alloc),
            m_Start(c.m_Start, alloc),
            m_Region(c.m_Region, alloc),
            m_Query(c.m_Query, alloc),
            m_Duration(c.m_Duration, alloc),
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


ScopeEngine::ProxyHostEnvironmentHelper* g_udoAdapterHostEnvironment = NULL;

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
            FString m_Name;

            KeyStruct(Extract_0_Data0 & c) :
                m_Name(c.m_Name)
            {
            }

            KeyStruct(const Extract_0_Data0 & c, IncrementalAllocator * alloc) :
                m_Name(const_cast<Extract_0_Data0&>(c).m_Name, alloc)
            {
            }

            KeyStruct(KeyStruct & c) :
                m_Name(c.m_Name)
            {
            }

            KeyStruct(const KeyStruct & c, IncrementalAllocator * alloc) :
                m_Name(const_cast<KeyStruct&>(c).m_Name, alloc)
            {
            }

            KeyStruct() :
                m_Name()
            {
            }

            friend std::ostream& operator<<(std::ostream& os, const KeyStruct& row)
            {

                ScopeEngine::OutputRowContent(
                    std::string{ u8"Name:string" },
                    reinterpret_cast<const char*>(&row),
                    os);

                return os;
            }
        };

        typedef KeyStruct KeyType;

        static int Compare(Extract_0_Data0 & row, KeyType & key)
        {
            int r = 0;
            if ((r = ScopeTypeCompare(row.m_Name, key.m_Name)) != 0)
                return r;
            return r;
        }

        static int Compare(Extract_0_Data0 * n1, Extract_0_Data0 * n2)
        {
            int r = 0;
            if ((r = ScopeTypeCompare((*n1).m_Name, (*n2).m_Name)) != 0)
                return r;
            return r;
        }

        // Key function for MKQsort algorithm
        static __int64 Key(Extract_0_Data0 * p, int depth)
        {
            if (depth < 1 && (*p).m_Name.IsNull())
            {
                // Special case for "null" string
                return (__int64)(256);
            }
            else if (depth == (int) (*p).m_Name.size())
            {
                // Special case for end-of-string (field separator)
                return (__int64)(-1);
            }
            else if (depth < (int) (*p).m_Name.size())
            {
                // For string convert to unsigned char first. Otherwise, unicode will have negative value which will have different order than binary comparison.
                return (__int64)((unsigned char)((*p).m_Name.buffer()[depth]));
            }

            depth -= (int) ((*p).m_Name.size() + 1);


            return 0;
        }

        // End of Key function for MKQSort algorithm
        static bool EofKey(Extract_0_Data0 * p, int depth)
        {
            depth -= (int) ((*p).m_Name.size() + 1);
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

        static bool Deserialize(TextInputStream<TextInputStreamTraitsConst<',', '\0', '\0', false, false, Default, false, false, false, 0, CharFormat_uint16, false, false>, CosmosInput> * input, Extract_0_Data0 & row)
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

                    input->Read(row.m_SepalLength);
                    input->Read(row.m_SepalWidth);
                    input->Read(row.m_PetalLength);
                    input->Read(row.m_PetalWidth);
                    input->Read(row.m_Name);

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
                            { input->CurrentLineNumber() - 1, 5, input->CurrentField() },
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
            static const std::array<const char*, 6> c_columnNames =
            {
                "SepalLength",
                "SepalWidth",
                "PetalLength",
                "PetalWidth",
                "Name",
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
    class KeyComparePolicy<Extract_0_Data0,UID_Process_2>
    {
    public:
        struct KeyStruct
        {
            FString m_Name;

            KeyStruct(Extract_0_Data0 & c) :
                m_Name(c.m_Name)
            {
            }

            KeyStruct(const Extract_0_Data0 & c, IncrementalAllocator * alloc) :
                m_Name(const_cast<Extract_0_Data0&>(c).m_Name, alloc)
            {
            }

            KeyStruct(KeyStruct & c) :
                m_Name(c.m_Name)
            {
            }

            KeyStruct(const KeyStruct & c, IncrementalAllocator * alloc) :
                m_Name(const_cast<KeyStruct&>(c).m_Name, alloc)
            {
            }

            KeyStruct() :
                m_Name()
            {
            }

            friend std::ostream& operator<<(std::ostream& os, const KeyStruct& row)
            {

                ScopeEngine::OutputRowContent(
                    std::string{ u8"Name:string" },
                    reinterpret_cast<const char*>(&row),
                    os);

                return os;
            }
        };

        typedef KeyStruct KeyType;

        static int Compare(Extract_0_Data0 & row, KeyType & key)
        {
            int r = 0;
            if ((r = ScopeTypeCompare(row.m_Name, key.m_Name)) != 0)
                return r;
            return r;
        }

        static int Compare(Extract_0_Data0 * n1, Extract_0_Data0 * n2)
        {
            int r = 0;
            if ((r = ScopeTypeCompare((*n1).m_Name, (*n2).m_Name)) != 0)
                return r;
            return r;
        }

    };




    template<>
    class RowTransformPolicy<Extract_0_Data0, Process_2_Data0, UID_Process_2>
    {
    public:
        static bool FilterTransformRow(Extract_0_Data0 & input, Process_2_Data0 & output, IncrementalAllocator * alloc)
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
#endif // defined(COMPILE_MANAGED)


#if defined(COMPILE_NATIVE)
    template<>
    class AdapterToHostRowCopyPolicy<Extract_0_Data0, Process_2_Data0, UID_Process_2>
    {
    public:
        static void CopyInputRow(Extract_0_Data0& inputRow, Process_2_Data0& outputRow, IncrementalAllocator& alloc)
        {
                throw ProxyHostRuntimeException(E_COPY_FROM_INPUT_ROW_NOT_SUPPORTED, {});
        }

        static void MarshalUdoRow(const IRowDataReader& udoRow, Process_2_Data0& outputRow, const ProxyHostPassTroughRow<Process_2_Data0>& passThroughRow, IncrementalAllocator& alloc)
        {
            if (udoRow.HasValue(0))
            {
                FixedLengthColumnData columnData;
                udoRow.Get(0, columnData);
                if (columnData.m_type != USqlColumnType::Double)
                {
                    throw ProxyHostRuntimeException(E_UNEXPECTED_COLUMN_TYPE, 
                        {0, USqlColumnTypeTraits<USqlColumnType::Double>::typeName, ProxyHostEnvironmentHelper::GetInstance()->GetTypeData(columnData.m_type).GetTypeName()});
                }
                if (columnData.m_isNull)
                    throw ProxyHostRuntimeException(E_UNEXPECTED_NULL_VALUE, {0, USqlColumnTypeTraits<USqlColumnType::Double>::typeName});
                    outputRow.m_SepalLength_Mean = columnData.GetData<double>();
            }
            else if (passThroughRow.HasValue(0))
                outputRow.m_SepalLength_Mean = passThroughRow.GetRuntimeRow().m_SepalLength_Mean;
            else
                ProxyColumnTypeTraits<double>::SetDefault(outputRow.m_SepalLength_Mean);
            if (udoRow.HasValue(1))
            {
                FixedLengthColumnData columnData;
                udoRow.Get(1, columnData);
                if (columnData.m_type != USqlColumnType::Double)
                {
                    throw ProxyHostRuntimeException(E_UNEXPECTED_COLUMN_TYPE, 
                        {1, USqlColumnTypeTraits<USqlColumnType::Double>::typeName, ProxyHostEnvironmentHelper::GetInstance()->GetTypeData(columnData.m_type).GetTypeName()});
                }
                if (columnData.m_isNull)
                    throw ProxyHostRuntimeException(E_UNEXPECTED_NULL_VALUE, {1, USqlColumnTypeTraits<USqlColumnType::Double>::typeName});
                    outputRow.m_SepalWidth_Mean = columnData.GetData<double>();
            }
            else if (passThroughRow.HasValue(1))
                outputRow.m_SepalWidth_Mean = passThroughRow.GetRuntimeRow().m_SepalWidth_Mean;
            else
                ProxyColumnTypeTraits<double>::SetDefault(outputRow.m_SepalWidth_Mean);
            if (udoRow.HasValue(2))
            {
                FixedLengthColumnData columnData;
                udoRow.Get(2, columnData);
                if (columnData.m_type != USqlColumnType::Double)
                {
                    throw ProxyHostRuntimeException(E_UNEXPECTED_COLUMN_TYPE, 
                        {2, USqlColumnTypeTraits<USqlColumnType::Double>::typeName, ProxyHostEnvironmentHelper::GetInstance()->GetTypeData(columnData.m_type).GetTypeName()});
                }
                if (columnData.m_isNull)
                    throw ProxyHostRuntimeException(E_UNEXPECTED_NULL_VALUE, {2, USqlColumnTypeTraits<USqlColumnType::Double>::typeName});
                    outputRow.m_PetalLength_Mean = columnData.GetData<double>();
            }
            else if (passThroughRow.HasValue(2))
                outputRow.m_PetalLength_Mean = passThroughRow.GetRuntimeRow().m_PetalLength_Mean;
            else
                ProxyColumnTypeTraits<double>::SetDefault(outputRow.m_PetalLength_Mean);
            if (udoRow.HasValue(3))
            {
                FixedLengthColumnData columnData;
                udoRow.Get(3, columnData);
                if (columnData.m_type != USqlColumnType::Double)
                {
                    throw ProxyHostRuntimeException(E_UNEXPECTED_COLUMN_TYPE, 
                        {3, USqlColumnTypeTraits<USqlColumnType::Double>::typeName, ProxyHostEnvironmentHelper::GetInstance()->GetTypeData(columnData.m_type).GetTypeName()});
                }
                if (columnData.m_isNull)
                    throw ProxyHostRuntimeException(E_UNEXPECTED_NULL_VALUE, {3, USqlColumnTypeTraits<USqlColumnType::Double>::typeName});
                    outputRow.m_PetalWidth_Mean = columnData.GetData<double>();
            }
            else if (passThroughRow.HasValue(3))
                outputRow.m_PetalWidth_Mean = passThroughRow.GetRuntimeRow().m_PetalWidth_Mean;
            else
                ProxyColumnTypeTraits<double>::SetDefault(outputRow.m_PetalWidth_Mean);
            if (udoRow.HasValue(4))
            {
                FixedArrayColumnData<FString> columnData(alloc, outputRow.m_Name);
                udoRow.Get(4, columnData);
                if (columnData.GetType() != USqlColumnType::String)
                {
                    throw ProxyHostRuntimeException(E_UNEXPECTED_COLUMN_TYPE, 
                        {4, USqlColumnTypeTraits<USqlColumnType::String>::typeName, ProxyHostEnvironmentHelper::GetInstance()->GetTypeData(columnData.GetType()).GetTypeName()});
                }
            }
            else if (passThroughRow.HasValue(4))
                outputRow.m_Name = passThroughRow.GetRuntimeRow().m_Name;
            else
                ProxyColumnTypeTraits<FString>::SetDefault(outputRow.m_Name);

            if (udoRow.HasValue(5))
            {
                FixedLengthColumnData columnData;
                udoRow.Get(5, columnData);
                if (columnData.m_type != USqlColumnType::Integer)
                {
                    throw ProxyHostRuntimeException(E_UNEXPECTED_COLUMN_TYPE, 
                        {5, USqlColumnTypeTraits<USqlColumnType::Integer>::typeName, ProxyHostEnvironmentHelper::GetInstance()->GetTypeData(columnData.m_type).GetTypeName()});
                }
                if (columnData.m_isNull)
                    throw ProxyHostRuntimeException(E_UNEXPECTED_NULL_VALUE, {5, USqlColumnTypeTraits<USqlColumnType::Integer>::typeName});
                    outputRow.m_Count = columnData.GetData<int>();
            }
            else if (passThroughRow.HasValue(5))
                outputRow.m_Count = passThroughRow.GetRuntimeRow().m_Count;
            else
                ProxyColumnTypeTraits<int>::SetDefault(outputRow.m_Count);
        }

        static const std::vector<columnIndex_t> OutputReadOnlyColumns()
        {
            return std::vector<columnIndex_t> {};
        }

        static const std::vector<columnIndex_t> InputReadOnlyColumns()
        {
            return std::vector<columnIndex_t> {};
        }

        static void CopyReadOnlyColumns(Extract_0_Data0& inputRow, Process_2_Data0& outputRow, IncrementalAllocator& alloc)
        {
        } 

    };
#endif // defined(COMPILE_NATIVE)



    template<> 
    class TextOutputPolicy<Process_2_Data0, UID_SV1_Extract_out0>
    {
    public:

        static void Serialize(TextOutputStream<TextOutputStreamTraitsConst<',', '\0', false, true, false, false, false, Default, false, CharFormat_uint16>, CosmosOutput> * output, Process_2_Data0 & row)
        {
            output->Write<double,false>(row.m_SepalLength_Mean);
            output->WriteDelimiter();
            output->Write<double,false>(row.m_SepalWidth_Mean);
            output->WriteDelimiter();
            output->Write<double,false>(row.m_PetalLength_Mean);
            output->WriteDelimiter();
            output->Write<double,false>(row.m_PetalWidth_Mean);
            output->WriteDelimiter();
            if (!row.m_Name.IsNull())
            {
                output->Write<FString,false>(row.m_Name);
            }
            output->WriteDelimiter();
            output->Write<int,false>(row.m_Count);
            output->WriteNewLine();
        }

        static void SerializeHeader(TextOutputStream<TextOutputStreamTraitsConst<',', '\0', false, true, false, false, false, Default, false, CharFormat_uint16>, CosmosOutput> * output)
        {
            SCOPE_ASSERT(!"TextOutputPolicy::SerializeHeader method should not be invoked.");
        }
    };



#if defined(COMPILE_MANAGED)
#endif // defined(COMPILE_MANAGED)

#if defined(COMPILE_NATIVE)
struct ExtractorType1_SV1_Extr : Extractor<Extract_0_Data0, TextExtractPolicy<Extract_0_Data0, UID_Extract_0>, TextInputStream<TextInputStreamTraitsConst<',', '\0', '\0', false, false, Default, false, false, false, 0, CharFormat_uint16, false, false>, CosmosInput>> { using Extractor<Extract_0_Data0, TextExtractPolicy<Extract_0_Data0, UID_Extract_0>, TextInputStream<TextInputStreamTraitsConst<',', '\0', '\0', false, false, Default, false, false, false, 0, CharFormat_uint16, false, false>, CosmosInput>>::Extractor; };
struct UnionAllType_Extract_0_Process_1_connector : ParallelUnionAll<ExtractorType1_SV1_Extr, Extract_0_Data0, false> { using ParallelUnionAll<ExtractorType1_SV1_Extr, Extract_0_Data0, false>::ParallelUnionAll; };
struct SorterType_Process_1 : Sorter<Extract_0_Data0> { using Sorter<Extract_0_Data0>::Sorter; };
struct ReducerType_Process_2 : ScopeProcessor<Extract_0_Data0, Process_2_Data0> { using ScopeProcessor<Extract_0_Data0, Process_2_Data0>::ScopeProcessor; };
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
        // load UDO adapter plugin dlls
        constexpr int maxFilePath = 1024;
        char path[maxFilePath + 20];
        size_t pathSize = LoadedImage::GetEngineDirectory(path, maxFilePath);
        ProxyHostEnvironmentHelper::CreateInstance(path);

        strcpy_s(path + pathSize, sizeof(path) - pathSize, "PythonUdoAdapter.dll");
        shared_ptr<LoadedImage> pythonPluginDll = LoadedImage::LoadFromFile(path);
        CreateUdoFactory pythonEntryMethod = (CreateUdoFactory)pythonPluginDll->GetProcAddress("CreateUdoFactory", TRUE);
        ProxyHostEnvironment pythonHostEnvironment(ProxyHostEnvironmentHelper::GetInstance(), 1283457024);
        IAdapterUdoFactory* pythonUdoFactory = GuardAdapterCode ([pythonEntryMethod, &pythonHostEnvironment]()
        {
            return pythonEntryMethod(pythonHostEnvironment);
        });
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

        // ExtractorType1_SV1_Extr: Extractor<Extract_0_Data0, TextExtractPolicy<Extract_0_Data0, UID_Extract_0>, TextInputStream<TextInputStreamTraitsConst<',', '\0', '\0', false, false, Default, false, false, false, 0, CharFormat_uint16, false, false>, CosmosInput>>
        unique_ptr<unique_ptr<ExtractorType1_SV1_Extr>[]> extractor_0_array(new unique_ptr<ExtractorType1_SV1_Extr>[inputCnt - 0]);
        
        for (int i = 0; i < inputCnt; i++)
        {
            extractor_0_array[i - 0].reset(new ExtractorType1_SV1_Extr(inputs[i], false, x_inputBufSize, x_inputBufCnt, x_inputVirtualMemoryLimit, InputStreamParameters(',', '\0', '\0', static_cast<const char*>(__nullptr), false, false, Default, false, false, 0, CharFormat_uint16), UID_Extract_0));
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
        unique_ptr<OperatorDelegate<Extract_0_Data0>> delegate_sorter_Process_1_ptr (new OperatorDelegate<Extract_0_Data0>(sorter_Process_1));
        OperatorDelegate<Extract_0_Data0> * delegate_sorter_Process_1 = delegate_sorter_Process_1_ptr.get();
        ULONG delegate_sorter_Process_1_count = 1;

        // ReducerType_Process_2: ScopeProcessor<Extract_0_Data0, Process_2_Data0>
            ProxyHostUdoCreationCodeEvaluation pythonCreationArgs_UID_Process_2("\'\'\'\r\n  The following is a sample Python UDO.\r\n  Details on Python UDOs: https://microsoft.sharepoint.com/:w:/r/teams/Cosmos/_layouts/15/Doc.aspx?sourcedoc=%7B7E714159-3C83-4822-A357-B44503EF0C80%7D&file=Scope_Python%20UDO%20Extenstion.docx&action=default&mobileredirect=true&DefaultItemOpen=1&cid=e5947e3b-6d54-429b-a1bf-eb226be1a3cf\r\n\'\'\'\r\n\r\nclass DataFrameDemoReducer:\r\n    def __init__(self):\r\n        self.pyadlahelper = __import__(\'pyadlahelper\')\r\n        pass\r\n\r\n    def Reduce(self, inputRowset, outputRow):\r\n        df = self.pyadlahelper.RowsetToDataframe(inputRowset, -1)\r\n        outputRow[\'Name\'] = inputRowset.Key[\'Name\']\r\n        outputRow[\'Count\'] = len(df)\r\n        distribution = df.describe()\r\n        outputRow[\'SepalLength_Mean\'] = round(distribution[\'SepalLength\'][\'mean\'], 2)\r\n        outputRow[\'SepalWidth_Mean\'] = round(distribution[\'SepalWidth\'][\'mean\'], 2)\r\n        outputRow[\'PetalLength_Mean\'] = round(distribution[\'PetalLength\'][\'mean\'], 2)\r\n        outputRow[\'PetalWidth_Mean\'] = round(distribution[\'PetalWidth\'][\'mean\'], 2)\r\n        yield outputRow\r\n\r\nclass SearchLogExtractor:\r\n    def __init__(self):\r\n        pass\r\n\r\n    def Extract(self, rawInput, outputRow):\r\n        stream = rawInput.GetBaseStream\r\n        bufferToRead = bytearray(100 * 1024 * 1024)\r\n        numBytesRead = stream.readinto(bufferToRead)\r\n        if numBytesRead == len(bufferToRead):\r\n            raise RuntimeError(\'input stream is too big\')\r\n\r\n        for row in bufferToRead[:numBytesRead].decode(\'utf-8\').split(\'\\r\\n\'):\r\n            for columnIndex, columnValue in enumerate(row.split(\'\\t\')):\r\n                columnType = outputRow.Schema[columnIndex].Type\r\n                outputRow[columnIndex] = columnType(columnValue)\r\n\r\n            yield outputRow\r\n", "DataFrameDemoReducer()");
            IAdapterReducer& pythonReducer_UID_Process_2 = GuardAdapterCode([pythonUdoFactory, &pythonCreationArgs_UID_Process_2]() -> IAdapterReducer&
            {
                return pythonUdoFactory->CreateReducer(pythonCreationArgs_UID_Process_2);
            });
        unique_ptr<ReducerType_Process_2> reducer_Process_2_ptr (new ReducerType_Process_2(ScopeReducerManagedFactory::MakeAdapter<Extract_0_Data0,Process_2_Data0,ReduceKey_Process_2,UID_Process_2>(pythonReducer_UID_Process_2, delegate_sorter_Process_1), delegate_sorter_Process_1, UID_Process_2));
        ReducerType_Process_2 * reducer_Process_2 = reducer_Process_2_ptr.get();
        ULONG reducer_Process_2_count = 1;

        using OutputterType2_SV1_Extr = Outputter<ReducerType_Process_2, Process_2_Data0, TextOutputPolicy<Process_2_Data0, UID_SV1_Extract_out0>, TextOutputStream<TextOutputStreamTraitsConst<',', '\0', false, true, false, false, false, Default, false, CharFormat_uint16>, CosmosOutput>, false>;
        unique_ptr<OutputterType2_SV1_Extr> outputter_SV1_Extract_out0_ptr(new OutputterType2_SV1_Extr(reducer_Process_2, outputs[0].outputFileName, false, outputs[0].bufferSize, outputs[0].bufferCount, OutputStreamParameters(',', "\r\n", '\0', static_cast<const char*>(__nullptr), false, true, false, false, NULL, Default, false, CharFormat_uint16), UID_SV1_Extract_out0));
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

            // release UDO adapter factories
            pythonUdoFactory->Release();

            // reset UDO adapter host environment
            g_udoAdapterHostEnvironment->Release();
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
template ScopeProcessorManaged<Extract_0_Data0, Process_2_Data0> * ScopeEngine::ScopeReducerManagedFactory::MakeAdapter<Extract_0_Data0, Process_2_Data0,ReduceKey_Process_2, UID_Process_2>(IAdapterReducer&, OperatorDelegate<Extract_0_Data0>*);
#endif // defined(COMPILE_NATIVE)

#endif
#pragma endregion SV1_Extract
#pragma region SV2_Extract
#if defined(COMPILE_SV2_EXTRACT) || defined(COMPILE_ALL_VERTICES)


#if defined(COMPILE_MANAGED)
#endif // defined(COMPILE_MANAGED)


#if defined(COMPILE_NATIVE)
    template<>
    class AdapterExtractorToHostRowCopyPolicy<Extract_4_Data0, UID_Extract_4>
    {
    public:
        static void MarshalUdoRow(const IAdapterUdoRow& udoRow, Extract_4_Data0& outputRow, IncrementalAllocator& alloc)
        {
            if (udoRow.HasValue(0))
            {
                FixedArrayColumnData<FString> columnData(alloc, outputRow.m_UserId);
                udoRow.Get(0, columnData);
                if (columnData.GetType() != USqlColumnType::String)
                {
                    throw ProxyHostRuntimeException(E_UNEXPECTED_COLUMN_TYPE, 
                        {0, USqlColumnTypeTraits<USqlColumnType::String>::typeName, ProxyHostEnvironmentHelper::GetInstance()->GetTypeData(columnData.GetType()).GetTypeName()});
                }
            }
            else
                ProxyColumnTypeTraits<FString>::SetDefault(outputRow.m_UserId);

            if (udoRow.HasValue(1))
            {
                FixedArrayColumnData<FString> columnData(alloc, outputRow.m_Start);
                udoRow.Get(1, columnData);
                if (columnData.GetType() != USqlColumnType::String)
                {
                    throw ProxyHostRuntimeException(E_UNEXPECTED_COLUMN_TYPE, 
                        {1, USqlColumnTypeTraits<USqlColumnType::String>::typeName, ProxyHostEnvironmentHelper::GetInstance()->GetTypeData(columnData.GetType()).GetTypeName()});
                }
            }
            else
                ProxyColumnTypeTraits<FString>::SetDefault(outputRow.m_Start);

            if (udoRow.HasValue(2))
            {
                FixedArrayColumnData<FString> columnData(alloc, outputRow.m_Region);
                udoRow.Get(2, columnData);
                if (columnData.GetType() != USqlColumnType::String)
                {
                    throw ProxyHostRuntimeException(E_UNEXPECTED_COLUMN_TYPE, 
                        {2, USqlColumnTypeTraits<USqlColumnType::String>::typeName, ProxyHostEnvironmentHelper::GetInstance()->GetTypeData(columnData.GetType()).GetTypeName()});
                }
            }
            else
                ProxyColumnTypeTraits<FString>::SetDefault(outputRow.m_Region);

            if (udoRow.HasValue(3))
            {
                FixedArrayColumnData<FString> columnData(alloc, outputRow.m_Query);
                udoRow.Get(3, columnData);
                if (columnData.GetType() != USqlColumnType::String)
                {
                    throw ProxyHostRuntimeException(E_UNEXPECTED_COLUMN_TYPE, 
                        {3, USqlColumnTypeTraits<USqlColumnType::String>::typeName, ProxyHostEnvironmentHelper::GetInstance()->GetTypeData(columnData.GetType()).GetTypeName()});
                }
            }
            else
                ProxyColumnTypeTraits<FString>::SetDefault(outputRow.m_Query);

            if (udoRow.HasValue(4))
            {
                FixedArrayColumnData<FString> columnData(alloc, outputRow.m_Duration);
                udoRow.Get(4, columnData);
                if (columnData.GetType() != USqlColumnType::String)
                {
                    throw ProxyHostRuntimeException(E_UNEXPECTED_COLUMN_TYPE, 
                        {4, USqlColumnTypeTraits<USqlColumnType::String>::typeName, ProxyHostEnvironmentHelper::GetInstance()->GetTypeData(columnData.GetType()).GetTypeName()});
                }
            }
            else
                ProxyColumnTypeTraits<FString>::SetDefault(outputRow.m_Duration);

            if (udoRow.HasValue(5))
            {
                FixedArrayColumnData<FString> columnData(alloc, outputRow.m_Urls);
                udoRow.Get(5, columnData);
                if (columnData.GetType() != USqlColumnType::String)
                {
                    throw ProxyHostRuntimeException(E_UNEXPECTED_COLUMN_TYPE, 
                        {5, USqlColumnTypeTraits<USqlColumnType::String>::typeName, ProxyHostEnvironmentHelper::GetInstance()->GetTypeData(columnData.GetType()).GetTypeName()});
                }
            }
            else
                ProxyColumnTypeTraits<FString>::SetDefault(outputRow.m_Urls);

            if (udoRow.HasValue(6))
            {
                FixedArrayColumnData<FString> columnData(alloc, outputRow.m_ClickedUrls);
                udoRow.Get(6, columnData);
                if (columnData.GetType() != USqlColumnType::String)
                {
                    throw ProxyHostRuntimeException(E_UNEXPECTED_COLUMN_TYPE, 
                        {6, USqlColumnTypeTraits<USqlColumnType::String>::typeName, ProxyHostEnvironmentHelper::GetInstance()->GetTypeData(columnData.GetType()).GetTypeName()});
                }
            }
            else
                ProxyColumnTypeTraits<FString>::SetDefault(outputRow.m_ClickedUrls);

        }
    };
#endif // defined(COMPILE_NATIVE)



    template<> 
    class TextOutputPolicy<Extract_4_Data0, UID_SV2_Extract_out0>
    {
    public:

        static void Serialize(TextOutputStream<TextOutputStreamTraitsConst<',', '\0', false, true, false, false, false, Default, false, CharFormat_uint16>, CosmosOutput> * output, Extract_4_Data0 & row)
        {
            if (!row.m_UserId.IsNull())
            {
                output->Write<FString,false>(row.m_UserId);
            }
            output->WriteDelimiter();
            if (!row.m_Start.IsNull())
            {
                output->Write<FString,false>(row.m_Start);
            }
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
            if (!row.m_Duration.IsNull())
            {
                output->Write<FString,false>(row.m_Duration);
            }
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

        static void SerializeHeader(TextOutputStream<TextOutputStreamTraitsConst<',', '\0', false, true, false, false, false, Default, false, CharFormat_uint16>, CosmosOutput> * output)
        {
            SCOPE_ASSERT(!"TextOutputPolicy::SerializeHeader method should not be invoked.");
        }
    };



#if defined(COMPILE_MANAGED)
#endif // defined(COMPILE_MANAGED)

#if defined(COMPILE_NATIVE)
struct ExtractorType1_SV2_Extr : ScopeExtractor<CosmosInput, Extract_4_Data0, -1> { using ScopeExtractor<CosmosInput, Extract_4_Data0, -1>::ScopeExtractor; };
struct UnionAllType_extractor_serially_Extract_4_connector : RestrictedUnionAllMerger<ExtractorType1_SV2_Extr, Extract_4_Data0> { using RestrictedUnionAllMerger<ExtractorType1_SV2_Extr, Extract_4_Data0>::RestrictedUnionAllMerger; };
#endif // defined(COMPILE_NATIVE)



#if defined(COMPILE_NATIVE)
namespace ScopeGeneratedClasses
{
    extern "C" __declspec(dllexport) void __stdcall SV2_Extract_execute(std::string * argv, int argc, InputFileInfo* inputs, int inputCnt, OutputFileInfo* outputs, int outputCnt, VertexExecutionInfo * vertexExecutionInfo)
    {
#ifdef USE_SSE4_2
        ScopeEngine::CheckCpuSupportsInstructions();
#endif

        ScopeEngine::Configuration::Create(ET_Cosmos, GetCompilerSettings(), vertexExecutionInfo);
        // load UDO adapter plugin dlls
        constexpr int maxFilePath = 1024;
        char path[maxFilePath + 20];
        size_t pathSize = LoadedImage::GetEngineDirectory(path, maxFilePath);
        ProxyHostEnvironmentHelper::CreateInstance(path);

        strcpy_s(path + pathSize, sizeof(path) - pathSize, "PythonUdoAdapter.dll");
        shared_ptr<LoadedImage> pythonPluginDll = LoadedImage::LoadFromFile(path);
        CreateUdoFactory pythonEntryMethod = (CreateUdoFactory)pythonPluginDll->GetProcAddress("CreateUdoFactory", TRUE);
        ProxyHostEnvironment pythonHostEnvironment(ProxyHostEnvironmentHelper::GetInstance(), 1283457024);
        IAdapterUdoFactory* pythonUdoFactory = GuardAdapterCode ([pythonEntryMethod, &pythonHostEnvironment]()
        {
            return pythonEntryMethod(pythonHostEnvironment);
        });
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

        // ExtractorType1_SV2_Extr: ScopeExtractor<CosmosInput, Extract_4_Data0, -1>
        unique_ptr<unique_ptr<ExtractorType1_SV2_Extr>[]> extractor_0_array(new unique_ptr<ExtractorType1_SV2_Extr>[inputCnt - 0]);
        
        for (int i = 0; i < inputCnt; i++)
        {
            ProxyHostUdoCreationCodeEvaluation pythonCreationArgs_UID_Extract_4("\'\'\'\r\n  The following is a sample Python UDO.\r\n  Details on Python UDOs: https://microsoft.sharepoint.com/:w:/r/teams/Cosmos/_layouts/15/Doc.aspx?sourcedoc=%7B7E714159-3C83-4822-A357-B44503EF0C80%7D&file=Scope_Python%20UDO%20Extenstion.docx&action=default&mobileredirect=true&DefaultItemOpen=1&cid=e5947e3b-6d54-429b-a1bf-eb226be1a3cf\r\n\'\'\'\r\n\r\nclass DataFrameDemoReducer:\r\n    def __init__(self):\r\n        self.pyadlahelper = __import__(\'pyadlahelper\')\r\n        pass\r\n\r\n    def Reduce(self, inputRowset, outputRow):\r\n        df = self.pyadlahelper.RowsetToDataframe(inputRowset, -1)\r\n        outputRow[\'Name\'] = inputRowset.Key[\'Name\']\r\n        outputRow[\'Count\'] = len(df)\r\n        distribution = df.describe()\r\n        outputRow[\'SepalLength_Mean\'] = round(distribution[\'SepalLength\'][\'mean\'], 2)\r\n        outputRow[\'SepalWidth_Mean\'] = round(distribution[\'SepalWidth\'][\'mean\'], 2)\r\n        outputRow[\'PetalLength_Mean\'] = round(distribution[\'PetalLength\'][\'mean\'], 2)\r\n        outputRow[\'PetalWidth_Mean\'] = round(distribution[\'PetalWidth\'][\'mean\'], 2)\r\n        yield outputRow\r\n\r\nclass SearchLogExtractor:\r\n    def __init__(self):\r\n        pass\r\n\r\n    def Extract(self, rawInput, outputRow):\r\n        stream = rawInput.GetBaseStream\r\n        bufferToRead = bytearray(100 * 1024 * 1024)\r\n        numBytesRead = stream.readinto(bufferToRead)\r\n        if numBytesRead == len(bufferToRead):\r\n            raise RuntimeError(\'input stream is too big\')\r\n\r\n        for row in bufferToRead[:numBytesRead].decode(\'utf-8\').split(\'\\r\\n\'):\r\n            for columnIndex, columnValue in enumerate(row.split(\'\\t\')):\r\n                columnType = outputRow.Schema[columnIndex].Type\r\n                outputRow[columnIndex] = columnType(columnValue)\r\n\r\n            yield outputRow\r\n", "SearchLogExtractor()");
            IAdapterExtractor& pythonExtractor_UID_Extract_4 = GuardAdapterCode([pythonUdoFactory, &pythonCreationArgs_UID_Extract_4]() -> IAdapterExtractor&
            {
                return pythonUdoFactory->CreateExtractor(pythonCreationArgs_UID_Extract_4);
            });
            extractor_0_array[i - 0].reset(new ExtractorType1_SV2_Extr(ScopeExtractorManagedFactory::MakeAdapter<CosmosInput,Extract_4_Data0,UID_Extract_4, 0>(pythonExtractor_UID_Extract_4), inputs[i], false, x_inputBufSize, x_inputBufCnt, x_inputVirtualMemoryLimit, UID_Extract_4));
        }

    ExtractorType1_SV2_Extr ** extractor_0 = (ExtractorType1_SV2_Extr **)extractor_0_array.get();

        
        ULONG extractor_0_count = (ULONG) inputCnt - 0;

        // Merge streams N->1
        // UnionAllType_extractor_serially_Extract_4_connector: RestrictedUnionAllMerger<ExtractorType1_SV2_Extr, Extract_4_Data0>
        unique_ptr<UnionAllType_extractor_serially_Extract_4_connector> unionall_extractor_serially_Extract_4_connector_ptr(new UnionAllType_extractor_serially_Extract_4_connector(extractor_0,extractor_0_count,1,1,UID_ParallelUnionAll_Extract_4));
        UnionAllType_extractor_serially_Extract_4_connector * unionall_extractor_serially_Extract_4_connector = unionall_extractor_serially_Extract_4_connector_ptr.get();
        ULONG unionall_extractor_serially_Extract_4_connector_count = 1;

        using OutputterType2_SV2_Extr = Outputter<UnionAllType_extractor_serially_Extract_4_connector, Extract_4_Data0, TextOutputPolicy<Extract_4_Data0, UID_SV2_Extract_out0>, TextOutputStream<TextOutputStreamTraitsConst<',', '\0', false, true, false, false, false, Default, false, CharFormat_uint16>, CosmosOutput>, false>;
        unique_ptr<OutputterType2_SV2_Extr> outputter_SV2_Extract_out0_ptr(new OutputterType2_SV2_Extr(unionall_extractor_serially_Extract_4_connector, outputs[0].outputFileName, false, outputs[0].bufferSize, outputs[0].bufferCount, OutputStreamParameters(',', "\r\n", '\0', static_cast<const char*>(__nullptr), false, true, false, false, NULL, Default, false, CharFormat_uint16), UID_SV2_Extract_out0));
        OutputterType2_SV2_Extr * outputter_SV2_Extract_out0 = outputter_SV2_Extract_out0_ptr.get();
        // Create timer to automatically dump statistics available at the time, when approaching max permitted time for vertex execution
        auto dumpStatsTimer{ ScopeEngine::CreateDumpStatsTimer(vertexExecutionInfo->m_updateStatusThresholdToAutoDumpStatistics, *outputter_SV2_Extract_out0) };

        try
        {
            // Init operator chain
            outputter_SV2_Extract_out0->InitOperatorPipeline();

            // Execute the whole vertex by calling the GetNextRow on top operator
            Extract_4_Data0 row;
            outputter_SV2_Extract_out0->GetNextRow(row);

            // Close operator chain
            outputter_SV2_Extract_out0->Close();

            // release UDO adapter factories
            pythonUdoFactory->Release();

            // reset UDO adapter host environment
            g_udoAdapterHostEnvironment->Release();
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
template ScopeExtractorManaged<CosmosInput,Extract_4_Data0> * ScopeEngine::ScopeExtractorManagedFactory::MakeAdapter<CosmosInput, Extract_4_Data0, UID_Extract_4, 0>(IAdapterExtractor&);
#endif // defined(COMPILE_NATIVE)

#endif
#pragma endregion SV2_Extract
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

#endif // COMPILE_NATIVE
#endif //#if defined(COMPILE_SV2_EXTRACT) || defined(COMPILE_ALL_VERTICES)
// Empty footer
